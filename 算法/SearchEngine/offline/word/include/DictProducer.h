#ifndef __SE_DICTPRODUCER_H__
#define __SE_DICTPRODUCER_H__

#include "DirScanner.h"
#include "WordSegmentation.h"

#include <fstream>
#include <unordered_map>
#include <set>
#include <sstream>

#define  CHSIZE 3

using std::ifstream;
using std::ofstream;
using std::unordered_map;
using std::set;
using std::istringstream;

namespace SearchEngine
{


class DictProducer
{
public:
    DictProducer();
    ~DictProducer();
    void createCnDict();
    void createEnDict();
    void store();//将词典库、索引库、id库存起来
    
private:
    void insertEnIndex(const string & elem, size_t id);
    void processLine(string & line);

    void insertIndex(const string & elem, size_t id);
    void openFile(ifstream & ifs, const string & fileName);
    void inputFile(ofstream & ofs, const string & fileName);
private:
    vector<string>                  _file;//存储文件路径
    unordered_map<string, int>      _dict;//单词与频率 （词语与频率）
    unordered_map<string, set<int>> _index;//字与包含这个字的词id号(通过字找到id，id找到词，再到词典库中找)
    unordered_map<int, string>      _idMap;//单词出现的序号 + 单词本身
    WordSegmentation                _jieba;//cppjieba分词对象
    DirScanner                      _dir;//目录扫描对象，为了获取文件路径
};

};//end of namespace SearchEngine
#endif  //__SE_DICTPRODUCER_H__
