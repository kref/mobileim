#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QTcpServer>
#include "QTcpSocket"
#include "server.h"
#include "QTcpServer"
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    server* ser;
    quint32 nextBlockSize;
private slots:
    void newConn();
    void resetConnRecord();
    void readData();
};

#endif // MAINWINDOW_H
