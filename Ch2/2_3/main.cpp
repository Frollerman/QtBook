#include <QObject>

class CPhotoStylerApp : public CWinApp
{
public:
    CPhotoStylerApp();
public:
    virtual BOOL InitInstance();

    afx_msg void OnAppAbout();
    afx_msg void OnFileNew();

    DECLARE_MESSAGE_MAP();
};
BEGIN_MESSAGE_MAP(CPhotoStylerApp, CWinApp)
    ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
    ON_COMMAND(ID_FILE_NEW, OnFileNew)
    ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
    ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
    ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

//////////////////////////////////////////

class MySignal
{
    Q_OBJECT
    //...
    signals:
        void doIt();
    //...
};

//////////////////////////////////////////

class MySignal
{
    Q_OBJECT
public:
    void sendSignal()
    {
        emit doIt();
    }
signals:
    void doIt();
};

//////////////////////////////////////////

class MySignal : public QObject
{
    Q_OBJECT
public:
    void sendSignal()
    {
        emit sendString("Information");
    }
signals:
    void sendString(const QString&);
};

//////////////////////////////////////////

class MySlot : public QObject
{
    Q_OBJECT
public:
    MySlot();
public slots:
    void slot()
    {
        //qDebug() << "I'm a slot";
        qDebug() << sender()->objectName();
    }
};

//////////////////////////////////////////

QObject::connect(const QObject*     sender,
                 const char*        signal,
                 const QObject*     receiver,
                 const char*        slot,
                 Qt::ConnectionType type = Qt::AutoConnection
                );

//////////////////////////////////////////Alt

QObject::connect(const QObject*     sender,
                 const QMetaMethod& signal,
                 const QObject*     receiver,
                 const QMetaMethod& slot,
                 Qt::ConnectionType type = Qt::AutoConnection
                );

//////////////////////////////////////////

void main ()
{
    //...
    QObject::connect(pSender, SIGNAL(signalMethod()),
                     pReceiver, SLOT(slotMethod())
                    );
    //...
}

//////////////////////////////////////////Alt

QObject::connect(pSender, &SenderClass::signalMethod,
                 pReceiver, &ReceiverClass::slotMethod
                );

//////////////////////////////////////////

MyClass::MyClass() : QObject()
{
    //...
    connect(pSender, SIGNAL(signalMethod()),
            pReceiver, SLOT(slotMethod())
           );
    //...
}

//////////////////////////////////////////

MyClass::MyClass() : QObject()
{
    connect(pSender, SIGNAL(signalMethod()), SLOT(slot()));
}
void MyClass::slot()
{
    qDebug() << "I'm a slot";
}

//////////////////////////////////////////

bool bOk = true;
bOk &= connect(pcmd1, SIGNAL(clicked()), pobjReceiver1, SLOT(slotButton1Clicked()));
bOk &= connect(pcmd2, SIGNAL(clicked()), pobjReceiver2, SLOT(slotButton2Clicked()));
Q_ASSERT(bOk);

//////////////////////////////////////////

MyClass::MyClass() : QObject()
{
    connect(pSender, SIGNAL(signalMethod()), SIGNAL(mySignal()));
}

//////////////////////////////////////////lambda function

connect(pcmd, &QPushButton::clicked, [=](){pwgt->hide();});

///////////////////////////////////////////////////////////

QObject::disconnect(sender, signal, receiver, slot);

///////////////////////////////////////////////////////////

void main()
{
    //...
    QObject::disconnect(pSender, SIGNAL(signalMethod()),
                        pReceiver, SLOT(slotMethod())
                       );
    //...
}

//disconnect(signal, receiver, slot)
//disconnect(receiver, slot)

///////////////////////////////////////////////////////////

MyClass::MyClass(QWidget* pwgt)
{
    //...
    QSignalMapper* psigMapper = new QSignalMapper(this);
    connect(psigMapper, SIGNAL(mapped(const QString&)),
            this,       SLOT(slotShowAction(const QString&))
           );

    QPushButton* pcmd1 = new QPushButton("Button1");
    connect(pcmd1, SIGNAL(clicked()), psigMapper, SLOT(map()));
    psigMapper->setMapping(pcmd1, "Button1 Action");

    QPushButton* pcmd2 = new QPushButton("Button2");
    connect(pcmd2, SIGNAL(clicked()), psigMapper, SLOT(map()));
    psigMapper->setMapping(pcmd1, "Button2 Action");
    //...
}

void MyClass::slotShowAction(const QString& str)
{
    qDebug() << str;
}

//////////////////////////////////////////////////////////class hierarchy

QObject* pobj1 = new QObject;
QObject* pobj2 = new QObject(pobj1);
QObject* pobj4 = new QObject(pobj2);
QObject* pobj3 = new QObject(pobj1);
pobj2->setObjectName("the first child of pobj1");
pobj3->setObjectName("the second child of pobj1");
pobj4->setObjectName("the first child of pobj2");

///////////////////////////////////////////////////////////object parent name output

for (QObject* pobj = pobj4; pobj; pobj = pobj->parent())
{
    qDebug() << pobj->objectName();
}

QObject* pobj = pobj1->findChild<QObject*>("the first child of pobj2");

QList<QObject*> plist = pobj1->findChildren<QObject*>(QRegExp("th*"));

QList<QObject*> plist = pobj1->findChildren<QObject*>();

//dumpObjectInfo(); //get name, parent class and signal-slot connections

//dumpObjectTree(); //show children objects' hierarchy

///////////////////////////////////////////////////////////

qDebug() << pobj->metaObject()->className(); // get parent name from meta

if (pobj1->metaObject()->className() == "MyClass") //compare class name with known
{
    //Do something
}

if(pobj->inherits("QWidjet")) //get class inheritance info
{
    QWidget* pwgt = static_cast<QWidget*>(pobj);
    //Do something with pwgt
}

QWidget* pwgt = qobject_cast<QWidget*>(pobj);
if(pwgt)
{
    //Do something with pwgt
}
