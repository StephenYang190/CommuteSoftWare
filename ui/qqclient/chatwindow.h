#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QDockWidget>

namespace Ui {
class chatwindow;
}

class chatwindow : public QDockWidget
{
    Q_OBJECT

public:
    explicit chatwindow(QWidget *parent = 0);
    void init(QString ori, QString des)
    {
        ori_id = ori;
        des_id = des;
    }

    ~chatwindow();

public slots:
    void NewMss(QString str);
private slots:
    void on_msssend_returnPressed();
signals:
    SendM(QString);
private:
    Ui::chatwindow *ui;
    QString ori_id;
    QString des_id;
};

#endif // CHATWINDOW_H
