/********************************************************************************
** Form generated from reading UI file 'borrowedbooksscreen.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BORROWEDBOOKSSCREEN_H
#define UI_BORROWEDBOOKSSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BorrowedBooksScreen
{
public:
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BorrowedBooksScreen)
    {
        if (BorrowedBooksScreen->objectName().isEmpty())
            BorrowedBooksScreen->setObjectName("BorrowedBooksScreen");
        BorrowedBooksScreen->resize(924, 547);
        centralwidget = new QWidget(BorrowedBooksScreen);
        centralwidget->setObjectName("centralwidget");
        BorrowedBooksScreen->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(BorrowedBooksScreen);
        statusbar->setObjectName("statusbar");
        BorrowedBooksScreen->setStatusBar(statusbar);

        retranslateUi(BorrowedBooksScreen);

        QMetaObject::connectSlotsByName(BorrowedBooksScreen);
    } // setupUi

    void retranslateUi(QMainWindow *BorrowedBooksScreen)
    {
        BorrowedBooksScreen->setWindowTitle(QCoreApplication::translate("BorrowedBooksScreen", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BorrowedBooksScreen: public Ui_BorrowedBooksScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BORROWEDBOOKSSCREEN_H
