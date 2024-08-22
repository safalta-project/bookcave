/********************************************************************************
** Form generated from reading UI file 'booklistscreen.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKLISTSCREEN_H
#define UI_BOOKLISTSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BookListScreen
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BookListScreen)
    {
        if (BookListScreen->objectName().isEmpty())
            BookListScreen->setObjectName("BookListScreen");
        BookListScreen->resize(1297, 940);
        centralwidget = new QWidget(BookListScreen);
        centralwidget->setObjectName("centralwidget");
        BookListScreen->setCentralWidget(centralwidget);
        menubar = new QMenuBar(BookListScreen);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1297, 25));
        BookListScreen->setMenuBar(menubar);
        statusbar = new QStatusBar(BookListScreen);
        statusbar->setObjectName("statusbar");
        BookListScreen->setStatusBar(statusbar);

        retranslateUi(BookListScreen);

        QMetaObject::connectSlotsByName(BookListScreen);
    } // setupUi

    void retranslateUi(QMainWindow *BookListScreen)
    {
        BookListScreen->setWindowTitle(QCoreApplication::translate("BookListScreen", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BookListScreen: public Ui_BookListScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKLISTSCREEN_H
