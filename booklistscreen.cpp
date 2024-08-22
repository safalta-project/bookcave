#include "booklistscreen.h"
#include "ui_booklistscreen.h"
#include "borrowscreen.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QScrollArea>
#include <QWidget>
#include <QMessageBox>
#include <QLineEdit>
#include <QSpacerItem>

// Constants
const int IMAGE_WIDTH = 100;
const int IMAGE_HEIGHT = 150;

BookListScreen::BookListScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BookListScreen)
{
    ui->setupUi(this);

    QVBoxLayout *mainLayout = new QVBoxLayout;

    // Add genre title label with increased size and bold font
    genreLabel = new QLabel(this);
    genreLabel->setAlignment(Qt::AlignCenter);
    genreLabel->setStyleSheet("QLabel { font-size: 24pt; font-weight: bold; }");
    mainLayout->addWidget(genreLabel);

    // Add spacing after the title
    mainLayout->addSpacing(20);

    // Add search functionality with smaller line edit
    QHBoxLayout *searchLayout = new QHBoxLayout;
    QLineEdit *searchInput = new QLineEdit;
    searchInput->setFixedWidth(200);  // Set a fixed width for the search input
    QPushButton *searchButton = new QPushButton("Search");
    searchLayout->addStretch();
    searchLayout->addWidget(searchInput);
    searchLayout->addWidget(searchButton);
    searchLayout->addStretch();
    mainLayout->addLayout(searchLayout);

    // Add spacing after the search bar
    mainLayout->addSpacing(20);

    connect(searchButton, &QPushButton::clicked, this, [this, searchInput]() {
        this->displayBooks(currentGenre, searchInput->text());
    });

    scrollArea = new QScrollArea;
    scrollArea->setWidgetResizable(true);
    scrollContent = new QWidget;
    scrollLayout = new QVBoxLayout(scrollContent);
    scrollArea->setWidget(scrollContent);

    mainLayout->addWidget(scrollArea);
    ui->centralwidget->setLayout(mainLayout);
}
BookListScreen::~BookListScreen()
{
    delete ui;
}

void BookListScreen::displayBooks(const QString& genre, const QString& searchTerm)
{
    currentGenre = genre;
    genreLabel->setText(genre + " Books");
    clearLayout(scrollLayout);

    QSqlQuery query;
    QString queryStr = "SELECT title, author, isbn, publisher, year, image_path, id FROM books WHERE genre = :genre";
    if (!searchTerm.isEmpty()) {
        queryStr += " AND (title LIKE :search OR author LIKE :search)";
    }
    query.prepare(queryStr);
    query.bindValue(":genre", genre);
    if (!searchTerm.isEmpty()) {
        query.bindValue(":search", "%" + searchTerm + "%");
    }

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to fetch books: " + query.lastError().text());
        return;
    }

    while (query.next()) {
        createBookWidget(query);
    }

    if (scrollLayout->count() == 0) {
        QLabel *noBooksLabel = new QLabel("No books found.");
        scrollLayout->addWidget(noBooksLabel);
    }
}

void BookListScreen::createBookWidget(const QSqlQuery& query)
{
    QString title = query.value("title").toString();
    QString author = query.value("author").toString();
    QString isbn = query.value("isbn").toString();
    QString publisher = query.value("publisher").toString();
    int year = query.value("year").toInt();
    QString imagePath = query.value("image_path").toString();
    int bookId = query.value("id").toInt();

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

    QPushButton *borrowButton = new QPushButton("Borrow", this);
    connect(borrowButton, &QPushButton::clicked, this, [this]() {
        borrowBook();
    });
    detailsLayout->addWidget(borrowButton);
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
}

void BookListScreen::borrowBook()
{
    BorrowScreen * b= new BorrowScreen(this);
    b->show();
}

void BookListScreen::clearLayout(QLayout *layout)
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
