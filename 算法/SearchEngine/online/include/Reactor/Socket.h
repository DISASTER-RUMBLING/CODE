#ifndef __SOCKET_H__
#define __SOCKET_H__

#include "../DisallowCopyAssign.h"

namespace SearchEngine
{

class Socket
{
public:
    Socket();
    explicit Socket(int fd);
    ~Socket();
    int fd() const;
    void shutDownWrite();

    DISALLOWCOPYANDASSIGN(Socket);
private:
    int _fd;
};

}//end of namespace search_engine
#endif
