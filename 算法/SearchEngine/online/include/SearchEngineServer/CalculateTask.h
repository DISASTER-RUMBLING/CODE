#ifndef __SE_TASK_H__
#define __SE_TASK_H__

#include "../Reactor/TcpConnection.h"
#include "../KeyRecommander/KeyRecommander.h"
#include "../WebPageSearcher/WebPageSearcher.h"

namespace SearchEngine 
{

using MYMAP = unordered_map<std::pair<string, unsigned short>, 
                            std::pair<int, vector<string>>>;

class CalculateTask 
{
public:
    CalculateTask(const string& msg, 
                  const TcpConnectionPtr& con,
                  KeyRecommander& key,
                  WebPageSearcher& web,
                  MYMAP& store)
    : _msg(msg)
    , _con(con)
    , _key(key)
    , _web(web)
    , _Store(store) 
    { }

    void wordSearcher();
    void pageSearcher();
    void nextPageSearcher();
    void process();

private:
    string _msg;//从客户端返回的数据，也就是要查询的数据
    TcpConnectionPtr _con;//Tcp连接的对象
    KeyRecommander &_key;//关键字对象的引用
    WebPageSearcher &_web;//网页搜索对象的引用
    MYMAP &_Store;
};

} // namespace search_engine

#endif // __SE_TASK_H__
