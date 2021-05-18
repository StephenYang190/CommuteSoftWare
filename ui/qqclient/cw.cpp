#include "cw.h"
#include "ui_cw.h"
#include "message.h"
#include <iostream>
#include <QListWidgetItem>

using namespace std;

Cw::Cw(QWidget *parent, SOCKET &cnn, std::string id) :
    QMainWindow(parent),
    ui(new Ui::Cw),
    ori_id(id),
    ConnectSocket(cnn)
{
    ui->setupUi(this);
    int iResult;
    while(1)
    {
        string recvms = "";
        iResult = ConnectSocket.receivemss(recvms);
        if (iResult == 0) {
            cout << recvms << endl;
            message mss;
            mss.newmessage(recvms);
            if(mss.type == "2")
            {
                if(mss.ori_id == "1")
                    break;
                fri_id.push_back(mss.ms);
                ConnectSocket.sendsuccess();
            }
        }
    }
    ConnectSocket.sendsuccess();

    for(int i = 0; i < fri_id.size(); i++)
    {
        QListWidgetItem * item = new QListWidgetItem;
        item->setText(fri_id[i].data());
        ui->frilist->addItem(item);
    }
}

Cw::~Cw()
{
    delete ui;
}

int Cw::recv_mss()
{
    int iResult;
    while(1)
    {
        string recvms;
        iResult = ConnectSocket.receivemss(recvms);
        if (iResult == 0) {
            message mss;
            mss.newmessage(recvms);
            if(mss.type == "1")
            {
                ui->mssview->appendPlainText(recvms.data());
            }
            else if(mss.type == "2")
            {
                QListWidgetItem * item = new QListWidgetItem;
                item->setText(mss.ms.data());
                ui->frilist->addItem(item);
            }
        } else if (iResult == 0)
        {
            printf("Connection closing...\n");
            return 1;
        }
        else {
            printf("recv failed: %d\n", WSAGetLastError());
            WSACleanup();
            return 1;
        }
    }
}

void Cw::on_msssend_returnPressed()
{
    int iresult;
    QString mss = ui->msssend->text();
    ui->msssend->clear();
    ui->mssview->appendPlainText(QString::fromStdString(ori_id + ":"));
    ui->mssview->appendPlainText(mss);
    string send_str;
    send_str = "1;" + ori_id + ";111;" + mss.toStdString() + ";";
    iresult = ConnectSocket.sendmss(send_str);
    cout << iresult << endl;
    if (iresult == SOCKET_ERROR) {
                printf("send failed: %d\n", WSAGetLastError());
                WSACleanup();
                return ;}
}
