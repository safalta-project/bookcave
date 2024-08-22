#include "loginscreen.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>




void setupDatabase(QSqlDatabase& db) {
    QSqlQuery query(db);

    // Students table
    QString createStudentsTable = R"(
        CREATE TABLE IF NOT EXISTS students (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
            email TEXT NOT NULL UNIQUE,
            student_id TEXT NOT NULL UNIQUE,
            phone TEXT,
            department TEXT
        );
    )";

    // Books table
    QString createBooksTable = R"(
        CREATE TABLE IF NOT EXISTS books (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            title TEXT NOT NULL,
            author TEXT NOT NULL,
            isbn TEXT NOT NULL UNIQUE,
            publisher TEXT,
            year INTEGER,
            genre TEXT NOT NULL,
            image_path TEXT,
            copies INTEGER DEFAULT 1
        );
    )";

    // BorrowedBooks table
    QString createBorrowedBooksTable = R"(
        CREATE TABLE IF NOT EXISTS borrowed_books (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            student_id INTEGER,
            book_id INTEGER,
            borrow_date TEXT NOT NULL,
            return_date TEXT,
            FOREIGN KEY(student_id) REFERENCES students(id),
            FOREIGN KEY(book_id) REFERENCES books(id)
        );
    )";

    // Execute the queries to create tables
    if (!query.exec(createStudentsTable)) {
        qDebug() << "Error creating students table:" << query.lastError().text();
    }

    if (!query.exec(createBooksTable)) {
        qDebug() << "Error creating books table:" << query.lastError().text();
    }

    if (!query.exec(createBorrowedBooksTable)) {
        qDebug() << "Error creating borrowed_books table:" << query.lastError().text();
    } else {
        qDebug() << "Tables created successfully or already exist.";
    }
}
void dropExistingTables(QSqlDatabase& db) {
    QSqlQuery query(db);

    // Drop the 'students' table if it exists
    QString dropStudentsTable = "DROP TABLE IF EXISTS students;";
    if (!query.exec(dropStudentsTable)) {
        qDebug() << "Error dropping students table:" << query.lastError().text();
    } else {
        qDebug() << "Students table dropped successfully.";
    }

    // Drop the 'books' table if it exists
    QString dropBooksTable = "DROP TABLE IF EXISTS books;";
    if (!query.exec(dropBooksTable)) {
        qDebug() << "Error dropping books table:" << query.lastError().text();
    } else {
        qDebug() << "Books table dropped successfully.";
    }

    // Drop the 'borrowed_books' table if it exists
    QString dropBorrowedBooksTable = "DROP TABLE IF EXISTS borrowed_books;";
    if (!query.exec(dropBorrowedBooksTable)) {
        qDebug() << "Error dropping borrowed_books table:" << query.lastError().text();
    } else {
        qDebug() << "BorrowedBooks table dropped successfully.";
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Set up the SQLite database connection
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database.db");  // SQLite database file

    if (!db.open()) {
        qDebug() << "Error: Unable to connect to the SQLite database.";
        qDebug() << db.lastError().text();
        return -1;
    } else {
        qDebug() << "SQLite database connection established successfully.";

        // Set up database schema
        setupDatabase(db);
    }
    LoginScreen w;

    w.show();
    return a.exec();
}
