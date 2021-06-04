/********************************************************************************
** Form generated from reading UI file 'commutewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMUTEWINDOW_H
#define UI_COMMUTEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommuteWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *mssview;
    QLineEdit *msssend;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CommuteWindow)
    {
        if (CommuteWindow->objectName().isEmpty())
            CommuteWindow->setObjectName(QStringLiteral("CommuteWindow"));
        CommuteWindow->resize(701, 533);
        centralwidget = new QWidget(CommuteWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(190, 130, 381, 291));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        mssview = new QPlainTextEdit(verticalLayoutWidget);
        mssview->setObjectName(QStringLiteral("mssview"));

        verticalLayout->addWidget(mssview);

        msssend = new QLineEdit(verticalLayoutWidget);
        msssend->setObjectName(QStringLiteral("msssend"));

        verticalLayout->addWidget(msssend);

        CommuteWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CommuteWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 701, 23));
        CommuteWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(CommuteWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        CommuteWindow->setStatusBar(statusbar);

        retranslateUi(CommuteWindow);

        QMetaObject::connectSlotsByName(CommuteWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CommuteWindow)
    {
        CommuteWindow->setWindowTitle(QApplication::translate("CommuteWindow", "PP\350\201\212\345\244\251", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CommuteWindow: public Ui_CommuteWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMUTEWINDOW_H
