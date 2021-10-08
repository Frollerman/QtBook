#include <QtWidgets>

class MyClass : public QWidget
{
    Q_OBJECT
private:

public:
    void paintEvent(QPaintEvent* pe) override;
};

void MyClass::paintEvent(QPaintEvent* pe)
{
    QPainter painter(this);
    QRect r(40, 40, 100, 100);

    if (pe->region().contains(r))
    {
        painter.drawRect(r);
    }
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget wgt;



    wgt.show();

    return app.exec();
}
