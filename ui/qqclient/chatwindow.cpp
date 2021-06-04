#include "chatwindow.h"
#include "ui_chatwindow.h"
#include "message.h"

chatwindow::chatwindow(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::chatwindow)
{
    ui->setupUi(this);
    ui->label->setText(des_id);
}

chatwindow::~chatwindow()
{
    delete ui;
}

void chatwindow::on_msssend_returnPressed()
{
    QString mss = ui->msssend->text();
    ui->msssend->clear();
    ui->mssview->appendPlainText(ori_id + ":");
    ui->mssview->appendPlainText(mss);
    QString send_str;
    send_str = "1;" + ori_id + ";" + des_id + ";" + mss + ";";
    emit SendM(send_str);
}

void chatwindow::NewMss(QString str)
{
    message mss;
    mss.newmessage(str.toStdString());
    if(mss.ori_id == des_id.toStdString())
    {
        ui->mssview->appendPlainText(QString::fromStdString(mss.ori_id) + ":");
        ui->mssview->appendPlainText(QString::fromStdString(mss.ms));
    }
}
