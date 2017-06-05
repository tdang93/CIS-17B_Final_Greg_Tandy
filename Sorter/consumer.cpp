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
    QStringList numberList;
    in >> numberList;

    QMutex_ptr->lock(); // Lock the thread

    QString QS;
    int counter = 0;
    QS += "Unsorted contents\n";
    for (int i = 0; i < QStringList_ptr->size(); ++i)
    {
        counter++;
        QS += "#";
        if(counter < 10)
        {
            QS += "0"; // formatting for single digit numbers (e.g. 01, 02, 03, etc.)
        }
        QS += QString::number(counter) += ": ";
        QS += QStringList_ptr->at(i);
        QS += "\n" ;
    }
    QS += "\n";

    std::sort(QStringList_ptr->begin(), QStringList_ptr->end());
    counter = 0;
    QS += "Sorted contents\n";
    while(!QStringList_ptr->isEmpty())
    {
        counter++;
        QS += "#";
        if(counter < 10)
        {
            QS += "0"; // formatting for single digit numbers (e.g. 01, 02, 03, etc.)
        }
        QS += QString::number(counter) += ": ";
        QS += QStringList_ptr->takeFirst();
        QS += "\n" ;
    }
    QMutex_ptr->unlock(); // Unlock the thread

    emit sendSignal(QS);
}
