#ifndef ERRORSHOW_H
#define ERRORSHOW_H

#include <QWidget>

namespace Ui {
class Errorshow;
}

class Errorshow : public QWidget
{
    Q_OBJECT

public:
    explicit Errorshow(QWidget *parent = 0);
    ~Errorshow();
public slots:
    void myshow();

private:
    Ui::Errorshow *ui;
};

#endif // ERRORSHOW_H
