#include <QApplication>
#include <QtCore>

#include <stdlib.h>

#include "server.h"
#include "tcpportsender.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QGuiApplication::setApplicationDisplayName(Server::tr("TCP Server"));

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    Server server;
    TcpPortSender tcpportsender;

    server.show();
    tcpportsender.show();

    return app.exec();
}
