#include "commutewindow.h"
#include "ui_mainwindow.h"
#include "ui_commutewindow.h"
#include <iostream>
using namespace std;

CommuteWindow::CommuteWindow(QWidget *parent, SOCKET cnn, std::string id) :
    QMainWindow(parent),
    ui(new Ui::CommuteWindow),
    ori_id(id)
{
    ui->setupUi(this);
    ConnectSocket = cnn;
}

CommuteWindow::~CommuteWindow()
{
    delete ui;
}

void CommuteWindow::on_msssend_returnPressed()
{
    int iresult;
    string mss = ui->msssend->text().toStdString();
    string send_str;
    send_str = "1;" + ori_id + ";111;" + mss;
    iresult = send(ConnectSocket, (char *) send_str.data(), (int) send_str.length(), 0);
    if (iresult == SOCKET_ERROR) {
                printf("send failed: %d\n", WSAGetLastError());
                closesocket(ConnectSocket);
                WSACleanup();
                return ;}
}

int CommuteWindow::recv_mss()
{
    int iResult;
    int recvbuflen = 512;
    while(1)
    {
        char recvbuf[recvbuflen];
        string recvms;
        iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
        if (iResult > 0) {
            ui->mssview->appendPlainText(recvbuf);
        } else if (iResult == 0)
            printf("Connection closing...\n");
        else {
            printf("recv failed: %d\n", WSAGetLastError());
            closesocket(ConnectSocket);
            WSACleanup();
            return 1;
        }
    }
}
