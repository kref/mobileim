#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>

#include "QLabel"
#include "QLineEdit"
#include "QTextEdit"
#include "QPushButton"
#include "QTimer"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include "QGridLayout"
#include "QAction"
#include "QMenu"
#include "QWidget"
#include "QRadioButton"
#include "QGroupBox"
#include "QHostInfo"
#include "QNetworkInterface"
#include "QNetworkAddressEntry"
#include "QDesktopWidget"
#include "QTcpSocket"
#include "QDataStream"
#include "dialog.h"
#include "QAbstractSocket"
namespace Ui {
    class MainWindow;
}
#define PORT_NUM_MIN 1024
#define PORT_NUM_MAX 8000
class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);
    void createComponent();
    void createMenu();
    void createLayout();
    void connectAll();
    void disconnectAll();
private:
    void abortSocketData();
private:
    QMenu* fileMenu;
    QMenu* loginMenu;
    QMenu* configMenu;
    QAction* openHistory;
    QAction* saveRecord;
    QAction* saveConfig;
    QAction* aboutAction;
    QAction* loginAction;
    QAction* exitAction;
    QTextEdit* msgEdit;
    QLabel* infoLabel;
    QLabel* extentLabel;
    QLabel* statusLabel;
    QLabel* timeLabel;
    QTextEdit* inputEdit;
    QPushButton* buttonSend;
    QPushButton* buttonExit;
    QPushButton* buttonConfig;
    QWidget* centralWidget;
    QDesktopWidget* dWidget;
    QRadioButton* clientOne;
    QRadioButton* clientTwo;
    QGroupBox* clientBox;
    QTcpSocket* tcpSocket;
private:
    QVBoxLayout* protraitMainLayout;
    QHBoxLayout* landscapeMainLayout;
    QVBoxLayout* landscapeRightLayout;
    QVBoxLayout* landscapeLeftLayout;
    QHBoxLayout* groupBoxLayout;
    QHBoxLayout* buttonLayout;
private:
    QTimer* clockTimer;
    bool once;
    QHostAddress m_SerAdd;
    int m_SerPort;
private:
    Ui::MainWindow *ui;
    qint32 nextBlockSize;
private slots:
    void clickButtonSend(bool singleClicked);
    void readData(int notuse);
    void setConfig();
    void connConfigChanged(QHostAddress newAdd, int newPort);
    void sendData();
    void changeClient();
};

#endif // MAINWINDOW_H
