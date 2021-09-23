#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QString str = "Lo";
    bool b1 = (str == "Lo");
    qDebug() << b1;
    bool b2 = (str != "LO");
    qDebug() << b2;

    QString str1 = "";
    QString str2;
    qDebug() << str1.isNull();
    qDebug() << str2.isNull();
    qDebug() << str1.isEmpty();
    qDebug() << str2.isEmpty();
    qDebug() << str1.length();
    qDebug() << str2.length();

    QString str3 = "Lo";
    QString str4 = "stris";
    QString str5 = str3 + str4;
    str3.append(str4);
    qDebug() << str5;
    qDebug() << str3;

    QString str6 = "Lostris";
    str6.replace("stris", "gic");
    qDebug() << str6;

    QString str7 = "LoStRiS";
    QString str8 = str7.toLower();
    QString str9 = str7.toUpper();
    qDebug() << str8;
    qDebug() << str9;

    QString str10 = QString::number(35.123);
    QString str11;
    str11.setNum(35.123);
    qDebug() << str10;
    qDebug() << str11;

    QString str12;
    QTextStream(&str12) << 35.123;
    qDebug() << str12;

    bool ok;
    QString str13 = "234";
    double d = str13.toDouble(&ok);
    int n = str13.toInt(&ok);
    qDebug() << d;
    qDebug() << n;

    QString str14 = "Ringo Star";
    QStringList list = str14.split(" ");
    qDebug() << list;

    QString str15 = list.join(" ");
    qDebug() << str15;

    return 0;
}
