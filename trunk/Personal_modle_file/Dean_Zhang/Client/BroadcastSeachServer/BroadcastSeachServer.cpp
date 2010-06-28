/****************************************************************************
**
** Trolltech hereby grants a license to use the Qt/Eclipse Integration
** plug-in (the software contained herein), in binary form, solely for the
** purpose of creating code to be used with Trolltech's Qt software.
**
** Qt Designer is licensed under the terms of the GNU General Public
** License versions 2.0 and 3.0 ("GPL License"). Trolltech offers users the
** right to use certain no GPL licensed software under the terms of its GPL
** Exception version 1.2 (http://trolltech.com/products/qt/gplexception).
**
** THIS SOFTWARE IS PROVIDED BY TROLLTECH AND ITS CONTRIBUTORS (IF ANY) "AS
** IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
** TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
** PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
** OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
** EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
** PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
** PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
** LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
** NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** Since we now have the GPL exception I think that the "special exception
** is no longer needed. The license text proposed above (other than the
** special exception portion of it) is the BSD license and we have added
** the BSD license as a permissible license under the exception.
**
****************************************************************************/

#include "BroadcastSeachServer.h"

BroadcastSeachServer::BroadcastSeachServer(QWidget *parent)
    : QDialog(parent)
{
	qDebug("processPendingDatagrams()>>>");
	//ui = new Ui_BroadcastSeachServer;
	ui.setupUi(this);
	//QString temp="Build Monitor...";

	
	//cout<<"Build Monitor..."<<endl;
	udpSocket = new QUdpSocket(this);
	//udpSocketSearch = new QUdpSocket(this); 
	udpSocket->bind(2021);
	connect(udpSocket,SIGNAL(readyRead()),this,SLOT(processPendingDatagrams()));
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(BroadcastSearch()));
	connect(udpSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));
	//connect(udpSocketSearch,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));
	ui.textBrowser->append("Build Monitor complete");
	qDebug("processPendingDatagrams()<<<");
}

BroadcastSeachServer::~BroadcastSeachServer()
{

}




void BroadcastSeachServer::processPendingDatagrams()//read
	{
	qDebug("processPendingDatagrams()>>>");
	while(udpSocket->hasPendingDatagrams())
		{
			QByteArray datagram;
			int t=udpSocket->pendingDatagramSize();
			datagram.resize(t);
			QHostAddress  TempAddress ;
			    	quint16 TempPort ;
			udpSocket->readDatagram(datagram.data(),datagram.size(),&TempAddress,&TempPort);
			ui.textBrowser->append(tr("received From->IP:%1,Port:%2").arg(TempAddress.toString()).arg(TempPort));
			ui.textBrowser->append(datagram.data());
			QString str(datagram);
		if(checkIPAvailable(str))
			{
			//	ServerAddress=*TempAddress;
			//	ServerPort=*TempPort;
		
		QStringList strList=str.split(":");
		if(!strList[0].isNull())
			{
				ServerAddress.setAddress(strList[0]);
				bool isok=false;
				if(!strList[1].isNull())
					{
						ServerPort=strList[1].toUInt(&isok,10);
						ui.textBrowser->append("Got Server Info succeed");
										ui.textBrowser->append(tr("Server Info->IP:%1,Port:%2").arg(ServerAddress.toString()).arg(ServerPort));
					}
				else
					{	
						ui.textBrowser->append("UnavAilable recv Data");
					}
			}
		else
			{	
				ui.textBrowser->append("UnavAilable recv Data");
			}
		
				
			}
		else
			{	
				ui.textBrowser->append("UnavAilable recv Data");
			}
			//cout<<"received respose:"<<datagram.data()<<endl;
			
		}
	qDebug("processPendingDatagrams()<<<");
	}
void BroadcastSeachServer::BroadcastSearch()
	{
	
	qDebug("BroadcastSearch()>>>");
	
	 QByteArray datagram ;
	 datagram="Server Request";
	 // cout<<"Broadcasting..."<<endl;
	 ui.textBrowser->append("Broadcasting...");
//	udpSocketSearch->writeDatagram(datagram.data(),datagram.size(),QHostAddress::Broadcast,2020);
	 QHostAddress ad;
	 ad.setAddress("172.19.197.80");//QHostAddress::Broadcast
	 qint64 rt ;

	rt= udpSocket->writeDatagram(datagram.data(),ad,2020);
	
	/*
	QByteArray sendData;
		QDataStream out(&sendData, QIODevice::WriteOnly);
		out.setVersion(QDataStream::Qt_4_7);
		QString str = "Server Request";
		out << str;
		QHostAddress ad;
			 ad.setAddress("172.19.197.80");//QHostAddress::Broadcast
		//returnValue is the number of bytes sent on success, otherwise returns -1
		qint64 returnValue = udpSocketSearch->writeDatagram(sendData, ad, 2020);
	*/	
		//qDebug("The value of writeData is: %d", returnValue);
	if(rt<0)
		{
			ui.textBrowser->append("send error");
		}
	qDebug("BroadcastSearch()<<<");
	}

void BroadcastSeachServer::DisplayError(QAbstractSocket::SocketError socketError)
	{
		switch(socketError)
			{
			case 	QAbstractSocket::ConnectionRefusedError:
					ui.textBrowser->append("ConnectionRefusedError");
					break;
			case 	QAbstractSocket::RemoteHostClosedError:
					ui.textBrowser->append("RemoteHostClosedError");
					break;
			case 	QAbstractSocket::HostNotFoundError:
					ui.textBrowser->append("HostNotFoundError");
					break;
			case 	QAbstractSocket::SocketAccessError:
					ui.textBrowser->append("SocketAccessError");
					break;
			case 	QAbstractSocket::SocketResourceError:
					ui.textBrowser->append("SocketResourceError");
					break;
			case 	QAbstractSocket::SocketTimeoutError:
					ui.textBrowser->append("SocketTimeoutError");
					break;
			case 	QAbstractSocket::DatagramTooLargeError:
					ui.textBrowser->append("DatagramTooLargeError");
					break;
			case 	QAbstractSocket::NetworkError:
					ui.textBrowser->append("NetworkError");
					break;
			case 	QAbstractSocket::AddressInUseError:
					ui.textBrowser->append("AddressInUseError");
					break;
			case 	QAbstractSocket::SocketAddressNotAvailableError:
					ui.textBrowser->append("SocketAddressNotAvailableError");
					break;
			case 	QAbstractSocket::UnsupportedSocketOperationError:
					ui.textBrowser->append("UnsupportedSocketOperationError");
					break;
			case 	QAbstractSocket::UnfinishedSocketOperationError:
					ui.textBrowser->append("UnfinishedSocketOperationError");
					break;
								
			default:
				ui.textBrowser->append(tr("Unknow socket Error:%1").arg(socketError));
			}
		
	}

bool BroadcastSeachServer::checkIPAvailable(QString str)
	{
	return true;
	}
