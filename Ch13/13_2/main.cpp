#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget wgt;

    QPalette pal(Qt::red, Qt::blue);
    QApplication::setPalette(pal);

    wgt.show();

    return app.exec();
}
