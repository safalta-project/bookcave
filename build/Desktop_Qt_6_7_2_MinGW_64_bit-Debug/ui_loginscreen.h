/********************************************************************************
** Form generated from reading UI file 'loginscreen.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINSCREEN_H
#define UI_LOGINSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginScreen
{
public:
    QWidget *centralwidget;
    QPushButton *toggleFullscreenButton;
    QLabel *title_label;
    QPushButton *loginButton;
    QLineEdit *username_field;
    QLabel *username_label;
    QLabel *password_label;
    QLineEdit *password_field;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginScreen)
    {
        if (LoginScreen->objectName().isEmpty())
            LoginScreen->setObjectName("LoginScreen");
        LoginScreen->resize(1553, 879);
        centralwidget = new QWidget(LoginScreen);
        centralwidget->setObjectName("centralwidget");
        toggleFullscreenButton = new QPushButton(centralwidget);
        toggleFullscreenButton->setObjectName("toggleFullscreenButton");
        toggleFullscreenButton->setGeometry(QRect(1500, 10, 31, 21));
        title_label = new QLabel(centralwidget);
        title_label->setObjectName("title_label");
        title_label->setGeometry(QRect(670, 180, 241, 141));
        loginButton = new QPushButton(centralwidget);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(670, 560, 191, 41));
        username_field = new QLineEdit(centralwidget);
        username_field->setObjectName("username_field");
        username_field->setGeometry(QRect(630, 430, 259, 28));
        username_label = new QLabel(centralwidget);
        username_label->setObjectName("username_label");
        username_label->setGeometry(QRect(630, 370, 259, 63));
        password_label = new QLabel(centralwidget);
        password_label->setObjectName("password_label");
        password_label->setGeometry(QRect(630, 470, 259, 31));
        password_field = new QLineEdit(centralwidget);
        password_field->setObjectName("password_field");
        password_field->setGeometry(QRect(630, 510, 259, 28));
        LoginScreen->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(LoginScreen);
        statusbar->setObjectName("statusbar");
        LoginScreen->setStatusBar(statusbar);

        retranslateUi(LoginScreen);

        QMetaObject::connectSlotsByName(LoginScreen);
    } // setupUi

    void retranslateUi(QMainWindow *LoginScreen)
    {
        LoginScreen->setWindowTitle(QCoreApplication::translate("LoginScreen", "LoginScreen", nullptr));
        toggleFullscreenButton->setText(QCoreApplication::translate("LoginScreen", "\360\237\227\226", nullptr));
        title_label->setText(QCoreApplication::translate("LoginScreen", "Bookcave", nullptr));
        loginButton->setText(QCoreApplication::translate("LoginScreen", "Login", nullptr));
        username_label->setText(QCoreApplication::translate("LoginScreen", "Username:", nullptr));
        password_label->setText(QCoreApplication::translate("LoginScreen", "Password:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginScreen: public Ui_LoginScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINSCREEN_H
