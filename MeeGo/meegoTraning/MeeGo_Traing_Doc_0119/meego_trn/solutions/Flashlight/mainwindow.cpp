#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), m_sensor(new QAmbientLightSensor(this))
{
    ui->setupUi(this);
    ui->graphicsView->setScene(new QGraphicsScene(this));
    // Setting the screen color to white
    ui->graphicsView->setBackgroundBrush(Qt::white);

    connect( m_sensor, SIGNAL(readingChanged()),
             this, SLOT(readingChanged()));
    m_sensor->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readingChanged() {
    QAmbientLightReading* r = m_sensor->reading();
    switch( r->lightLevel() ) {
    case QAmbientLightReading::Dark: {
         ui->graphicsView->setBackgroundBrush(Qt::white);
         break;
        }
    case QAmbientLightReading::Twilight: {
         ui->graphicsView->setBackgroundBrush(Qt::lightGray);
         break;
        }
    case QAmbientLightReading::Light: {
        ui->graphicsView->setBackgroundBrush(Qt::gray);
        break;
        }
    case QAmbientLightReading::Bright: {
        ui->graphicsView->setBackgroundBrush(Qt::darkGray);
        break;
        }
    case QAmbientLightReading::Sunny: {
        ui->graphicsView->setBackgroundBrush(Qt::black);
        break;
        }

    }
}
