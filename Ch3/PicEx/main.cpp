#include <QtWidgets>
#include "Counter.h"

int main (int argc, char** argv)
{
    QApplication app(argc, argv);

    QLabel      lbl1("");
    QLabel*     plbl1 = &lbl1;

    QLabel      lbl2("");
    QLabel*     plbl2 = &lbl2;

    //QPushButton cmd("ADD");
    //Counter counter;

    plbl1->setPixmap(QPixmap(":/open.png"));
    plbl2->setPixmap(QPixmap(":/quit.png"));

    lbl1.show();
    lbl2.show();
    //cmd.show();

//    QObject::connect(&cmd, SIGNAL(clicked()),
//                     &counter, SLOT(slotInc())
//                    );

//    QObject::connect(&counter, SIGNAL(counterChanged(int)),
//                     &lbl, SLOT(setNum(int))
//                    );

//    QObject::connect(&counter, SIGNAL(goodbye()),
//                     &app, SLOT(quit())
//                    );

    return app.exec();
}
