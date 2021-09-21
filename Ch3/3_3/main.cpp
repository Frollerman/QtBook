//#include "mainwindow.h"

#include <QApplication>

//#include <QCoreApplication>

using namespace Qt;

void dummyOutput(QtMsgType, const QMessageLogContext&, const QString&)
{
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
#ifndef QT_DEBUG
    qInstallMessageHandler(dummyOutput);
#endif

    qDebug() << "Test1" << 123 << "Test2" << 456 << endl;

    int n = 7777;
    qDebug() << "DEC:" << n << "= HEX:" << hex << uppercasedigits << n << endl;
    qDebug() << 1 << 2 << 3 << 4;
    qDebug().nospace() << 1 << 2 << 3 << 4 << endl << endl;

//==============================================================================

    int l = qMax<int>(3, 5);
    qDebug() << "l =" << l;
    int m = qMin<int>(3,5);
    qDebug() << "m =" << m << endl;

    int o = qAbs(-5);
    qDebug() << "o =" << o << endl;

    int p = qRound(5.2);
    qDebug() << "p =" << p;
    int q = qRound(-5.2);
    qDebug() << "q =" << q;
    int r = qRound(5.6);
    qDebug() << "r =" << r << endl;

    int s = qBound(2, 12, 7); //returns the number between min and max
    qDebug() << "s =" << s << endl;

//==============================================================================

    //qDebug() << "Test" << endl;
    //MainWindow w;
    //w.show();
    return 0; //return a.exec();
}
