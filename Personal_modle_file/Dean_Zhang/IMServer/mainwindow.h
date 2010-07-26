#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myserver.h"

#include <QListWidget>
namespace Ui {
    class MainWindow;
}

class MyServer;
typedef struct ClientNode clientNode;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

//Ui::MainWindow *ui;
protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    MyServer* server;

public slots:
void setTextBrowser(QString str);
void addNodetoList(QString str);
void deleteNodefromList(QString str);
void ProcessInterAction(QListWidgetItem *item);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();


};

#endif // MAINWINDOW_H
