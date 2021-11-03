#include <QCoreApplication>
#include <QtNetwork>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QTcpSocket socket;

    socket.connectToHost(QHostAddress::LocalHost, 2424);
    socket.waitForDisconnected();
    qDebug() << socket.readAll();

    return 0;
}
