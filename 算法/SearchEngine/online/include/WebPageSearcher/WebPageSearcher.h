#ifndef __SE_WEB_PAGE_SEARCHER_H__
#define __SE_WEB_PAGE_SEARCHER_H__

#include "WebPageQuery.h"
#include "../Reactor/TcpConnection.h"

namespace SearchEngine
{
using TcpConnectionPtr = shared_ptr<TcpConnection>;

class WebPageSearcher
{
    friend class CalculateTask;
public:    
    WebPageSearcher(string keys);
    WebPageSearcher();
    vector<string> doQuery();

    void setMVal(string sought, TcpConnectionPtr con);

private:
    string _sought; //查询关键字
    WebPageQuery *   _pQuery;//网页查询类的指针
    TcpConnectionPtr   _conn;//Tcp连接的对象，是个智能指针，所以没有将数据成员写为引用
};

} // namespace search_engine

#endif // __SE_WEB_PAGE_SEARCHER_H__
