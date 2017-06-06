#include <QtWidgets>
#include <QtNetwork>

#include "tcpportsender.h"

TcpPortSender::TcpPortSender(QWidget *parent)
    : QWidget(parent)
{
    statusLabel = new QLabel(tr("Ready to broadcast datagrams on port 54545"));
    statusLabel->setWordWrap(true);

    startButton = new QPushButton(tr("&Start"));
    quitButton = new QPushButton(tr("&Quit"));

    buttonBox = new QDialogButtonBox;
    buttonBox->addButton(startButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);

    timer = new QTimer(this);
    udpSocket = new QUdpSocket(this);

    connect(startButton, SIGNAL(clicked()), this, SLOT(startBroadcasting()));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(timer, SIGNAL(timeout()), this, SLOT(broadcastDatagram()));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(statusLabel);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    setWindowTitle(tr("Broadcast Sender"));
}

void TcpPortSender::startBroadcasting()
{
    startButton->setEnabled(false);
    timer->start(1000);
}

void TcpPortSender::broadcastDatagram()
{
    QString cTime = (QTime::currentTime().toString());
    time_t cDate;
    time (&cDate);

    statusLabel->setText(ctime(&cDate));
    QByteArray datagram = cTime.toUtf8();
    udpSocket->writeDatagram(datagram.data(), datagram.size(),
                             QHostAddress::Broadcast, 54545);
}
