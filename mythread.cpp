#include "mythread.h"

TheObj::TheObj( QObject *parent ) : QObject( parent )
{

}

void TheObj::slot_timeout()
{
    qDebug()<<__FUNCTION__<<__LINE__<<thread()<<QThread::currentThreadId();
}

MyThread::MyThread( QObject *parent ) : QThread( parent )
{

}

void MyThread::run()
{
    QTimer theTimer;

    TheObj obj;

    connect( &theTimer, SIGNAL(timeout()),
             this, SLOT(thread_slot_timeout()) );

    connect( &theTimer, SIGNAL(timeout()),
             &obj, SLOT(slot_timeout()));

    theTimer.start( 2000 );

    QThread::run();

    qDebug()<<__FUNCTION__<<__LINE__<<thread()<<QThread::currentThreadId();
}

bool MyThread::event(QEvent *event)
{
    if ( event->type() >= QEvent::User )
    {
        qDebug()<<__FUNCTION__<<__LINE__<<thread()<<QThread::currentThreadId();
        event->accept();

        requestInterruption();

        return true;
    }

    return QThread::event(event);
}

void MyThread::thread_slot_timeout()
{
    qDebug()<<__FUNCTION__<<__LINE__<<thread()<<QThread::currentThreadId();

    QEvent *pEvent = new QEvent( QEvent::User );
    qApp->postEvent( this, pEvent );
}

