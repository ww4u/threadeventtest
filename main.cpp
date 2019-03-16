#include <QCoreApplication>

#include "mythread.h"

#include <QThread>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyThread *pThread = new MyThread( );
    pThread->moveToThread( pThread );

    qDebug()<<a.thread()<<QThread::currentThreadId()<<QThread::currentThread();

    pThread->start();

    return a.exec();
}
