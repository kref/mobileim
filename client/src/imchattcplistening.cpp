/*
 * imchattcplistening.cpp
 *
 *  Created on: 2010-6-26
 *      Author: Terry.Li
 */

#include "imchattcplistening.h"
#include "qdebug.h"

ImChatTcpListening::ImChatTcpListening(QObject *parent) :
QTcpServer(parent)
	{
	socket = new ImChatTcpListeningClient(this);
	connect(socket, SIGNAL(readData(QString)), this, SLOT(receiveData(QString)));	
	
	if (!listen(QHostAddress::Any, 6665)) {        
	    qDebug("Terry <> Failed to listen port in ImClient::startListeningClient()");
	}
	}

ImChatTcpListening::~ImChatTcpListening()
	{
	
	}

void ImChatTcpListening::incomingConnection(int socketId)
	{
    socket->setSocketDescriptor(socketId); 
	}

void ImChatTcpListening::receiveData(const QString &message)
	{	
	emit notfiyReceiveData(message);
	}
