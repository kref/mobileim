/*
 * imchattcplistening.h
 *
 *  Created on: 2010-6-26
 *      Author: Terry.Li
 */

#ifndef IMCHATTCPLISTENING_H
#define IMCHATTCPLISTENING_H

#include <QTcpServer>
#include "imchattcplisteningclient.h"

class ImChatTcpListening : public QTcpServer
	{
	Q_OBJECT
	
public:
	ImChatTcpListening(QObject *parent = 0);
	virtual ~ImChatTcpListening();
	
void incomingConnection(int socketId);

signals:
    void notfiyReceiveData(const QString &message);
    
public slots:
    void receiveData(const QString &message);
    
private:
    ImChatTcpListeningClient *socket;
	};

#endif /* IMCHATTCPLISTENING_H */
