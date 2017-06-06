#ifndef SERVER_H
#define SERVER_H

#include <tcpportsender.h>

#include <QDialog>

// forward declarations, or else Qt will complain
class QLabel;
class QPushButton;
class QTcpServer;
class QNetworkSession;
class TcpPortSender;

class Server : public QDialog
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = Q_NULLPTR);
    TcpPortSender tcpPortSender;

private slots:
    void sessionOpened();
    void sendFortune();

private:
    QLabel *statusLabel;
    QTcpServer *tcpServer;
    QList<int> fortunes;
    QNetworkSession *networkSession;
    QDataStream in;
};

#endif
