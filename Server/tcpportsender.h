#ifndef SENDER_H
#define SENDER_H

#include <QTime>
#include <QDate>
#include <ctime>
#include <iostream>

#include <QWidget>

class QDialogButtonBox;
class QLabel;
class QPushButton;
class QUdpSocket;
class QTimer;

class TcpPortSender : public QWidget
{
    Q_OBJECT

public:
    TcpPortSender(QWidget *parent = 0);
    int tcpPort = 0;

private slots:
    void startBroadcasting();
    void broadcastDatagram();

private:
    QLabel *statusLabel;
    QPushButton *startButton;
    QPushButton *quitButton;
    QDialogButtonBox *buttonBox;
    QUdpSocket *udpSocket;
    QTimer *timer;
};

#endif
