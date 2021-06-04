/********************************************************************************
** Form generated from reading UI file 'cw.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CW_H
#define UI_CW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Cw
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *personalID;
    QLineEdit *SendF;
    QListWidget *frilist;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Cw)
    {
        if (Cw->objectName().isEmpty())
            Cw->setObjectName(QStringLiteral("Cw"));
        Cw->resize(281, 516);
        centralwidget = new QWidget(Cw);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 281, 471));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        personalID = new QLabel(verticalLayoutWidget);
        personalID->setObjectName(QStringLiteral("personalID"));

        horizontalLayout->addWidget(personalID);

        SendF = new QLineEdit(verticalLayoutWidget);
        SendF->setObjectName(QStringLiteral("SendF"));

        horizontalLayout->addWidget(SendF);


        verticalLayout->addLayout(horizontalLayout);

        frilist = new QListWidget(verticalLayoutWidget);
        frilist->setObjectName(QStringLiteral("frilist"));

        verticalLayout->addWidget(frilist);

        Cw->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Cw);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 281, 23));
        Cw->setMenuBar(menubar);
        statusbar = new QStatusBar(Cw);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Cw->setStatusBar(statusbar);

        retranslateUi(Cw);

        QMetaObject::connectSlotsByName(Cw);
    } // setupUi

    void retranslateUi(QMainWindow *Cw)
    {
        Cw->setWindowTitle(QApplication::translate("Cw", "PP", Q_NULLPTR));
        personalID->setText(QApplication::translate("Cw", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Cw: public Ui_Cw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CW_H
