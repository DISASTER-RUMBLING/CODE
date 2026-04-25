#ifndef __SE_KEY_RECOMMANDER_H__
#define __SE_KEY_RECOMMANDER_H__

#include "Dictionary.h"
#include "../Reactor/TcpConnection.h"

#include <string>
#include <queue>
#include <memory>

using std::string;
using std::priority_queue;
using std::shared_ptr;

namespace SearchEngine 
{
 
class KeyRecommander
{
	using TcpConnectionPtr  = shared_ptr<TcpConnection>;
    friend class CalculateTask;

	typedef struct CandidateResult 
	{
		string _word;//单词
		int    _freq;//词频
		int    _dist;//最小编辑距离
	} Res;//候选结果

	struct myCompare
	{
		bool operator()(const Res& lhs, const Res& rhs) const;
	};

public:
    KeyRecommander() 
    : _pdict(Dictionary::getInstance()) 
	{ }
    
    void setKrValue(const string& sought, TcpConnectionPtr conn)
	{
		_sought = sought;
		_conn = conn;
    }

    vector<string> doQuery();

private:
    void insertPrique(std::pair<string,int> &elem ,Res &myResult);
    void initFinalResult(vector<string> &finalResult);
    void eraseFinalResult(vector<string> &finalResult);
private:	
    string _sought;//待查询的单词
    priority_queue<Res, vector<Res>, myCompare> _prique;//优先级队列
    TcpConnectionPtr _conn;//Tcp连接的对象，智能指针的对象，可以不用加引用
    Dictionary *_pdict;
};

} // namespace search_engine

#endif // __SE_KEY_RECOMMANDER_H__
