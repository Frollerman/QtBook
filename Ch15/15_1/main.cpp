#include <QtWidgets>
#include "MouseFilter.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QLineEdit txt("QLineEdit");
    txt.installEventFilter(new MouseFilter(&txt));
    txt.show();

    QLabel lbl("QLabel");
    lbl.installEventFilter(new MouseFilter(&lbl));
    lbl.show();

    QPushButton cmd("QpushButton");
    cmd.installEventFilter(new MouseFilter(&cmd));
    cmd.show();

    return app.exec();
}
