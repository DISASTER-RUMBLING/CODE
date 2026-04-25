#include "../../include/LRUCache/LRUCache.h"

namespace SearchEngine 
{

int LRUCache::get(string key, vector<string>& value) 
{
    auto it = _cache.find(key);
    if(it == _cache.end()) 
	{
        return -1;
    } 
    else
    {
        _nodes.splice(_nodes.begin(), _nodes, it->second);
        value = it->second->value;
        return 0;
    }
}

void LRUCache::put(string key, vector<string> value) 
{
	auto it = _cache.find(key);
	if (it != _cache.end()) 
	{
		_nodes.splice(_nodes.begin(), _nodes, it->second);
		it->second->value = value;
		return;
	}

	_nodes.emplace_front(CacheNode(key, value));
	_cache[key] = _nodes.begin();
	if (_cache.size() > _capacity)
	{
		_cache.erase(_nodes.back().key);
		_nodes.pop_back();
	}
}

//将key与满足key的候选词val添加到待更新的链表中，也就是放在list尾部
void LRUCache::addRecord(string key, vector<string> val)
{
    CacheNode tmp(key, val);
    _pendingUpdateList.push_back(tmp);
}

//mergePending与update的效果其实没有什么区别，只是使用函数的
//对象不一样
//
//合并，使用LRU算法，将lrucache._pendingUpdateList中的内容
//更新合并到list<CacheNode>中
void LRUCache::mergePending(const LRUCache& lrucache) 
{
    for(auto& it : lrucache._pendingUpdateList) 
	{
          put(it.key, it.value);
    }
}

//更新，使用LRU算法，将lrucache._cache中的内容
//更新合并到list<CacheNode>中
void LRUCache::update(const LRUCache& lrucache) 
{
    for(auto& it : lrucache._cache) 
	{
        string key = it.first;
        vector<string> val = it.second->value;
        put(key, val);
    }
}

} // namespace search_engine
