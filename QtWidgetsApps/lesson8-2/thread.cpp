#include "thread.h"

MyThread::MyThread(QObject *parent)
    : QThread{parent}
{

}

void MyThread::run()
{
    exec();
}
