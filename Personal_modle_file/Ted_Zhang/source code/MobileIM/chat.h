#ifndef CHAT_H
#define CHAT_H

#include <QtGui>
#include "ui_Chat.h"
#include "MobileIM.h"


class Chat : public QWidget, public Ui::Chat
	{
		Q_OBJECT
public:
		Chat(QWidget *parent=0);
		~Chat();
		void draw(QListWidgetItem *item);
public slots:
//		void goToMainWindow();
		void outPut();
//		void draw(QListWidgetItem *item);
public:
		QList<QString> m_friendname;
		QList<QPlainTextEdit*> m_sendtextedit;
		QList<QPlainTextEdit*> m_receivetextedit;
		bool m_chatingflag;
	};
#endif
