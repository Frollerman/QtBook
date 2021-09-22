#include "mainwindow.h"

#include <QApplication>
#include <QtAlgorithms>

bool lessThan(const QString& str1, const QString& str2)
{
    return QString::compare(str1, str2, Qt::CaseInsensitive) < 0;
}

bool caseInsensitiveLessThan(const QString &s1, const QString &s2)
{
    return s1.toLower() < s2.toLower();
}

int main(int argc, char *argv[])
{
    QString values[] = {"Xandria", "Therion", "Nightwish", "Haggard"};
    const int n = sizeof(values) / sizeof(QString);
    QString copyOfValues[n];
    std::copy(values, values + n, copyOfValues);

    QList<QString> list;
    list << "Within Temptation" << "Anubis" << "Mantus";
    std::sort(list.begin(), list.end());
    qDebug() << "Sorted list=" << list;

    //std::sort(list.begin(), list.end(), caseLessThan);
    std::sort(list.begin(), list.end(), caseInsensitiveLessThan);
    //std::less(list.begin(), list.end());
    qDebug() << "Less list=" << list;

//    QList<int> list2;
//    list2 << 1 << 2 << 3 << 4 << 5 << 6;
//    std::sort(list2.begin(), list2.end(), std::greater());
//    qDebug() << "Greater list=" << list2;

    QList<QString> list3;
    list3 << "Within Temptation" << "Anubis" << "anubis" << "Mantus";
    std::sort(list3.begin(), list3.end(), lessThan);
    qDebug() << list3;



    return 0;
}
