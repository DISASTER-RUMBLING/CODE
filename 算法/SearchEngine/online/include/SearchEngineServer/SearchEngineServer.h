#ifndef __SE_SEARCH_ENGINE_SERVER_H__
#define __SE_SEARCH_ENGINE_SERVER_H__

#include "CalculateTask.h"
#include "../Reactor/TcpServer.h"
#include "../Reactor/ThreadPool.h"
#include "../KeyRecommander/KeyRecommander.h"
#include "../WebPageSearcher/WebPageSearcher.h"
#include <iostream>

namespace std
{
template <>
struct hash<pair<string, unsigned short>>
{
    size_t operator()(const pair<string, unsigned short> &rhs) const 
    {
        return  rhs.second * rhs.second;
    }
};

};//end of namespace std

namespace SearchEngine 
{

using MYMAP = unordered_map<std::pair<string, unsigned short>, std::pair<int, vector<string>>>;

class SearchEngineServer 
{
public:
    SearchEngineServer(size_t threadNum, size_t queSize,
                       const string& ip, unsigned short port);

    void start();
    void stop();

    void onMessage(const TcpConnectionPtr& con);
    void onConnection(const TcpConnectionPtr& con);
    void onClose(const TcpConnectionPtr& con);


public:
    ThreadPool        _threadPool;//线程池对象
    TcpServer         _tcpServer;//TcpServer对象
    KeyRecommander    _keyRecommander;//关键字推荐对象
    WebPageSearcher   _webPageSearcher;//网页搜索对象 
    MYMAP             _Store;
};

} // namespace search_engine

#endif // __SE_SEARCH_ENGINE_SERVER_H__
