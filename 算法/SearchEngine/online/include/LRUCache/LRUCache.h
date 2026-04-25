#ifndef __SE_LRUCACHE_H__
#define __SE_LRUCACHE_H__

#include <string>
#include <vector>
#include <list>
#include <unordered_map>

using std::string;
using std::list;
using std::unordered_map;
using std::vector;

namespace SearchEngine 
{

class LRUCache 
{
    friend class CacheManager;
public:
    LRUCache(int capacity)
    : _capacity(capacity) 
    { 
    }

    int  get(string key, vector<string>& val);
    void put(string key, vector<string> value);

    void addRecord(string key, vector<string> val);
    void mergePending(const LRUCache& lrucache);

    void update(const LRUCache& lrucache);

private:
    struct CacheNode 
    {
        CacheNode(string k, vector<string> v)
        : key(k)
        , value(v) 
        { 
        }

		//例如：key为武汉  那么value就是满足value的所有值
        string key;//待查询的值
        vector<string> value; //符号条件的值，存放在容器中
    }; 

private:
	//就是容量，其实可以设置为size_t  _capacity
    unordered_map<string, list<CacheNode>>::size_type _capacity;
	//节点，用于存放元素
    list<CacheNode> _nodes;
	//存放元素以及元素在节点中的迭代器的键值对
    unordered_map<string, list<CacheNode>::iterator> _cache;
	//待更新节点
    list<CacheNode> _pendingUpdateList;
};

} // namespace search_engine

#endif // __SE_LRUCACHE_H__
