#include <QtWidgets>

int main(int argc, char** argv)
{
    QApplication app(argc,argv);
    QWidget wgt;

    QPushButton* pcmdA = new QPushButton("A");
    QPushButton* pcmdB = new QPushButton("B");
    QPushButton* pcmdC = new QPushButton("C");

    //Layout setup

//    QHBoxLayout* phbxLayout = new QHBoxLayout;
//    phbxLayout->setContentsMargins(10, 10, 10, 10);
//    phbxLayout->setSpacing(20);
//    phbxLayout->addWidget(pcmdA,1);
//    phbxLayout->addWidget(pcmdB,2);
//    phbxLayout->addWidget(pcmdC,3);
//    wgt.setLayout(phbxLayout);

    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    pvbxLayout->setContentsMargins(10, 10, 10, 10);
    pvbxLayout->setSpacing(20);
    pvbxLayout->addWidget(pcmdA,1);
    pvbxLayout->addWidget(pcmdB,2);
    pvbxLayout->addWidget(pcmdC,3);
    wgt.setLayout(pvbxLayout);

    wgt.show();

    return app.exec();
}
