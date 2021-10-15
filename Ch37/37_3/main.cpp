#include "mainwindow.h"

#include <QApplication>
#include <QTimer>

void delay(int n)
{
    QEventLoop loop;
    QTimer::singleShot(n, &loop, SLOT(quit()));
    loop.exec();
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;

    //QTimer::singleShot(5 * 60 * 1000, &app, SLOT(quit()));

    w.show();

    delay(5000);

    return app.exec();
}
