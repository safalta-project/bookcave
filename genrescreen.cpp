#include "genrescreen.h"
#include "ui_genrescreen.h"
#include "booklistscreen.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QVBoxLayout>
#include <QPushButton>
#include <QIcon>
#include <QSize>
#include <QLabel>

GenreScreen::GenreScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GenreScreen)
{
    ui->setupUi(this);
    setupGenreButtons();
}

GenreScreen::~GenreScreen()
{
    delete ui;
}

void GenreScreen::setupGenreButtons()
{
    QString projectPath = "D:/bookcave";
    QStringList genres = {
        "Computer Science",
        "Engineering",
        "Science Fiction",
        "Non-Fiction",
        "Chemistry",
        "Self Help",
        "Novel",
        "Fiction",
        "Math",
        "Physics",
        "History",
        "Literature"
    };

    QStringList images = {
        projectPath+"/resources/images/computer.jpg",
        projectPath+"/resources/images/engineering.jpg",
        projectPath+"/resources/images/scifi.jpg",
        projectPath+"/resources/images/nonfiction.png",
        projectPath+"/resources/images/chemistry.png",
        projectPath+"/resources/images/selfhelp.jpg",
        projectPath+"/resources/images/novel.jpg",
        projectPath+"/resources/images/fiction.jpg",
        projectPath+"/resources/images/maths.jpg",
        projectPath+"/resources/images/physics.jpg",
        projectPath+"/resources/images/history.jpg",
        projectPath+"/resources/images/literature.jpeg"
    };

    QVBoxLayout *mainLayout = new QVBoxLayout;

    QLabel *headerLabel = new QLabel("Genre", this);
    QFont font = headerLabel->font();
    font.setPointSize(26);
    font.setBold(true);
    headerLabel->setFont(font);
    headerLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(headerLabel);

    int numColumns = 4; // Four images per row
    int imageSize = 80;

    for (int i = 0; i < genres.size(); i += numColumns) {
        QHBoxLayout *rowLayout = new QHBoxLayout;
        rowLayout->setSpacing(0);
        rowLayout->setContentsMargins(0, 0, 0, 0);

        for (int j = 0; j < numColumns; ++j) {
            int index = i + j;
            if (index >= genres.size()) break;

            QWidget *widget = new QWidget(this);
            QVBoxLayout *vLayout = new QVBoxLayout(widget);
            QPushButton *button = new QPushButton(this);
            QLabel *label = new QLabel(genres[index], this);

            QPixmap pixmap(images[index]);
            if (!pixmap.isNull()) {
                QIcon icon(pixmap.scaled(imageSize, imageSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                button->setIcon(icon);
                button->setIconSize(QSize(imageSize, imageSize));
            }

            button->setStyleSheet(
                "QPushButton {"
                "    border: none;"
                "    padding: 0;"
                "}"
                );

            button->setFixedSize(imageSize, imageSize);
            button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

            connect(button, &QPushButton::clicked, this, [this, genre = genres[index]]() {
                BookListScreen *bookListScreen = new BookListScreen(this);
                bookListScreen->displayBooks(genre);
                bookListScreen->show();
            });

            vLayout->addWidget(button);
            vLayout->addWidget(label);
            vLayout->setAlignment(Qt::AlignCenter);
            vLayout->setSpacing(0);

            rowLayout->addWidget(widget);
        }

        mainLayout->addLayout(rowLayout);
    }

    ui->centralwidget->setLayout(mainLayout);
}


