#include "../../include/SearchEngineServer/SearchEngineServer.h"
#include "../../include/MyLog.h"

namespace SearchEngine 
{

SearchEngineServer::SearchEngineServer(size_t threadNum
									   , size_t queSize
									   , const string& ip
									   , unsigned short port)
: _threadPool(threadNum, queSize)
, _tcpServer(ip, port)
{ }

void SearchEngineServer::start() 
{
	_threadPool.start();
	   
	using namespace std::placeholders;
	_tcpServer.setAllCallback(std::bind(&SearchEngineServer::onConnection, this, _1),
                               std::bind(&SearchEngineServer::onMessage, this, _1),
                               std::bind(&SearchEngineServer::onClose, this, _1));

	_tcpServer.start();
}

inline void SearchEngineServer::stop() 
{
    _threadPool.stop();
    _tcpServer.stop();
}

void SearchEngineServer::onConnection(const TcpConnectionPtr& con) 
{
    std:: cout << con->toString() << " has connected!" << std::endl;
    LogInfo("[LogInfo]: client conn success");

    string send = "服务器连接成功！\n\
		\"1 查询内容\" 请求推荐关键字\n\
		\"2 查询内容\" 查询网页\n\
		\"3\"          往下翻页\n\
		\"4\"          往上翻页\n\
		\"5\"          回到首页\n\
		\"6\"          去往尾页\n";
    con->sendInLoop(send);
}

void SearchEngineServer::onMessage(const TcpConnectionPtr& con)
{
    string msg = con->receive();
    printf("\e[0;33m" "IO thread[-1] got a msg\n" "\e[0m");

    CalculateTask calTask(msg, con, _keyRecommander, _webPageSearcher, _Store);
    _threadPool.addTask(std::bind(&CalculateTask::process, calTask));
}

void SearchEngineServer::onClose(const TcpConnectionPtr& con) 
{
    InetAddress addr = con->getPeerAddr();
    string ip = addr.ip();
    unsigned port = addr.port();
    _Store.erase(std::make_pair(ip, port));
    std::cout << con->toString() << " has closed!" << std::endl;
    LogInfo("[LogInfo]: client conn break");
}

} // namespace search_engine
