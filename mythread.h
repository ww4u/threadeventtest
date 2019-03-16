#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QtCore>
#include <QThread>

class TheObj : public QObject
{
    Q_OBJECT
public:
    TheObj( QObject *parent = nullptr );

protected Q_SLOTS:
    void slot_timeout();
};

class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread( QObject *parent= nullptr  );

protected:
    virtual void run();
public:
    virtual bool event(QEvent *event);

protected Q_SLOTS:
    void thread_slot_timeout();

};

#endif // MYTHREAD_H
