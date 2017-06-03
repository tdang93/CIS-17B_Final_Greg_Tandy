#ifndef PRODUCER_H
#define PRODUCER_H

#include <QThread>
#include <QMutex>

class Producer : public QThread
{
    Q_OBJECT
public:
    Producer();
    ~Producer();

    QMutex* QMutex_ptr = NULL;
    QList<int>* QList_ptr = NULL;
    Producer* producer_ptr = NULL;
    void fill();

signals:
    void sendSignal();

public slots:
    void run();
};

#endif // PRODUCER_H
