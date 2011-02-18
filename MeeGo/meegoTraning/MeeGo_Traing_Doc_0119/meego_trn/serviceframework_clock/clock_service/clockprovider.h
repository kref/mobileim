#ifndef CLOCKPROVIDER_H
#define CLOCKPROVIDER_H

#include <QObject>

class ClockProvider : public QObject
{
    Q_OBJECT
public:
    explicit ClockProvider(QObject *parent = 0);

signals:
    void hereItComes(QString time);

public slots:
    void requestTime();
};

#endif // CLOCKPROVIDER_H
