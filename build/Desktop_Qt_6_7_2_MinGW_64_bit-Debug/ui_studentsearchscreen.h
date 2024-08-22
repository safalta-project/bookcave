/********************************************************************************
** Form generated from reading UI file 'studentsearchscreen.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTSEARCHSCREEN_H
#define UI_STUDENTSEARCHSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentSearchScreen
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *StudentSearchScreen)
    {
        if (StudentSearchScreen->objectName().isEmpty())
            StudentSearchScreen->setObjectName("StudentSearchScreen");
        StudentSearchScreen->resize(785, 512);
        centralwidget = new QWidget(StudentSearchScreen);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(240, 130, 351, 131));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(160, 280, 461, 94));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName("lineEdit");

        verticalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        StudentSearchScreen->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(StudentSearchScreen);
        statusbar->setObjectName("statusbar");
        StudentSearchScreen->setStatusBar(statusbar);

        retranslateUi(StudentSearchScreen);

        QMetaObject::connectSlotsByName(StudentSearchScreen);
    } // setupUi

    void retranslateUi(QMainWindow *StudentSearchScreen)
    {
        StudentSearchScreen->setWindowTitle(QCoreApplication::translate("StudentSearchScreen", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("StudentSearchScreen", "Student Search ", nullptr));
        label_2->setText(QCoreApplication::translate("StudentSearchScreen", "Student ID:", nullptr));
        pushButton->setText(QCoreApplication::translate("StudentSearchScreen", "Search \360\237\224\215 ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentSearchScreen: public Ui_StudentSearchScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTSEARCHSCREEN_H
