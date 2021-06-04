/********************************************************************************
** Form generated from reading UI file 'errorshow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERRORSHOW_H
#define UI_ERRORSHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Errorshow
{
public:
    QLabel *label;

    void setupUi(QWidget *Errorshow)
    {
        if (Errorshow->objectName().isEmpty())
            Errorshow->setObjectName(QStringLiteral("Errorshow"));
        Errorshow->resize(240, 46);
        label = new QLabel(Errorshow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 5, 221, 31));
        label->setAlignment(Qt::AlignCenter);
        label->setMargin(3);
        label->setIndent(2);

        retranslateUi(Errorshow);

        QMetaObject::connectSlotsByName(Errorshow);
    } // setupUi

    void retranslateUi(QWidget *Errorshow)
    {
        Errorshow->setWindowTitle(QApplication::translate("Errorshow", "Error", Q_NULLPTR));
        label->setText(QApplication::translate("Errorshow", "\350\264\246\345\217\267\346\210\226\345\257\206\347\240\201\351\224\231\350\257\257", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Errorshow: public Ui_Errorshow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERRORSHOW_H
