#include "../../include/Reactor/EventLoop.h"
#include "../../include/Reactor/Acceptor.h"
#include "../../include/Reactor/TcpConnection.h"
#include <unistd.h>
#include <sys/eventfd.h>

#include <iostream>

using std::cout;
using std::cerr;
using std::endl;

namespace SearchEngine
{

EventLoop::EventLoop(Acceptor &acceptor)
: _epfd(createEpollFd())
, _evtList(1024)
, _isLooping(false)
, _acceptor(acceptor)
, _conns()
, _efd(createEventFd())
, _pendings()
, _mutex()
{
    //获取listenfd
    int listenfd = _acceptor.fd();
    //将listenfd放在红黑树上进行监听
    addEpollReadFd(listenfd);

    //还需要监听用于通知的文件描述符_efd
    addEpollReadFd(_efd);
}

EventLoop::~EventLoop()
{
    close(_epfd);
    close(_efd);
}

//事件是否在循环
void EventLoop::loop()
{
    _isLooping = true;
    while(_isLooping)
    {
        waitEpollFd();
    }
}

void EventLoop::unloop()
{
    _isLooping = false;
}

//为了封装epoll_wait函数
void EventLoop::waitEpollFd()
{
    int nready = 0;
    do{
        nready = epoll_wait(_epfd, &*_evtList.begin(), _evtList.size(), 3000);
    }while(-1 == nready && errno == EINTR);

    if(-1 == nready)
    {
        cerr << "-1 == nready" << endl;
        return;
    }
    else if(0 == nready)
    {
        cout << ">>epoll_wait timeout!!!" << endl;
    }
    else
    {
        //需要将vector手动扩容
        if(nready == (int)_evtList.size())
        {
            _evtList.resize(2 * nready);
        }

        for(int idx = 0; idx < nready; ++idx)
        {
            int fd = _evtList[idx].data.fd;
            int listenfd = _acceptor.fd();
            if(fd == listenfd)//listenfd就绪了
            {
                if(_evtList[idx].events & EPOLLIN)
                {
                    //处理新的连接请求
                    handleNewConnection();
                }
            }
            else if(fd == _efd)//用于通知的文件描述符就绪
            {
                if(_evtList[idx].events & EPOLLIN)
                {
                    handleRead();
                    //执行所有的任务，也就是遍历vector
                    doPendingFunctors();
                }
            }
            else
            {
                if(_evtList[idx].events & EPOLLIN)
                {
                    //老的连接上有数据发过来
                    handleMessage(fd);
                }
            }
        }
    }
}

//处理新的连接请求
void EventLoop::handleNewConnection()
{
    //只要accept函数有正确返回结果，就表明三次握手建立成功了
    int connfd = _acceptor.accept();
    if(connfd < 0)
    {
        perror("handleNewConnection");
        return;
    }

    //将connfd放在红黑树上进行监听
    addEpollReadFd(connfd);

    //就说明可以创建TcpConnection的对象
    TcpConnectionPtr con(new TcpConnection(connfd, this));

    con->setNewConnectionCallback(_onNewConnection);//连接建立的注册
    con->setMessageCallback(_onMessage);//消息达到的注册
    con->setCloseCallback(_onClose);//连接断开的注册

    //将键值对放在map中
    _conns.insert({connfd, con});

    con->handleNewConnectionCallback();//执行连接建立的事件
}

//处理老的连接上的数据的收发
void EventLoop::handleMessage(int fd)
{
    auto it = _conns.find(fd);
    if(it != _conns.end())
    {
        //判断连接有没有断开
        bool flag = it->second->isClosed();
        if(flag)
        {
            //执行连接断开的事件
            it->second->handleCloseCallback();
            //将文件描述符从红黑树上删除掉
            delEpollReadFd(fd);
            //还需要从map数据结构中删除
            _conns.erase(it);
        }
        else
        {
            //执行消息达到的事件
            it->second->handleMessageCallback();
        }
    }
    else
    {
        cout << "该连接不存在" << endl;
        return;
    }
}

//封装epoll_create函数
int EventLoop::createEpollFd()
{
    int fd = epoll_create(1);
    if(fd < 0)
    {
        perror("createEpollFd");
        return -1;
    }
    return fd;
}

//将文件描述符放在红黑树上进行监听
void EventLoop::addEpollReadFd(int fd)
{
    struct epoll_event evt;
    evt.data.fd = fd;
    evt.events = EPOLLIN;

    int ret = epoll_ctl(_epfd, EPOLL_CTL_ADD, fd, &evt);
    if(ret < 0)
    {
        perror("addEpollReadFd");
        return;
    }
}

//将文件描述符从红黑树上取消监听
void EventLoop::delEpollReadFd(int fd)
{
    struct epoll_event evt;
    evt.data.fd = fd;
    evt.events = EPOLLIN;

    int ret = epoll_ctl(_epfd, EPOLL_CTL_DEL, fd, &evt);
    if(ret < 0)
    {
        perror("delEpollReadFd");
        return;
    }

}

void EventLoop::setNewConnectionCallback(TcpConnectionCallback &&cb)
{
    _onNewConnection = std::move(cb);
}

void EventLoop::setMessageCallback(TcpConnectionCallback &&cb)
{
    _onMessage = std::move(cb);
}

void EventLoop::setCloseCallback(TcpConnectionCallback &&cb)
{
    _onClose = std::move(cb);
}

//封装了read函数
void EventLoop::handleRead()
{
    uint64_t one = 1;
    ssize_t ret = read(_efd, &one, sizeof(uint64_t));
    if(ret != sizeof(uint64_t))
    {
        perror("handleRead");
        return;
    }
}

//封装了write函数
void EventLoop::wakeup()
{
    uint64_t one = 1;
    ssize_t ret = write(_efd, &one, sizeof(uint64_t));
    if(ret != sizeof(uint64_t))
    {
        perror("handleRead");
        return;
    }
}

//封装了eventfd
int EventLoop::createEventFd()
{
    int fd = eventfd(0, 0);
    if(fd < 0)
    {
        perror("createEventFd");
        return -1;
    }
    return fd;
}

//执行所有的任务，也就是遍历vector
void EventLoop::doPendingFunctors()
{
    vector<Functor> tmp;
    {
        lock_guard<mutex> lg(_mutex);
        tmp.swap(_pendings);//交换
    }


    //此处的cb在进行回调的时候执行的“任务”也就是
    //在TcpConnection的sendInLoop函数中通过bind
    //绑定的this，以及send函数，以及msg就会被
    //触发，将数据发送给客户端
    //_loop->runInLoop(bind(&TcpConnection::send, this, msg));
    for(auto &cb : tmp)
    {
        cb();//执行任务
    }
}

void EventLoop::runInLoop(Functor &&cb)
{
    //将锁的粒度减小(范围减小)
    {
        lock_guard<mutex> lg(_mutex);
        //需要将“任务”存放在vector，也就是数据成员_pendings中
        _pendings.push_back(std::move(cb));
    }

    //唤醒EventLoop/Reactor进行接收数据与发送数据
    wakeup();
}

}//end of namespace search_engine
