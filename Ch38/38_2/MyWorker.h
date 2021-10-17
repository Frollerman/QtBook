#ifndef MYWORKER_H
#define MYWORKER_H

#include <QtWidgets>

class MyWorker : public QObject
{
    Q_OBJECT
private:
    int m_nValue;
    QTimer* m_ptimer;

public:
    MyWorker(QObject* pobj = nullptr) : QObject(pobj)
                                      , m_nValue(10)
    {
        m_ptimer = new QTimer(this);

        connect(m_ptimer, SIGNAL(timeout()), SLOT(setNextValue()));
    }

signals:
    void valueChanged(int);
    void finished();

public slots:
    void slotDoWork()
    {
        m_ptimer->start(1000);
    }

private slots:
    void setNextValue()
    {
        emit valueChanged(--m_nValue);
        if(!m_nValue)
        {
            m_ptimer->stop();
            emit finished();
        }
    }
};

#endif // MYWORKER_H
