#include <QApplication>
#include "UdpClient.h"

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    UdpClient client;

    client.show();

    return app.exec();
}
