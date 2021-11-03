#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QtWidgets>
#include <QUdpSocket>

class UdpServer : public QTextEdit
{
    Q_OBJECT
private:
    QUdpSocket* m_pudp;

public:
    UdpServer(QWidget* pwgt = nullptr);

private slots:
    void slotSendDatagram();
};

#endif // UDPSERVER_H
