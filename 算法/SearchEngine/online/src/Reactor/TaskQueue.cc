#include "../../include/Reactor/TaskQueue.h"

namespace SearchEngine
{

TaskQueue::TaskQueue(size_t capa)
: _capacity(capa)
, _que()
, _mutex()
, _notEmpty()
, _notFull()
, _flag(true)
{

}

TaskQueue::~TaskQueue()
{

}

//生产与消费
void TaskQueue::push(ElemType &&task)
{
    //1、拿锁（上锁）
    unique_lock<mutex> ul(_mutex);
    //2、判断是不是满的
    while(full())
    {
        //3、如果是满的，就直接睡眠
        _notFull.wait(ul);
    }
    //4、如果不满，将数据value存起来
    _que.push(std::move(task));
    //5、唤醒消费者
    _notEmpty.notify_one();
    //6、解锁
}

ElemType TaskQueue::pop()
{
    unique_lock<mutex> ul(_mutex);

    while(empty() && _flag)
    {
        _notEmpty.wait(ul);
    }

    if(_flag)
    {
        //现获取第一个元素，然后删除
        ElemType tmp = _que.front();
        _que.pop();

        _notFull.notify_one();

        return tmp;
    }
    else
    {
        return nullptr;
    }
}

//判空与判满
bool TaskQueue::empty() const
{
    return 0 == _que.size();
}

bool TaskQueue::full() const
{
    return _capacity == _que.size();
}

//唤醒所有等待在_notEmpty条件变量上的线程
void TaskQueue::wakeup()
{
    _flag = false;
    _notEmpty.notify_all();
}

}//end of namespace search_engine
