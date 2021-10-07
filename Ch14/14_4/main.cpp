#include <QtWidgets>

// ======================================================================
class ResizeObserver : public QLabel
{
public:
    ResizeObserver(QWidget* pwgt = nullptr) : QLabel(pwgt)
    {
        setAlignment(Qt::AlignCenter);
    }

protected:
    virtual void resizeEvent(QResizeEvent* pe)
    {
        setText(QString("Resized")
                + "\n width()=" + QString::number(pe->size().width())
                + "\n height()=" + QString::number(pe->size().height())
                );
    }
};

// =======================================================================
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    ResizeObserver wgt;

    wgt.resize(250, 130);
    wgt.show();

    return app.exec();
}
