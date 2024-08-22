/********************************************************************************
** Form generated from reading UI file 'allbooksscreen.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALLBOOKSSCREEN_H
#define UI_ALLBOOKSSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AllBooksScreen
{
public:
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AllBooksScreen)
    {
        if (AllBooksScreen->objectName().isEmpty())
            AllBooksScreen->setObjectName("AllBooksScreen");
        AllBooksScreen->resize(1447, 842);
        centralwidget = new QWidget(AllBooksScreen);
        centralwidget->setObjectName("centralwidget");
        AllBooksScreen->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(AllBooksScreen);
        statusbar->setObjectName("statusbar");
        AllBooksScreen->setStatusBar(statusbar);

        retranslateUi(AllBooksScreen);

        QMetaObject::connectSlotsByName(AllBooksScreen);
    } // setupUi

    void retranslateUi(QMainWindow *AllBooksScreen)
    {
        AllBooksScreen->setWindowTitle(QCoreApplication::translate("AllBooksScreen", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AllBooksScreen: public Ui_AllBooksScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALLBOOKSSCREEN_H
