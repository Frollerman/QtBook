#include "mainwindow.h"

#include <QApplication>
#include <QSet>
#include <QtCore>
//-------------------------------------------QHash and QMultiHash

int main(int argc, char *argv[])
{
    //-----Associative Containers----------------------

    //------------------------------------------QMap and QMultiMap

    QMap<QString, QString> mapPhonebook;
    mapPhonebook["Piggy"] = "+49 631322187";
    mapPhonebook["Kermit"] = "+49 631322181";
    mapPhonebook["Gonzo"] = "+49 631322186";

    QMap<QString, QString>::iterator it = mapPhonebook.begin();
    for (;it != mapPhonebook.end(); ++it)
    {
        qDebug() << "Name:" << it.key()
                 << " Phone:" << it.value();
    }

    if (mapPhonebook.contains("Kermit"))
    {
        qDebug() << "Phone:" << mapPhonebook["Kermit"];
    }

    QMultiMap<QString, QString> multiMapPhonebook;
    multiMapPhonebook.insert("Kermit", "+49 631322181");
    multiMapPhonebook.insert("Gonzo", "+49 631322186");
    multiMapPhonebook.insert("Gonzo", "+49 631322000");
    multiMapPhonebook.insert("Gonzo", "+49 631322010");
    multiMapPhonebook.insert("Piggy", "+49 631322187");
    multiMapPhonebook.insert("Piggy", "+49 631322999");

    QMultiMap<QString, QString>::iterator mit =
                                    multiMapPhonebook.find("Piggy");
    for (; mit != multiMapPhonebook.end() && mit.key() == "Piggy"; ++mit)
    {
        qDebug() << mit.value();
    }

//    class MyClass
//    {
//    public:
//        QString firstName;
//        QString secondName;
//    };

//    inline bool operator==(const MyClass& mc1, const MyClass& mc2)
//    {
//        return (mc1.firstName() == mc2.firstName()
//                && mc1.secondName() == mc2.secondName()
//                );
//    }

//    inline uint qHash(const MyClass& mc)
//    {
//        return qHash(mc.firstName()) ^ qHash(mc.secondName());
//    }

    //-----------------------------------------------------QSet

    QSet<QString> set1;
    QSet<QString> set2;

    set1 << "Therion" << "Nightwish" << "Xandria";
    set2 << "Mantus" << "Haggard" << "Therion";

//    QList<QString> list1;
//    QList<QString> list2;
//    QList<QString> list3;

    QSet<QString> setResult = set1;
    setResult.unite(set2);
    //list1 = setResult.toList();
    //qDebug() << "Unity = " << setResult.toList();
    qDebug() << "Unity = " << setResult.values();

    setResult = set1;
    setResult.intersect(set2);
    qDebug() << "Intersection of set1 with set2 = " << setResult.values();

    setResult = set1;
    setResult.subtract(set2);
    qDebug() << "Subtraction of set2 from set1 = " << setResult.values();



    return 0;
}
