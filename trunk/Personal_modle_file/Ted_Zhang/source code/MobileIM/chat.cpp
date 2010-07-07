#include <QtGui>
#include "chat.h"

Chat::Chat(QWidget *parent) : QWidget(parent)
	{
	setupUi(this);
	m_chatingflag = false;
	tabchat->removeTab(1);
	m_sendtextedit.append(sendtextedit);
	m_receivetextedit.append(receivetextedit);
	QObject::connect(pbclose, SIGNAL(clicked()),
					 this, SLOT(close()));
	QObject::connect(pbsend,SIGNAL(clicked()),
					 this, SLOT(outPut()));
	
	}
Chat::~Chat()
	{
	QObject::disconnect(pbclose,SIGNAL(clicked()),
						this,SLOT(close()));
	}
void Chat::outPut()
	{
	QString content;
	for (int i=0;i<m_sendtextedit.size();i++)
	{
	content = m_sendtextedit.at(i)->toPlainText();
	m_receivetextedit.at(i)->setPlainText(content);
	}
	
	}
void Chat::draw(QListWidgetItem *item)
	{
		QString pagename = item->text();
		bool addflag = false;
		if(!m_friendname.contains(pagename))
			{
			m_friendname.append(pagename);
			addflag = true;
			}

		if(!m_chatingflag)
			{
			tabchat->setTabText(0,pagename);
			m_chatingflag = true;
			}
		else
			{
			 if(addflag)
			 {
			 int number = m_friendname.size();
			 QWidget *tempwidget = new QWidget();
			 
			 tempwidget->setObjectName(m_friendname[number-1]);
			 QVBoxLayout *verticalLayout = new QVBoxLayout(tempwidget);
			 verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
			 QPlainTextEdit *ReceiveTextEdit = new QPlainTextEdit(tempwidget);
			 m_receivetextedit.append(ReceiveTextEdit);		
			 ReceiveTextEdit->setObjectName(QString::fromUtf8("ReceiveTextEdit"));
		     
			 QBrush brush(QColor(180, 188, 255, 255));
		     brush.setStyle(Qt::SolidPattern);
			 QPalette temppalette;
		     QBrush tempbrush(QColor(246, 255, 239, 255));
		     tempbrush.setStyle(Qt::SolidPattern);
		     temppalette.setBrush(QPalette::Active, QPalette::Base, tempbrush);
		     temppalette.setBrush(QPalette::Inactive, QPalette::Base, tempbrush);
		     temppalette.setBrush(QPalette::Disabled, QPalette::Base, brush);
		     ReceiveTextEdit->setPalette(temppalette);
			 verticalLayout->addWidget(ReceiveTextEdit);
			 
			 QFrame *line = new QFrame(tempwidget);
			 line->setObjectName(QString::fromUtf8("line"));
			 line->setFrameShape(QFrame::HLine);
			 line->setFrameShadow(QFrame::Sunken);

			 verticalLayout->addWidget(line);

			 QPlainTextEdit *sendTextEdit = new QPlainTextEdit(tempwidget);
			 sendTextEdit->setObjectName(QString::fromUtf8("sendTextEdit"));
			 m_sendtextedit.append(sendTextEdit);
			 sendTextEdit->setPalette(temppalette);
			 
			 verticalLayout->addWidget(sendTextEdit);
			 QIcon tempicon;
			 tempicon.addFile(QString::fromUtf8(":/newPrefix/Contacts.png"), QSize(), QIcon::Normal, QIcon::Off);
			 tabchat->insertTab(number-1,tempwidget,tempicon,m_friendname[number-1]);
			 tabchat->setTabText(number-1,m_friendname[number-1]);
			 tabchat->setCurrentIndex(m_friendname.size()-1);
			 
			 }
			 else
			 {
			  tabchat->setCurrentIndex(m_friendname.indexOf(pagename));	 
			 }

			}
		    showMaximized();
	}
