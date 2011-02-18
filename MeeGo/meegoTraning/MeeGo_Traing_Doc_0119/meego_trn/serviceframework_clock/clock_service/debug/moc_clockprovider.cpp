/****************************************************************************
** Meta object code from reading C++ file 'clockprovider.h'
**
** Created: Wed 12. Jan 13:26:29 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../clockprovider.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clockprovider.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ClockProvider[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   15,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      41,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ClockProvider[] = {
    "ClockProvider\0\0time\0hereItComes(QString)\0"
    "requestTime()\0"
};

const QMetaObject ClockProvider::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ClockProvider,
      qt_meta_data_ClockProvider, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ClockProvider::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ClockProvider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ClockProvider::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ClockProvider))
        return static_cast<void*>(const_cast< ClockProvider*>(this));
    return QObject::qt_metacast(_clname);
}

int ClockProvider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: hereItComes((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: requestTime(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ClockProvider::hereItComes(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
