/*
 * CIMServer.h
 *
 *  Created on: 2010-6-19
 *      Author: BenQ
 */

#ifndef CIMSERVER_H_
#define CIMSERVER_H_
#include <QUdpSocket>
#include <QAbstractSocket>


class CIMServer :public QObject
        {
        Q_OBJECT
public:
        CIMServer();
        virtual ~CIMServer();

private slots:
        void processPendingDatagrams();
        void DisplayError(QAbstractSocket::SocketError socketError);
private:
        QUdpSocket *udpSocket;

        };

#endif /* CIMSERVER_H_ */
