#include "client.h"
#include "textedit.h"

#include <QTextEdit>
#include <QHBoxLayout>
#include <QApplication>
#include <QMutex>
#include <QtCore>

int main(int argc, char **argv)
{
//    QMutex mutex;

//    QList<int> myQList;
    QApplication app(argc, argv);

//    Producer producer;
    Client client;
    TextEdit textEdit;
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
//    producer.QList_ptr = &myQList;
//    producer.QMutex_ptr = &mutex;

//    consumer.QList_ptr = &myQList;
//    consumer.QMutex_ptr = &mutex;

//    QObject::connect(&producer, SIGNAL(sendSignal()), &consumer, SLOT(run()));
    QObject::connect(&client, SIGNAL(sendSignal(QString)), &textEdit, SLOT(SetText(QString)));

//    textEdit.show();
    client.show();
    textEdit.show();
    return app.exec();
}
