/****************************************************************************
** Meta object code from reading C++ file 'clientinteractionview.h'
**
** Created: Mon Jul 26 01:17:59 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../clientinteractionview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clientinteractionview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ClientInterActionView[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   22,   22,   22, 0x05,

 // slots: signature, parameters, type, tag, flags
      50,   22,   22,   22, 0x0a,
      75,   22,   22,   22, 0x0a,
      99,   22,   22,   22, 0x0a,
     125,   22,   22,   22, 0x0a,
     175,  168,   22,   22, 0x0a,
     210,   22,   22,   22, 0x08,
     237,   22,   22,   22, 0x08,
     263,   22,   22,   22, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ClientInterActionView[] = {
    "ClientInterActionView\0\0"
    "updateTextBrowser(QString)\0"
    "on_radioButton_clicked()\0"
    "on_pushButton_clicked()\0"
    "processPendingDatagrams()\0"
    "DisplayError(QAbstractSocket::SocketError)\0"
    "str,ip\0setTextBrowserDlg(QString,QString)\0"
    "on_radioButton_2_clicked()\0"
    "on_pushButton_3_clicked()\0"
    "on_pushButton_2_clicked()\0"
};

const QMetaObject ClientInterActionView::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ClientInterActionView,
      qt_meta_data_ClientInterActionView, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ClientInterActionView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ClientInterActionView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ClientInterActionView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ClientInterActionView))
        return static_cast<void*>(const_cast< ClientInterActionView*>(this));
    if (!strcmp(_clname, "Ui::Dialog"))
        return static_cast< Ui::Dialog*>(const_cast< ClientInterActionView*>(this));
    return QDialog::qt_metacast(_clname);
}

int ClientInterActionView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updateTextBrowser((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: on_radioButton_clicked(); break;
        case 2: on_pushButton_clicked(); break;
        case 3: processPendingDatagrams(); break;
        case 4: DisplayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 5: setTextBrowserDlg((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: on_radioButton_2_clicked(); break;
        case 7: on_pushButton_3_clicked(); break;
        case 8: on_pushButton_2_clicked(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void ClientInterActionView::updateTextBrowser(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
