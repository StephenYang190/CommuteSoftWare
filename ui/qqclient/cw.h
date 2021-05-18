#ifndef CW_H
#define CW_H

#include <QMainWindow>
#include "networksocket.h"
#include <winsock2.h>
#include <ws2tcpip.h>
#include <vector>

namespace Ui {
class Cw;
}

class Cw : public QMainWindow
{
    Q_OBJECT

public:
    explicit Cw(QWidget *parent, SOCKET &cnn, std::string id);
    int recv_mss();
    ~Cw();

private slots:

    void on_msssend_returnPressed();

private:
    Ui::Cw *ui;
    NetworkSocket ConnectSocket;
    std::string ori_id;
    std::vector<std::string> fri_id;
};

#endif // CW_H
