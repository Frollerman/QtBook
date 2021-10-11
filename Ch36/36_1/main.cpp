#include <QApplication>
#include "FileFinder.h"

// ----------------------------------------------------------------------
int main (int argc, char** argv)
{
    QApplication app(argc, argv);

    FileFinder fileFinder;

    fileFinder.resize(370, 240);
    fileFinder.show();

    return app.exec();
}
