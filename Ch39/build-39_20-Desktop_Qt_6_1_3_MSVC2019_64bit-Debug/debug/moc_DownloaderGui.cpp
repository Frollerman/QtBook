/****************************************************************************
** Meta object code from reading C++ file 'DownloaderGui.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../39_20/DownloaderGui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DownloaderGui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DownloaderGui_t {
    const uint offsetsAndSize[12];
    char stringdata0[62];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_DownloaderGui_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_DownloaderGui_t qt_meta_stringdata_DownloaderGui = {
    {
QT_MOC_LITERAL(0, 13), // "DownloaderGui"
QT_MOC_LITERAL(14, 6), // "slotGo"
QT_MOC_LITERAL(21, 0), // ""
QT_MOC_LITERAL(22, 9), // "slotError"
QT_MOC_LITERAL(32, 20), // "slotDownloadProgress"
QT_MOC_LITERAL(53, 8) // "slotDone"

    },
    "DownloaderGui\0slotGo\0\0slotError\0"
    "slotDownloadProgress\0slotDone"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DownloaderGui[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x08,    0 /* Private */,
       3,    0,   39,    2, 0x08,    1 /* Private */,
       4,    2,   40,    2, 0x08,    2 /* Private */,
       5,    2,   45,    2, 0x08,    5 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    2,    2,
    QMetaType::Void, QMetaType::QUrl, QMetaType::QByteArray,    2,    2,

       0        // eod
};

void DownloaderGui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DownloaderGui *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->slotGo(); break;
        case 1: _t->slotError(); break;
        case 2: _t->slotDownloadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 3: _t->slotDone((*reinterpret_cast< const QUrl(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject DownloaderGui::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_DownloaderGui.offsetsAndSize,
    qt_meta_data_DownloaderGui,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_DownloaderGui_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<qint64, std::false_type>, QtPrivate::TypeAndForceComplete<qint64, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QUrl &, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>


>,
    nullptr
} };


const QMetaObject *DownloaderGui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DownloaderGui::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DownloaderGui.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DownloaderGui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
