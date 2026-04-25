#include "../../include/KeyRecommander/KeyRecommander.h"
#include <string.h>

namespace SearchEngine
{

vector<string> KeyRecommander::doQuery() 
{
	//candit存储查询之后获取的结果
    vector<std::pair<string, int>> candit = _pdict->doQuery(_sought);
    vector<string> finalResult;

    if (!candit.size()) 
	{
		return vector<string>();
	}

    Res myResult;
    for (auto& elem : candit) 
	{
        if(3 == _pdict->nBytesCode(elem.first[0]))//是中文词组
		{	
			//将结果插入到优先级队列中（注意比较方式：编辑距离、词频、字母序）	
            insertPrique(elem, myResult);
        }
    }
	//最终的结果存放在了finalResult中，只有五个候选词
	//然后将优先级队列清空
    initFinalResult(finalResult);

	//后面的英文也做同样的操作，将优先级最高的五个存起来
	//放在finalResult中
    for (auto& elem : candit)
	{
        if(1 == _pdict->nBytesCode(elem.first[0])) //是英文词组
		{ 
            insertPrique(elem, myResult);
        }
    }
    initFinalResult(finalResult);
    eraseFinalResult(finalResult);

    return finalResult;
}

void KeyRecommander::insertPrique(std::pair<string,int> &elem ,Res &myResult)
{
    bzero(&myResult, sizeof(myResult));
    myResult._dist = _pdict->editDistance(_sought, elem.first);//获取编辑距离
    myResult._freq = elem.second;
    myResult._word = elem.first;
	//插入到优先级队列中
    _prique.push(myResult);
}

void KeyRecommander::initFinalResult(vector<string> & finalResult) 
{
    int i = 0;
    while (!_prique.empty() && i++ < 5)
	{
		//只要_prique（也就是优先级队列不为空），将优先级
		//最高的五个候选词放在vector中存起来
        finalResult.emplace_back(_prique.top()._word);
        _prique.pop();
    }

	//清空_prique（也就是优先级队列）
    while (_prique.size())
	{
        _prique.pop();
    }
}

void KeyRecommander::eraseFinalResult(vector<string> & finalResult)
{
    size_t resultSize= finalResult.size();
    if(resultSize > 5) 
	{
        auto it = finalResult.begin();
        finalResult.erase(it + 3, it + 5);
        finalResult.erase(it + 6, it + 8);
    }
}

bool KeyRecommander::myCompare::operator()(const CandidateResult & lhs
										   , const CandidateResult & rhs) const 
{
	//首先按照最小编辑距离进行比较,最小编辑距离越小，说明越接近查询的结果
    if(lhs._dist > rhs._dist) //距离更小的优先级高
	{
        return true;
    }
    else if (lhs._dist == rhs._dist && lhs._freq < rhs._freq) //频率高的优先级高
	{
        return true;
    }
    else if (lhs._dist == rhs._dist && lhs._freq == rhs._freq) 
	{
		//英文字母顺序更小的优先级高
		if(strcmp(lhs._word.c_str(), rhs._word.c_str()) > 0) 
		{ 
            return true;
        }else { 
			return false; 
		}
    }
    else 
	{ 
		return false; 
	}
}

} // namespace search_engine
