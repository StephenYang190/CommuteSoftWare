#include "errorshow.h"
#include "ui_errorshow.h"

Errorshow::Errorshow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Errorshow)
{
    ui->setupUi(this);
}

Errorshow::~Errorshow()
{
    delete ui;
}

void Errorshow::myshow()
{
    this->show();
}
