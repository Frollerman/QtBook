#include <QObject>

class MyClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool readOnly READ isReadOnly WRITE setReadOnly)

private:
    bool m_bReadOnly;

public:
    MyClass(QObject* pobj = 0) : QObject(pobj)
                               , m_bReadOnly(false)
    {
    }

public:
    void setReadOnly(bool bReadOnly)
    {
        m_bReadOnly = bReadOnly;
    }

    bool isReadOnly() const
    {
        return m_bReadOnly;
    }
};

const QMetaObject* pmo = pobj->metaObject();
for (int i = 0; i < pmo->propertyCount(); ++i)
{
    const QMetaProperty mp = pmo-property(i);
    qDebug() << "Property#:" << i;
    qDebug() << "Type:" << mp.typename();
    qDebug() << "Name:" << mp.name();
    qDebug() << "Value:" << pobj->property(mp.name());
}

