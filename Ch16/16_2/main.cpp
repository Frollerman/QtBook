#include <QtWidgets>

void mousePress(QWidget* pwgt,
                int x,
                int y,
                Qt::MouseButton bt = Qt::LeftButton,
                Qt::MouseButtons bts = Qt::LeftButton
                )
{
    if (pwgt)
    {
        QMouseEvent* pePress =
                new QMouseEvent(QEvent::MouseButtonPress,
                                QPoint(x, y),
                                bt,
                                bts,
                                Qt::NoModifier
                                );
        QApplication::postEvent(pwgt, pePress);
    }
}

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QLineEdit txt("Edit");
    txt.show();
    txt.resize(300,30);

    app.exec();
}
