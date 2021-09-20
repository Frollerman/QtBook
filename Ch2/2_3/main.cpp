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
