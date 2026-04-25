#ifndef __SOCKETIO_H__
#define __SOCKETIO_H__

namespace SearchEngine
{

class SocketIO
{
public:
    explicit SocketIO(int fd);
    ~SocketIO();
    int readn(char *buf, int len);
    int readLine(char *buf, int len);
    int writen(const char *buf, int len);

private:
    int _fd;
};

}//end of namespace search_engine

#endif
