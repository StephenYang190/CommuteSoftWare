#include "cw.h"
#include "ui_cw.h"
#include "message.h"
#include <iostream>
#include <QListWidgetItem>
#include <QThread>
#include "chatwindow.h"

using namespace std;

Cw::Cw(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Cw)
{
    ui->setupUi(this);
}

Cw::~Cw()
{
    delete ui;
}

void Cw::LoginS(QString id)
{
    ori_id = id;
    ui->personalID->setText(ori_id);
    this->show();
}

void Cw::NewFri(QString id) {
    fri_id.push_back(id);
    chatlog nlog(ori_id, id);
    logs.push_back(nlog);

    QListWidgetItem * item = new QListWidgetItem;
    item->setText(id.toStdString().data());
    ui->frilist->addItem(item);
}

int Cw::Find(QString id)
{
    for(int i = 0; i < fri_id.size(); i++)
    {
        if(fri_id[i] == id)
            return i;
    }
    return -1;
}

void Cw::ReadMss(QString str)
{
    message mss;
    mss.newmessage(str.toStdString());
    if(mss.des_id == ori_id.toStdString())
    {
        int iresult = this->Find(QString::fromStdString(mss.ori_id));
        if(iresult == -1)
            return ;
        QString nwmss;
        nwmss = QString::fromStdString(mss.ori_id) + ":" + QString::fromStdString(mss.ms);
        logs[iresult].logs.push_back(nwmss);

        emit NewMss(str);
    }
}

void Cw::Sendto(QString str)
{
    message mss;
    mss.newmessage(str.toStdString());

    int iresult = this->Find(QString::fromStdString(mss.des_id));
    if(iresult == -1)
        return ;
    QString nwmss;
    nwmss = QString::fromStdString(mss.ori_id) + ":" + QString::fromStdString(mss.ms);
    logs[iresult].logs.push_back(nwmss);

    emit SendM(str);
}

void Cw::on_SendF_returnPressed()
{
    QString des = ui->SendF->text();
    ui->SendF->clear();
    int iresult = this->Find(des);
    if(iresult != -1)
    {
        chatwindow * nwindow = new chatwindow;
        nwindow->init(ori_id, des);
        QObject::connect(nwindow, SIGNAL(SendM(QString)), this, SLOT(Sendto(QString)));
        QObject::connect(this, SIGNAL(NewMss(QString)), nwindow, SLOT(NewMss(QString)));
        nwindow->show();
    }
}
