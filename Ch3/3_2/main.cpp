//#include "mainwindow.h"

#include <QApplication>

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();
//}

#include <QObject>
#include <QIODevice>
#include <QFile>
#include <QDateTime>

using namespace Qt;

void messageToFile(QtMsgType                    type,
                   const QMessageLogContext&    context,
                   const QString&               msg
                  )
{
    QFile file("protocol.log");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
        return;

    QString strDateTime =
            QDateTime::currentDateTime().toString("dd.MM.yy-hh:mm");

    QTextStream out(&file);
    switch (type)
    {
    case QtInfoMsg:
        out << strDateTime << " Info: " << msg
            << ", " << context.file << endl;
        break;
    case QtDebugMsg:
        out << strDateTime << " Debug: " << msg
            << ", " << context.file << endl;
        break;
     case QtWarningMsg:
        out << strDateTime << " Warning: " << msg
            << ", " << context.file << endl;
        break;
     case QtCriticalMsg:
        out << strDateTime << " Critical: " << msg
            << ", " << context.file << endl;
        break;
     case QtFatalMsg:
        out << strDateTime << " Fatal: " << msg
            << ", " << context.file << endl;
        abort();
     }
}

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    qInstallMessageHandler(messageToFile);
    //...

    qInfo("Info Message");
    qDebug("Debug Message");
    qWarning("Warning Message");
    qCritical("Critical Message");
    qFatal("Fatal Message");

    //return 0;
}
