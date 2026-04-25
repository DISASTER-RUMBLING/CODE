#include "../../include/LRUCache/CacheManager.h"

namespace SearchEngine 
{

CacheManager*  CacheManager::_pInstance = nullptr;

CacheManager* CacheManager::getInstance() 
{
    if(!_pInstance) 
    {
       _pInstance = new CacheManager();
    }
    return _pInstance;
}

CacheManager::CacheManager() 
{
	//初始化函数中填了文件名字，但是文件名字确没有起作用，
	//因为根本就没有用到文件名
	//这里可以增加优化，读取文件中的缓存信息，也可以将缓存
	//信息写入文件中，做一个持久化的处理
    init("data/cache.dat");
}

void CacheManager::init(const string& filename) 
{
	//缓存大小预设为7
    _caches.reserve(7);
    _caches2.reserve(7);

    for(int i = 0; i < 7; i++) 
    {
		//关键字部分的候选词为5个
        _caches.emplace_back(LRUCache(5));
		//网页搜索部分的候选文章为3个
        _caches2.emplace_back(LRUCache(3));
    }
	//这里使用的是自己实现的缓存，如果学过Redis，可以
	//使用Redis作为缓存
}
    
void CacheManager::updateCache()
{
     printf("\e[0;35m" 
            "wordCache thread[0] got a task[update cache]\n" 
            "\e[0m");

     //把所有子cache的pendinglist的node依次插入主cache中
     //然后情况pendingList
     int cnt = 0;

	 //一共七个，1-6是次缓存
     for(int i = 1; i < 7; ++i) 
     {
		 //如果次缓存的待更新节点为空，就将cnt++
         if (!_caches[i]._pendingUpdateList.size()) 
         {
             ++cnt;
             continue;
         }
		 //_cache[0]是主缓存，将每个次缓存的待更新链表中的数据都合并到主缓存
		 //的待更新链表中
		 _caches[0].mergePending(_caches[i]);
		 //将次缓存的待更新链表清空，防止数据的滞留（不影响下一次的待更新数据）
		 //比如第一次待更新链表为有数据A，如果没有清空，第二次待更新链表中会
		 //残留A，但是这个A是不需要的，所以需要清空，因为每一次待更新的数据
		 //是不一样的
		 _caches[i]._pendingUpdateList.clear();
     }
	 //这样循环结束后，主缓存中的数据就是最全的，所有的数据都在主缓存中
     
     if (6 == cnt) 
     {
        printf("\e[0;35m" 
               "wordCache thread[0] got a task[update cache]\n" 
               "\e[0m");
         return;
     }

	 //将主缓存中的数据同步更新到每个次缓存中，目的是保证每个缓存中的数据是
	 //一致的，这样的好处是，客户端发送数据来了后，使用任何一个缓存进行查询
	 //的效果就是一样的，不然0号线程只有0号缓存中的数据，1号线程只有1号缓存
	 //中的数据，那么0号线程查询1号缓存中的数据，那就查不到
     for(int i = 1; i < 7; ++i)
     {
         _caches[i].update(_caches[0]);
     }
     printf("\e[0;35m" 
            "wordCache thread[0] finished a task[update cache success]\n" 
            "\e[0m");
}

//这个updateCache2的作用与updateCache是完全一样的
void CacheManager::updateCache2() 
{
     printf("\e[0;35m" 
            "wordCache thread[0] finished a task[update cache success]\n" 
            "\e[0m");

     //把所有子cache的pendinglist的node依次插入主cache中
     //然后情况pendingList
	 int cnt = 0;
     for(int i = 1; i < 7; ++i) 
     {
         if (!_caches2[i]._pendingUpdateList.size()) 
         {
             ++cnt;
             continue;
         }
		 _caches2[0].mergePending(_caches2[i]);
		 _caches2[i]._pendingUpdateList.clear();
     }

     if (6 == cnt) 
     {
         printf("\e[0;35m" 
                "wordCache thread[0] finished a task[update cache success]\n" 
                "\e[0m");
         return;
     }

     for(int i = 1; i < 7; ++i) {
         _caches2[i].update(_caches2[0]);
     }
     printf("\e[0;35m" 
             "wordCache thread[0] finished a task[update cache success]\n" 
             "\e[0m");
}

LRUCache& CacheManager::getCache(string name) 
{
	//#include <string>
	//int stoi(const std::string& str,  std::size_t* pos = 0, int base = 10);
	//函数作用：将字符串str转成int整数
    int idx = stoi(name);
    return _caches[idx];
}
    
LRUCache& CacheManager::getCache2(string name) 
{
    int idx = stoi(name);
    return _caches2[idx];
}

}// namespace search_engine

