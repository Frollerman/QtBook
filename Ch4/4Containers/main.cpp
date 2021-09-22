#include "mainwindow.h"

#include <QApplication>
#include <QBitArray>
#include <QByteArray>
#include <QtCore>

int main(int argc, char *argv[])
{
    //----------------------------------------QVector

    QVector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    qDebug() << vec;

    QByteArray arr[3];
//    arr[0] = arr[1] = 0xFF;
//    arr[0] = 0xFF;
//    arr[1] = 0xFF;
//    arr[2] = 0x0;

    QByteArray a =           "Test Data";
    QByteArray aCompressed = qCompress(a);
    qDebug() << qUncompress(aCompressed);

    QByteArray aBase64 = a.toBase64();
    qDebug() << aBase64;

    qDebug() << QByteArray::fromBase64(aBase64);

    QBitArray bits(3);
    bits[0] = bits[1] = true;
    bits[2] = false;

    //------------------------------------------QList

    QList<int> list;
    list << 10 << 20 << 30;

    QList<int>::iterator it = list.begin();
    while (it != list.end())
    {
        qDebug() << "Element:" << *it;
        ++it;
    }

    //-------------------------------------------QStack

    QStack<QString> stk;
    stk.push("Era");
    stk.push("Corvus Corax");
    stk.push("Gathering");

    while (!stk.empty())
    {
        qDebug() << "Element:" << stk.pop();
    }

    //-------------------------------------------QQueue

    QQueue<QString> que;
    que.enqueue("Era");
    que.enqueue("Corvus Corax");
    que.enqueue("Gathering");

    while (!que.empty())
    {
        qDebug() << "Element:" << que.dequeue();
    }

    return 0;
}
