#include <QApplication>
#include <QSettings>

// Пример для централизованного использования объекта настроек

class App : public QApplication
{
    Q_OBJECT

private:
    QSettings* m_pSettings;

public:
    App(int& argc,
        char** argv,
        const QString& strOrg,
        const QString& strAppName
        ) : QApplication(argc, argv)
          , m_pSettings(nullptr)
    {
        setOrganizationName(strOrg);
        setApplicationName(strAppName);

        m_pSettings = new QSettings(strOrg, strAppName, this);
    }

    static App* theApp()
    {
        return (App*)qApp;
    }

    QSettings* settings()
    {
        return m_pSettings;
    }
};


int main(int argc, char **argv)
{
    App app(argc, argv, "MyCompany", "MyApp");

//    QSettings* pst = App::theApp()->settings();
//    pst->setValue("Language", "en");

    return app.exec();
}
