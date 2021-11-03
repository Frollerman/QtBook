#include <QApplication>
#include <QTextStream>
#include <QTextCodec>
#include <QCoreApplication>
#include <QProcess>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    QTextStream outStream(stdout);
//    outStream.setCodec(QTextCodec::codecForName("cp866"));
//    outStream << QString("Русский текст в консоли");

//    QLocale curLocale(QLocale("ru_RU"));
//    QLocale::setDefault(curLocale);

//    QTextCodec *codec = QTextCodec::codecForLocale();
//    codec->setCodecForLocale("UTF-8");
//    QTextCodec::setCodecForLocale(codec);

//    QProcess process;
//    process.setWorkingDirectory("D:\\QtProjects\\cmdtest");
//    process.start("ipconfig");

//    QProcess::startDetached("chcp 65001", QStringList() << "", "D:\\QtProjects\\cmdtest");

//    QProcess::startDetached("ipconfig", QStringList() << "", "D:\\QtProjects\\cmdtest");

    //QProcess::execute("ipconfig");
    //QProcess::execute("cmd /c ipconfig");

    qDebug() << "Test";

    return a.exec();
}
