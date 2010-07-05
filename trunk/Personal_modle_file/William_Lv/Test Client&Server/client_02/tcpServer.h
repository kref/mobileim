/*
 * tcpServer.h
 *
 *  Created on: 2010-6-6
 *      Author: Administrator
 */

#ifndef TCPSERVER_H_
#define TCPSERVER_H_
#include "QTcpServer"
#define MAX_CLIENT_NUM 10
static quint16 clientNum = 0;

class tcpServer:public QTcpServer
	{
	Q_OBJECT
public:
	tcpServer();
	virtual ~tcpServer();
	const static quint16 maxClientNum = MAX_CLIENT_NUM;
private:
	void incomingConnection(int descriptor);
	};

#endif /* TCPSERVER_H_ */


