#include "myserver.h"
#include <QTcpSocket>



#include <iostream>
using namespace std;


MyServer::MyServer()
{
//myui=
cout<<"Build Server..."<<endl;
//textBrowser->append("Build Server...");
//myui->textBrowser->append("Build Server...");
//emit updateTextBrowser("Build Server...");
}



bool MyServer::BuildServer()
{
emit updateTextBrowser("Build Server...");

    tcpServer = new QTcpServer(this);

    if(!tcpServer->listen(QHostAddress::Any,6666))
    {
        cout<<"listen error:"<<tcpServer->errorString().data()<<endl;
emit updateTextBrowser(tr("listen error:%1").arg(tcpServer->errorString()));

        return false;
    }

    connect(tcpServer,SIGNAL(newConnection()),this,SLOT(Accept()));

    cout<<"Accepting... ..."<<endl;
  emit updateTextBrowser("Accepting... ...");

return true;

}


void  MyServer::Accept()
{
    cout<<"accept a connect"<<endl;
   emit updateTextBrowser("accept a connect");
    QTcpSocket *clientSocket = tcpServer->nextPendingConnection();
    //add node to socket list
    //ClientList.append(clientSocket);
    connect(clientSocket,SIGNAL(disconnected()),this,SLOT(OnDisconnected()));
    connect(clientSocket,SIGNAL(readyRead()),this,SLOT(Service()));
    connect(clientSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(DisplayError(QAbstractSocket::SocketError)));
    cout<<"accept client IP:"<<qPrintable(clientSocket->peerAddress().toString())<<" Port:"<<clientSocket->peerPort()<<" Name:"<<qPrintable(clientSocket->peerName())<<endl;
//emit updateTextBrowser(tr("accept client IP:%1,Port:%2, Name:%3").arg(clientSocket->peerAddress().toString(),clientSocket->peerPort(),clientSocket->peerName()));
    QString ipInfo(clientSocket->peerAddress().toString());
    QString portInfo(tr("%1").arg(clientSocket->peerPort()));
    QString nameInfo(clientSocket->peerName());
  emit updateTextBrowser(tr("accept client IP:%1,Port:%2, Name:%3").arg(ipInfo,portInfo,nameInfo));
}

//multi-socket's signal call the same slot
void MyServer::Service()
{

   // QTcpSocket currentSock;

    /*
    //slot's ::sender == this.sender
    //estimate the sender of client
    QListIterator<QTcpSocket*> L(ClientList);

    while(L.hasNext())
    {
        QTcpSocket *currentSock= L.next();

        if(currentSock->objectName()== this->sender()->objectName())
        {

           // currentSock=*tempSock;
            cout<<"from "<<qPrintable(currentSock->peerAddress().toString())<<"->Port:"<<currentSock->peerPort()<<" Name:"<<qPrintable(currentSock->peerName())<<endl;
            QByteArray recvData=currentSock->read(1024);
            cout<<"RecvData:"<<recvData.data()<<endl;
            //here can use thread to do something if it cost too much time such as search the list
            break;
        }

    }

*/

   cout<<"receive message----------->>>"<<endl;
emit updateTextBrowser("receive message----------->>>");
    QTcpSocket *currentSock = qobject_cast<QTcpSocket *>(sender());

    cout<<"IP:"<<qPrintable(currentSock->peerAddress().toString())<<" Port:"<<currentSock->peerPort()<<" Name:"<<qPrintable(currentSock->peerName())<<endl;
    QString ipInfo(currentSock->peerAddress().toString());
QString portInfo(tr("%1").arg(currentSock->peerPort()));
QString nameInfo(currentSock->peerName());
    emit updateTextBrowser(tr(" client IP:%1,Port:%2, Name:%3").arg(ipInfo,portInfo,nameInfo));

    QByteArray recvData=currentSock->read(1024);
    QString temp(recvData);
    cout<<"RecvData:"<<recvData.data()<<endl;
  emit updateTextBrowser(tr("RecvData-------->:\n%1\n---------<").arg(temp));
  emit updateTextBrowserDlg(tr("RecvData-------->:\n%1\n---------<").arg(temp),currentSock->peerAddress().toString());


    QString str(recvData);
    int outputData=-1;
    if(ParseData(str,&outputData))
    {
        switch(outputData)
        {
        case online:
            if(ClientOnline(currentSock))
            {
                cout<<"client online succeed"<<endl;
                emit updateTextBrowser("client online succeed");
            }
            else
            {
                cout<<"client online failed"<<endl;
                 emit updateTextBrowser("client online failed");
            }

            break;
        case offline:
            if(ClientOffline(currentSock))
            {
                cout<<"client offline succeed"<<endl;
                 emit updateTextBrowser("client offline succeed");
            }
            else
            {
                cout<<"client offline failed"<<endl;
           emit updateTextBrowser("client offline failed");
             }
            currentSock->close();
            break;
        case talking:
            if(talk(currentSock))
            {
                cout<<"client talk succeed"<<endl;
               emit updateTextBrowser("client talk succeed");
            }
            else
            {
                cout<<"client talk failed"<<endl;
           emit updateTextBrowser("client talk failed");
             }
           break;
        default:
            cout<<"unknown request"<<endl;
          emit updateTextBrowser("unknown request");
        }

    }
    else// no available data
    {
        cout<<"no available data"<<endl;
       emit updateTextBrowser("no available data");
    }





    //get sender's socket and we can communicate with it
    //thread process-->moveToThread   thread
emit updateTextBrowser("receive complete-----------------<<<");
cout<<"service complete-----------------<<<"<<endl;
 emit updateTextBrowser("service complete-----------------<<<");
}



void MyServer::DisplayError(QAbstractSocket::SocketError socketError)
        {
            cout<<"socket error occured "<<endl;
emit updateTextBrowser("socket error occured");
             QTcpSocket *currentSock = qobject_cast<QTcpSocket *>(sender());
             cout<<"IP "<<qPrintable(currentSock->peerAddress().toString())<<"->Port:"<<currentSock->peerPort()<<" Name"<<qPrintable(currentSock->peerName())<<endl;
             QString ipInfo(currentSock->peerAddress().toString());
QString portInfo(tr("%1").arg(currentSock->peerPort()));
QString nameInfo(currentSock->peerName());
          emit updateTextBrowser(tr("IP:%1,Port:%2, Name:%3").arg(ipInfo,portInfo,nameInfo));


             cout<<"error:"<<qPrintable(currentSock->errorString())<<endl;
emit updateTextBrowser(tr("error:%1").arg(currentSock->errorString()));



                switch(socketError)
                        {
                        case 	QAbstractSocket::ConnectionRefusedError:
                                        cout<<"ConnectionRefusedError"<<endl;
                                    emit updateTextBrowser("ConnectionRefusedError");
                                        break;
                        case 	QAbstractSocket::RemoteHostClosedError:
                                cout<<"RemoteHostClosedError"<<endl;
                             emit updateTextBrowser("RemoteHostClosedError");
                                if(ClientOffline(currentSock))
                                {
                                    cout<<"client socket "<<qPrintable(currentSock->peerAddress().toString())<<" offline succeed"<<endl;
                                    emit updateTextBrowser(tr("client socket %1 offline succeed").arg(currentSock->peerAddress().toString()));

                                }
                                else
                                {
                                    cout<<"client socket "<<qPrintable(currentSock->peerAddress().toString())<<" offline failed"<<endl;
                               emit updateTextBrowser(tr("client socket %1 offline failed").arg(currentSock->peerAddress().toString()));
                                }
                                currentSock->close();
                                        break;
                        case 	QAbstractSocket::HostNotFoundError:
                                cout<<"HostNotFoundError"<<endl;
                              emit updateTextBrowser("HostNotFoundError");
                                        break;
                        case 	QAbstractSocket::SocketAccessError:
                                cout<<"SocketAccessError"<<endl;
                              emit updateTextBrowser("SocketAccessError");
                                        break;
                        case 	QAbstractSocket::SocketResourceError:
                                cout<<"SocketResourceError"<<endl;
                             emit updateTextBrowser("SocketResourceError");
                                        break;
                        case 	QAbstractSocket::SocketTimeoutError:
                                cout<<"SocketTimeoutError"<<endl;
                             emit updateTextBrowser("SocketTimeoutError");
                                        break;
                        case 	QAbstractSocket::DatagramTooLargeError:
                                cout<<"DatagramTooLargeError"<<endl;
                             emit updateTextBrowser("DatagramTooLargeError");
                                        break;
                        case 	QAbstractSocket::NetworkError:
                                cout<<"NetworkError"<<endl;
                             emit updateTextBrowser("NetworkError");
                                        break;
                        case 	QAbstractSocket::AddressInUseError:
                                cout<<"AddressInUseError"<<endl;
                             emit updateTextBrowser("AddressInUseError");
                                        break;
                        case 	QAbstractSocket::SocketAddressNotAvailableError:
                                cout<<"SocketAddressNotAvailableError"<<endl;
                            emit updateTextBrowser("SocketAddressNotAvailableError");
                                        break;
                        case 	QAbstractSocket::UnsupportedSocketOperationError:
                                cout<<"UnsupportedSocketOperationError"<<endl;
                           emit updateTextBrowser("UnsupportedSocketOperationError");
                                        break;
                        case 	QAbstractSocket::UnfinishedSocketOperationError:
                                cout<<"UnfinishedSocketOperationError"<<endl;
                            emit updateTextBrowser("UnfinishedSocketOperationError");
                                        break;
                        default :
                                cout<<"Unknown socket error:"<<socketError<<endl;
                           emit updateTextBrowser(tr("Unknown socket error %1").arg(socketError));



                        }

        }

void MyServer::OnDisconnected()
{
    QTcpSocket *currentSock = qobject_cast<QTcpSocket *>(sender());
    cout<<"disconnected a connection:";
 emit updateTextBrowser("disconnected a connection:");
    cout<<"IP:"<<qPrintable(currentSock->peerAddress().toString())<<"->Port:"<<currentSock->peerPort()<<" Name"<<qPrintable(currentSock->peerName())<<endl;
    QString ipInfo(currentSock->peerAddress().toString());
QString portInfo(tr("%1").arg(currentSock->peerPort()));
QString nameInfo(currentSock->peerName());
 emit updateTextBrowser(tr("IP:%1,Port:%2, Name:%3").arg(ipInfo,portInfo,nameInfo));


    if(ClientOffline(currentSock))
    {
        cout<<"client socket "<<qPrintable(currentSock->peerAddress().toString())<<" offline succeed"<<endl;
 emit updateTextBrowser(tr("client socket %1 offline succeed").arg(currentSock->peerAddress().toString()));
    }
    else
    {
        cout<<"client socket "<<qPrintable(currentSock->peerAddress().toString())<<" offline failed"<<endl;
  emit updateTextBrowser(tr("client socket %1 offline failed").arg(currentSock->peerAddress().toString()));

    }





    currentSock->close();


}

bool MyServer::ClientOffline(QTcpSocket *sock)
{
    cout<<"execute client offline"<<endl;
emit updateTextBrowser("execute client offline");

    QListIterator<clientNode*> L(ClientList);

    while(L.hasNext())
    {
        clientNode *tempNode=L.next();

        if(tempNode->sock == sock)
        {
             cout<<"found appointed Node"<<endl;
        emit updateTextBrowser("found appointed Node");
            //do offline
            ClientList.removeOne(tempNode);
//ui->listWidget->findItems(tempNode->sock->peerAddress().toString());
//QListWidgetItem *aItem= ui->listWidget->findItems(tempNode->sock->peerAddress().toString());
           // ui->listWidget->removeItemWidget(*aItem);
          //  ui->listWidget->takeItem(aItem);
            emit deletefromListWidget(tempNode->sock->peerAddress().toString());

    //        L.toFront();//reset the list
                QListIterator<clientNode*> List(ClientList);
            //transmit online info to other in the node list
            while(List.hasNext())
            {
                clientNode *tempNode=List.next();
                QByteArray offlineData(sock->peerAddress().toString().toAscii());
                offlineData+="-->offline";
                cout<<"send:"<<offlineData.data()<<endl;
                QString temp(offlineData);
          emit updateTextBrowser(tr("send: %1").arg(temp));
               int rt= tempNode->sock->write(offlineData.data());
                if(rt>0)
                {
                    cout<<qPrintable(sock->peerAddress().toString())<<"-->"<<qPrintable(tempNode->sock->peerAddress().toString())<<"send data complete"<<endl;
            emit updateTextBrowser(tr("%1 --> %2 send data complete").arg(sock->peerAddress().toString(),tempNode->sock->peerAddress().toString()));
                }
                else
                {
                    cout<<qPrintable(sock->peerAddress().toString())<<"-->"<<qPrintable(tempNode->sock->peerAddress().toString())<<"send data failed"<<endl;
            emit updateTextBrowser(tr("%1 --> %2 send data failed").arg(sock->peerAddress().toString(),tempNode->sock->peerAddress().toString()));
                }
            }

            return true;
        }


    }
    cout<<"no exist Node, return false"<<endl;
  emit updateTextBrowser("no exist Node, return false");
    return false;
}

bool MyServer::ClientOnline(QTcpSocket *sock)
{
    cout<<"execute client online"<<endl;
   emit updateTextBrowser("execute client online");

    QListIterator<clientNode*> L(ClientList);
   // bool isFound=false;
    while(L.hasNext())
    {
        clientNode *tempNode=L.next();

        if(tempNode->sock==sock)
        {
             cout<<"found appointed Node"<<endl;
     emit updateTextBrowser("found appointed Node");
             cout<<"this socket already exist,return false"<<endl;
     emit updateTextBrowser("this socket already exist,return false");
             return false;
        }
    }
L.toFront();
    //transmit online info to other in the node list
    while(L.hasNext())
    {
        clientNode *tempNode=L.next();
        QByteArray onlineData(sock->peerAddress().toString().toAscii());
         onlineData+="-->online";
       int rt= tempNode->sock->write(onlineData.data());
       cout<<"send:"<<onlineData.data()<<endl;
       QString temp(onlineData);
     emit updateTextBrowser(tr("send: %1").arg(temp));
        if(rt>0)
        {
            cout<<qPrintable(sock->peerAddress().toString())<<"-->"<<qPrintable(tempNode->sock->peerAddress().toString())<<"send data complete"<<endl;
     emit updateTextBrowser(tr("%1 --> %2 send data complete").arg(sock->peerAddress().toString(),tempNode->sock->peerAddress().toString()));
        }
        else
        {
            cout<<qPrintable(sock->peerAddress().toString())<<"-->"<<qPrintable(tempNode->sock->peerAddress().toString())<<"send data failed"<<endl;
     emit updateTextBrowser(tr("%1 --> %2 send data failed").arg(sock->peerAddress().toString(),tempNode->sock->peerAddress().toString()));
        }
    }

    clientNode *client=new clientNode;
    client->sock=sock;
  //  client->sock=
    ClientList.append(client);
//ui->listWidget->addItem(client->sock->peerAddress().toString());
emit addtoListWidget(client->sock->peerAddress().toString());
    return true;
}
bool MyServer::ParseData(QString str,int *output)
{
    cout<<"execute ParseData"<<endl;
  emit updateTextBrowser("execute ParseData");
    if(str=="online")
    {
        *output=online;
        return true;
    }
    else if(str=="offline")
    {
        *output=offline;
        return true;
    }
    else if(str=="talking")
    {
        *output=talking;
        return true;
    }

    cout<<"can not parse Data unknown data??"<<endl;
 emit updateTextBrowser("can not parse Data unknown data??");
    return false;
}

 bool MyServer::talk(QTcpSocket *sock)
 {
     //transmit online info to other in the node list
     QListIterator<clientNode*> L(ClientList);
     while(L.hasNext())
     {
         clientNode *tempNode=L.next();

         if(tempNode->sock==sock)
             continue;
         QByteArray talkData(sock->peerAddress().toString().toAscii());
         talkData+="talking";
        int rt= tempNode->sock->write(talkData.data());
        cout<<"send:"<<talkData.data()<<endl;
        QString temp(talkData);
 emit updateTextBrowser(tr("send: %1").arg(temp));
         if(rt>0)
         {
             cout<<qPrintable(sock->peerAddress().toString())<<"-->"<<qPrintable(tempNode->sock->peerAddress().toString())<<"send data complete"<<endl;
 emit updateTextBrowser(tr("%1 --> %2 send data complete").arg(sock->peerAddress().toString(),tempNode->sock->peerAddress().toString()));

         }
         else
         {
             cout<<qPrintable(sock->peerAddress().toString())<<"-->"<<qPrintable(tempNode->sock->peerAddress().toString())<<"send data failed"<<endl;
   emit updateTextBrowser(tr("%1 --> %2 send data failed").arg(sock->peerAddress().toString(),tempNode->sock->peerAddress().toString()));

         }
     }
     return true;
 }

 clientNode MyServer::GetNodeInfoFromIP(QString ip)
 {
     QListIterator<clientNode*> L(ClientList);
     while(L.hasNext())
     {
         clientNode *tempNode=L.next();
        if(ip==tempNode->sock->peerAddress().toString())
        {
          return *tempNode;
        }
     }
 }

















