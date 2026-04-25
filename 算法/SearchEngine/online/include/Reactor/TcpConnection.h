#ifndef __TCPCONNECTION_H__
#define __TCPCONNECTION_H__

#include "Socket.h"
#include "SocketIO.h"
#include "InetAddress.h"

#include <functional>
#include <memory>

using std::function;
using std::shared_ptr;

namespace SearchEngine
{

class EventLoop;//前向声明

class TcpConnection
: public std::enable_shared_from_this<TcpConnection>
{
    using TcpConnectionPtr = shared_ptr<TcpConnection>;
    using TcpConnectionCallback = function<void(const TcpConnectionPtr &)>;
public:
    explicit TcpConnection(int fd, EventLoop *loop);
    ~TcpConnection();
    void send(const string &msg);
    void sendInLoop(const string &msg);
    string receive();
    bool isClosed() const;

    //为了方便调试的函数
    string toString();

/* private: */
    //获取本端地址与对端地址
    InetAddress getLocalAddr();
    InetAddress getPeerAddr();

public:
    //三个回调的注册
    void setNewConnectionCallback(const TcpConnectionCallback &cb);
    void setMessageCallback(const TcpConnectionCallback &cb);
    void setCloseCallback(const TcpConnectionCallback &cb);

    //三个回调的执行
    void handleNewConnectionCallback();
    void handleMessageCallback();
    void handleCloseCallback();

private:
    EventLoop *_loop;//让TcpConnection知道EventLoop的存在
    SocketIO _sockIO;

    //为了调试而加入的三个数据成员
    Socket _sock;
    InetAddress _localAddr;
    InetAddress _peerAddr;

    TcpConnectionCallback _onNewConnection;//连接建立
    TcpConnectionCallback _onMessage;//消息到达
    TcpConnectionCallback _onClose;//连接断开
};

}//end of namespace search_engine
#endif
