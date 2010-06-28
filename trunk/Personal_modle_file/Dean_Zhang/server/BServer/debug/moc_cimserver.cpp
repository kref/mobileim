/****************************************************************************
** Meta object code from reading C++ file 'cimserver.h'
**
** Created: Sun Jun 27 23:00:22 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cimserver.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cimserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CIMServer[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      49,   37,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CIMServer[] = {
    "CIMServer\0\0processPendingDatagrams()\0"
    "socketError\0DisplayError(QAbstractSocket::SocketError)\0"
};

const QMetaObject CIMServer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CIMServer,
      qt_meta_data_CIMServer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CIMServer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CIMServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CIMServer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CIMServer))
        return static_cast<void*>(const_cast< CIMServer*>(this));
    return QObject::qt_metacast(_clname);
}

int CIMServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: processPendingDatagrams(); break;
        case 1: DisplayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
