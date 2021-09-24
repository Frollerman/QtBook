#include <QtWidgets>

int main(int argc, char** argv)
{
    QApplication app(argc,argv);
    QWidget wgt;

    QPushButton* pcmdA = new QPushButton("A");
    QPushButton* pcmdB = new QPushButton("B");

    //Layout setup

    QBoxLayout* pbxLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    pbxLayout->addWidget(pcmdA,1);
    pbxLayout->addStretch(1);
    pbxLayout->addWidget(pcmdB,2);
    wgt.setLayout(pbxLayout);

    wgt.resize(350, 40);
    wgt.show();

    return app.exec();
}
