/***********************************************************************************
*Copyright(c)2010     Teleca company.
*All rights reserved.
*
*Name: UdpCS.h
*Description: The header file of use UDP protocol send/receive text 
*             information, it use full-duplex transmission mode, CS means 
*             Client and Server.
*  
*Version: 1.1
*Author:  Johnny Liu
*Date:    July 05, 2010
************************************************************************************/

#ifndef UDPCS_H
#define UDPCS_H

#include <QtGui/QDialog>
#include <QUdpSocket>

class UdpCS : public QDialog
{
    Q_OBJECT

public:   
    /************************************************************************
     * Constructor
     * 
     * @parent: Point to the parent of UdpCS class, default value is NULL.
     * 
     * @localBindPort: The port number of local server, provide for 
     * another client can connect to local server, because this program 
     * is full-duplex transmission mode.
     ***********************************************************************/
    UdpCS(QWidget *parent = 0, int localBindPort = 5825);
	
    ~UdpCS();

signals:
    //In the end of sendDataToServer(), after the data are sended, emit this signal.
    void sendDataFinished();
    
private slots:
    /***********************************************************************
    *Name: sendDataToServer
    * 
    *Function: Use UDP send data to the server. And emit the signal
    *          sendDataFinished() after all the data are sended.
    ************************************************************************/
    void sendDataToServer(QString sendData, int serverPort);
	
    /***********************************************************************
    *Name: receivedData
    *
    *Function: Get all the data in the stream and store them in a variable.
    *
    *Return value: The variable that store the data that get from the stream.          
    ************************************************************************/
    QString receivedData();
    
private:   
    //Disconnect all connect at last
    void disConnectAll();
    
    //Send data socket
    QUdpSocket udpSendSocket;
    
    //Accept data socket
    QUdpSocket udpRecvSocket;
};

#endif // UdpCS_H
