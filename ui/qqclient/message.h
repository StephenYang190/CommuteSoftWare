#ifndef MESSAGE_H
#define MESSAGE_H

#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>

class message
{
public:
    std::string type;
    std::string ori_id;
    std::string des_id;
    std::string ms;
    message();
    int newmessage(std::string rev_ms);
    ~message(){}
};

#endif // MESSAGE_H
