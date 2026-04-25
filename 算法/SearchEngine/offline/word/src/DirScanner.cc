#include "../include/DirScanner.h"

#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <iostream>
#include <string>

using std::cout;
using std::endl;

namespace SearchEngine 
{

DirScanner::DirScanner() 
{
}

DirScanner::~DirScanner() 
{
}

void DirScanner::operator()(const string& dirname) 
{
	//遍历目录
    traverse(dirname);    
}

vector<string> &DirScanner::files() 
{
    return _files;
}

void DirScanner::traverse(const string& dirname) 
{
    DIR* dir;
    struct dirent* direntptr;
    dir = opendir(dirname.c_str());
    if (!dir) 
    {
        cout << "this " << dirname.c_str() << " is NULL" << endl;
        return;
    } 
    while ((direntptr = readdir(dir)) != NULL) 
    {
        //把当前目录和上一级目录都去掉，避免死循环
        if(strncmp(direntptr->d_name, ".", 1) != 0 
           &&strncmp(direntptr->d_name, "..", 2) != 0)
        {
			//将所有的文件路径与文件名存储在vector中
            _files.push_back(dirname+ "/" + direntptr->d_name);
        }
    }
    closedir(dir);
}

} // namespace SearchEngine
