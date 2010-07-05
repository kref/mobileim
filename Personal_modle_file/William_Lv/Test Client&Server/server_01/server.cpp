#include "server.h"

server::server()
{
    int a = 0;
    if(!listen(QHostAddress::Any, 3111))
    {
        a = 1;
    }
    nextBlockSize = 0;
}

server::~server()
{
}


void server::incomingConnection(int handle)
{
    QTcpSocket* newConn = new QTcpSocket(this);//this->nextPendingConnection();
    newConn->setSocketDescriptor(handle);
    tcpListMem* mem = new tcpListMem();
    mem->tcpSocket = newConn;
    mem->descriptor = handle;
    connect(mem->tcpSocket, SIGNAL(readyRead()), this, SLOT(readData(int)));
    list.append(*mem);
}

void server::readData(int notuse)
{
    QDataStream in;
    if(!list.isEmpty())
    {
    tcpListMem mem = list.last();
    in.setDevice(mem.tcpSocket);
    in.setVersion(QDataStream::Qt_4_6);
    forever
    {
        if(nextBlockSize == 0)
        {
            if(mem.tcpSocket->bytesAvailable() < sizeof(quint32))
            {
                break;
            }
            in >> nextBlockSize;
        }
        if(nextBlockSize == 0xFFFFFFFF)
        {
          //  closeConnectiont();
            break;
        }
        if(mem.tcpSocket->bytesAvailable() < nextBlockSize)
        {
            break;
        }
        quint32 blockSize = nextBlockSize;
        quint8  blockType = 0;
        quint8  segID = 0;
        quint32 segLen = 0;
        quint8  segNext = 0xFF;
        QString content;
        in.device()->seek(0);
        in >> blockSize >> blockType >> segID >> segLen >> segNext >> content;
        qDebug() <<"block size" <<blockSize;
    }
//    mem.tcpSocket-
    }
}
tcpListMem::tcpListMem()
{}
