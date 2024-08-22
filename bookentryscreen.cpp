#include "bookentryscreen.h"
#include "ui_bookentryscreen.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QDir>
#include <QFileInfo>

BookEntryScreen::BookEntryScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BookEntryScreen)
{
    ui->setupUi(this);

    // Connect the upload button to the slot
    connect(ui->uploadButton, &QPushButton::clicked, this, &BookEntryScreen::onUploadButtonClicked);

    QFont font = ui->titleLabel->font();
    font.setPointSize(28);
    font.setBold(true);
    ui->titleLabel->setFont(font);

    // Connect the save button to the slot
    connect(ui->saveButton, &QPushButton::clicked, this, &BookEntryScreen::onSaveButtonClicked);

    // Toggle Fullscreen Button
    connect(ui->toggleButton, &QToolButton::clicked, this, &BookEntryScreen::toggleFullscreen);

    // Connect genre radio buttons to the slot
    connect(ui->csButton, &QRadioButton::clicked, this, &BookEntryScreen::onGenreRadioButtonClicked);
    connect(ui->engineeringButton, &QRadioButton::clicked, this, &BookEntryScreen::onGenreRadioButtonClicked);
    connect(ui->scifiButton, &QRadioButton::clicked, this, &BookEntryScreen::onGenreRadioButtonClicked);
    connect(ui->nonFictionButton, &QRadioButton::clicked, this, &BookEntryScreen::onGenreRadioButtonClicked);
    connect(ui->chemistryButton, &QRadioButton::clicked, this, &BookEntryScreen::onGenreRadioButtonClicked);
    connect(ui->selfHelpButton, &QRadioButton::clicked, this, &BookEntryScreen::onGenreRadioButtonClicked);
    connect(ui->novelButton, &QRadioButton::clicked, this, &BookEntryScreen::onGenreRadioButtonClicked);
    connect(ui->fictionButton, &QRadioButton::clicked, this, &BookEntryScreen::onGenreRadioButtonClicked);
    connect(ui->mathButton, &QRadioButton::clicked, this, &BookEntryScreen::onGenreRadioButtonClicked);
    connect(ui->physicsButton, &QRadioButton::clicked, this, &BookEntryScreen::onGenreRadioButtonClicked);
    connect(ui->historyButton, &QRadioButton::clicked, this, &BookEntryScreen::onGenreRadioButtonClicked);
    connect(ui->literatureButton, &QRadioButton::clicked, this, &BookEntryScreen::onGenreRadioButtonClicked);
}

BookEntryScreen::~BookEntryScreen()
{
    delete ui;
}

void BookEntryScreen::toggleFullscreen()
{
    if (isFullScreen()) {
        showNormal();
    } else {
        showFullScreen();
    }
}

void BookEntryScreen::onUploadButtonClicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));
    if (!fileName.isEmpty()) {
        // Create a new folder within the project path
        QString projectPath = QCoreApplication::applicationDirPath(); // Get project directory
        QString imageFolderPath = projectPath + "/book_images";

        // Check if the directory exists, if not, create it
        QDir dir(imageFolderPath);
        if (!dir.exists()) {
            dir.mkpath(".");
        }

        // Create a new file path in the new directory
        QString newFilePath = imageFolderPath + "/" + QFileInfo(fileName).fileName();

        // Copy the selected file to the new directory
        if (QFile::copy(fileName, newFilePath)) {
            ui->designImage->setPixmap(QPixmap(newFilePath).scaled(ui->designImage->size(), Qt::KeepAspectRatio));
            ui->uploadLabel->setText(newFilePath);  // Display the new file path
            imageFilePath = newFilePath;  // Store the new file path
        } else {
            QMessageBox::warning(this, tr("File Copy Error"), tr("Failed to copy the image file."));
        }
    }
}

void BookEntryScreen::onSaveButtonClicked()
{
    QString bookName = ui->bookNameEdit->text();
    QString author = ui->authorEdit->text();
    QString isbn = ui->isbnEdit->text();
    QString publisher = ui->publisherEdit->text();
    QString year = ui->yearEdit->text();
    QString copies = ui->copiesEdit->text();

    if (bookName.isEmpty() || author.isEmpty() || isbn.isEmpty() || selectedGenre.isEmpty()) {
        QMessageBox::warning(this, tr("Input Error"), tr("Book Name, Author, ISBN, and Genre are required."));
        return;
    }

    // Saving the book details to the database
    QSqlQuery query;
    query.prepare("INSERT INTO books (title, author, isbn, publisher, year, genre, image_path, copies) "
                  "VALUES (:title, :author, :isbn, :publisher, :year, :genre, :image_path, :copies)");
    query.bindValue(":title", bookName);
    query.bindValue(":author", author);
    query.bindValue(":isbn", isbn);
    query.bindValue(":publisher", publisher);
    query.bindValue(":year", year);
    query.bindValue(":genre", selectedGenre);
    query.bindValue(":copies", copies);
    query.bindValue(":image_path", imageFilePath);

    if (!query.exec()) {
        QSqlError error = query.lastError();
        QString errorMessage = QString("Error Type: %1\nDatabase Error Code: %2\nDriver Error Code: %3\nError Message: %4")
                                   .arg(error.type())
                                   .arg(error.databaseText())
                                   .arg(error.driverText())
                                   .arg(error.text());
        QMessageBox::critical(this, tr("Save Error"), errorMessage);
    } else {
        QMessageBox::information(this, tr("Success"), tr("Book saved successfully."));
    }
}

void BookEntryScreen::onGenreRadioButtonClicked()
{
    QRadioButton *radioButton = qobject_cast<QRadioButton*>(sender());
    if (radioButton) {
        selectedGenre = radioButton->text();
    }
}
