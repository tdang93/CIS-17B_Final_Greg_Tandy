#include "consumer.h"
#include "client.h"

Consumer::Consumer()
{
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(45454, QUdpSocket::ShareAddress);
    connect(udpSocket, SIGNAL(readyRead()),
            this, SLOT(processPendingDatagrams()));
}

Consumer::~Consumer()
{

}

void Consumer::run()
{
    pour();
}

void Consumer::pour()
{
//    QStringList numberList;
//    in >> numberList;
    QString QS;
    QS += "Starting time: " + cTime + "\n";

    myQMutex.lock(); // Lock the thread


    int counter = 0;
    QS += "Unsorted contents\n";
    for (int i = 0; i < QList_ptr->size(); ++i)
    {
        counter++;
        QS += "#";
        if(counter < 10)
        {
            QS += "0"; // formatting for single digit numbers (e.g. 01, 02, 03, etc.)
        }
        QS += QString::number(counter) += ": ";
        QS += QString::number(QList_ptr->at(i));
        QS += "\n" ;
    }
    QS += "\n";

    std::sort(QList_ptr->begin(), QList_ptr->end());
    counter = 0;
    QS += "Sorted contents\n";
    while(!QList_ptr->isEmpty())
    {
        counter++;
        QS += "#";
        if(counter < 10)
        {
            QS += "0"; // formatting for single digit numbers (e.g. 01, 02, 03, etc.)
        }
        QS += QString::number(counter) += ": ";
        QS += QString::number(QList_ptr->takeFirst());
        QS += "\n" ;
    }

    myQMutex.unlock(); // Unlock the thread

    QS += "Ending Time: " + cTime + "\n\n";

    emit sendSignal(QS);
}

void Consumer::processPendingDatagrams()
{
    if (udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size());
        cTime = datagram.data();

    }
}
