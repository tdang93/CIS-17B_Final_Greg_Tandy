#ifndef CLIENT_H
#define CLIENT_H

#include "consumer.h"
#include "textedit.h"

#include <QDialog>
#include <QTcpSocket>
#include <QDataStream>
#include <QWidget>

class QComboBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QTcpSocket;
class QNetworkSession;
class QUdpSocket;
class QAction;

class Client : public QDialog
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = Q_NULLPTR);

    Consumer myConsumer;
    TextEdit myTextEdit;

private slots:
    void requestNewFortune();
    void readFortune();
    void displayError(QAbstractSocket::SocketError socketError);
    void enableGetFortuneButton();
    void sessionOpened();
    void processPendingDatagrams();

private:
    QComboBox *hostCombo;
    QLineEdit *portLineEdit;
    QLabel *statusLabel;
    QPushButton *getFortuneButton;

    QTcpSocket *tcpSocket;
    QDataStream in;
    QString currentFortune;

    QNetworkSession *networkSession;

    QPushButton *quitButton;
    QUdpSocket *udpSocket;

    QString tPort;
    QString latestTCPport = "";
    QString latestCTime = "";
};

#endif
