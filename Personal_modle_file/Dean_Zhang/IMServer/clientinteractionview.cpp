#include "clientinteractionview.h"
#include "mainwindow.h"

#include <QInputDialog>
#include <QDir>

ClientInterActionView::ClientInterActionView(QWidget *parent): QDialog(parent)
{
    setupUi(this);
 //   radioButton->
  //  tcpRadioBtnSelected=true;
 //   radioButton->setDown(true);
radioButton->setChecked(true);
udpSocket=NULL;
}



ClientInterActionView::~ClientInterActionView()
{
    if(udpSocket!=NULL)
    delete udpSocket;
    udpSocket=NULL;
emit updateTextBrowser("close dialog");
}

void ClientInterActionView::GetClientInfo(clientNode nodeinfo,MyServer* server)
{
   //  this->sock=nodeinfo.sock;
  //  this->name=nodeinfo.name;
   // this-> state=nodeinfo.state;

this->server=server;
connect(this->server,SIGNAL(updateTextBrowserDlg(QString,QString)),this,SLOT(setTextBrowserDlg(QString,QString)));
    this->Info=nodeinfo;
QString t1=this->Info.sock->peerAddress().toString();
    lineEdit->setText(this->Info.sock->peerAddress().toString());
    int port=this->Info.sock->peerPort();
    lineEdit_2->setText(tr("%1").arg(port));



}

void ClientInterActionView::on_pushButton_clicked()
{
    if(textEdit->text()=="")
    {
        textBrowser->append("empty msg");
        return;
    }
 QString sendstr;
        QByteArray sendba=textEdit->text().toAscii();

            if(radioButton->isChecked())//selected tcp mode
            {
                this->Info.sock->write(sendba);
                QString t(sendba);
                sendstr=tr("TCP send:------------>>>\n%1\nsend msg complete------------<<<\n").arg(t);


            }
            else if(radioButton_2->isChecked())//udp mode
            {

                if(udpSocket==NULL)
                {
                    // init udp socket
                   udpSocket=new QUdpSocket(this);
                   udpSocket->bind(this->udpBindPort);
                   connect(udpSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(DisplayError(QAbstractSocket::SocketError)));
                   connect(udpSocket,SIGNAL(readyRead()),this,SLOT(processPendingDatagrams()));
                }

               qint64 rt ;
              rt= udpSocket->writeDatagram(sendba.data(),this->Info.sock->peerAddress(),this->udpPeerPort);
              QString t(sendba);
              sendstr=tr("UDP send:------------>>>\n%1\nsend msg complete------------<<<\n").arg(t);
            }

            textEdit->clear();
            textBrowser->append(sendstr);
             emit updateTextBrowser(sendstr);

}

void ClientInterActionView::on_radioButton_clicked()
{

}

void ClientInterActionView::processPendingDatagrams()
{
    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        int t=udpSocket->bytesAvailable();
        datagram.resize(t);
        QHostAddress  TempAddress ;
        quint16 TempPort ;
        udpSocket->readDatagram(datagram.data(),datagram.size(),&TempAddress,&TempPort);
        QString recvData(datagram);
        textBrowser->append(tr("UDP received  From--------->IP:%1,Port:%2\n%3\n-------------<").arg(TempAddress.toString()).arg(TempPort).arg(recvData));
        emit updateTextBrowser(recvData);
    }
}


void ClientInterActionView::DisplayError(QAbstractSocket::SocketError socketError)
        {
                switch(socketError)
                        {
                        case 	QAbstractSocket::ConnectionRefusedError:
                                        textBrowser->append("ConnectionRefusedError");
                                        emit updateTextBrowser("ConnectionRefusedError");
                                        break;
                        case 	QAbstractSocket::RemoteHostClosedError:
                                        textBrowser->append("RemoteHostClosedError");
                                        emit updateTextBrowser("RemoteHostClosedError");
                                        break;
                        case 	QAbstractSocket::HostNotFoundError:
                                        textBrowser->append("HostNotFoundError");
                                        emit updateTextBrowser("HostNotFoundError");
                                        break;
                        case 	QAbstractSocket::SocketAccessError:
                                        textBrowser->append("SocketAccessError");
                                        emit updateTextBrowser("SocketAccessError");
                                        break;
                        case 	QAbstractSocket::SocketResourceError:
                                        textBrowser->append("SocketResourceError");
                                        emit updateTextBrowser("SocketResourceError");
                                        break;
                        case 	QAbstractSocket::SocketTimeoutError:
                                        textBrowser->append("SocketTimeoutError");
                                        emit updateTextBrowser("SocketTimeoutError");
                                        break;
                        case 	QAbstractSocket::DatagramTooLargeError:
                                        textBrowser->append("DatagramTooLargeError");
                                        emit updateTextBrowser("DatagramTooLargeError");
                                        break;
                        case 	QAbstractSocket::NetworkError:
                                        textBrowser->append("NetworkError");
                                        emit updateTextBrowser("NetworkError");
                                        break;
                        case 	QAbstractSocket::AddressInUseError:
                                        textBrowser->append("AddressInUseError");
                                        emit updateTextBrowser("AddressInUseError");
                                        break;
                        case 	QAbstractSocket::SocketAddressNotAvailableError:
                                        textBrowser->append("SocketAddressNotAvailableError");
                                        emit updateTextBrowser("SocketAddressNotAvailableError");
                                        break;
                        case 	QAbstractSocket::UnsupportedSocketOperationError:
                                        textBrowser->append("UnsupportedSocketOperationError");
                                        emit updateTextBrowser("UnsupportedSocketOperationError");
                                        break;
                        case 	QAbstractSocket::UnfinishedSocketOperationError:
                                        textBrowser->append("UnfinishedSocketOperationError");
                                        emit updateTextBrowser("UnfinishedSocketOperationError");
                                        break;

                        default:
                                textBrowser->append(tr("Unknow socket Error:%1").arg(socketError));
                                emit updateTextBrowser(tr("Unknow socket Error:%1").arg(socketError));
                        }

        }

void ClientInterActionView::setTextBrowserDlg(QString str,QString ip)
{

    if(ip==this->Info.sock->peerAddress().toString())
    textBrowser->append(str);
}

void ClientInterActionView::on_pushButton_2_clicked()
{

    QString str(tr("end socket Ip:%1").arg(this->Info.sock->peerAddress().toString()));
    textBrowser->append(str);
     emit updateTextBrowser(str);
    this->Info.sock->close();
}

void ClientInterActionView::on_pushButton_3_clicked()
{
    this->close();
    delete this;
}

void ClientInterActionView::on_radioButton_2_clicked()
{
    bool ok;
         QString textBindPort = QInputDialog::getText(this, tr("input the bind port"),
                                              tr("bind port:"), QLineEdit::Normal,
                                              "0", &ok);
 bool isOk;
         if (ok && !textBindPort.isEmpty())
         {

            this->udpBindPort=textBindPort.toUInt(&isOk,10);

         }

         if(isOk==false)
                  this->udpBindPort=0;
isOk=false;
         QString textPeerPort = QInputDialog::getText(this, tr("input the peer port"),
                                              tr("peer port:"), QLineEdit::Normal,
                                              "0", &ok);

         if (ok && !textPeerPort.isEmpty())
         {

            this->udpPeerPort=textPeerPort.toUInt(&isOk,10);
         }

if(isOk==false)
          this->udpPeerPort=0;







}
