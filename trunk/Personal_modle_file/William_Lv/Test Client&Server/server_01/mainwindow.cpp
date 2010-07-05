#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ser = new server();
    connect(ser, SIGNAL(newConnection()), this, SLOT(newConn()));
    connect(ui->buttonResetRecord, SIGNAL(clicked()), this, SLOT(resetConnRecord()));
    connect(ui->buttonExit, SIGNAL(clicked()), this, SLOT(close()));
    nextBlockSize = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::newConn()
{
    ui->editConnRecord->appendPlainText("new conncetion..\0");

    if(!ser->list.isEmpty())
    {

    tcpListMem mem = ser->list.last();
    ui->editConnRecord->appendPlainText(mem.tcpSocket->peerAddress().toString());
    connect(mem.tcpSocket, SIGNAL(readyRead()), this, SLOT(readData()));
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_6);

    quint32 blockSize = 0;
    quint8  blockType = 0;
    quint8  segID = 0;
    quint32 segLen = 0;
    quint8  segNext = 0;
    QString content("Hello");
    segLen = content.size() + sizeof(segLen) + sizeof(segID);
    out<<blockSize<<blockType<<segID<<segLen<<segNext<<content;
    out.device()->seek(0);
    out<<quint32(block.size() - sizeof(quint32));
    ser->list.first().tcpSocket->write(block);
    }
}


void MainWindow::resetConnRecord()
{
    ui->editConnRecord->clear();
    ser->list.clear();
}
void MainWindow::readData()
{
    QDataStream in;
    bool readOk = false;
    QString content;
    tcpListMem mem;
    QTime a;
    if(!ser->list.isEmpty())
    {
    mem = ser->list.last();
    if(mem.tcpSocket)
    {
        in.setDevice(mem.tcpSocket);
        in.setVersion(QDataStream::Qt_4_6);
    }
    else
    {
        return;
    }
   forever
    {
        if(nextBlockSize == 0)
        {
            if(mem.tcpSocket->bytesAvailable() < sizeof(quint32))
            {   
                break;
            }
            qDebug()<<"Client send"<< mem.tcpSocket->bytesAvailable() <<"bytes";
            in >> nextBlockSize;
            qDebug()<<"nextBlockSize : " <<nextBlockSize;
        }
        if(nextBlockSize == 0xFFFFFFFF)
        {
          //  closeConnectiont();
            readOk = true;
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
        quint8  segNext = 0;

//        in.device()->seek(0);
        in >> blockType >> segID >> segLen >> segNext >> content;
        qDebug() <<"block size" <<blockSize << "content is " << content;
        nextBlockSize = 0;
    }
//    mem.tcpSocket-
    }
    if(!content.isEmpty())
    {
       ui->editMsg->appendPlainText("Time: "
               + a.currentTime().toString() + "  " + mem.tcpSocket->peerAddress().toString()
               + " say :" + content);
       nextBlockSize = 0;
    }
}
