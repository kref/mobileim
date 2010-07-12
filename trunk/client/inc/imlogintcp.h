/*
 * imlogintcp.h
 *
 *  Created on: Jun 24, 2010
 *      Author: cninteli
 */

#ifndef IMLOGINTCP_H
#define IMLOGINTCP_H

#include <QTcpSocket>
#include <QString>

class ImLoginTcp : public QObject
	{	
	Q_OBJECT
	
public:
	ImLoginTcp();
	virtual ~ImLoginTcp();

public: // New function
	bool isConnnected();	
	void connectToHost();
	void sendData(const QString &message);
	
signals:
    void connected();
    void connectError(const QString &connectErr);    
    void disconnected();
    void readData(const QString &message);

public slots:
    void notifyConnected();
    void notifyConnectError(const QString &connectErr);
    void notifyDisconnected();
    void notifyReadData();

private: // New function
    void close();
    
private: // New data
    QTcpSocket m_tcpScoket;
    
	};

#endif /* IMLOGINTCP_H */
