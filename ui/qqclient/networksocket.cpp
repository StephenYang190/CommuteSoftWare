#include "networksocket.h"
#include <iostream>
#include <QString>
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

int NetworkSocket::Login(QString account, QString password)
{
    int iresult;
    QString send_str;
    send_str = "0;" + account + ";" + "0;" + password + ";";
    iresult = send(ConnectSocket, (char *) send_str.toStdString().data(), (int) send_str.length(), 0);
    if (iresult == SOCKET_ERROR) {
                printf("send failed: %d\n", WSAGetLastError());
                closesocket(ConnectSocket);
                WSACleanup();
                return 1;}

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
            QString recvms;
            iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
            if (iResult > 0) {
                recvms = recvbuf;
                cout << "receive : " << recvms.toStdString() << endl;
                mss.newmessage(recvms.toStdString());
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

int NetworkSocket::sendmss(QString send_str)
{
    return send(ConnectSocket, (char *) send_str.toStdString().data(), (int) send_str.length(), 0);
}

client::client()
{
    sc = new NetworkSocket;
    workthread = new QThread;
    rc = new RcMss(sc->ConnectSocket);
    rc->moveToThread(workthread);
    QObject::connect(rc, SIGNAL(receivemss(QString )), this, SLOT(MessagePro(QString)));
    QObject::connect(this, SIGNAL(run()), rc, SLOT(ReadMessage()));

    workthread->start();
}

client::~client()
{

}

void client::Login(QString account, QString password)
{
    sc->Login(account, password);
    account_id = account;
}

void client::SendM(QString send_str) {
    int iResult;
    iResult = sc->sendmss(send_str);

    std::cout << iResult << std::endl;
    if(iResult == 0)
    {
        std::cout << "send successfully." << std::endl;
    } else{
        std::cout << "send unsuccessfully." << std::endl;
    }
}

void client::MessagePro(QString str) {
    message mss;
    mss.newmessage(str.toStdString());

    switch(mss.type[0])
    {
        case '0':
        {
            if(mss.ms == "111")
            {
                sc->sendsuccess();
                emit LoginS(account_id);
            }
            else
            {
                emit LoginF();
            }

            break;
        }
        case '1':
        {
            emit ReadMessage(str);
            break;
        }
        case '2':
        {
            if(mss.ms == "1")
            {
                emit NewFri(QString::fromStdString(mss.ori_id));
            }
            else
            {
                emit DropFri(QString::fromStdString(mss.ori_id));
            }
            break;
        }
        case '3':
        {
            break;
        }

    }

}

void client::start() {
    emit run();
}

void RcMss::ReadMessage() {
    int iResult;
    int recvbuflen = 512;
    while(1)
    {
        char recvbuf[recvbuflen];
        QString recvms;
        iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
        recvms = recvbuf;
        std::cout << recvms.toStdString() << std::endl;
        if (iResult > 0) {
            emit receivemss(recvms);
        } else if (iResult == 0)
        {
            printf("Connection closing...\n");
            return ;
        }
        else {
            printf("recv failed: %d\n", WSAGetLastError());
            closesocket(ConnectSocket);
            WSACleanup();
            return ;
        }
    }

    return ;
}
