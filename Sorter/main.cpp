#include "client.h"

//#include <QTextEdit>
#include <QHBoxLayout>
#include <QApplication>
#include <QtCore>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    Client client;
    client.show();

    return app.exec();
}
