/********************************************************************************
** Form generated from reading UI file 'chatwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWINDOW_H
#define UI_CHATWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chatwindow
{
public:
    QWidget *dockWidgetContents;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPlainTextEdit *mssview;
    QLineEdit *msssend;

    void setupUi(QDockWidget *chatwindow)
    {
        if (chatwindow->objectName().isEmpty())
            chatwindow->setObjectName(QStringLiteral("chatwindow"));
        chatwindow->resize(321, 453);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        verticalLayoutWidget = new QWidget(dockWidgetContents);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 321, 431));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        mssview = new QPlainTextEdit(verticalLayoutWidget);
        mssview->setObjectName(QStringLiteral("mssview"));

        verticalLayout->addWidget(mssview);

        msssend = new QLineEdit(verticalLayoutWidget);
        msssend->setObjectName(QStringLiteral("msssend"));

        verticalLayout->addWidget(msssend);

        chatwindow->setWidget(dockWidgetContents);

        retranslateUi(chatwindow);

        QMetaObject::connectSlotsByName(chatwindow);
    } // setupUi

    void retranslateUi(QDockWidget *chatwindow)
    {
        chatwindow->setWindowTitle(QApplication::translate("chatwindow", "PP", Q_NULLPTR));
        label->setText(QApplication::translate("chatwindow", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class chatwindow: public Ui_chatwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWINDOW_H
