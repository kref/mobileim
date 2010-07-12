/*
 * imchattcp.h
 *
 *  Created on: Jun 24, 2010
 *      Author: cninteli
 */

#ifndef IMCHATTCP_H
#define IMCHATTCP_H

#include <QTcpSocket>
#include <QString>

class ImChatTcp : public QObject
	{	
	Q_OBJECT
	
public:
	ImChatTcp();
	virtual ~ImChatTcp();

public: // New function
	bool isConnnected();	
	void connectToClient(const QString &ip);
	void sendMessage(const QString &message);
	
signals:
    void connected();
    void connectError(const QString &connectErr);    
    void disconnected();
    void readMessage(const QString &message);

public slots:
    void notifyConnected();
    void notifyConnectError(const QString &connectErr);
    void notifyDisconnected();
    void notifyReadMessage();

private: // New function
    void close();
    
private: // New data
    QTcpSocket m_tcpScoket;
    
	};

#endif /* IMCHATTCP_H */
