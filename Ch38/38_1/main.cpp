#include <QApplication>
#include "Shell.h"

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    Shell        shell;

    shell.setWindowTitle("Command Shell");
    shell.resize(320, 240);
    shell.show();

    return app.exec();
}
