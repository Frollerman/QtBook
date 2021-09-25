#ifndef PROGRESS_H
#define PROGRESS_H

#include <QWidget>

class QProgressBar;

//=====================================================

class Progress : public QWidget
{
    Q_OBJECT
private:
    QProgressBar* m_pprb;
    int m_nStep;

public:
    Progress(QWidget* pobj = 0);

public slots:
    void slotStep();
    void slotReset();
};

#endif // PROGRESS_H
