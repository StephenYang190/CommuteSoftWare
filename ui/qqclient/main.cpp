#include "mainwindow.h"
#include "networksocket.h"
#include "cw.h"
#include "errorshow.h"
#include <QApplication>
#include <QString>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow * w = new MainWindow;
    w->show();

    Cw * cwindow = new Cw;
    cwindow->hide();

    client * clnt = new client;
    clnt->start();

    Errorshow * er = new Errorshow;
    er->hide();
    
    QObject::connect(w, SIGNAL(Login(QString, QString)), clnt, SLOT(Login(QString, QString)));
    QObject::connect(clnt, SIGNAL(LoginS(QString)), w, SLOT(LoginS(QString)));
    QObject::connect(clnt, SIGNAL(LoginS(QString)), cwindow, SLOT(LoginS(QString)));
    QObject::connect(cwindow, SIGNAL(SendM(QString)), clnt, SLOT(SendM(QString)));
    QObject::connect(clnt, SIGNAL(NewFri(QString)), cwindow, SLOT(NewFri(QString)));
    QObject::connect(clnt, SIGNAL(ReadMessage(QString)), cwindow, SLOT(ReadMss(QString)));
    QObject::connect(clnt, SIGNAL(LoginF()), er, SLOT(myshow()));

    return a.exec();
}
