#ifndef COMMUTEWINDOW_H
#define COMMUTEWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <winsock2.h>
#include <ws2tcpip.h>

namespace Ui {
class CommuteWindow;
}

class CommuteWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit CommuteWindow(QWidget *parent, SOCKET cnn, std::string id);
    int recv_mss();
    ~CommuteWindow();
private:
    Ui::CommuteWindow *ui;
    SOCKET ConnectSocket;
    std::string ori_id;
signals:

private slots:
    void on_msssend_returnPressed();
};

#endif // COMMUTEWINDOW_H
