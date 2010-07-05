#ifndef SERVER_H
#define SERVER_H
#include <QtCore>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>

class tcpListMem
{
public:
    tcpListMem();
QTcpSocket* tcpSocket;
int         descriptor;
};

class server:public QTcpServer
{
    Q_OBJECT
public:
    server();
    virtual ~server();
     QList<tcpListMem> list;
protected:
    void incomingConnection(int handle);
private:

    int nextBlockSize;
public slots:
    void readData(int notuse);
};


#endif // SERVER_H
