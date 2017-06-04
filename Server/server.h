#ifndef SERVER_H
#define SERVER_H

#include <QDialog>

// forward declarations, or else Qt will complain
class QLabel;
class QPushButton;
class QTcpServer;
class QNetworkSession;

class Server : public QDialog
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = Q_NULLPTR);

private slots:
    void sessionOpened();
    void sendFortune();

private:
    QLabel *statusLabel;
    QTcpServer *tcpServer;
    QStringList fortunes;
    QNetworkSession *networkSession;
    QDataStream in;
};

#endif
