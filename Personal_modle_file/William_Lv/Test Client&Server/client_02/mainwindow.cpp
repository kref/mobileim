#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_dialog.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    tcpSocket = new QTcpSocket(this);
    m_SerAdd.setAddress(QHostAddress::LocalHost);
    m_SerPort = 3111;
    tcpSocket->connectToHost(m_SerAdd, m_SerPort);
    QAbstractSocket::SocketState state = tcpSocket->state();
    ui->setupUi(this);
    nextBlockSize = 0;
    createMenu();
    createComponent();
    createLayout();
    connectAll();
    once = false;
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

void MainWindow::createComponent()
{
	QHostInfo info;
	QList<QHostAddress> add;
	add = info.addresses();
    msgEdit = new QTextEdit;
    msgEdit->setReadOnly(true);
    if(!add.isEmpty())
    	{
		msgEdit->setText(add.first().toString());
    	}
    QNetworkInterface* netInterface = new QNetworkInterface;
    QNetworkInterface::InterfaceFlags a = netInterface->flags();
    QString hdadd = netInterface->hardwareAddress();
    QList<QNetworkAddressEntry> aa;
    aa = netInterface->addressEntries();
    if(!hdadd.isEmpty())
    	{
		msgEdit->setText(hdadd);
    	}
    infoLabel = new QLabel;
    infoLabel->setText(tr("info"));
    extentLabel = new QLabel;
    extentLabel->setText(tr("extent."));
    statusLabel = new QLabel;
    timeLabel = new QLabel;
    timeLabel->setText(tr("Time:"));
    inputEdit = new QTextEdit;
    buttonSend = new QPushButton;
    buttonSend->setText(tr("&Send"));
    buttonExit = new QPushButton;
    buttonExit->setText(tr("Exit"));
    buttonConfig = new QPushButton;
    buttonConfig->setText(tr("Configure"));

    clientOne = new QRadioButton(tr("Client One"));
    clientTwo = new QRadioButton(tr("Client Two"));
    clientOne->setChecked(true);
    tcpSocket->connectToHost(QHostAddress::LocalHost, 3111);
    groupBoxLayout = new QHBoxLayout;
    clientBox = new QGroupBox;
    groupBoxLayout->addWidget(clientOne);
    groupBoxLayout->addWidget(clientTwo);
    clientBox->setLayout(groupBoxLayout);
    
    connect(clientOne, SIGNAL(clicked(bool)), this, SLOT(changeClient()));
    connect(clientTwo, SIGNAL(clicked(bool)), this, SLOT(changeClient()));
}

void MainWindow::createMenu()
{
//    loginMenu = menuBar()->addMenu(tr("&Login"));
//     fileMenu = menuBar()->addMenu(tr("&File"));
//    configMenu = menuBar()->addMenu(tr("&Configuration"));
//    openHistory = new QAction(tr("&Open History"),fileMenu);
//    saveRecord = new QAction(tr("&Save Record As"),fileMenu);
//    saveConfig = new QAction(tr("&Save Configuration"), configMenu);
//    aboutAction = new QAction(tr("About"), fileMenu);
//    loginAction = new QAction(tr("&Login"),configMenu);
//    exitAction = new QAction(tr("&Exit"), fileMenu);


//    fileMenu->addAction(openHistory);
//    fileMenu->addAction(saveRecord);
//    fileMenu->addAction(aboutAction);
//    fileMenu->addSeparator();
//    fileMenu->addAction(exitAction);

//    configMenu->addAction(saveConfig);

//    loginMenu->addAction(loginAction);
}

void MainWindow::createLayout()
{
    protraitMainLayout = new QVBoxLayout;
    landscapeMainLayout = new QHBoxLayout;
    landscapeRightLayout = new QVBoxLayout;
    landscapeLeftLayout = new QVBoxLayout;
    buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(buttonSend);
    buttonLayout->addSpacing(10);
    buttonLayout->addWidget(buttonExit);
    buttonLayout->addStretch();
    buttonLayout->addWidget(buttonConfig);
    protraitMainLayout->addWidget(clientBox,0);
    protraitMainLayout->addWidget(msgEdit,2);
    protraitMainLayout->addWidget(inputEdit,1);
    protraitMainLayout->addLayout(buttonLayout,0);
    
    centralWidget = new QWidget(this);
    centralWidget->setLayout(protraitMainLayout);
    setCentralWidget(centralWidget);
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    setSizePolicy(sizePolicy);
    centralWidget->setSizePolicy(sizePolicy);
    setWindowTitle(tr("IM Client")); 
}

void MainWindow::clickButtonSend(bool singleClicked)
{
//    if(singleClicked)
//    {
//    }
//    else
//    {
        QAbstractSocket::SocketState state = tcpSocket->state();
        msgEdit->append(QString::number(state));
        QString content = inputEdit->toPlainText();
        if(!content.isEmpty())
        {
//            msgEdit->append(content);

            qDebug()<<"send...\n"<<content;
        }
//    }
}
void MainWindow::connectAll()
{
    connect(buttonSend, SIGNAL(clicked(bool)), this, SLOT(clickButtonSend(bool)));
    connect(buttonSend, SIGNAL(clicked(bool)), this, SLOT(sendData()));
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readData(int)));
    connect(buttonConfig, SIGNAL(clicked()), this, SLOT(setConfig()));
    connect(buttonExit, SIGNAL(clicked()), this, SLOT(close()));
}
void MainWindow::sendData()
	{
        //lockSendData:lock here
            if(!once)
            {
                QByteArray block;
                QDataStream out(&block, QIODevice::WriteOnly);
                out.setVersion(QDataStream::Qt_4_6);

                quint32 blockSize = 0;
                quint8  blockType = 0;
                quint8  segID = 0;
                quint32 segLen = 0;
                quint8  segNext = 0;
                QString content = inputEdit->toPlainText();
                if(content.isEmpty())
                {
                    return;
                }
                inputEdit->clear();

                segLen = content.size() + sizeof(segLen) + sizeof(segID);
                out<<blockSize<<blockType<<segID<<segLen<<segNext<<content;
                out.device()->seek(0);
                int sa = block.size();
                out<<quint32(block.size() - sizeof(quint32));
                msgEdit->append(content + "  :content size :" + QString::number(sa));
                tcpSocket->write(block);
                tcpSocket->flush();
            }
        //lockSendData:unlock here
	}

void MainWindow::changeClient()
	{
	if(clientOne->isChecked())
		{
	
		}
	else
		{
        tcpSocket->connectToHost(m_SerAdd, m_SerPort);
		}
	
	
	}
void MainWindow::readData(int notuse)
{
    QDataStream in;
    in.setDevice(tcpSocket);
    in.setVersion(QDataStream::Qt_4_6);
    forever
    {
        if(nextBlockSize == 0)
        {
            if(tcpSocket->bytesAvailable() < sizeof(quint32))
            {
                break;
            }
            in >> nextBlockSize;
        }
        if(nextBlockSize == 0xFFFF)
        {
          //  closeConnectiont();
            break;
        }
        if(tcpSocket->bytesAvailable() < nextBlockSize)
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
void MainWindow::setConfig()
    {
        Dialog dlg(this);
        if(dlg.exec())
            {
            QString strAdd = dlg.ui->editAdd->text();
            QString strPort = dlg.ui->editPort->text();
            int portInUInt = strPort.toInt();
            QHostAddress a(strAdd);
            QAbstractSocket::NetworkLayerProtocol protocol = a.protocol();
            switch(protocol)
                {
                case QAbstractSocket::IPv4Protocol:
                    if(portInUInt > PORT_NUM_MIN && portInUInt < PORT_NUM_MAX)
                    {
                        emit connConfigChanged(QHostAddress(strAdd), strPort.toInt()); // some signal
                    }
                    break;
                case QAbstractSocket::UnknownNetworkLayerProtocol:
                    return;
                default:
                    return;
                }
            }
    }

void  MainWindow::connConfigChanged(QHostAddress newAdd, int newPort)
{
    //lockSendData:lock here
    abortSocketData();
    //lockSendData:unlock here
    m_SerAdd = newAdd;
    m_SerPort = newPort;
    tcpSocket->connectToHost(m_SerAdd, m_SerPort);
    nextBlockSize = 0;
    once = false;
}
void MainWindow::abortSocketData()
{
    tcpSocket->abort();
}
