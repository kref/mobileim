#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(new QGraphicsScene(this));
    // Setting the screen color to white
    ui->graphicsView->setBackgroundBrush(Qt::white);
}

MainWindow::~MainWindow()
{
    delete ui;
}
