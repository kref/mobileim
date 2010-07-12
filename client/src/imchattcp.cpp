/*
 * tcpsocketclient.cpp
 *
 *  Created on: Jun 24, 2010
 *      Author: cninteli
 */
#include <QHostAddress>
#include <QAbstractSocket>

#include "imchattcp.h"

ImChatTcp::ImChatTcp()
	{
	connect(&m_tcpScoket, SIGNAL(connected()), this, SLOT(notifyConnected()));
	connect(&m_tcpScoket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(notifyConnectError(QString)));
	connect(&m_tcpScoket, SIGNAL(disconnected()), this, SLOT(notifyDisconnected()));
	connect(&m_tcpScoket, SIGNAL(readyRead()), this, SLOT(notifyReadMessage()));
	}

ImChatTcp::~ImChatTcp()
	{		
	close();
	}

bool ImChatTcp::isConnnected()
	{	
	// QTcpSocket::isValid:
    // Returns true if the socket is valid and ready for use; otherwise returns false.
	// Note: The socket's state must be ConnectedState before reading and writing can occur.
	
	return m_tcpScoket.isValid();
	}

void ImChatTcp::close()
	{		
	//QTcpSocket::isOpen
    //Returns true if the device is open; otherwise returns false. 
	//A device is open if it can be read from and/or written to. 
	//By default, this function returns false if openMode() returns NotOpen.
	if (m_tcpScoket.isOpen())
	    m_tcpScoket.close();
	
	m_tcpScoket.disconnectFromHost();
	}

void ImChatTcp::connectToClient(const QString &ip)
	{			
	m_tcpScoket.connectToHost(ip, 6665);	
	}

void ImChatTcp::sendMessage(const QString &message)
	{		
	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_7);
	out << quint16(0) << quint8('M') << message;

	out.device()->seek(0);
    out << quint16(block.size() - sizeof(quint16));
	    
	//QTcpSocket::write
	//Writes the content of byteArray to the device. 
	//Returns the number of bytes that were actually written, or -1 if an error occurred.
	qint64 result = m_tcpScoket.write(block);
	}

void ImChatTcp::notifyConnected()
	{	
	emit connected();
	}

void ImChatTcp::notifyConnectError(const QString &connectErr)
	{		
	emit connectError(connectErr);
	}

void ImChatTcp::notifyDisconnected()
	{	
	emit disconnected();
	}

void ImChatTcp::notifyReadMessage()
	{		
	QDataStream in(&m_tcpScoket);
	in.setVersion(QDataStream::Qt_4_7);

    if (m_tcpScoket.bytesAvailable() < sizeof(quint16)){    
    return;
    }
    
    quint16 blockSize; 
    in >> blockSize;
    
    if (m_tcpScoket.bytesAvailable() < blockSize){    
    return;
    }
    
    quint8 requestType;
    in >> requestType;
    
    if (requestType == 'M'){
    QString chatMessage;
    in >> chatMessage;  
    emit readMessage(chatMessage);
    }     	
	}
