#ifndef __SE_TIMER_FD_H__
#define __SE_TIMER_FD_H__

#include <functional>

using std::function;

namespace SearchEngine
{

class TimerFd 
{
    using TimerFdCallback = function<void()>;
public:
    TimerFd(int initsec, int perisec, TimerFdCallback &&cb);
    ~TimerFd();
    void start();
    void stop();

private:
    void handleRead();
    int createTimerFd();
    void setTimerFd(int initsec, int perisec);

private:
    int _timerfd;
    int _initsec;
    int _perisec;
    TimerFdCallback _cb;
    bool _isStarted;
};

} // namespace search_engine

#endif // __SE_TIMER_FD_H__
