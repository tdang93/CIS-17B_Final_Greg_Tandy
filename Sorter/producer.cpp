#include "producer.h"
#include <QTextStream>

Producer::Producer()
{

}

Producer::~Producer()
{

}

void Producer::run()
{
    fill();
}

void Producer::fill()
{
    QMutex_ptr->lock(); // lock the thread

    //number of outputs
    for (int i = 0; i < 50; i++)
    {
        QList_ptr->push_back((qrand() % 1000) + 1);
    }
    QMutex_ptr->unlock(); // unlock the thread

    emit sendSignal();
}
