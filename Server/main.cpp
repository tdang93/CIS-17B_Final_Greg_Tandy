#include <QApplication>
#include <QtCore>

#include <stdlib.h>

#include "server.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QGuiApplication::setApplicationDisplayName(Server::tr("TCP Server"));

    Server server;
    server.show();

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    return app.exec();
}
