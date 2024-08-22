/********************************************************************************
** Form generated from reading UI file 'bookentryscreen.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKENTRYSCREEN_H
#define UI_BOOKENTRYSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BookEntryScreen
{
public:
    QWidget *centralwidget;
    QLabel *titleLabel;
    QToolButton *toggleButton;
    QLabel *designImage;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *bookNameLabel;
    QLineEdit *bookNameEdit;
    QLabel *authorLabel;
    QLineEdit *authorEdit;
    QLabel *isbnLabel;
    QLineEdit *isbnEdit;
    QLabel *genreLabel;
    QGridLayout *gridLayout;
    QRadioButton *csButton;
    QRadioButton *fictionButton;
    QRadioButton *mathButton;
    QRadioButton *engineeringButton;
    QRadioButton *physicsButton;
    QRadioButton *scifiButton;
    QRadioButton *nonFictionButton;
    QRadioButton *chemistryButton;
    QRadioButton *selfHelpButton;
    QRadioButton *novelButton;
    QRadioButton *historyButton;
    QRadioButton *literatureButton;
    QLabel *publisherLabel;
    QLineEdit *publisherEdit;
    QLabel *yearLabel;
    QLineEdit *yearEdit;
    QLabel *copiesLabel;
    QLineEdit *copiesEdit;
    QLabel *uploadLabel;
    QPushButton *uploadButton;
    QPushButton *saveButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BookEntryScreen)
    {
        if (BookEntryScreen->objectName().isEmpty())
            BookEntryScreen->setObjectName("BookEntryScreen");
        BookEntryScreen->resize(1454, 902);
        centralwidget = new QWidget(BookEntryScreen);
        centralwidget->setObjectName("centralwidget");
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setGeometry(QRect(30, 110, 511, 151));
        toggleButton = new QToolButton(centralwidget);
        toggleButton->setObjectName("toggleButton");
        toggleButton->setGeometry(QRect(1420, 10, 25, 27));
        designImage = new QLabel(centralwidget);
        designImage->setObjectName("designImage");
        designImage->setGeometry(QRect(70, 320, 301, 291));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(620, 50, 512, 625));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        bookNameLabel = new QLabel(layoutWidget);
        bookNameLabel->setObjectName("bookNameLabel");

        verticalLayout->addWidget(bookNameLabel);

        bookNameEdit = new QLineEdit(layoutWidget);
        bookNameEdit->setObjectName("bookNameEdit");

        verticalLayout->addWidget(bookNameEdit);

        authorLabel = new QLabel(layoutWidget);
        authorLabel->setObjectName("authorLabel");

        verticalLayout->addWidget(authorLabel);

        authorEdit = new QLineEdit(layoutWidget);
        authorEdit->setObjectName("authorEdit");

        verticalLayout->addWidget(authorEdit);

        isbnLabel = new QLabel(layoutWidget);
        isbnLabel->setObjectName("isbnLabel");

        verticalLayout->addWidget(isbnLabel);

        isbnEdit = new QLineEdit(layoutWidget);
        isbnEdit->setObjectName("isbnEdit");

        verticalLayout->addWidget(isbnEdit);

        genreLabel = new QLabel(layoutWidget);
        genreLabel->setObjectName("genreLabel");

        verticalLayout->addWidget(genreLabel);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        csButton = new QRadioButton(layoutWidget);
        csButton->setObjectName("csButton");

        gridLayout->addWidget(csButton, 0, 0, 1, 1);

        fictionButton = new QRadioButton(layoutWidget);
        fictionButton->setObjectName("fictionButton");

        gridLayout->addWidget(fictionButton, 2, 0, 1, 1);

        mathButton = new QRadioButton(layoutWidget);
        mathButton->setObjectName("mathButton");

        gridLayout->addWidget(mathButton, 2, 3, 1, 1);

        engineeringButton = new QRadioButton(layoutWidget);
        engineeringButton->setObjectName("engineeringButton");

        gridLayout->addWidget(engineeringButton, 0, 1, 1, 1);

        physicsButton = new QRadioButton(layoutWidget);
        physicsButton->setObjectName("physicsButton");

        gridLayout->addWidget(physicsButton, 2, 1, 1, 1);

        scifiButton = new QRadioButton(layoutWidget);
        scifiButton->setObjectName("scifiButton");

        gridLayout->addWidget(scifiButton, 0, 2, 1, 1);

        nonFictionButton = new QRadioButton(layoutWidget);
        nonFictionButton->setObjectName("nonFictionButton");

        gridLayout->addWidget(nonFictionButton, 0, 3, 1, 1);

        chemistryButton = new QRadioButton(layoutWidget);
        chemistryButton->setObjectName("chemistryButton");

        gridLayout->addWidget(chemistryButton, 1, 0, 1, 1);

        selfHelpButton = new QRadioButton(layoutWidget);
        selfHelpButton->setObjectName("selfHelpButton");

        gridLayout->addWidget(selfHelpButton, 1, 1, 1, 1);

        novelButton = new QRadioButton(layoutWidget);
        novelButton->setObjectName("novelButton");

        gridLayout->addWidget(novelButton, 1, 2, 1, 1);

        historyButton = new QRadioButton(layoutWidget);
        historyButton->setObjectName("historyButton");

        gridLayout->addWidget(historyButton, 2, 2, 1, 1);

        literatureButton = new QRadioButton(layoutWidget);
        literatureButton->setObjectName("literatureButton");

        gridLayout->addWidget(literatureButton, 1, 3, 1, 1);


        verticalLayout->addLayout(gridLayout);

        publisherLabel = new QLabel(layoutWidget);
        publisherLabel->setObjectName("publisherLabel");

        verticalLayout->addWidget(publisherLabel);

        publisherEdit = new QLineEdit(layoutWidget);
        publisherEdit->setObjectName("publisherEdit");

        verticalLayout->addWidget(publisherEdit);

        yearLabel = new QLabel(layoutWidget);
        yearLabel->setObjectName("yearLabel");

        verticalLayout->addWidget(yearLabel);

        yearEdit = new QLineEdit(layoutWidget);
        yearEdit->setObjectName("yearEdit");

        verticalLayout->addWidget(yearEdit);

        copiesLabel = new QLabel(layoutWidget);
        copiesLabel->setObjectName("copiesLabel");

        verticalLayout->addWidget(copiesLabel);

        copiesEdit = new QLineEdit(layoutWidget);
        copiesEdit->setObjectName("copiesEdit");

        verticalLayout->addWidget(copiesEdit);

        uploadLabel = new QLabel(layoutWidget);
        uploadLabel->setObjectName("uploadLabel");

        verticalLayout->addWidget(uploadLabel);

        uploadButton = new QPushButton(layoutWidget);
        uploadButton->setObjectName("uploadButton");

        verticalLayout->addWidget(uploadButton);

        saveButton = new QPushButton(layoutWidget);
        saveButton->setObjectName("saveButton");

        verticalLayout->addWidget(saveButton);

        BookEntryScreen->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(BookEntryScreen);
        statusbar->setObjectName("statusbar");
        BookEntryScreen->setStatusBar(statusbar);

        retranslateUi(BookEntryScreen);

        QMetaObject::connectSlotsByName(BookEntryScreen);
    } // setupUi

    void retranslateUi(QMainWindow *BookEntryScreen)
    {
        BookEntryScreen->setWindowTitle(QCoreApplication::translate("BookEntryScreen", "MainWindow", nullptr));
        titleLabel->setText(QCoreApplication::translate("BookEntryScreen", "Book Entry Portal", nullptr));
        toggleButton->setText(QCoreApplication::translate("BookEntryScreen", "\360\237\227\226", nullptr));
        designImage->setText(QString());
        bookNameLabel->setText(QCoreApplication::translate("BookEntryScreen", "Book Name:", nullptr));
        authorLabel->setText(QCoreApplication::translate("BookEntryScreen", "Author:", nullptr));
        isbnLabel->setText(QCoreApplication::translate("BookEntryScreen", "ISBN No:", nullptr));
        genreLabel->setText(QCoreApplication::translate("BookEntryScreen", "Genre:", nullptr));
        csButton->setText(QCoreApplication::translate("BookEntryScreen", "Computer Science", nullptr));
        fictionButton->setText(QCoreApplication::translate("BookEntryScreen", "Fiction", nullptr));
        mathButton->setText(QCoreApplication::translate("BookEntryScreen", "Mathematics", nullptr));
        engineeringButton->setText(QCoreApplication::translate("BookEntryScreen", "Engineering", nullptr));
        physicsButton->setText(QCoreApplication::translate("BookEntryScreen", "Physics", nullptr));
        scifiButton->setText(QCoreApplication::translate("BookEntryScreen", "Sci-Fi", nullptr));
        nonFictionButton->setText(QCoreApplication::translate("BookEntryScreen", "non-fiction", nullptr));
        chemistryButton->setText(QCoreApplication::translate("BookEntryScreen", "Chemistry", nullptr));
        selfHelpButton->setText(QCoreApplication::translate("BookEntryScreen", "Self-Help", nullptr));
        novelButton->setText(QCoreApplication::translate("BookEntryScreen", "Novel", nullptr));
        historyButton->setText(QCoreApplication::translate("BookEntryScreen", "History", nullptr));
        literatureButton->setText(QCoreApplication::translate("BookEntryScreen", "Literature", nullptr));
        publisherLabel->setText(QCoreApplication::translate("BookEntryScreen", "Publisher:", nullptr));
        yearLabel->setText(QCoreApplication::translate("BookEntryScreen", "Published Year:", nullptr));
        copiesLabel->setText(QCoreApplication::translate("BookEntryScreen", "Number of Copies:", nullptr));
        uploadLabel->setText(QCoreApplication::translate("BookEntryScreen", "Upload Image:", nullptr));
        uploadButton->setText(QCoreApplication::translate("BookEntryScreen", "Browse....", nullptr));
        saveButton->setText(QCoreApplication::translate("BookEntryScreen", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BookEntryScreen: public Ui_BookEntryScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKENTRYSCREEN_H
