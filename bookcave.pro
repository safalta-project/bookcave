QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    allbooksscreen.cpp \
    bookentryscreen.cpp \
    booklistscreen.cpp \
    borrowedbooksscreen.cpp \
    borrowscreen.cpp \
    dashboardscreen.cpp \
    genrescreen.cpp \
    main.cpp \
    loginscreen.cpp \
    studentprofilescreen.cpp \
    studentregistrationscreen.cpp \
    studentsearchscreen.cpp

HEADERS += \
    allbooksscreen.h \
    bookentryscreen.h \
    booklistscreen.h \
    borrowedbooksscreen.h \
    borrowscreen.h \
    dashboardscreen.h \
    genrescreen.h \
    loginscreen.h \
    studentprofilescreen.h \
    studentregistrationscreen.h \
    studentsearchscreen.h

FORMS += \
    allbooksscreen.ui \
    bookentryscreen.ui \
    booklistscreen.ui \
    borrowedbooksscreen.ui \
    borrowscreen.ui \
    dashboardscreen.ui \
    genrescreen.ui \
    loginscreen.ui \
    studentprofilescreen.ui \
    studentregistrationscreen.ui \
    studentsearchscreen.ui

# Resource File
RESOURCES += resources/resources.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
