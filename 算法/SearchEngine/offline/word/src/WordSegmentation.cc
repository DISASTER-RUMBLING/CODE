#include "../include/WordSegmentation.h"

vector<string> SearchEngine::WordSegmentation::operator()(const string str)
{
    vector<string> words;
    _jieba.CutAll(str, words); //FullSegment
    return words;
}

void SearchEngine::WordSegmentation::CutSmall(const string & str, vector<string> & vec, size_t sz)
{
	//细粒度分词，传参为待分词内容、保存分词结果的vector、单个词的最大长度
    _jieba.CutSmall(str, vec, sz);
}
