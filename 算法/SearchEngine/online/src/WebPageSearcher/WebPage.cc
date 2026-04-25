#include "../../include/WebPageSearcher/WebPage.h"
#include "../../include/WebPageSearcher/KMP.h"
#include "../../include/WebPageSearcher/WordSegmentation.h"

#include <string>

namespace SearchEngine
{

webPage::webPage()
: _jieba()
, _sim()
{}

webPage::webPage(string &doc, WordSegmentation *jieba, simhash::Simhasher *sim) 
: _jieba(jieba)
, _sim(sim)
{
    processDoc(doc);
}

webPage::~webPage() 
{}

int webPage::getDocid() 
{
    return _docid;
}

string webPage::getTile() 
{
    if(_docTitle.size()) 
	{
        return _docTitle;
    }
    else
	{
        return nullptr;
    }
}

string webPage::getUrl() 
{
    if(_docUrl.size()) 
	{
        return _docUrl;
    }
    else
	{
        return nullptr;
    }
}

string webPage::summary(const vector<string> & queryWord)
{
	//这个函数有问题，查找queryWord中的word也好，通过word
	//找到的num也好，都没有起到作用，最终只是将_docContent
	//中的第一句展示出来了。说白了，这个摘要有待优化
	//可以根据待查找词，分成之后的词 前后各找10各字组合在一起
	//形成摘要 这样更合理(这部分有待进一步优化)
    KMP kmp;
    set<int> Pos;
    for(auto word : queryWord)
	{
        Pos.insert(_docContent.find(word));
    }
    vector<int> Post;
    for(auto num : Pos) 
	{
        Post.push_back(num);
    }

    int pos = kmp(_docContent, "。");
    
    return _docContent.substr(0, pos);
}

//本函数使用KMP算法，从字符串中寻找子串，然后获取对应的
//信息，比如：文章id、标题、链接等
void webPage::processDoc(const string &doc) 
{
    KMP kmp;
    string doc1 = "<docid>";
    string doc2 = "</docid>";
    int dm1 = kmp(doc, doc1) + doc1.size();
    int dm2 = kmp(doc, doc2);  
    _docid = atoi(doc.substr(dm1, dm2 - dm1).c_str());
    
    string t1 = "<title>";
    string t2 = "</title>";
    int tm1 = kmp(doc, t1) + t1.size();
    int tm2 = kmp(doc, t2);
    _docTitle = doc.substr(tm1, tm2 - tm1);
    
    string u1 = "<url>";
    string u2 = "</url>";
    int um1 = kmp(doc, u1) + u1.size();
    int um2 = kmp(doc, u2);
    _docUrl = doc.substr(um1, um2 - um1);

    string d1 = "<description>";
    string d2 = "</description>";
    int dem1 = kmp(doc, d1) + d1.size();
    int dem2 = kmp(doc, d2);
    _docContent = doc.substr(dem1, dem2 - dem1);
}

map<string, int> &webPage::getWordsMap()
{
    string str = _docContent;
    vector<string> results = _jieba->operator()(str);

    for(string & word : results)
    {
        int & isExit = _wordsMap[word];
        if (isExit)
        {
            ++isExit;
        } 
        else 
        {
            isExit = 1;
        }
    }
    return _wordsMap;
}

void webPage::calaTopK(vector<string> & wordsVec, int k)
{ 
    vector<std::pair<string, double>> res;
    _sim->extract(_docContent, res, k);

    for(auto & it : res) 
    {
        wordsVec.push_back(it.first);
    }
}

};//end of namespace search_engine
