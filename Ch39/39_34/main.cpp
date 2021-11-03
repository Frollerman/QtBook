#include <QCoreApplication>
#include <QtNetwork>
#include <QHostInfo>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QNetworkProxy proxy;
    proxy.setType(QNetworkProxy::HttpProxy);
    proxy.setHostName("192.168.178.1");
    proxy.setPort(8080);
    proxy.setUser("user");
    proxy.setPassword("password");
    QNetworkProxy::setApplicationProxy(proxy);

    QHostInfo::lookupHost(QStringLiteral("qt-book.com"),
                          this,
                          SLOT(slotPrintResults(QHostInfo))
                          );

    return a.exec();
}

void HostInfoExample::slotPrintResults(QHostInfo info)
{
    qDebug() << "HostName: " << info.hostName();
    qDebug() << "Host IP: " << "Adrs: " << info.addresses();
}
