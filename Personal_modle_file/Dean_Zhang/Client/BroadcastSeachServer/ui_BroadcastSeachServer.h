/********************************************************************************
** Form generated from reading UI file 'BroadcastSeachServer.ui'
**
** Created: Sun Jun 27 16:52:21 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BROADCASTSEACHSERVER_H
#define UI_BROADCASTSEACHSERVER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_BroadcastSeachServer
{
public:
    QTextBrowser *textBrowser;
    QPushButton *pushButton;

    void setupUi(QDialog *BroadcastSeachServer)
    {
        if (BroadcastSeachServer->objectName().isEmpty())
            BroadcastSeachServer->setObjectName(QString::fromUtf8("BroadcastSeachServer"));
        BroadcastSeachServer->resize(400, 300);
        textBrowser = new QTextBrowser(BroadcastSeachServer);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(0, 10, 256, 281));
        textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        pushButton = new QPushButton(BroadcastSeachServer);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(280, 30, 75, 23));

        retranslateUi(BroadcastSeachServer);

        QMetaObject::connectSlotsByName(BroadcastSeachServer);
    } // setupUi

    void retranslateUi(QDialog *BroadcastSeachServer)
    {
        BroadcastSeachServer->setWindowTitle(QApplication::translate("BroadcastSeachServer", "BroadcastSeachServer", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("BroadcastSeachServer", "Broadcast", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BroadcastSeachServer: public Ui_BroadcastSeachServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BROADCASTSEACHSERVER_H
