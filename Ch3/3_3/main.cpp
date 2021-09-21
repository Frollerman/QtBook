//#include "mainwindow.h"

#include <QApplication>
#include <QtCore>
#include <QLibraryInfo>

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

    double dValue1 = 0.0;
    double dValue2 = 4;
    if (qFuzzyCompare(1 + dValue1, 1 + dValue2))
    {
        qDebug() << "values are equal" << endl;
    }
    else
    {
        qDebug() << "values are not equal" << endl;
    }

    qDebug() << "Number of bits for qint64 =" << (sizeof(qint64) * 8);
    qDebug() << "Minimum of qint64 = -" << ~(~quint64(0) >> 1);
    qDebug() << "Maximum of qint64 =" << (~quint64(0) >> 1);
    qDebug() << "Number of bits for quint64 =" << (sizeof(quint64) * 8);
    qDebug() << "Minimum of quint64 =" << 0;
    qDebug() << "Maximum of quint64 =" << ~quint64(0);

    qDebug() << "Library version:"
             << QLibraryInfo::version();

    qDebug() << "Locations:";
    qDebug() << "Headers:"
             << QLibraryInfo::path(QLibraryInfo::HeadersPath);
    qDebug() << "Libraries:"
             << QLibraryInfo::path(QLibraryInfo::LibrariesPath);
    qDebug() << "Binaries:"
             << QLibraryInfo::path(QLibraryInfo::BinariesPath);
    qDebug() << "Prefix:"
             << QLibraryInfo::path(QLibraryInfo::PrefixPath);
    qDebug() << "Documentation:"
             << QLibraryInfo::path(QLibraryInfo::DocumentationPath);
    qDebug() << "Plugins:"
             << QLibraryInfo::path(QLibraryInfo::PluginsPath);
    qDebug() << "Data:"
             << QLibraryInfo::path(QLibraryInfo::DataPath);
    qDebug() << "Settings:"
             << QLibraryInfo::path(QLibraryInfo::SettingsPath);

    qDebug() << "Examples"
             << QLibraryInfo::path(QLibraryInfo::ExamplesPath);


//==============================================================================

    //qDebug() << "Test" << endl;
    //MainWindow w;
    //w.show();
    return 0; //return a.exec();
}
