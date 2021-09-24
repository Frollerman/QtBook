#include <QtWidgets>

int main(int argc, char** argv)
{
    QApplication app(argc,argv);
    QWidget wgt;

    QPushButton* pcmdA = new QPushButton("A");
    QPushButton* pcmdB = new QPushButton("B");
    QPushButton* pcmdC = new QPushButton("C");
    QPushButton* pcmdD = new QPushButton("D");

    //Layout setup

    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    QHBoxLayout* phbxLayout = new QHBoxLayout;
    phbxLayout->setContentsMargins(5, 5, 5, 5);
    phbxLayout->setSpacing(15);
    phbxLayout->addWidget(pcmdC);
    phbxLayout->addWidget(pcmdD);

    pvbxLayout->setContentsMargins(5, 5, 5, 5);
    pvbxLayout->setSpacing(15);
    pvbxLayout->addWidget(pcmdA,1);
    pvbxLayout->addWidget(pcmdB,2);
    pvbxLayout->addLayout(phbxLayout);
    wgt.setLayout(pvbxLayout);

    wgt.show();

    return app.exec();
}
