#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cw.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
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

    emit Login(account, password);
}

void MainWindow::LoginS(QString id) {
    this->hide();
}
