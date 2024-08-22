/********************************************************************************
** Form generated from reading UI file 'dashboardscreen.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBOARDSCREEN_H
#define UI_DASHBOARDSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DashboardScreen
{
public:
    QWidget *centralwidget;
    QLabel *titleLabel;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QCommandLinkButton *commandLinkButton_4;
    QCommandLinkButton *commandLinkButton;
    QCommandLinkButton *commandLinkButton_2;
    QCommandLinkButton *commandLinkButton_5;
    QCommandLinkButton *commandLinkButton_3;
    QCommandLinkButton *commandLinkButton_6;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DashboardScreen)
    {
        if (DashboardScreen->objectName().isEmpty())
            DashboardScreen->setObjectName("DashboardScreen");
        DashboardScreen->resize(1665, 986);
        centralwidget = new QWidget(DashboardScreen);
        centralwidget->setObjectName("centralwidget");
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setGeometry(QRect(600, 130, 391, 161));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(340, 400, 831, 161));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        commandLinkButton_4 = new QCommandLinkButton(layoutWidget);
        commandLinkButton_4->setObjectName("commandLinkButton_4");

        gridLayout->addWidget(commandLinkButton_4, 0, 0, 1, 1);

        commandLinkButton = new QCommandLinkButton(layoutWidget);
        commandLinkButton->setObjectName("commandLinkButton");

        gridLayout->addWidget(commandLinkButton, 0, 1, 1, 1);

        commandLinkButton_2 = new QCommandLinkButton(layoutWidget);
        commandLinkButton_2->setObjectName("commandLinkButton_2");

        gridLayout->addWidget(commandLinkButton_2, 0, 2, 1, 1);

        commandLinkButton_5 = new QCommandLinkButton(layoutWidget);
        commandLinkButton_5->setObjectName("commandLinkButton_5");

        gridLayout->addWidget(commandLinkButton_5, 1, 0, 1, 1);

        commandLinkButton_3 = new QCommandLinkButton(layoutWidget);
        commandLinkButton_3->setObjectName("commandLinkButton_3");

        gridLayout->addWidget(commandLinkButton_3, 1, 1, 1, 1);

        commandLinkButton_6 = new QCommandLinkButton(layoutWidget);
        commandLinkButton_6->setObjectName("commandLinkButton_6");

        gridLayout->addWidget(commandLinkButton_6, 1, 2, 1, 1);

        DashboardScreen->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(DashboardScreen);
        statusbar->setObjectName("statusbar");
        DashboardScreen->setStatusBar(statusbar);

        retranslateUi(DashboardScreen);

        QMetaObject::connectSlotsByName(DashboardScreen);
    } // setupUi

    void retranslateUi(QMainWindow *DashboardScreen)
    {
        DashboardScreen->setWindowTitle(QCoreApplication::translate("DashboardScreen", "MainWindow", nullptr));
        titleLabel->setText(QCoreApplication::translate("DashboardScreen", "Dashboard", nullptr));
        commandLinkButton_4->setText(QCoreApplication::translate("DashboardScreen", "All Books", nullptr));
        commandLinkButton->setText(QCoreApplication::translate("DashboardScreen", "Books By Genre", nullptr));
        commandLinkButton_2->setText(QCoreApplication::translate("DashboardScreen", "Book Borrow Portal", nullptr));
        commandLinkButton_5->setText(QCoreApplication::translate("DashboardScreen", "Search Student", nullptr));
        commandLinkButton_3->setText(QCoreApplication::translate("DashboardScreen", "Student Registration Portal", nullptr));
        commandLinkButton_6->setText(QCoreApplication::translate("DashboardScreen", "Book Entry Portal", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DashboardScreen: public Ui_DashboardScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARDSCREEN_H
