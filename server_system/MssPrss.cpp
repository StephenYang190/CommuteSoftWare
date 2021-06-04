//
// Created by yang on 2021/4/30.
//

#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <thread>
#include "ClioneData.h"

#define DEFAULT_PORT "27015"
#define DEFAULT_BUFLEN 512

using namespace std;

int login(SOCKET &ClientSocket, ClioneData &Clients, string &id)
{
    int iResult;
    int recvbuflen = DEFAULT_BUFLEN;
    while(1)
    {
        message mss;
        char recvbuf[recvbuflen];
        string recvms;
        iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
        if (iResult > 0) {
            recvms = recvbuf;
            cout << "receive : " << recvms << endl;
            mss.newmessage(recvms);
            if(mss.type == "0")
            {
                iResult = Clients.login(mss.ori_id, mss.ms, ClientSocket);
                if(iResult == 1)
                {
                    string ms = "0;0;0;111;";
                    send(ClientSocket, (char *) ms.data(), ms.size(), 0);
                    cout << "Correcte" << endl;
                    id = mss.ori_id;
                    break;
                }
                else
                {
                    string ms = "0;0;0;000;";
                    send(ClientSocket, (char *) ms.data(), ms.size(), 0);
                    cout << "Wrong" << endl;
                }
            }
            else
            {
                continue;
            }
        } else if (iResult == 0) {
            printf("Connection closing...\n");
            return 1;
        }
        else {
            printf("recv failed: %d\n", WSAGetLastError());
            return 1;
        }
    }
    Clients.waitack(ClientSocket);
    cout << "login successfully." << endl;

    //send friends data
    Clients.sendfrnds(id);

    return 0;
}

