#ifndef __TASKQUEUE_H__
#define __TASKQUEUE_H__

#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>

using std::queue;
using std::mutex;
using std::unique_lock;
using std::condition_variable;
using std::function;

namespace SearchEngine
{

using ElemType = function<void()>;

class TaskQueue
{
public:
    TaskQueue(size_t capa);
    ~TaskQueue();

    //生产与消费
    void push(ElemType &&task);
    ElemType pop();

    //判空与判满
    bool empty() const;
    bool full() const;

    //唤醒所有等待在_notEmpty条件变量上的线程
    void wakeup();

private:
    size_t _capacity;//任务队列的大小
    queue<ElemType> _que;//存放任务的数据结构
    mutex _mutex;//互斥锁
    condition_variable _notEmpty;//非空条件变量（消费者）
    condition_variable _notFull;//非满条件变量（生产者）
    bool _flag;//标识

};
}//end of namespace search_engine

#endif
