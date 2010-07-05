/***********************************************************************************
*Copyright(c)2010     Teleca company.
*All rights reserved.¡¡
*
*Name: UdpCS.cpp
*Description: Implement of use UDP send/receive text information, 
*             it use full-duplex transmission mode.                                                   
*
*Version: 1.1
*Author:  Johnny Liu
*Date:    July 05, 2010
************************************************************************************/

#include <QtGui>
#include <QtNetwork>
#include "UdpCS.h"

//Constructor
UdpCS::UdpCS(QWidget *parent, int localBindPort)
    : QDialog(parent)
    {	
	udpRecvSocket.bind(localBindPort);	
	
	//If have accepted data, process them
	connect(&udpRecvSocket, SIGNAL(readyRead()), this, SLOT(receivedData()));
    }

//Send the QString sendData to the No. serverPort port of the server
void UdpCS::sendDataToServer(QString sendData, int serverPort)
	{	
	//We only can send the QByteArray type data in stream.
	QByteArray barrSendData; 
	QDataStream out(&barrSendData, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_7);
	
	QString str = sendData; 
	out << str;
	
	//returnValue is the number of bytes number that sent success, otherwise returns -1
	qint64 returnValue = udpSendSocket.writeDatagram(barrSendData, 
			QHostAddress::LocalHost, serverPort);
	
	qDebug("The value of writeData is: %d", returnValue);
	
	//If returnValur is -1, then pop up a warning box
	if (returnValue == -1) {
	QMessageBox msgBox;
		
	msgBox.setText(tr("Udp send data failed!"));
	msgBox.setStandardButtons(QMessageBox::Ok);
	
	//Modal dialog
	int ret = msgBox.exec();
	}
	
	//After the data have writed success, emit send data finish signal
	emit sendDataFinished();
	}

//Process the data that received from stream, add them in the return variable: strReceivedData
QString UdpCS::receivedData()
	{
	QByteArray barrDatagram;
	
	do {
	    barrDatagram.resize(udpRecvSocket.pendingDatagramSize());
	    udpRecvSocket.readDatagram(barrDatagram.data(), barrDatagram.size());
	} while (udpRecvSocket.hasPendingDatagrams());
	
	//Store the data that get from the stream
	QString strReceivedData;
	
	//Input received data into strReceivedData
	QDataStream in(&barrDatagram, QIODevice::ReadOnly);
	in.setVersion(QDataStream::Qt_4_7);
	in >> strReceivedData;
	
	return strReceivedData;
	}

//Disconnect all connect at last
void UdpCS::disConnectAll()
	{
	disconnect(&udpRecvSocket, SIGNAL(readyRead()), this, SLOT(processData()));			
	}

//Destructor
UdpCS::~UdpCS()
    { 
    disConnectAll();
    }
