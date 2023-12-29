/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.1. It"
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
struct qt_meta_stringdata_CLASSmainwindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSmainwindowENDCLASS = QtMocHelpers::stringData(
    "mainwindow",
    "Image_Processing",
    "",
    "QLabel*",
    "on_Contrast_clicked",
    "on_Load_Image_clicked",
    "on_Crop_Image_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSmainwindowENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[11];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[20];
    char stringdata5[22];
    char stringdata6[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSmainwindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSmainwindowENDCLASS_t qt_meta_stringdata_CLASSmainwindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "mainwindow"
        QT_MOC_LITERAL(11, 16),  // "Image_Processing"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 7),  // "QLabel*"
        QT_MOC_LITERAL(37, 19),  // "on_Contrast_clicked"
        QT_MOC_LITERAL(57, 21),  // "on_Load_Image_clicked"
        QT_MOC_LITERAL(79, 21)   // "on_Crop_Image_clicked"
    },
    "mainwindow",
    "Image_Processing",
    "",
    "QLabel*",
    "on_Contrast_clicked",
    "on_Load_Image_clicked",
    "on_Crop_Image_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSmainwindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   38,    2, 0x08,    1 /* Private */,
       4,    0,   43,    2, 0x08,    4 /* Private */,
       5,    0,   44,    2, 0x08,    5 /* Private */,
       6,    0,   45,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::QImage, QMetaType::QImage, 0x80000000 | 3,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject mainwindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSmainwindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSmainwindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSmainwindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<mainwindow, std::true_type>,
        // method 'Image_Processing'
        QtPrivate::TypeAndForceComplete<QImage, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QImage &, std::false_type>,
        QtPrivate::TypeAndForceComplete<QLabel *, std::false_type>,
        // method 'on_Contrast_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Load_Image_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Crop_Image_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void mainwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<mainwindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { QImage _r = _t->Image_Processing((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QLabel*>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->on_Contrast_clicked(); break;
        case 2: _t->on_Load_Image_clicked(); break;
        case 3: _t->on_Crop_Image_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QLabel* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *mainwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mainwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSmainwindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int mainwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
