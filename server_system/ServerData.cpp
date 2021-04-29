//
// Created by TongdaYang on 2021/4/24.
//

#include "ServerData.h"

using namespace std;


int ServerData::find_client(string idname) {
    for(int i = 0; i < clients.size(); i++)
    {
        if(clients[i].id == idname)
            return i;
    }
    return -1;
}

int ServerData::push(SOCKET new_client_socket, std::string idname) {
    client_info new_client(new_client_socket, idname);
    clients.push_back(new_client);
    return 0;
}


