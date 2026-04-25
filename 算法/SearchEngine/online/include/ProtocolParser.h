#ifndef __SE_PROTOCOL_PARSER__
#define __SE_PROTOCOL_PARSER__

#include <sstream>

using std::string;
using std::istringstream;

namespace SearchEngine
{

class ProtocolParser 
{
public:
    ProtocolParser(string msg)
    :_msg(msg) 
    {
        doParser();
    }

    void doParser();

public:
    int    _id;
    string _sought;

private:
    string _msg;
};

inline void ProtocolParser::doParser() 
{
    istringstream is(_msg.c_str());
    string s;
    is >> s;
    _id = atoi(s.c_str());
    is >> s;
    _sought = s;
}

} // namespace search_engine

#endif // __SE_PROTOCOL_PARSER__
