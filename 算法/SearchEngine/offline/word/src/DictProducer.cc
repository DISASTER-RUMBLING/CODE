#include "../include/DictProducer.h"

#include <fstream>

using std::ifstream;
using std::ofstream;

namespace SearchEngine
{

DictProducer::DictProducer()
    : _jieba()
      , _dir()
    {   
        //打开目录
        _dir("../data/CN/art");

        for(auto & fileName : _dir.files())
        {
            //将所有中文语料文件路径存储在DictProducer的vector容器中
            _file.push_back(fileName);
        }

        //创建中文词典库
        createCnDict();

        _dir.files().clear();
		_file.clear();
        _dir("../data/EN");
        for(auto & fileName : _dir.files())
        {
            //将所有英文语料文件路径存储在DictProducer的vector容器中
            _file.push_back(fileName);
        }

        //创建英文词典库
        createEnDict();

        //将词典库、索引库、id库存起来
        store();
    }

DictProducer::~DictProducer()
{

}

//创建中文词典库
void DictProducer::createCnDict()
{
    for(string & fileName : _file)
    {
        ifstream ifs;
        openFile(ifs, fileName);
        string line;
        //以空白字符为分隔符，
        //读到line中，然后进行分词处理
        while(ifs >> line)
        {
            //使用cppjieba对象进行分词
            vector<string> results = _jieba(line);
            for(string & elem : results)
            {
                //汉字组(这里就是在判断是不是中文)
                if(elem.size() % CHSIZE == 0)
                { 
                    int & isExit = _dict[elem];
                    if(isExit)
                    {
                        ++isExit;
                    }
                    else
                    {
                        isExit = 1;
                        size_t id = _dict.size();
                        //单词(或者短语)第一次出现的时候，会将对应的序号
                        //与单词(或者短语)存起来，单词的序号最大值其实也
                        //就是单词的总数
                        _idMap[id] = elem;
                        insertIndex(elem, id);
                    }
                }
            }
        }
        ifs.close();
    }
}

void DictProducer::insertIndex(const string & elem, size_t id)
{
    vector<string> results;
    _jieba.CutSmall(elem, results, 1);
    for(string & it : results)
    {
        _index[it].insert(id);
    }
}

void DictProducer::store()
{
    ofstream ofs_dict;
    inputFile(ofs_dict, "../data/dict.dat");
    for(auto it = _dict.begin(); it != _dict.end(); ++it )
    {
        ofs_dict <<  it->first << " " << it->second << endl;
    }

    ofstream ofs_index;
    inputFile(ofs_index, "../data/index.dat");
    for(auto it = _index.begin(); it != _index.end(); ++it )
    {
        ofs_index <<  it->first << " " ;
        for(auto & st : it->second )
        {
            ofs_index << st << " ";
        }
        ofs_index << endl;
    }
#if 1
    ofstream ofs_idMap;
    inputFile(ofs_idMap, "../data/idMap.dat");
    for(auto it = _idMap.begin(); it != _idMap.end(); ++it )
    {
        ofs_idMap <<  it->first << " " << it->second << endl;
    }
    ofs_idMap.close();
#endif
    ofs_dict.close();
    ofs_index.close();
}

void DictProducer::createEnDict()
{
    for(string & fileName : _file)
    {

        ifstream ifs;  
        openFile(ifs,fileName);
        string line;   
        while(getline(ifs, line))
        {                  
            processLine(line);
            istringstream iss(line);
            string word;                                         
            while(iss >> word)
            {   
                //对于英文而言，一个字符就是一个字节
                int &isExit = _dict[word];
                if(isExit)
                {
                    ++isExit;
                }
                else
                {
                    isExit = 1;
                    size_t id = _dict.size();
                    _idMap[id] = word;
                    insertEnIndex(word, id);
                }
            }    
        }    
        ifs.close();
    }
}

void DictProducer::insertEnIndex(const string & word, size_t id)
{
    for(size_t  i = 0; i < word.size(); ++i)
    {   
        //ch的初始化采用的是count个char，也就是每次都是一个char
        //也就是a b c d这种，也就是26个字母对应的索引           
        string ch(1,word[i]);
        _index[ch].insert(id);
    }           
}

void DictProducer::processLine(string & line)
{
    for(auto & elem : line)
    {
        if(!isalpha(elem))
        {
            elem = ' ';
        }
        else if(isupper(elem))
        {
            elem = tolower(elem);
        }
    }
}

void DictProducer::openFile(ifstream &ifs, const string & fileName)
{
    ifs.open(fileName);
    cout << "open >>>" << fileName << endl;
    if(!ifs)
    {
        perror("open file failed in Dict ifs");
        return;
    }
}

void DictProducer::inputFile(ofstream & ofs, const string & fileName)
{
    ofs.open(fileName);
    if(!ofs)
    {
        perror("open file failed in Dict ifs");
        return;
    }
}

}; // end of namespace SearchEngine
