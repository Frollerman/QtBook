#include <QCoreApplication>
#include <QtXml>
#include <QXmlDefaultHandler>

class AddressBookParser : public QXmlDefaultHandler
{
private:
    QString m_strText;

public:
    // ----------------------------------------------------
    bool startElement(const QString&,
                      const QString&,
                      const QString&,
                      const QXmlAttributes& attrs
                      )
    {
        for(int i = 0; i < attrs.count(); i++)
        {
            if(attrs.localName(i) == "number")
            {
                qDebug() << "Attr: " << attrs.value(i);
            }
        }
        return true;
    }

    // ----------------------------------------------------

    bool characters(const QString& strText)
    {
        m_strText = strText;
        return true;
    }

    // -----------------------------------------------------

    bool endElement(const QString&, const QString& str)
    {
        if(str != "contact" && str != "addressbook")
        {
            qDebug() << "TagName: " << str
                     << "\tText: " << m_strText;
        }
        return true;
    }

    // -----------------------------------------------------

    bool fatalError(const QXmlParseException& exception)
    {
        qDebug() << "Line: " << exception.lineNumber()
                 << ", Column: " << exception.columnNumber()
                 << ", Message: " << exception.message();
        return false;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    AddressBookParser handler;
    QFile file("D:\\QtProjects\\Ch40\\build-40_6-Desktop_Qt_6_1_3_MSVC2019_64bit-Debug\\debug\\addressbook.xml");
    QXmlInputSource source(&file);
    QXmlSimpleReader reader;

    reader.setContentHandler(&handler);
    reader.parse(source);

    return app.exec();
}
