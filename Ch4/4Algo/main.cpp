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
    //-------------------------------------------------------Sort

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

    //-----------------------------------------------Search

    QList<QString> list4;
    list4 << "Within Temptation" << "Anubis" << "Mantus";
    QList<QString>::iterator it =
            std::find(list4.begin(), list4.end(), "Anubis");
    if (it != list.end())
    {
        qDebug() << "Found=" << *it;
    }
    else
    {
        qDebug() << "Not Found";
    }

    //----------------------------------------------Comparison

    QList<QString> list5;
    list5 << "Within Temptation" << "Anubis" << "Mantus";

    QVector<QString> vec(3);
    vec[0] = "Within Temptation";
    vec[1] = "Anubis";
    vec[2] = "Mantus";

    qDebug() << "Equal="
             << std::equal(list5.begin(), list5.end(), vec.begin());

    //---------------------------------------------Filling

    QList<QString> list6;
    list6 << "Within Temptation" << "Anubis" << "Mantus";
    std::fill(list6.begin(), list6.end(), "Beatles");
    qDebug() << list6;

    //--------------------------------------------Copy

    QList<QString> list7;
    list7 << "Within Temptation" << "Anubis" << "Mantus";
    QVector<QString> vec2(3);
    std::copy(list7.begin(), list7.end(), vec2.begin());
    qDebug() << vec2;

    //----------------------------------------Counting
    QList<QString> list8;
    list8 << "Within Temptation" << "Anubis" << "Mantus" << "Mantus";
    int num = std::count(list8.begin(), list8.end(), "Mantus");
    qDebug() << num;



    return 0;
}
