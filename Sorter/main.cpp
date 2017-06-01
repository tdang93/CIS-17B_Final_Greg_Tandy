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

//    void run();
    QMutex* QMutex_ptr = NULL;
    QList<unsigned long long>* QList_ptr = NULL;
    Producer* producer_ptr = NULL;
    void fill(int times);

    int times;

signals:
    void sendSignal();

public slots:
//    void run(int);
    void run();
};

#endif // PRODUCER_H

#ifndef CONSUMER_H
#define CONSUMER_H

#include <QThread>
#include <QMutex>

class Consumer : public QThread
{
    Q_OBJECT
public:
    Consumer();
    ~Consumer();

//    void run();
    QMutex* QMutex_ptr = NULL;
    QList<unsigned long long>* QList_ptr = NULL;
    int send;

    void pour();
signals:
    void sendSignal(QString);

public slots:
//    void pour();
    void run();
};

#endif // CONSUMER_H

//==================================================
//MAIN
#include <QTextEdit>
#include <QHBoxLayout>
#include <QApplication>
#include <QMutex>

int main(int argc, char **argv)
{
    QMutex mutex;

    QList<int> myQList;
    QApplication app(argc, argv);

    Producer producer;
    Consumer consumer;

    producer.QList_ptr = &myQList;
    producer.QMutex_ptr = &mutex;

    consumer.QList_ptr = &myQList;
    consumer.QMutex_ptr = &mutex;

    QObject::connect(&producer, SIGNAL(sendSignal()), &consumer, SLOT(run()));
    QObject::connect(&consumer, SIGNAL(sendSignal(QString)), &textEdit, SLOT(SetText(QString)));

    return app.exec();
}
//MAIN
//==================================================


