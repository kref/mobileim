/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Jul 5 19:14:38 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *editConnRecord;
    QSpacerItem *verticalSpacer;
    QPlainTextEdit *editMsg;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QLabel *labelAdd;
    QLineEdit *addressEdit;
    QSpacerItem *horizontalSpacer;
    QLabel *labelPort;
    QLineEdit *portEdit;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *buttonSave;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *buttonResetRecord;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *buttonExit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(614, 539);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 9, 571, 469));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        editConnRecord = new QPlainTextEdit(verticalLayoutWidget);
        editConnRecord->setObjectName(QString::fromUtf8("editConnRecord"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(editConnRecord->sizePolicy().hasHeightForWidth());
        editConnRecord->setSizePolicy(sizePolicy);
        editConnRecord->setSizeIncrement(QSize(0, 2));

        verticalLayout->addWidget(editConnRecord);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        editMsg = new QPlainTextEdit(verticalLayoutWidget);
        editMsg->setObjectName(QString::fromUtf8("editMsg"));
        editMsg->setSizeIncrement(QSize(0, 1));

        verticalLayout->addWidget(editMsg);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelAdd = new QLabel(verticalLayoutWidget);
        labelAdd->setObjectName(QString::fromUtf8("labelAdd"));

        horizontalLayout->addWidget(labelAdd);

        addressEdit = new QLineEdit(verticalLayoutWidget);
        addressEdit->setObjectName(QString::fromUtf8("addressEdit"));

        horizontalLayout->addWidget(addressEdit);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        labelPort = new QLabel(verticalLayoutWidget);
        labelPort->setObjectName(QString::fromUtf8("labelPort"));

        horizontalLayout->addWidget(labelPort);

        portEdit = new QLineEdit(verticalLayoutWidget);
        portEdit->setObjectName(QString::fromUtf8("portEdit"));

        horizontalLayout->addWidget(portEdit);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        buttonSave = new QPushButton(verticalLayoutWidget);
        buttonSave->setObjectName(QString::fromUtf8("buttonSave"));

        horizontalLayout_6->addWidget(buttonSave);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        buttonResetRecord = new QPushButton(verticalLayoutWidget);
        buttonResetRecord->setObjectName(QString::fromUtf8("buttonResetRecord"));

        horizontalLayout_6->addWidget(buttonResetRecord);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        buttonExit = new QPushButton(verticalLayoutWidget);
        buttonExit->setObjectName(QString::fromUtf8("buttonExit"));

        horizontalLayout_6->addWidget(buttonExit);


        verticalLayout->addLayout(horizontalLayout_6);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 614, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        labelAdd->setText(QApplication::translate("MainWindow", " IP Address:", 0, QApplication::UnicodeUTF8));
        labelPort->setText(QApplication::translate("MainWindow", " Port: ", 0, QApplication::UnicodeUTF8));
        buttonSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        buttonResetRecord->setText(QApplication::translate("MainWindow", "Reset", 0, QApplication::UnicodeUTF8));
        buttonExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
