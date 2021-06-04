#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <networksocket.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void Login(QString account, QString password);
private slots:
    void on_LoginButton_clicked();

public slots:
    void LoginS(QString id);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
