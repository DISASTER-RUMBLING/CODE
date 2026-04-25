#ifndef __SE_DICTPRODUCER_H__
#define __SE_DICTPRODUCER_H__

#include "WordSegmentation.h"

namespace SearchEngine
{

class DictProducer
{
public:
    DictProducer()
    : _jieba()
    {}

    ~DictProducer()
    {}

    WordSegmentation & getJieba() 
    {
        return _jieba;
    }
private:
    WordSegmentation _jieba;
};

};//end of namespace SearchEngine
#endif  //__SE_DICTPRODUCER_H__
