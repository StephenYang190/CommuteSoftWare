#include "networksocket.h"
#include <iostream>
#include <string>
#include "message.h"

using namespace std;

NetworkSocket::NetworkSocket()
{
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if(iResult != 0)
    {
        cout << "fail" << endl;
    }

    struct addrinfo hints, *result, *ptr;

    ZeroMemory( &hints, sizeof(hints) );
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

// Resolve the server address and port
    iResult = getaddrinfo("127.0.0.1", "27015", &hints, &result);
    if (iResult != 0) {
        printf("getaddrinfo failed: %d\n", iResult);
        WSACleanup();
        return ;
    }

    // Attempt to connect to the first address returned by
    // the call to getaddrinfo
    ptr=result;

    // Create a SOCKET for connecting to server
    ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
                           ptr->ai_protocol);

    if (ConnectSocket == INVALID_SOCKET) {
       cout<< "Error at socket(): " << WSAGetLastError() << endl;;
        freeaddrinfo(result);
        WSACleanup();
        return ;
    }

    // Connect to server.
    iResult = connect( ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        closesocket(ConnectSocket);
        ConnectSocket = INVALID_SOCKET;
    }

    // Should really try the next address returned by getaddrinfo
    // if the connect call failed
    // But for this simple example we just free the resources
    // returned by getaddrinfo and print an error message

    freeaddrinfo(result);

    if (ConnectSocket == INVALID_SOCKET) {
        printf("Unable to connect to server!\n");
        WSACleanup();
        return ;
    }
}

int NetworkSocket::Login(std::string account, std::string password)
{
    int iresult;
    string send_str;
    send_str = "0;" + account + ";" + "0;" + password + ";";
    iresult = send(ConnectSocket, (char *) send_str.data(), (int) send_str.length(), 0);
    if (iresult == SOCKET_ERROR) {
                printf("send failed: %d\n", WSAGetLastError());
                closesocket(ConnectSocket);
                WSACleanup();
                return 1;}

    int iResult;
    int recvbuflen = 512;
    while(1)
    {
        char recvbuf[recvbuflen];
        string recvms;
        iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
        recvms = recvbuf;
        cout << "receive : " << recvms << endl;
        if (iResult > 0) {
            message mss;
            mss.newmessage(recvbuf);

            if(mss.type == "0")
            {
                if(mss.ms == "111")
                {
                    break;
                }
                else
                {
                    return 1;
                }
            }
            else
            {
                return 1;
            }

        } else if (iResult == 0)
        {
            printf("Connection closing...\n");
            return 1;
        }
        else {
            printf("recv failed: %d\n", WSAGetLastError());
            closesocket(ConnectSocket);
            WSACleanup();
            return 1;
        }
    }

    return 0;
}

NetworkSocket::~NetworkSocket()
{

}

int NetworkSocket::sendsuccess()
{
    int iresult;
    string send_str;
    send_str = "3;0;0;111;";
    iresult = send(ConnectSocket, (char *) send_str.data(), (int) send_str.length(), 0);
    if (iresult == SOCKET_ERROR) {
                printf("send failed: %d\n", WSAGetLastError());
                closesocket(ConnectSocket);
                WSACleanup();
                return 1;}
    cout << "send confine" << endl;

    return 0;
}

int NetworkSocket::waitack()
{
    int iResult;
        int recvbuflen = 512;
        while(1)
        {
            message mss;
            char recvbuf[recvbuflen];
            string recvms;
            iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
            if (iResult > 0) {
                recvms = recvbuf;
                cout << "receive : " << recvms << endl;
                mss.newmessage(recvms);
                if(mss.type == "3")
                {
                    break;
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

        return 0;
}

int NetworkSocket::receivemss(std::string &str)
{
    int iResult;
    int recvbuflen = 512;
    while(1)
    {
        char recvbuf[recvbuflen];
        string recvms;
        iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
        recvms = recvbuf;
        if (iResult > 0) {
            str = recvms;
            break;
        } else if (iResult == 0)
        {
            printf("Connection closing...\n");
            return 1;
        }
        else {
            printf("recv failed: %d\n", WSAGetLastError());
            closesocket(ConnectSocket);
            WSACleanup();
            return 1;
        }
    }

    return 0;
}

int NetworkSocket::sendmss(std::string send_str)
{
    return send(ConnectSocket, (char *) send_str.data(), (int) send_str.length(), 0);
}

NetworkSocket::NetworkSocket(NetworkSocket &cnn)
{
    ConnectSocket = cnn.ConnectSocket;
}

NetworkSocket::NetworkSocket(SOCKET cnn)
{
    ConnectSocket = cnn;
}
