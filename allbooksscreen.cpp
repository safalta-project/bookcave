#include "allbooksscreen.h"
#include "ui_allbooksscreen.h"
#include "borrowscreen.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QScrollArea>
#include <QMessageBox>
#include <QLineEdit>
#include <QSpacerItem>

// Constants
const int IMAGE_WIDTH = 100;
const int IMAGE_HEIGHT = 150;

AllBooksScreen::AllBooksScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AllBooksScreen)
{
    ui->setupUi(this);

    QVBoxLayout *mainLayout = new QVBoxLayout;

    // Add title label with increased size and bold font
    QLabel *titleLabel = new QLabel("All Books", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("QLabel { font-size: 24pt; font-weight: bold; }");
    mainLayout->addWidget(titleLabel);

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

    // Add filter functionality
    QHBoxLayout *filterLayout = new QHBoxLayout;
    QLabel *sortLabel = new QLabel("Sort by:");
    sortComboBox = new QComboBox;
    sortComboBox->addItem("Published Year");
    sortComboBox->addItem("Alphabetical Order");
    sortComboBox->addItem("Number of Books");
    filterLayout->addStretch();
    filterLayout->addWidget(sortLabel);
    filterLayout->addWidget(sortComboBox);
    filterLayout->addStretch();
    mainLayout->addLayout(filterLayout);

    connect(sortComboBox, &QComboBox::currentTextChanged, this, &AllBooksScreen::sortBooks);

    scrollArea = new QScrollArea;
    scrollArea->setWidgetResizable(true);
    scrollContent = new QWidget;
    scrollLayout = new QVBoxLayout(scrollContent);
    scrollContent->setLayout(scrollLayout);
    scrollArea->setWidget(scrollContent);

    mainLayout->addWidget(scrollArea);
    ui->centralwidget->setLayout(mainLayout);

    // Connect search button
    connect(searchButton, &QPushButton::clicked, this, [this, searchInput]() {
        this->displayBooks(searchInput->text());
    });


    // Display all books initially
    displayBooks();
}

AllBooksScreen::~AllBooksScreen()
{
    delete ui;
}

void AllBooksScreen::displayBooks(const QString &searchTerm)
{
    clearLayout(scrollLayout);

    QSqlQuery query;
    QString queryStr = "SELECT title, author, isbn, publisher, year, image_path, id FROM books";
    if (!searchTerm.isEmpty()) {
        queryStr += " WHERE title LIKE :search OR author LIKE :search";
    }
    queryStr += " ORDER BY ";
    QString sortCriteria = sortComboBox->currentText();
    if (sortCriteria == "Published Year") {
        queryStr += "year DESC";
    } else if (sortCriteria == "Alphabetical Order") {
        queryStr += "title ASC";
    } else if (sortCriteria == "Number of Books") {
        queryStr += "copies ASC";  // Modify as needed for your actual use case
    }

    query.prepare(queryStr);
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

void AllBooksScreen::createBookWidget(const QSqlQuery &query)
{
    QString title = query.value("title").toString();
    QString author = query.value("author").toString();
    QString isbn = query.value("isbn").toString();
    QString publisher = query.value("publisher").toString();
    int year = query.value("year").toInt();
    QString imagePath = query.value("image_path").toString();


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

void AllBooksScreen::borrowBook()
{
    BorrowScreen *b = new BorrowScreen(this);
    b->show();
}

void AllBooksScreen::clearLayout(QLayout *layout)
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

void AllBooksScreen::sortBooks()
{
    // Re-fetch and display books based on the new sort criteria
    displayBooks();
}

