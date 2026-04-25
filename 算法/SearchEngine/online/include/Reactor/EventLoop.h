#ifndef __EVENTLOOP_H__
#define __EVENTLOOP_H__

#include <sys/epoll.h>
#include <vector>
#include <map>
#include <memory>
#include <functional>
#include <mutex>

using std::vector;
using std::map;
using std::shared_ptr;
using std::function;
using std::mutex;
using std::lock_guard;

namespace SearchEngine
{

class Acceptor;//前向声明
class TcpConnection;

using TcpConnectionPtr = shared_ptr<TcpConnection>;
using TcpConnectionCallback = function<void(const TcpConnectionPtr &)>;
using Functor = function<void()>;

class EventLoop
{
public:
    EventLoop(Acceptor &acceptor);
    ~EventLoop();

    //事件是否在循环
    void loop();
    void unloop();

private:
    //为了封装epoll_wait函数
    void waitEpollFd();

    //处理新的连接请求
    void handleNewConnection();

    //处理老的连接上的数据额的收发
    void handleMessage(int fd);

    //封装epoll_create函数
    int createEpollFd();

    //将文件描述符放在红黑树上进行监听
    void addEpollReadFd(int fd);
    
    //将文件描述符从红黑树上取消监听
    void delEpollReadFd(int fd);

public:
    void setNewConnectionCallback(TcpConnectionCallback &&cb);
    void setMessageCallback(TcpConnectionCallback &&cb);
    void setCloseCallback(TcpConnectionCallback &&cb);

    //封装了read函数
    void handleRead();

    //封装了write函数
    void wakeup();

    //封装了eventfd
    int createEventFd();

    //执行所有的任务，也就是遍历vector
    void doPendingFunctors();

    //执行任务的函数
    void runInLoop(Functor &&cb);

private:
    int _epfd;//由epoll_create创建的文件描述符
    vector<struct epoll_event> _evtList;//存放就绪文件描述符的数据结构
    bool _isLooping;//标识事件是否在循环
    Acceptor &_acceptor;//为了获取Acceptor类中的accept函数
    map<int, TcpConnectionPtr> _conns;//存放文件描述符与TcpConnection连接对象的键值对

    TcpConnectionCallback _onNewConnection;//连接建立
    TcpConnectionCallback _onMessage;//消息到达
    TcpConnectionCallback _onClose;//连接断开

    int _efd;//使用eventfd创建的文件描述符
    vector<Functor> _pendings;//待执行的"任务"
    mutex _mutex;//互斥访问共享资源vector

};

}//end of namespace search_engine

#endif
