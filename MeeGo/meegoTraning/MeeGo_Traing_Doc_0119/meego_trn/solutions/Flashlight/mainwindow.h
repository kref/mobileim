#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAmbientLightSensor>

QTM_USE_NAMESPACE;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void readingChanged();

private:
    Ui::MainWindow *ui;
    QAmbientLightSensor* m_sensor;
};

#endif // MAINWINDOW_H
