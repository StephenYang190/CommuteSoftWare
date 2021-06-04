#ifndef CW_H
#define CW_H

#include <QMainWindow>
#include "networksocket.h"
#include <winsock2.h>
#include <ws2tcpip.h>
#include <vector>
#include <QString>
#include "chatwindow.h"

namespace Ui {
class Cw;
}

class chatlog
{
public:
    QString ori_id;
    QString des_id;
    std::vector<QString> logs;
    chatlog(QString ori, QString des)
    {
        ori_id = ori;
        des_id = des;
    }

    ~chatlog(){}
};

class Cw : public QMainWindow
{
    Q_OBJECT

public:
    explicit Cw(QWidget *parent = nullptr);
    int Find(QString id);
    ~Cw();

private slots:

    void on_SendF_returnPressed();

public slots:
    void LoginS(QString id);
    void NewFri(QString id);
    void ReadMss(QString str);
    void Sendto(QString str);
signals:
    void SendM(QString send_str);
    void NewMss(QString str);

private:
    Ui::Cw *ui;
    QString ori_id;
    std::vector<QString> fri_id;
    std::vector<chatlog> logs;
};

#endif // CW_H
