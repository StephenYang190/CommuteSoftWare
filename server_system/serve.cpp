//
// Created by yang on 2021/4/23.
//

#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <thread>
#include "ClioneData.h"
#include "MssPrss.h"

#pragma comment(lib, "Ws2_32.lib")

#define DEFAULT_PORT "27015"
#define DEFAULT_BUFLEN 512

using namespace std;

static ClioneData Clients;

int clientServe(SOCKET ClientSocket)
{
    int iResult;
    int recvbuflen = DEFAULT_BUFLEN;
    message mss;

    //Login confirm
    if(login(ClientSocket, Clients) != 0)
    {
        cout << "Connect close" << endl;
        return 1;
    }
    // Receive until the peer shuts down the connection
    do {
        char recvbuf[DEFAULT_BUFLEN];
        string recvms;
        iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
        if (iResult > 0) {
            recvms = recvbuf;
            mss.newmessage(recvms);
            cout << "from " << mss.ori_id << "to " << mss.des_id << endl;
            cout << mss.ms << endl;
        } else if (iResult == 0)
            printf("Connection closing...\n");
        else {
            printf("recv failed: %d\n", WSAGetLastError());
            return 1;
        }

    } while (iResult > 0);

    return 0;
}

int main() {
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if(iResult != 0)
    {
        cout << "fail" << endl;
    }

    iResult = Clients.init("client_data.txt");
    if(iResult != 0)
    {
        cout << "Failed to open the file" << endl;
        return 1;
    }

    struct addrinfo *result = NULL, *ptr = NULL, hints;

    ZeroMemory(&hints, sizeof (hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

// Resolve the local address and port to be used by the server
    iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
    if (iResult != 0) {
        printf("getaddrinfo failed: %d\n", iResult);
        WSACleanup();
        return 1;
    }

    SOCKET ListenSocket = INVALID_SOCKET;
    // Create a SOCKET for the server to listen for client connections
    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ListenSocket == INVALID_SOCKET) {
        printf("Error at socket(): %ld\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        return 1;
    }

    // Setup the TCP listening socket
    iResult = bind( ListenSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
    freeaddrinfo(result);

    if ( listen( ListenSocket, SOMAXCONN ) == SOCKET_ERROR ) {
        printf( "Listen failed with error: %ld\n", WSAGetLastError() );
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    SOCKET ClientSocket;
    ClientSocket = INVALID_SOCKET;

// Accept a client socket
    while(1)
    {
        ClientSocket = accept(ListenSocket, NULL, NULL);
        if (ClientSocket != INVALID_SOCKET) {
            cout << "Recieve a new connection." << endl;
            thread th(clientServe, ClientSocket);
            th.detach();
        }
    }

    return 0;
}