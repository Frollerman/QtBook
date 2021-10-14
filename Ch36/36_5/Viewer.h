#ifndef VIEWER_H
#define VIEWER_H

#include <QTextEdit>

// ================================================================
class Viewer : public QTextEdit
{
    Q_OBJECT
public:
    Viewer(QWidget* pwgt = nullptr);

public slots:
    void slotDirectoryChanged(const QString&);
    void slotFileChanged(const QString&);
};

#endif // VIEWER_H
