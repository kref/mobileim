#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QTcpServer>
 //#include <QList>
#include <QTcpSocket>

#include "mainwindow.h"
#include "ui_mainwindow.h"




enum ClientRequest
{
    online,
 offline,
 talking
};

typedef struct ClientNode
{
    QTcpSocket *sock;
    QString name;
    int state;
    bool isActive;
}clientNode,*p_clientNode;

class MyServer : public QObject
{
    Q_OBJECT
public:
    MyServer();
    bool BuildServer();
    clientNode GetNodeInfoFromIP(QString ip);
private:
//Ui_MainWindow *myui;
    QTcpServer *tcpServer;
  //  QList<QTcpSocket*> ClientList;
    QList<clientNode*> ClientList;



    bool ParseData(QString str,int *output);
    bool ClientOffline(QTcpSocket *sock);
    bool ClientOnline(QTcpSocket *sock);
    bool talk(QTcpSocket *sock);

private slots:
    void Service();
    void Accept();
   // void deleteService();
    void DisplayError(QAbstractSocket::SocketError socketError);
    void OnDisconnected();

  //  Ui_MainWindow *ui;
signals:
    void updateTextBrowser(QString);
    void updateTextBrowserDlg(QString,QString);
    void addtoListWidget(QString);
    void deletefromListWidget(QString);
};

#endif // MYSERVER_H
