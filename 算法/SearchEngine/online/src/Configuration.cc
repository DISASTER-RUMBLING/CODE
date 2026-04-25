#include "../include/Configuration.h"

namespace SearchEngine {

Configuration* Configuration::_pInstance = nullptr; 

/* string Configuration::_config_file_path = "conf/server.conf";       // 配置文件路径 */

// 静态成员函数
Configuration* Configuration::getInstance() 
{
    if (!_pInstance) 
    {
        _pInstance = new Configuration("conf/server.conf");          
    }
    return _pInstance;
}

Configuration::Configuration(const string &filePath)
{
    // 初始化配置文件部分
    /* ifstream ifs; */
    /* ifs.open(file_path); */
    ifstream ifs(filePath);
    if (!ifs.good()) 
	{ 
		std::cerr << "open server.conf fail" << endl;
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

map<string, string>& Configuration::getConfigs() 
{
    return _configs;
}

} // namespace search_engine
