/********************************************************************************
** Form generated from reading UI file 'borrowscreen.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BORROWSCREEN_H
#define UI_BORROWSCREEN_H

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

class Ui_BorrowScreen
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QPushButton *borrowButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BorrowScreen)
    {
        if (BorrowScreen->objectName().isEmpty())
            BorrowScreen->setObjectName("BorrowScreen");
        BorrowScreen->resize(927, 511);
        centralwidget = new QWidget(BorrowScreen);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(310, 60, 481, 151));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(350, 220, 133, 119));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName("lineEdit");

        verticalLayout->addWidget(lineEdit);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName("lineEdit_2");

        verticalLayout->addWidget(lineEdit_2);

        borrowButton = new QPushButton(centralwidget);
        borrowButton->setObjectName("borrowButton");
        borrowButton->setGeometry(QRect(380, 350, 83, 29));
        BorrowScreen->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(BorrowScreen);
        statusbar->setObjectName("statusbar");
        BorrowScreen->setStatusBar(statusbar);

        retranslateUi(BorrowScreen);

        QMetaObject::connectSlotsByName(BorrowScreen);
    } // setupUi

    void retranslateUi(QMainWindow *BorrowScreen)
    {
        BorrowScreen->setWindowTitle(QCoreApplication::translate("BorrowScreen", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("BorrowScreen", "Borrow Portal", nullptr));
        label_2->setText(QCoreApplication::translate("BorrowScreen", "Student ID:", nullptr));
        label_3->setText(QCoreApplication::translate("BorrowScreen", "Book ISBN Number:", nullptr));
        borrowButton->setText(QCoreApplication::translate("BorrowScreen", "Borrow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BorrowScreen: public Ui_BorrowScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BORROWSCREEN_H
