#include "client.h"

//#include <QTextEdit>
#include <QHBoxLayout>
#include <QApplication>
#include <QtCore>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    Client client;

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

//    QObject::connect(&producer, SIGNAL(sendSignal()), &consumer, SLOT(run()));
//    QObject::connect(&client, SIGNAL(sendSignal(QString)), &textEdit, SLOT(SetText(QString))); Disabled after moving Consumer back into Sorter

    client.show();
    return app.exec();
}
