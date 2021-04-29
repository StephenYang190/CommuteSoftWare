//
// Created by TongdaYang on 2021/4/24.
//

#ifndef SERVER_SYSTEM_SERVERDATA_H
#define SERVER_SYSTEM_SERVERDATA_H
#include <string>
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>


class massage{
public:
    std::string type;
    std::string ori_id;
    std::string des_id;
    std::string ms;
    massage(std::string rev_ms)
    {
        int star = 0;
        int k = 0;
        int i = 0;
        while(i < rev_ms.size())
        {
            if(rev_ms[i] == ';')
            {
                type = rev_ms.substr(star, i - star);
                i++;
                star = i;
                break;
            }
            i++;
        }
        while(i < rev_ms.size())
        {
            if(rev_ms[i] == ';')
            {
                ori_id = rev_ms.substr(star, i - star);
                i++;
                star = i;
                break;
            }
            i++;
        }
        while(i < rev_ms.size())
        {
            if(rev_ms[i] == ';')
            {
                des_id = rev_ms.substr(star, i - star);
                i++;
                star = i;
                break;
            }
            i++;
        }
        ms = rev_ms.substr(star, rev_ms.size() - star);
    }
    ~massage(){}

};
class client_info{
public:
    std::string id;
    SOCKET Client;
    client_info(SOCKET client_, std::string idnum)
    {
        Client = client_;
        id = idnum;
    }
    client_info()
    {
        Client = INVALID_SOCKET;
        id = "";
    }
};
class ServerData {
private:
    std::vector<client_info> clients;
public:
    ServerData(){}
    int find_client(std::string idname);
    int push(SOCKET new_client_socket, std::string idname);
    ~ServerData(){}
};


#endif //SERVER_SYSTEM_SERVERDATA_H
