#include "../../include/Configuration.h"
#include "../../include/KeyRecommander/Dictionary.h"
#include "../../include/WebPageSearcher/WebPageQuery.h"
#include "../../include/SearchEngineServer/SearchEngineServer.h"
#include "../../include/LRUCache/CacheManager.h"
#include "../../include/TimerManager/TimerFd.h"

#include <thread>

using std::string;
using std::thread;

using namespace SearchEngine;

int main(int argc, char *argv[]) 
{

	//获取在线模块下conf/server.conf配置文件中的内容，包括：ip、port、子线程数目
	//任务队列大小 等等 
    map<string, string> configs = Configuration::getInstance()->getConfigs();

    int threadNum = stoi(configs["threadNum"]);
    int queSize   = stoi(configs["queSize"]);
    string ip     = configs["ip"];
    size_t port   = stoi(configs["port"]);

	//将关键字推荐部分的三个文件中的内容加载到内存中，
	//并用数据结构将其存起来，三个文件分别是：
	//词典库、索引库、身份库（idMap）
    Dictionary::getInstance();
	//将网页搜索部分对应的三个文件加载到内存中，
	//用数据结构将其存起来,三个文件分别是：
	//网页库、网页偏移库、倒排索引库
    WebPageQuery::getWebQueryPtr();

    cout << "loading server ..." << endl;

	//预设条件，目的就是为了将缓存管理类CacheManager中的数据成员进行初始化
    CacheManager *p = CacheManager::getInstance();

	//定时器类定时执行更新函数updateCache与updateCache2，更新缓存
	//两份代码逻辑是一样的，就是为了在真正查询前，将缓存跑起来
    TimerFd tf1(2, 3, std::bind(&CacheManager::updateCache, p));
    thread th1(&TimerFd::start, &tf1);

    TimerFd tf2(3, 5, std::bind(&CacheManager::updateCache2, p));
    thread th2(&TimerFd::start, &tf2);

	//真正运行服务器的代码，进行真正的查询操作
    SearchEngineServer seServer(threadNum, queSize, ip, port);
    seServer.start();
    return 0;
}
