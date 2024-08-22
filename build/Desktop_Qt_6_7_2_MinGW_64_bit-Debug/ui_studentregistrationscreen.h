/********************************************************************************
** Form generated from reading UI file 'studentregistrationscreen.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTREGISTRATIONSCREEN_H
#define UI_STUDENTREGISTRATIONSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentRegistrationScreen
{
public:
    QWidget *centralwidget;
    QLabel *titleText;
    QToolButton *ToggleFullScreen;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *nameLabel;
    QLineEdit *nameEditField;
    QLabel *emailLabel;
    QLineEdit *emailEditField;
    QLabel *studentIdLabel;
    QLineEdit *studentIdEditField;
    QLabel *numberLabel;
    QLineEdit *numberEditField;
    QLabel *departmentLabel;
    QLineEdit *departmentEditField;
    QPushButton *studentRegistrationButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *StudentRegistrationScreen)
    {
        if (StudentRegistrationScreen->objectName().isEmpty())
            StudentRegistrationScreen->setObjectName("StudentRegistrationScreen");
        StudentRegistrationScreen->resize(1603, 929);
        centralwidget = new QWidget(StudentRegistrationScreen);
        centralwidget->setObjectName("centralwidget");
        titleText = new QLabel(centralwidget);
        titleText->setObjectName("titleText");
        titleText->setGeometry(QRect(530, 100, 861, 151));
        ToggleFullScreen = new QToolButton(centralwidget);
        ToggleFullScreen->setObjectName("ToggleFullScreen");
        ToggleFullScreen->setGeometry(QRect(1590, 30, 25, 27));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(600, 250, 321, 341));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        nameLabel = new QLabel(widget);
        nameLabel->setObjectName("nameLabel");

        verticalLayout->addWidget(nameLabel);

        nameEditField = new QLineEdit(widget);
        nameEditField->setObjectName("nameEditField");

        verticalLayout->addWidget(nameEditField);

        emailLabel = new QLabel(widget);
        emailLabel->setObjectName("emailLabel");

        verticalLayout->addWidget(emailLabel);

        emailEditField = new QLineEdit(widget);
        emailEditField->setObjectName("emailEditField");

        verticalLayout->addWidget(emailEditField);

        studentIdLabel = new QLabel(widget);
        studentIdLabel->setObjectName("studentIdLabel");

        verticalLayout->addWidget(studentIdLabel);

        studentIdEditField = new QLineEdit(widget);
        studentIdEditField->setObjectName("studentIdEditField");

        verticalLayout->addWidget(studentIdEditField);

        numberLabel = new QLabel(widget);
        numberLabel->setObjectName("numberLabel");

        verticalLayout->addWidget(numberLabel);

        numberEditField = new QLineEdit(widget);
        numberEditField->setObjectName("numberEditField");

        verticalLayout->addWidget(numberEditField);

        departmentLabel = new QLabel(widget);
        departmentLabel->setObjectName("departmentLabel");

        verticalLayout->addWidget(departmentLabel);

        departmentEditField = new QLineEdit(widget);
        departmentEditField->setObjectName("departmentEditField");

        verticalLayout->addWidget(departmentEditField);

        studentRegistrationButton = new QPushButton(widget);
        studentRegistrationButton->setObjectName("studentRegistrationButton");

        verticalLayout->addWidget(studentRegistrationButton);

        StudentRegistrationScreen->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(StudentRegistrationScreen);
        statusbar->setObjectName("statusbar");
        StudentRegistrationScreen->setStatusBar(statusbar);

        retranslateUi(StudentRegistrationScreen);

        QMetaObject::connectSlotsByName(StudentRegistrationScreen);
    } // setupUi

    void retranslateUi(QMainWindow *StudentRegistrationScreen)
    {
        StudentRegistrationScreen->setWindowTitle(QCoreApplication::translate("StudentRegistrationScreen", "MainWindow", nullptr));
        titleText->setText(QCoreApplication::translate("StudentRegistrationScreen", "Student Registration Portal", nullptr));
        ToggleFullScreen->setText(QCoreApplication::translate("StudentRegistrationScreen", "][", nullptr));
        nameLabel->setText(QCoreApplication::translate("StudentRegistrationScreen", "Name:", nullptr));
        emailLabel->setText(QCoreApplication::translate("StudentRegistrationScreen", "Email:", nullptr));
        studentIdLabel->setText(QCoreApplication::translate("StudentRegistrationScreen", "Student ID:", nullptr));
        numberLabel->setText(QCoreApplication::translate("StudentRegistrationScreen", "Number:", nullptr));
        departmentLabel->setText(QCoreApplication::translate("StudentRegistrationScreen", "Department:", nullptr));
        studentRegistrationButton->setText(QCoreApplication::translate("StudentRegistrationScreen", "Register", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentRegistrationScreen: public Ui_StudentRegistrationScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTREGISTRATIONSCREEN_H
