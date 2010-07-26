#ifndef CLIENTINTERACTIONVIEW_H
#define CLIENTINTERACTIONVIEW_H


#include "myserver.h"

#include "ui_ClientInterActionView.h"
#include <QUdpSocket>
class ClientInterActionView : public QDialog,Ui::Dialog
{
    Q_OBJECT
public:
    ClientInterActionView(QWidget *parent = NULL);
    ~ClientInterActionView();
    void GetClientInfo(clientNode nodeinfo,MyServer* server);

private:
   // QTcpSocket *sock;
   // QString name;
   // int state;
    clientNode Info;
//bool tcpRadioBtnSelected;
QUdpSocket *udpSocket;
   MyServer* server;
   quint16 udpPeerPort;
   quint16 udpBindPort;
signals:
    void updateTextBrowser(QString);

public slots:
    void on_radioButton_clicked();
    void on_pushButton_clicked();

    void processPendingDatagrams();
  void  DisplayError(QAbstractSocket::SocketError);

  void setTextBrowserDlg(QString str,QString ip);

private slots:
    void on_radioButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
};

#endif // CLIENTINTERACTIONVIEW_H
