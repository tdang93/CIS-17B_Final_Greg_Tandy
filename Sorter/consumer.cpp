#include "consumer.h"

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

    std::sort(QList_ptr->begin(), QList_ptr->end());

    QString QS;
    int counter = 0;
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
    QMutex_ptr->unlock(); // unlock the thread

    emit sendSignal(QS);
}
