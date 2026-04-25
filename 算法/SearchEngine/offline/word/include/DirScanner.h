#ifndef __SE_DIRSCANNER_H__
#define __SE_DIRSCANNER_H__

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace SearchEngine 
{

class DirScanner
{
public:
    DirScanner();
    ~DirScanner();
    void operator()(const string& dirname);
    vector<string>& files();
    void traverse(const string& dirname);
private:
    vector<string> _files;//存储文件路径
};

} // namespace SearchEngine

#endif // __SE_DIRSCANNER_H__
