#ifndef __SE_PAGE_H__
#define __SE_PAGE_H__

#include "DictProducer.h"
#include "WordSegmentation.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <map>

using std::string;
using std::vector;
using std::unordered_map;
using std::set;
using std::pair;
using std::map;

namespace SearchEngine
{

class Configuration;

struct RSSIteam 
{
    string _title;
    string _link;
    string _content;
};

class Compare
{
    bool operator()(const pair<int,double> & lhs, const pair<int, double> & rhs) 
    {
            return lhs.first < rhs.first;
    }
};

class PageLib
{
public:
    PageLib();
    ~PageLib() 
    {}
private:
    void create();
    void store();
    void handleInvertIndex();
    /* void handleWordMap(); */
    /* void handleTopK(); */
    void PageDeDuplication();
private:
    int    _DOCICNUM;//去重后的文章总数
    vector<RSSIteam> _rss;//解析rss，将其存在vector中
    Configuration *  _config;//读取配置文件获取xml文件的路径
    DictProducer     _dict;//分词对象
    WordSegmentation &_jieba;//分词对象中jieba对象的引用
    unordered_map<string, set<pair<int , double>>> _invertIndex;//倒排索引
};

} // namespace search_engine

#endif // __SE_PAGE_H__
