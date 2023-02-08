#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QObject>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);
    void run() override;
};

#endif // THREAD_H
