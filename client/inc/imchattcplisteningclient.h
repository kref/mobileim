/*
 * imchattcplisteningclient.h
 *
 *  Created on: 2010-6-26
 *      Author: Terry.Li
 */

#ifndef IMCHATTCPLISTENINGCLIENT_H
#define IMCHATTCPLISTENINGCLIENT_H

#include <QTcpSocket>

class ImChatTcpListeningClient : public QTcpSocket
	{
	Q_OBJECT
	
public:
	ImChatTcpListeningClient(QObject *parent = 0);
	virtual ~ImChatTcpListeningClient();

public: // New function
	void replyClient(); // Reply client with other client information(ip and port)

signals:
    void readData(const QString &message);
	
public slots:
    void readClient();    //Read ip and port of client and store them on server
	};

#endif /* IMCHATTCPLISTENINGCLIENT_H */
