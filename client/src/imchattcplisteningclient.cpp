/*
 * imchattcplisteningclient.cpp
 *
 *  Created on: 2010-6-26
 *      Author: Terry.Li
 */

#include "imchattcplisteningclient.h"

ImChatTcpListeningClient::ImChatTcpListeningClient(QObject *parent) : 
QTcpSocket(parent)
	{
    connect(this, SIGNAL(readyRead()), this, SLOT(readClient()));
    connect(this, SIGNAL(disconnected()), this, SLOT(deleteLater()));    
	}

ImChatTcpListeningClient::~ImChatTcpListeningClient()
	{
	// TODO Auto-generated destructor stub
	}
	
void ImChatTcpListeningClient::readClient()    //Read ip and port of client and store them on server
	{	
    QDataStream in(this);
    in.setVersion(QDataStream::Qt_4_7);

    if (bytesAvailable() < sizeof(quint16))
        return;
    
    quint16 blockSize;
    in >> blockSize;
    if (bytesAvailable() < blockSize)
        return;

    quint8 requestType;
    QString messageFromClient;

    in >> requestType;
    if ( requestType == 'M' ) {
    in >> messageFromClient;     
    emit readData(messageFromClient);    
    //close();
    }
	}
    
