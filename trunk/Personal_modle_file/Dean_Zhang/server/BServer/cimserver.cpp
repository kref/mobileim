/*
 * CIMServer.cpp
 *
 *  Created on: 2010-6-19
 *      Author: BenQ
 */

#include "CIMServer.h"
#include <QHostInfo>
 #include <QHostAddress>
#include <QAbstractSocket>
#include <iostream>
using namespace std;

CIMServer::CIMServer()
        {
        // TODO Auto-generated constructor stub
        udpSocket = new QUdpSocket(this);

        udpSocket->bind(2020);
                connect(udpSocket,SIGNAL(readyRead()),this,SLOT(processPendingDatagrams()));
                connect(udpSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));
                cout<<"***Server build***"<<endl;
        }

CIMServer::~CIMServer()
        {
        // TODO Auto-generated destructor stub
        }

void CIMServer::processPendingDatagrams()
        {
        while(udpSocket->hasPendingDatagrams())
                {
                                QByteArray datagram;
                                int t=udpSocket->pendingDatagramSize();
                                datagram.resize(t);
                                //datagram.resize(1024);
                                QHostAddress  TempAddress ;
                                quint16 TempPort ;

                                udpSocket->readDatagram(datagram.data(),datagram.size(),&TempAddress,&TempPort);




                                cout<<"received :"<<datagram.data()<<endl;
                                QString str(datagram);
                                if(str=="Server Request")
                                {
                        //	QHostInfo info;
                                QHostInfo info=QHostInfo::fromName(QHostInfo::localHostName());
                                if (!info.addresses().isEmpty())
                                        {
                                        QHostAddress address = info.addresses().first();
                                        //QString
                                        QByteArray sendData=address.toString().toAscii();
                                //QByteArray sendData=TempAddress.toString().toAscii();
                        //	QString tp=QString::number(qlonglong(TempPort),10));
                        //int t= (int)TempPort;
                        QString tp=QString::number(2020,10);
                                        sendData+=":";
                                        sendData+=tp.toAscii();
                                        cout<<"respose data:"<<sendData.data()<<endl;
                                        udpSocket->writeDatagram(sendData.data(),TempAddress,TempPort);
                                        cout<<"respose IP Info complete"<<endl;
                                        }


                                }
                                else
                                        {
                                                cout<<"bad data received"<<endl;
                                        }

                }

        }

void CIMServer::DisplayError(QAbstractSocket::SocketError socketError)
        {
                switch(socketError)
                        {
                        case 	QAbstractSocket::ConnectionRefusedError:
                                        cout<<"ConnectionRefusedError"<<endl;
                                        break;
                        case 	QAbstractSocket::RemoteHostClosedError:
                                cout<<"RemoteHostClosedError"<<endl;
                                        break;
                        case 	QAbstractSocket::HostNotFoundError:
                                cout<<"HostNotFoundError"<<endl;
                                        break;
                        case 	QAbstractSocket::SocketAccessError:
                                cout<<"SocketAccessError"<<endl;
                                        break;
                        case 	QAbstractSocket::SocketResourceError:
                                cout<<"SocketResourceError"<<endl;
                                        break;
                        case 	QAbstractSocket::SocketTimeoutError:
                                cout<<"SocketTimeoutError"<<endl;
                                        break;
                        case 	QAbstractSocket::DatagramTooLargeError:
                                cout<<"DatagramTooLargeError"<<endl;
                                        break;
                        case 	QAbstractSocket::NetworkError:
                                cout<<"NetworkError"<<endl;
                                        break;
                        case 	QAbstractSocket::AddressInUseError:
                                cout<<"AddressInUseError"<<endl;
                                        break;
                        case 	QAbstractSocket::SocketAddressNotAvailableError:
                                cout<<"SocketAddressNotAvailableError"<<endl;
                                        break;
                        case 	QAbstractSocket::UnsupportedSocketOperationError:
                                cout<<"UnsupportedSocketOperationError"<<endl;
                                        break;
                        case 	QAbstractSocket::UnfinishedSocketOperationError:
                                cout<<"UnfinishedSocketOperationError"<<endl;
                                        break;
                        default :
                                cout<<"Unknown socket error:"<<socketError<<endl;
                                ;


                        }

        }
