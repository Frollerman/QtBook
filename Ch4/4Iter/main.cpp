#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    //Java-style iterators

    QList<QString> list;
    list << "Within Temptation" << "Anubis" << "Mantus";
    QListIterator<QString> it(list);
    while (it.hasNext())
    {
        qDebug() << "Element:" << it.next();
    }

    list << "Beatles" << "ABBA" << "Boney M";
    QMutableListIterator<QString> mit(list);
    while(mit.hasNext())
    {
        if (mit.next() == "Boney M")
        {
            mit.setValue("Rolling Stones");
        }
        qDebug() << mit.peekPrevious();
    }

//=======================================================

    //STL-style iterators

    QVector<QString> vec;
    vec << "In Extremo" << "Blackmore's Night" << "Cultus Ferox";
    QVector<QString>::iterator it2 = vec.begin();
    for (; it2 != vec.end(); ++ it2)
    {
        qDebug() << "Element:" << *it2;
    }

    QVector<QString>::iterator it3 = vec.end();
    for (;it3 != vec.begin();)
    {
        --it3;
        qDebug() << "Element:" << *it3;
    }

    QVector<QString>::const_iterator cit = vec.constBegin();
    for (; cit != vec.constEnd(); ++cit)
    {
        qDebug() << "Element:" << *cit;
    }

    std::sort(vec.begin(), vec.end());
    qDebug() << vec;

    QList<QString> list2;
    list2 << "Subway to sally" << "Rammstein" << "After Forever";
    foreach(QString str, list2)
    {
        qDebug() << "Element:" << str;
    }

    QVector<QString> vec2;
    vec2.append("In Extremo");
    vec2.append("Blackmore's Night");
    vec2.append("Cultus Ferox");
    qDebug() << vec2;

    return 0;
}
