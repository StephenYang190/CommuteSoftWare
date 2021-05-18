#ifndef NETWORKSOCKET_H
#define NETWORKSOCKET_H

#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>

class NetworkSocket
{
public:
    SOCKET ConnectSocket;
    NetworkSocket();
    NetworkSocket(NetworkSocket &cnn);
    NetworkSocket(SOCKET cnn);
    int Login(std::string account, std::string password);
    int sendsuccess();
    int waitack();
    int receivemss(std::string &str);
    int sendmss(std::string);
    ~NetworkSocket();
};

#endif // NETWORKSOCKET_H
