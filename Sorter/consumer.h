#ifndef CONSUMER_H
#define CONSUMER_H

#include <QThread>
#include <QMutex>
#include <algorithm>

class Consumer : public QThread
{
    Q_OBJECT
public:
    Consumer();
    ~Consumer();

    QMutex* QMutex_ptr = NULL;
    QList<int>* QList_ptr = NULL;
    int send;

    void pour();
signals:
    void sendSignal(QString);

public slots:
    void run();
};

#endif // CONSUMER_H
