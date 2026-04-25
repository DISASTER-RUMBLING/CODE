#ifndef __CONFIGURATION_H__
#define __CONFIGURATION_H__


#include <string>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>

using std::string;
using std::map;
using std::set;
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::pair;
using std::cerr;

namespace SearchEngine
{
// 单例模式
class Configuration 
{
public:
    static Configuration* getInstance(const char* filePath); 
    map<string, string> & getConfigs();     // 获取存放配置文件内容的map 
private:
    explicit Configuration(const string& filePath); // 构造函数私有化
    ~Configuration();

private:
    Configuration(const Configuration &) = delete;
    Configuration& operator=(const Configuration &) = delete;

    static Configuration *_pInstance;
    string _configFilePath;       // 配置文件路径
    map<string, string> _configs;   // 配置文件内容
};


} // namespace SearchEngine

#endif // __CONFIGURATION_H__


