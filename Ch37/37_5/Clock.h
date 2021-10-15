#ifndef CLOCK_H
#define CLOCK_H

#include <QtWidgets>
#include <QDateTime>

// ======================================================
class Clock : public QLabel
{
    Q_OBJECT

public:
    Clock(QWidget* pwgt = nullptr) : QLabel(pwgt)
    {
        QTimer* ptimer = new QTimer(this);
        connect(ptimer, SIGNAL(timeout()), SLOT(slotUpdateDateTime()));
        ptimer->start(500);
        slotUpdateDateTime();
    }

public slots:
    void slotUpdateDateTime()
    {
        QString str =
                //QDateTime::currentDateTime().toString(Qt::DateFormat(SystemLocaleLongDate));
                QLocale::system().toString(QDateTime::currentDateTime(), QLocale::LongFormat);
        setText("<H2><CENTER>" + str + "</CENTER></H2>");
    }
};

#endif // CLOCK_H
