#ifndef SERVER_H
#define SERVER_H

#include <QDialog>
#include <QThread>
#include <QMutex>

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
    QMutex* QMutex_ptr = NULL;
    QString number;
    QStringList* QStringList_ptr = NULL;

private slots:
    void sessionOpened();
    void sendNumberList();

private:
    QLabel *statusLabel;
    QTcpServer *tcpServer;
    QNetworkSession *networkSession;
};

#endif
