#ifndef __SE_WEB_PAGE_QUERY_H__
#define __SE_WEB_PAGE_QUERY_H__

#include "cppjieba/Simhasher.hpp"
#include "WordSegmentation.h"
#include "WebPage.h"

#include <unordered_map>
#include <set>
#include <vector>
#include <string>
#include <utility>

using std::string;
using std::vector;
using std::set;
using std::unordered_map;
using std::pair;

namespace SearchEngine
{

class WebPageQuery
{
public:
    static WebPageQuery *getWebQueryPtr()
	{
        if(_pQuery == nullptr) 
		{
            _pQuery = new WebPageQuery();
            atexit(destroy);
        }
        return _pQuery;
    }

    static void destroy() 
	{
        if(_pQuery)
		{
            delete _pQuery;
			_pQuery = nullptr;

        }
    }
    vector<string> doQuery(const string & str);
private:
    WebPageQuery();
    ~WebPageQuery();
private:
    void loadLibary();
    vector<double> getQueryWordsWeightVector(vector<string> & queryWords);
    bool executeQuery(const vector<string> &queryWords,
                      unordered_map<int, vector<double>> & resultVec);
    vector<string> create_Json(vector<int> &docidVec, 
							   const vector<string> &queryWords);
    string returnNoAnswer();

    static bool ComPair(const std::pair<int, double> & lhs, 
						const std::pair<int, double> & rhs) 
	{
        return lhs.second > rhs.second;
    }
private:
    static WebPageQuery *_pQuery;
    WordSegmentation _jieba;//结巴对象进行分词
    simhash::Simhasher  _sim;//simhash对象进行去重
	//因为我们没有学数据库，如果学了，这些数据是可以在离线部分存放在数据库中，
	//这样我们在在线部分直接读数据库中的内容即可（此处需要注意，数据量如果很大，
	//我们是不能一次性加载到内存中的）
	//存放离线部分生成的网页库
    unordered_map<int, webPage> _pageLib;
	//存放离线部分生成的偏移库
    unordered_map<int, pair<int, int>> _offsetLib;
	//存放离线部分生成的倒排索引库
    unordered_map<string, set<std::pair<int, double>>> _inverIndexTable;
};

};//end of namespace search_engine

#endif  //end of __SE_WEB_PAGE_QUERY_H__
