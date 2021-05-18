#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cw.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), socket()
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_LoginButton_clicked()
{
    QString account = ui->AccountText->text();
    QString password = ui->PasswordText->text();
    std::cout << account.toStdString().data() << std::endl;
    std::cout << password.toStdString().data() << std::endl;

    int iresult;
    iresult = socket.Login(account.toStdString(), password.toStdString());
    std::cout << iresult << std::endl;
    if(iresult == 0)
    {
        iresult = socket.sendsuccess();
        if(iresult == -1)
            return ;
        Cw *cmw = new Cw(this, socket.ConnectSocket, account.toStdString());
        this->hide();
        cmw->show();
    }
}
