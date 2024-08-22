/********************************************************************************
** Form generated from reading UI file 'studentprofilescreen.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTPROFILESCREEN_H
#define UI_STUDENTPROFILESCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentProfileScreen
{
public:
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *StudentProfileScreen)
    {
        if (StudentProfileScreen->objectName().isEmpty())
            StudentProfileScreen->setObjectName("StudentProfileScreen");
        StudentProfileScreen->resize(640, 480);
        centralwidget = new QWidget(StudentProfileScreen);
        centralwidget->setObjectName("centralwidget");
        StudentProfileScreen->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(StudentProfileScreen);
        statusbar->setObjectName("statusbar");
        StudentProfileScreen->setStatusBar(statusbar);

        retranslateUi(StudentProfileScreen);

        QMetaObject::connectSlotsByName(StudentProfileScreen);
    } // setupUi

    void retranslateUi(QMainWindow *StudentProfileScreen)
    {
        StudentProfileScreen->setWindowTitle(QCoreApplication::translate("StudentProfileScreen", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentProfileScreen: public Ui_StudentProfileScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTPROFILESCREEN_H
