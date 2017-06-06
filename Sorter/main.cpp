#include "consumer.h"
#include "textedit.h"
#include "client.h"

#include <QTextEdit>
#include <QHBoxLayout>
#include <QApplication>
#include <QMutex>
#include <QtCore>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QMutex mutex;
    QStringList myQStringList;
//    Producer producer;
    Consumer consumer;
    Client client;
    TextEdit textEdit;

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

//    producer.QList_ptr = &myQList;
//    producer.QMutex_ptr = &mutex;

    consumer.QStringList_ptr = &myQStringList;
    consumer.QMutex_ptr = &mutex;

//    client.Consumer_ptr = &consumer; // assigning client's Consumer_ptr to address of consumer in main

//    QObject::connect(&producer, SIGNAL(sendSignal()), &consumer, SLOT(run()));
//    QObject::connect(&client, SIGNAL(sendSignal(QString)), &textEdit, SLOT(SetText(QString))); Disabled after moving Consumer back into Sorter
    QObject::connect(&consumer, SIGNAL(sendSignal(QString)), &textEdit, SLOT(SetText(QString)));

    client.show();
    textEdit.show();
    return app.exec();
}
