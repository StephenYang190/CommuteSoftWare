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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Cw
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QListWidget *frilist;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *mssview;
    QLineEdit *msssend;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Cw)
    {
        if (Cw->objectName().isEmpty())
            Cw->setObjectName(QStringLiteral("Cw"));
        Cw->resize(640, 480);
        centralwidget = new QWidget(Cw);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 641, 431));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        frilist = new QListWidget(horizontalLayoutWidget);
        frilist->setObjectName(QStringLiteral("frilist"));

        horizontalLayout->addWidget(frilist);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        mssview = new QPlainTextEdit(horizontalLayoutWidget);
        mssview->setObjectName(QStringLiteral("mssview"));

        verticalLayout->addWidget(mssview);

        msssend = new QLineEdit(horizontalLayoutWidget);
        msssend->setObjectName(QStringLiteral("msssend"));

        verticalLayout->addWidget(msssend);


        horizontalLayout->addLayout(verticalLayout);

        Cw->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Cw);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 640, 23));
        Cw->setMenuBar(menubar);
        statusbar = new QStatusBar(Cw);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Cw->setStatusBar(statusbar);

        retranslateUi(Cw);

        QMetaObject::connectSlotsByName(Cw);
    } // setupUi

    void retranslateUi(QMainWindow *Cw)
    {
        Cw->setWindowTitle(QApplication::translate("Cw", "MainWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Cw: public Ui_Cw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CW_H
