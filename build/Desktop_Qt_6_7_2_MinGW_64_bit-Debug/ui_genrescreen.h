/********************************************************************************
** Form generated from reading UI file 'genrescreen.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENRESCREEN_H
#define UI_GENRESCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GenreScreen
{
public:
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GenreScreen)
    {
        if (GenreScreen->objectName().isEmpty())
            GenreScreen->setObjectName("GenreScreen");
        GenreScreen->resize(1665, 987);
        centralwidget = new QWidget(GenreScreen);
        centralwidget->setObjectName("centralwidget");
        GenreScreen->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(GenreScreen);
        statusbar->setObjectName("statusbar");
        GenreScreen->setStatusBar(statusbar);

        retranslateUi(GenreScreen);

        QMetaObject::connectSlotsByName(GenreScreen);
    } // setupUi

    void retranslateUi(QMainWindow *GenreScreen)
    {
        GenreScreen->setWindowTitle(QCoreApplication::translate("GenreScreen", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GenreScreen: public Ui_GenreScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENRESCREEN_H
