#ifndef __SE_WEBPAGE_H__
#define __SE_WEBPAGE_H__


#include "cppjieba/Simhasher.hpp"
#include <string>
#include <vector>
#include <map>
#include <set>

using std::set;
using std::map;
using std::vector;
using std::string;

namespace SearchEngine
{

class Configuration;
class WordSegmentation;

class webPage
{
public:
    webPage();
    webPage(string &doc, WordSegmentation *jieba, simhash::Simhasher *sim);
    ~webPage();

    int getDocid();
    string getTile();
    string getUrl();
    string summary(const vector<string> &quertWord);
    map<string, int> &getWordsMap();

private:
	//该函数中有KMP算法的使用，可以研究一下KMP算法的使用
    void processDoc(const string & doc); 
    void calaTopK(vector<string> & wordsVec, int k); 

private:
    const static int TOP_NUM = 20;
    int     _docid;//文章id
    string  _docTitle;//标题
    string  _docUrl;//链接
    string  _docContent;//内容
    string  _docSummary;//摘要
    vector<string>  _topWords;//热词
    map<string, int>     _wordsMap;
    WordSegmentation  *_jieba;//结巴指针
    simhash::Simhasher *_sim;//simhash指针

};

};// end of namespace search_engine
#endif // end of __SE_WEBPAGE_H__

