/****************************************************************************
** Meta object code from reading C++ file 'dashboardscreen.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../dashboardscreen.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dashboardscreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSDashboardScreenENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSDashboardScreenENDCLASS = QtMocHelpers::stringData(
    "DashboardScreen",
    "on_allBooksButton_clicked",
    "",
    "on_booksByGenreButton_clicked",
    "on_bookBorrowPortalButton_clicked",
    "on_studentInfoPortalButton_clicked",
    "on_studentRegistrationPortalButton_clicked",
    "on_bookEntryPortalButton_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSDashboardScreenENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    1 /* Private */,
       3,    0,   51,    2, 0x08,    2 /* Private */,
       4,    0,   52,    2, 0x08,    3 /* Private */,
       5,    0,   53,    2, 0x08,    4 /* Private */,
       6,    0,   54,    2, 0x08,    5 /* Private */,
       7,    0,   55,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject DashboardScreen::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSDashboardScreenENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSDashboardScreenENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSDashboardScreenENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<DashboardScreen, std::true_type>,
        // method 'on_allBooksButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_booksByGenreButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_bookBorrowPortalButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_studentInfoPortalButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_studentRegistrationPortalButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_bookEntryPortalButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void DashboardScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DashboardScreen *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_allBooksButton_clicked(); break;
        case 1: _t->on_booksByGenreButton_clicked(); break;
        case 2: _t->on_bookBorrowPortalButton_clicked(); break;
        case 3: _t->on_studentInfoPortalButton_clicked(); break;
        case 4: _t->on_studentRegistrationPortalButton_clicked(); break;
        case 5: _t->on_bookEntryPortalButton_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *DashboardScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DashboardScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSDashboardScreenENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int DashboardScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
