#include "borrowedbooksscreen.h"
#include "ui_borrowedbooksscreen.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QScrollArea>
#include <QMessageBox>
#include <QPixmap>
#include <QCheckBox>
#include <QFrame>

// Constants
const int IMAGE_WIDTH = 100;
const int IMAGE_HEIGHT = 150;

BorrowedBooksScreen::BorrowedBooksScreen(const QString &studentId, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BorrowedBooksScreen),
    studentId(studentId)  // Initialize the studentId member variable
{
    ui->setupUi(this);

    QVBoxLayout *mainLayout = new QVBoxLayout;

    // Add title label with increased size and bold font
    QLabel *titleLabel = new QLabel("Borrowed Books", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("QLabel { font-size: 24pt; font-weight: bold; }");
    mainLayout->addWidget(titleLabel);

    // Add spacing after the title
    mainLayout->addSpacing(20);

    scrollArea = new QScrollArea;
    scrollArea->setWidgetResizable(true);
    scrollContent = new QWidget;
    scrollLayout = new QVBoxLayout(scrollContent);
    scrollArea->setWidget(scrollContent);

    mainLayout->addWidget(scrollArea);

    // Add return button at the bottom
    returnButton = new QPushButton("Return Selected Book", this);
    mainLayout->addWidget(returnButton);

    ui->centralwidget->setLayout(mainLayout);

    // Connect return button
    connect(returnButton, &QPushButton::clicked, this, &BorrowedBooksScreen::onReturnButtonClicked);

    // Display borrowed books
    displayBorrowedBooks();
}

BorrowedBooksScreen::~BorrowedBooksScreen()
{
    delete ui;
}

void BorrowedBooksScreen::displayBorrowedBooks()
{
    clearLayout(scrollLayout);

    QSqlQuery query;
    QString queryStr = "SELECT b.title, b.author, b.isbn, b.publisher, b.year, b.image_path, b.id, "
                       "bb.borrow_date, bb.return_date "
                       "FROM books b "
                       "JOIN borrowed_books bb ON b.id = bb.book_id "
                       "WHERE bb.student_id = :studentId";

    query.prepare(queryStr);
    query.bindValue(":studentId", studentId);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to fetch borrowed books: " + query.lastError().text());
        return;
    }

    while (query.next()) {
        createBookWidget(query);
    }

    if (scrollLayout->count() == 0) {
        QLabel *noBooksLabel = new QLabel("No borrowed books.");
        scrollLayout->addWidget(noBooksLabel);
    }
}

void BorrowedBooksScreen::createBookWidget(const QSqlQuery &query)
{
    QString title = query.value("title").toString();
    QString author = query.value("author").toString();
    QString isbn = query.value("isbn").toString();
    QString publisher = query.value("publisher").toString();
    int year = query.value("year").toInt();
    QString imagePath = query.value("image_path").toString();
    int bookId = query.value("id").toInt();
    QString borrowDate = query.value("borrow_date").toString();
    QString returnDate = query.value("return_date").toString();

    QWidget *bookWidget = new QWidget;
    QHBoxLayout *bookLayout = new QHBoxLayout(bookWidget);

    // Image
    QLabel *imageLabel = new QLabel;
    QPixmap pixmap(imagePath);
    if (!pixmap.isNull()) {
        imageLabel->setPixmap(pixmap.scaled(IMAGE_WIDTH, IMAGE_HEIGHT, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    imageLabel->setFixedSize(IMAGE_WIDTH, IMAGE_HEIGHT);

    // Details widget
    QWidget *detailsWidget = new QWidget;
    QVBoxLayout *detailsLayout = new QVBoxLayout(detailsWidget);
    detailsLayout->setSpacing(5);

    detailsLayout->addWidget(new QLabel("Title: " + title));
    detailsLayout->addWidget(new QLabel("Author: " + author));
    detailsLayout->addWidget(new QLabel("ISBN: " + isbn));
    detailsLayout->addWidget(new QLabel("Publisher: " + publisher));
    detailsLayout->addWidget(new QLabel("Year: " + QString::number(year)));
    detailsLayout->addWidget(new QLabel("Borrow Date: " + borrowDate));
    detailsLayout->addWidget(new QLabel("Return Date: " + returnDate));

    QCheckBox *selectCheckBox = new QCheckBox("Select for Return", this);
    detailsLayout->addWidget(selectCheckBox);
    detailsLayout->addStretch();

    bookLayout->addWidget(imageLabel);
    bookLayout->addWidget(detailsWidget, 1);

    // Add a horizontal line to separate books
    QFrame *line = new QFrame();
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);

    QVBoxLayout *bookContainerLayout = new QVBoxLayout();
    bookContainerLayout->addWidget(bookWidget);
    bookContainerLayout->addWidget(line);

    scrollLayout->addLayout(bookContainerLayout);

    // Store the book ID with the checkbox for later use
    selectCheckBox->setProperty("bookId", bookId);
}

void BorrowedBooksScreen::onReturnButtonClicked()
{
    QList<int> booksToReturn;

    // Collect all selected books
    for (int i = 0; i < scrollLayout->count(); ++i) {
        QLayoutItem *item = scrollLayout->itemAt(i);
        if (QVBoxLayout *bookContainerLayout = dynamic_cast<QVBoxLayout*>(item->layout())) {
            QWidget *bookWidget = bookContainerLayout->itemAt(0)->widget();
            QCheckBox *selectCheckBox = bookWidget->findChild<QCheckBox*>();
            if (selectCheckBox && selectCheckBox->isChecked()) {
                int bookId = selectCheckBox->property("bookId").toInt();
                booksToReturn.append(bookId);
            }
        }
    }

    if (booksToReturn.isEmpty()) {
        QMessageBox::information(this, "No Selection", "Please select books to return.");

        return;
    }

    returnBooks(booksToReturn);

    // After returning, refresh the display
    displayBorrowedBooks();
}

void BorrowedBooksScreen::clearLayout(QLayout *layout)
{
    QLayoutItem *item;
    while ((item = layout->takeAt(0))) {
        if (QWidget *widget = item->widget()) {
            widget->deleteLater();
        }
        if (QLayout *childLayout = item->layout()) {
            clearLayout(childLayout);
        }
        delete item;
    }
}

void BorrowedBooksScreen::returnBooks(const QList<int>& bookIds)
{
    QSqlQuery query;

    foreach (int bookId, bookIds) {
        query.prepare("DELETE FROM borrowed_books WHERE book_id = :bookId AND student_id = :studentId");
        query.bindValue(":bookId", bookId);
        query.bindValue(":studentId", studentId);

        if (!query.exec()) {
            QMessageBox::critical(this, "Error", "Failed to return book with ID: " + QString::number(bookId) + "\n" + query.lastError().text());
            return;
        }
    }

    QMessageBox::information(this, "Success", "Selected books have been returned successfully.");
}
