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
    QMutex_ptr->lock(); // Lock the thread

    QString QS;
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
    QMutex_ptr->unlock(); // Unlock the thread

    emit sendSignal(QS);
}
