/********************************************************************************
** Form generated from reading UI file 'Chat.ui'
**
** Created: Wed Jul 7 15:30:07 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chat
{
public:
    QFormLayout *formLayout;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QTabWidget *tabchat;
    QWidget *myself;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *receivetextedit;
    QFrame *line;
    QPlainTextEdit *sendtextedit;
    QWidget *tab_2;
    QPushButton *pbsend;
    QPushButton *pbclose;

    void setupUi(QWidget *Chat)
    {
        if (Chat->objectName().isEmpty())
            Chat->setObjectName(QString::fromUtf8("Chat"));
        Chat->resize(248, 340);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(130, 153, 177, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(198, 226, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(164, 189, 216, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(65, 76, 88, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(87, 102, 118, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(192, 204, 216, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        Chat->setPalette(palette);
        formLayout = new QFormLayout(Chat);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        toolButton = new QToolButton(Chat);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setMinimumSize(QSize(40, 40));
        toolButton->setMaximumSize(QSize(40, 40));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/newPrefix/chat.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(40, 40));
        toolButton->setAutoRaise(false);

        horizontalLayout_2->addWidget(toolButton);

        toolButton_2 = new QToolButton(Chat);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setMinimumSize(QSize(40, 40));
        toolButton_2->setMaximumSize(QSize(40, 40));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/newPrefix/transfer.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);
        toolButton_2->setIconSize(QSize(40, 40));
        toolButton_2->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButton_2);

        toolButton_3 = new QToolButton(Chat);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setMinimumSize(QSize(40, 40));
        toolButton_3->setMaximumSize(QSize(40, 40));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/newPrefix/dockswap.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon2);
        toolButton_3->setIconSize(QSize(40, 40));
        toolButton_3->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButton_3);


        formLayout->setLayout(0, QFormLayout::SpanningRole, horizontalLayout_2);

        tabchat = new QTabWidget(Chat);
        tabchat->setObjectName(QString::fromUtf8("tabchat"));
        tabchat->setBaseSize(QSize(0, 0));
        QPalette palette1;
        QBrush brush9(QColor(179, 196, 255, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush9);
        QBrush brush10(QColor(180, 188, 255, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush10);
        tabchat->setPalette(palette1);
        tabchat->setTabShape(QTabWidget::Rounded);
        tabchat->setIconSize(QSize(20, 20));
        tabchat->setElideMode(Qt::ElideNone);
        tabchat->setUsesScrollButtons(true);
        tabchat->setDocumentMode(true);
        tabchat->setTabsClosable(false);
        tabchat->setMovable(false);
        myself = new QWidget();
        myself->setObjectName(QString::fromUtf8("myself"));
        verticalLayout = new QVBoxLayout(myself);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        receivetextedit = new QPlainTextEdit(myself);
        receivetextedit->setObjectName(QString::fromUtf8("receivetextedit"));
        QPalette palette2;
        QBrush brush11(QColor(246, 255, 239, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush11);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush10);
        receivetextedit->setPalette(palette2);
        receivetextedit->setTabChangesFocus(false);

        verticalLayout->addWidget(receivetextedit);

        line = new QFrame(myself);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        sendtextedit = new QPlainTextEdit(myself);
        sendtextedit->setObjectName(QString::fromUtf8("sendtextedit"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Base, brush11);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush11);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush10);
        sendtextedit->setPalette(palette3);
        sendtextedit->setLineWrapMode(QPlainTextEdit::WidgetWidth);
        sendtextedit->setBackgroundVisible(false);

        verticalLayout->addWidget(sendtextedit);

        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/newPrefix/Contacts.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabchat->addTab(myself, icon3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabchat->addTab(tab_2, QString());

        formLayout->setWidget(1, QFormLayout::SpanningRole, tabchat);

        pbsend = new QPushButton(Chat);
        pbsend->setObjectName(QString::fromUtf8("pbsend"));
        pbsend->setMinimumSize(QSize(50, 50));
        pbsend->setMaximumSize(QSize(50, 50));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/newPrefix/TEXT.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbsend->setIcon(icon4);
        pbsend->setIconSize(QSize(50, 50));

        formLayout->setWidget(2, QFormLayout::LabelRole, pbsend);

        pbclose = new QPushButton(Chat);
        pbclose->setObjectName(QString::fromUtf8("pbclose"));
        pbclose->setMinimumSize(QSize(50, 50));
        pbclose->setMaximumSize(QSize(50, 50));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/newPrefix/iTunes.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbclose->setIcon(icon5);
        pbclose->setIconSize(QSize(50, 50));

        formLayout->setWidget(2, QFormLayout::FieldRole, pbclose);


        retranslateUi(Chat);

        tabchat->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Chat);
    } // setupUi

    void retranslateUi(QWidget *Chat)
    {
        Chat->setWindowTitle(QApplication::translate("Chat", "Chat", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QString());
        toolButton_2->setText(QApplication::translate("Chat", "File transfer", 0, QApplication::UnicodeUTF8));
        toolButton_3->setText(QApplication::translate("Chat", "Other", 0, QApplication::UnicodeUTF8));
        tabchat->setTabText(tabchat->indexOf(myself), QString());
        tabchat->setTabText(tabchat->indexOf(tab_2), QString());
        pbsend->setText(QString());
        pbclose->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Chat: public Ui_Chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
