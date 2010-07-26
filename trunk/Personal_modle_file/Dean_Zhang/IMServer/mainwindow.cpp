#include "mainwindow.h"
#include "ui_mainwindow.h"

#include"clientinteractionview.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
server=new MyServer();
    connect(server,SIGNAL(updateTextBrowser(QString)),this,SLOT(setTextBrowser(QString)));
    connect(server,SIGNAL(addtoListWidget(QString)),this,SLOT(addNodetoList(QString)));
    connect(server,SIGNAL(deletefromListWidget(QString)),this,SLOT(deleteNodefromList(QString)));
    connect(ui->listWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(ProcessInterAction(QListWidgetItem *)));
}

void MainWindow::setTextBrowser(QString str)
{
    ui->textBrowser->append(str);
}

void MainWindow::addNodetoList(QString str)
{
   ui->listWidget->addItem(str);
}

void MainWindow::deleteNodefromList(QString str)
{
    QList<QListWidgetItem *> currentList=ui->listWidget->findItems(str,0);
 //  ui->listWidget-> removeItemWidget(currentList);
    int n=ui->listWidget->row(currentList.at(0));
   QListWidgetItem* temp= ui->listWidget->takeItem(n);
   delete temp;
    
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

void MainWindow::on_pushButton_2_clicked()   //build Server button
{

      if(server->BuildServer())
      {
          //cout<<"build server complete"<<endl;
        ui->textBrowser->append("build server complete");
      }
      else
         // cout<<"build server failed"<<endl;
          ui->textBrowser->append("build server failed");
}

void MainWindow::on_pushButton_clicked()    // close Server button
{

}

void MainWindow::ProcessInterAction(QListWidgetItem *item)
{
    ClientInterActionView *myDialog = new ClientInterActionView;

    connect(myDialog,SIGNAL(updateTextBrowser(QString)),this,SLOT(setTextBrowser(QString)));
    myDialog->show();

    clientNode tempNode=server->GetNodeInfoFromIP(item->text());

    myDialog->GetClientInfo(tempNode,this->server);




}

















