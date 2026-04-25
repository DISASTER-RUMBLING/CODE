#include "../../include/Reactor/ThreadPool.h"
#include <iostream>

using std::cout;
using std::endl;

namespace SearchEngine
{

thread_local const char *tname = "name_wangdao";

ThreadPool::ThreadPool(size_t threadNum, size_t queSize)
: _threadNum(threadNum)
, _threads()
, _queSize(queSize)
, _taskQue(_queSize)
, _isExit(false)
{
}

ThreadPool::~ThreadPool()
{
}

//线程池的启动与停止
void ThreadPool::start()
{
    //创建工作线程，并且将其运行启动，同时还要存放在容器
    /* for(size_t idx = 0; idx < _threadNum ; ++idx) */
    for(size_t idx = 1; idx < _threadNum - 1; ++idx)//为何这么改
    {
        //给每个线程一个名字
        _threads.push_back(thread(&ThreadPool::doTask, this, std::to_string(idx)));
    }
}

void ThreadPool::stop()
{
    //任务执行完毕之后，才能让主线程继续向下执行
    while(!_taskQue.empty())
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    _isExit = true;//标识线程池要退出来了
    //唤醒所有等待在_notEmpty条件变量上的线程
    /* _notEmpty.notify_all(); */
    _taskQue.wakeup();

    //回收工作线程
    for(auto &th : _threads)
    {
        th.join();
    }
}

//任务的添加与获取
void ThreadPool::addTask(Task &&task)
{
    if(task)
    {
        _taskQue.push(std::move(task));
    }
}

Task ThreadPool::getTask()
{
    return _taskQue.pop();
}

//线程池交给工作线程执行的任务，也就是线程入口函数
void ThreadPool::doTask(string name)
{
    tname = name.c_str();
    printf("\e[0;32m" "calculate thread[%s] created\n" "\e[0m", tname);
    while(!_isExit)
    {
        //获取任务
        Task taskcb  = getTask();
        if(taskcb)
        {
            string out = "calculate thread[" + string(tname) + "] got a task";
            printf("\e[0;32m" "%s\n" "\e[0m", out.c_str());
            //执行任务
            /* taskcb->process();//此处会有多态 */
            taskcb();
        }
        else
        {
            cout << "nullptr == taskcb" << endl;
        }
    }
}

}//end of namespace search_engine
