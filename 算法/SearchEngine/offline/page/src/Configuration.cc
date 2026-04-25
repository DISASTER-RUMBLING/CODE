#include "../include/Configuration.h"

namespace SearchEngine
{
Configuration* Configuration::_pInstance = nullptr; //饱汉模式，因为是离线部分不用考虑多线程安全

Configuration *Configuration::getInstance(const char* filePath) 
{
    // 静态成员函数
    if (!_pInstance) 
    {
        _pInstance = new Configuration(string(filePath));          
    }
    return _pInstance;
}

Configuration::Configuration(const string & filePath) 
: _configFilePath(filePath) 
{
    // 初始化配置文件部分
    ifstream ifs;
    ifs.open(_configFilePath);
    if (!ifs.good()) 
    { 
        std::cerr << "open en_file_dir faile" << endl; 
        return;
    }

    string line, key, val;
    while (getline(ifs, line), !ifs.eof()) 
    {
        istringstream iss(line); 
        iss >> key;
        iss >> val;
        pair<string, string> record (key, val);
        _configs.insert(record);
    }
    ifs.close();
}

map<string, string> & Configuration::getConfigs() 
{
    return _configs;
}
} // endof namespace SearchEngine
