/****************************************************************************
** Meta object code from reading C++ file 'myserver.h'
**
** Created: Mon Jul 26 00:14:21 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../myserver.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyServer[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      39,   37,    9,    9, 0x05,
      77,    9,    9,    9, 0x05,
     102,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
     132,    9,    9,    9, 0x08,
     142,    9,    9,    9, 0x08,
     163,  151,    9,    9, 0x08,
     206,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MyServer[] = {
    "MyServer\0\0updateTextBrowser(QString)\0"
    ",\0updateTextBrowserDlg(QString,QString)\0"
    "addtoListWidget(QString)\0"
    "deletefromListWidget(QString)\0Service()\0"
    "Accept()\0socketError\0"
    "DisplayError(QAbstractSocket::SocketError)\0"
    "OnDisconnected()\0"
};

const QMetaObject MyServer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MyServer,
      qt_meta_data_MyServer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyServer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyServer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyServer))
        return static_cast<void*>(const_cast< MyServer*>(this));
    return QObject::qt_metacast(_clname);
}

int MyServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updateTextBrowser((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: updateTextBrowserDlg((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: addtoListWidget((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: deletefromListWidget((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: Service(); break;
        case 5: Accept(); break;
        case 6: DisplayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 7: OnDisconnected(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void MyServer::updateTextBrowser(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyServer::updateTextBrowserDlg(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyServer::addtoListWidget(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyServer::deletefromListWidget(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
