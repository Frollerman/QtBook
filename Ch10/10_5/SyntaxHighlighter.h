#ifndef SYNTAXHIGHLIGHTER_H
#define SYNTAXHIGHLIGHTER_H

#include <QSyntaxHighlighter>

class QTextDocument;

// =========================================================
class SyntaxHighlighter: public QSyntaxHighlighter
{
    Q_OBJECT
private:
    QStringList m_lstKeywords;
protected:
    enum { NormalState = -1, InsideCStyleComment, InsideCString };

    virtual void highlightBlock(const QString&);

    QString getKeyword(int i, const QString& str) const;

public:
    SyntaxHighlighter(QTextDocument* parent = 0);
};

#endif // SYNTAXHIGHLIGHTER_H
