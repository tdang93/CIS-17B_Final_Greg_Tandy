#ifndef CONSUMER_H
#define CONSUMER_H

#include <QThread>
#include <QMutex>
#include <algorithm>
#include <QtNetwork>

class Consumer : public QThread
{
    Q_OBJECT
public:
    Consumer();
    ~Consumer();

    QMutex myQMutex;
    QList<int>* QList_ptr = NULL;
    QDataStream in;

    void pour();
signals:
    void sendSignal(QString);

public slots:
    void run();
};

#endif // CONSUMER_H
