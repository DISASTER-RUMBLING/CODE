#include "../include/Pagelib.h"
#include "../include/tinyxml2.h"
#include "../include/DirScanner.h"
#include "../include/Configuration.h"
#include <simhash/Simhasher.hpp>

#include <math.h>
#include <fstream>
#include <regex>
#include <iostream>
#include <fstream>
#include <map>

using std::cout;
using std::endl;
using std::ofstream;
using std::map;
using namespace tinyxml2;

namespace SearchEngine 
{

PageLib::PageLib() 
: _config(Configuration::getInstance("../conf/page.conf"))
, _jieba(_dict.getJieba())
{
	//create函数的作用就是在进行rss解析，将处理好之后的结果都存放在vector中
    create();
    cout << "网页库信息采集成功！服务器加油中！！！" << endl;
    PageDeDuplication(); //网页去重
    cout << "网页去重已完成！" << endl;
    handleInvertIndex();       //建立倒排索引
    cout << "倒排索引建立成功！距离胜利不远了！" << endl;
    store();  //持久化网页库、偏移库、倒排索引表 << endl;
    cout << "任务结束，此次创建网页信息完成！！！" << endl;
}

void PageLib::create() 
{
	//创建目录扫描的对象，该类重载了函数调用运算符
    DirScanner dir;

	//通过键值对获取存储的xml文件的路径（data/xml）
	//此处getConfigs函数的返回类型是一个map
    dir(_config->getConfigs().find("XMLDIR")->second);
	//解析xml文件，也就是作业rss解析
    for (string & filename : dir.files())
    {
        XMLDocument doc;
        doc.LoadFile(filename.c_str());
        if (doc.ErrorID()) 
        {
            perror("loadFile fail");
            return;
        }
        XMLElement *itemNode = 
            doc.FirstChildElement("rss")->FirstChildElement("channel")->FirstChildElement("item");
        while(itemNode) 
        {
            RSSIteam rssItem;
            std::regex reg("<[^>]+>");//通用正则表达式

			//每次都在判断，防止标题、链接、描述信息为空（可以将内容也解析一下）
            if(itemNode->FirstChildElement("title")) 
            {
                string title = itemNode->FirstChildElement("title")->GetText();
                title = regex_replace(title, reg, "");
                rssItem._title = title;
            }
            else 
            {
                rssItem._title = "这篇文档没有标题Qaq";
            }

            if(itemNode->FirstChildElement("link"))
            {
                string link =  itemNode->FirstChildElement("link")->GetText();
                rssItem._link = link;
            }
            else
            {
                rssItem._link = "这篇文档没有链接";
            }


            //读取的文档如果有content，则保留content，不保留description
            //读取的文档如果没有content，则保留description
            if(itemNode->FirstChildElement("content"))
            {
                string content = itemNode->FirstChildElement("content")->GetText();
                content = regex_replace(content, reg, "");
                rssItem._content = content;
            }
            else 
            {
                if(itemNode->FirstChildElement("description"))
                {
                    string content = itemNode->FirstChildElement("description")->GetText();
                    content = regex_replace(content, reg, "");
                    rssItem._content = content;
                }
                else
                {
                    rssItem._content = "这篇文档没有内容";
                }
            }

			//将网页信息存储在vector容器中，一篇篇的进行存储
            _rss.push_back(rssItem);
            itemNode = itemNode->NextSiblingElement("item");
        }
    }
}



void PageLib::PageDeDuplication() 
{
    size_t topN = 20;

	//初始化simhash对象，使用simhash进行去重
    simhash::Simhasher simhasher(DICT_PATH, HMM_PATH, IDF_PATH, STOP_WORD_PATH);
    vector<pair<int, uint64_t>> Sim;

	//调试信息，可以查看去重前的文章数目
	cout << "去重前的文章数目 = " << _rss.size() << endl;

    for(size_t i = 0; i < _rss.size(); ++i)
    {
        uint64_t u = 0;
		//make函数的作用：根据前topN个权重计算降维后的Simhash值
		//计算后的Simhash值为u，将其存放在vector中
        simhasher.make(_rss[i]._content, topN, u);
        Sim.push_back(std::make_pair(i, u));
    }

	//将文章的Simhash值进行两两比较（使用海明距离比较），然后将描述信息
	//短的文件id存放在set中，这样后面遍历Sim的时候，将存在set中的文章
	//id删除，这样就达到了去重的目的
    set<int> tmp;
    for(size_t it = 0; it < Sim.size(); ++it) 
    {
        int id1 = Sim[it].first;
        int sz1 = _rss[id1]._content.size();
        for(size_t it2 = (it + 1); it2 < Sim.size(); ++it2)
        {
			//isEqual函数的作用:改写第三方库中的海明距离函数，返回距离
            if(simhash::Simhasher::isEqual(Sim[it].second, Sim[it2].second))
            {
                int sz2 = _rss[Sim[it2].first]._content.size();
                if(sz1 >= sz2 ) 
                {
                    tmp.insert(Sim[it2].first);
                }
                else
                {
                    tmp.insert(id1);
                    break;
                }
            }
        }
    }
    int s = 0;
    for(auto num : tmp) 
    {
        num -= 0;
        int i = 0;
        for(auto it = _rss.begin(); it != _rss.end(); ++it, ++i)
        {
            if(num == i)
            {
                _rss.erase(it);//从_rss中删除重复的文章
                ++s;//可以直接删除，s没有作用
                break;
            }
        }
    } 
    _DOCICNUM = _rss.size();

	//调试信息，可以查看去重后的文章数目
	cout << "去重后的文章数目 = " << _rss.size() << endl;
}


//重要：保存倒排索引库的信息
void PageLib::handleInvertIndex()
{
    unordered_map<string, unordered_map<int, double>> tf; 
    int i = 0;
	//遍历去重后的文章,然后将描述信息分词，然后将单词，文章id与词频
	//存起来在tf中
    for(auto it = _rss.begin(); it != _rss.end(); ++it)
    {
		//为了让docid从1开始
        int docid = ++i;
        string doc = it->_content;
        vector<string> results = _jieba(doc);
        for(string & word : results) 
        {
            auto & isExit = tf[word];
            ++isExit[docid];
        }
    }


	//计算单词在每篇文章中的权重，然后将其存放在倒排索引表中
	//计算权重使用了TF-IDF算法
    //
    //存放{{文章id 文章中所有词的原始权重的平方和}, ...}
    //1  w1^2 + w2^2...;  
    unordered_map<int, double> docW;  
                                      
    //假设
    //hello在第一篇文章出现3次，在第二篇文章出现10次，在第三篇文章出现7次
    // hello (1, 3)  (2, 10) (3, 7)
    for(auto it = tf.begin(); it != tf.end(); ++it)
    {
        string word = it->first;       //hello
        size_t DF = it->second.size(); //包含这个单词的文章个数  3
		//遍历单词对应的文章id与词频的数据结构unordered_map
        for(auto num = it->second.begin(); num != it->second.end(); ++num)
        {
            int docid = num->first;
            int TF = num->second;
            double IDF = log(1.0 * _DOCICNUM /(DF + 1))/log(2);
            double w = TF * IDF;

            //tf中本来记录的是{单词 {[文章id 单词出现次数] [文章id 单词出现次数]...}}
            //改变为{单词 {[文章id 原始权重] [文章id 原始权重]...}}
            num->second = w;
            docW[docid] += w * w;  
        }
    }

    //目前
    //tf中存放了 hello (1, w)  (2, w) (3, w)
    //docW中包含了一条记录 1  ALLW
    for(auto it = tf.begin(); it != tf.end(); ++ it) 
    {
        string word = it->first;
        for(auto elem = it->second.begin(); elem != it->second.end(); ++elem) 
        {
            int docid = elem->first;
            double sumW2 = docW[docid];
            double w = elem->second;

            //得到归一化权重
            double FinW = w / sqrt(sumW2);

			//将单词，文章id，权重存放在本类的数据成员
            //也就是倒排索引对应的数据结构中
            _invertIndex[word].insert(std::make_pair(docid, FinW));
        }
    }
}

void PageLib::store() 
{
    /* _dict.store(); */
    ofstream ofs("../data/ripepage.dat"); //网页库
    if(!ofs)
    { 
        perror("ofs fail");
        return;
    }
    ofstream ofs1("../data/offset.dat"); //网页偏移库
    if(!ofs1) 
    { 
        perror("ofs fail");
        return;
    }
    for(size_t i = 0; i != _rss.size(); ++i)
    {
        size_t idx = i + 1;
        ofs1 << idx << " ";//文章id
        size_t  beginpos = ofs.tellp();
        ofs1 << beginpos << " ";//文章的起始位置
        ofs << "<doc>"<<endl;
        ofs << "\t<docid>" << i + 1 << "</docid>" <<endl;
        ofs << "\t<title>" << _rss[i]._title << "</title>" <<endl;
        ofs << "\t<url>" << _rss[i]._link << "</url>" <<endl;
        ofs << "\t<content>" << _rss[i]._content << "</content>" <<endl;
        ofs << "</doc>" <<endl;
        size_t endpos = ofs.tellp();//文章的终止位置
        size_t len = endpos - beginpos;//文章的长度（包含有<doc><docid><title>这些）
        ofs1 << len << "\n";
    }
    cout << "网页库和网页偏移库持久化完成" << endl;

    ofstream ofs2;
    ofs2.open("../data/invertIndex.dat");
	//遍历倒排索引表，将其存放在文件中
    for(auto & it : _invertIndex)
    {
        ofs2 << it.first << " ";
        for(auto it2 = it.second.begin(); it2 != it.second.end(); ++it2) 
        {
            ofs2 << it2->first << " " << it2->second << " " ;
        }
        ofs2 << endl;
    }
    cout << "倒排索引库持久化完成" << endl;
    ofs.close();
    ofs1.close();
    ofs2.close();
}

} // namespace SearchEngine



