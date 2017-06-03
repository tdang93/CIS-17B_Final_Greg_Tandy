#include "consumer.h"
#include "producer.h"
#include "textedit.h"

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
    TextEdit textEdit;

    producer.QList_ptr = &myQList;
    producer.QMutex_ptr = &mutex;

    consumer.QList_ptr = &myQList;
    consumer.QMutex_ptr = &mutex;

    QObject::connect(&producer, SIGNAL(sendSignal()), &consumer, SLOT(run()));
    QObject::connect(&consumer, SIGNAL(sendSignal(QString)), &textEdit, SLOT(SetText(QString)));

    textEdit.show();
    producer.fill();

    return app.exec();
}
