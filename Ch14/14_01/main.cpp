#include <QtWidgets>

void MyWidget::keyPressEvent(QKeyEvent* pe)
{
    switch (pe->key())
    {
        case Qt::Key_Z:
        {
            if (pe->modifiers() & Qt::ShiftModifier)
            {
                //Do smth
            }
            else
            {
                //Do smth else
            }
            break;
        }
        default:
            QWidget::keyPressEvent(pe); //Send further
    }
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);



    return app.exec();
}
