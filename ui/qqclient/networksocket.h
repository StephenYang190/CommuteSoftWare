#ifndef NETWORKSOCKET_H
#define NETWORKSOCKET_H

#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>
#include <QObject>
#include <QThread>

class NetworkSocket
{
public:
    SOCKET ConnectSocket;
    NetworkSocket();
    int Login(QString account, QString password);
    int sendsuccess();
    int waitack();
    int sendmss(QString);
    ~NetworkSocket();
};

class RcMss : public QObject
{
    Q_OBJECT
public:
    SOCKET ConnectSocket;
    RcMss(SOCKET cs)
    {
        ConnectSocket = cs;
    }
    ~RcMss(){}
signals:
    void receivemss(QString str);
public slots:
    void ReadMessage();
};

class client : public QObject
{
    Q_OBJECT
private:
    NetworkSocket * sc;
    QThread * workthread;
    RcMss * rc;
    QString account_id;
signals:
    void ReadMessage(QString str);
    void NewFri(QString fri_id);
    void DropFri(QString fri_id);
    void LoginS(QString);
    void LoginF();
    void run();
public slots:
    void Login(QString account, QString password);
    void SendM(QString send_str);
    void MessagePro(QString str);
public:
    client();
    void start();
    ~client();

};

#endif // NETWORKSOCKET_H
