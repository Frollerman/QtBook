#include "mainwindow.h"

#include <QApplication>
#include <QRegularExpression>

int main(int argc, char *argv[])
{
    QRegularExpression reg("[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}");
    QString str("this is an ip-address 123.222.63.1 lets check it");
    qDebug() << (str.contains(reg) > 0);

    QRegularExpression rxp("(.com|.ru");
    //int n1 = rxp.indexIn("www.bhv.ru"); //obsolete
    //int n1 = rxp.indexIn("www.bhv.ru"); //obsolete

    //int n1 = rxp.captureCount("www.bhv.ru");
    //int n2 = rxp.captureCount("www.bhv.de");

    QRegularExpression regEmail("([a-zA-Z0-9_\\-\\.]+)@([a-zA-Z0-9_.-])+\\.([a-zA-Z]{2,4}|[0-9]{1,3})");
    QString strEmail1 = "Max.Schlee@neonway.com";
    QString strEmail2 = "Max.Schlee#neonway.com";
    QString strEmail3 = "Max.Schlee@neonway";
    //bool b1 = regEmail.exactMatch(strEmail1); //obsolete
    QRegularExpressionMatch m1 = regEmail.match(strEmail1);
    QRegularExpressionMatch m2 = regEmail.match(strEmail2);
    QRegularExpressionMatch m3 = regEmail.match(strEmail3);
    bool b1 = m1.hasMatch();
    bool b2 = m1.hasPartialMatch();
    bool b3 = m1.hasPartialMatch();
    qDebug() << b1;
    qDebug() << b2;
    qDebug() << b3;

//    QRegularExpression reg2("^\\d+\\d?\\d?$");
//    qDebug() << reg2.indexIn("567"); // 0 obsolete
//    qDebug() << reg2.indexIn("3GB"); // -1 obsolete
//    qDebug() << reg2.indexIn("111B"); // -1 obsolete
//    qDebug() << reg2.indexIn("010"); // 0 obsolete
//    qDebug() << reg2.indexIn("10"); // 0 obsolete
//    qDebug() << reg2.indexIn("2"); // 0 obsolete
//    qDebug() << reg2.indexIn("-2"); // -1 obsolete

    QStringList lst;
    lst << "576" << "3GB" << "111B" << "010" << "10" << "2" << "-2";
    QStringList lstNumbers = lst.filter(QRegularExpression("^\\d+\\d?\\d?$"));
    qDebug() << lstNumbers;

    //--------------------------------------------------------------QVariant

    QVariant v1(34);
    QVariant v2(true);
    QVariant v3("Lostris");

    int t1 = v1.type();
    QString tt1 = QVariant::typeToName(t1);
    qDebug() << tt1;

    QVariant v(5.0);
    qDebug() << QVariant::typeToName(v.type());

    QVariant v4(23);
    int a = v4.toInt() + 5;
    qDebug() << a;

    QVariant v5(23);
    int a5 = v5.value<int>() + 5;
    qDebug() << a5;

//    QPixmap pix(":/myimg.png"); //creating QPixmap object
//    QVariant vPix = pix; //converting to QVariant
//    QPixmap::operator QVariant() //not working for some reason
//    QPixmap pix2 = vPix.value<QPixmap>(); //getting QPixmap object from QVariant

    //--------------------------------------------------------------Shared Data

    QString str1; //refers to shared_null
    QString str2; //refers to shared_null
    str1 = "New string"; //refers to data, link counter = 1
    str2 = str1; //str1 and str2 refer to the same data, link counter = 2
    str1 += " addition"; //copying data for str1

    return 0;
}
