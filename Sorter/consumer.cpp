#include "Consumer.h"

Consumer::Consumer()
{

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
    QMutex_ptr->lock(); // lock the thread

    QString QS;
    int counter = 0;
    while(!QList_ptr->isEmpty())
    {
        counter++;
        QS += "#";
        QS += QString::number(counter) += ": ";
        QS += QString::number(QList_ptr->takeFirst());
        QS += "\n" ;
    }
    QMutex_ptr->unlock(); // unlock the thread

    emit sendSignal(QS);
}
