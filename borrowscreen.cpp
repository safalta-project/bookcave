#include "borrowscreen.h"
#include "ui_borrowscreen.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>

BorrowScreen::BorrowScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BorrowScreen)
{
    ui->setupUi(this);
    QFont font = ui->label->font();
    font.setPointSize(28);
    font.setBold(true);
    ui->label->setFont(font);

    // Connect the borrow button to the borrow function
    connect(ui->borrowButton, &QPushButton::clicked, this, &BorrowScreen::onBorrowButtonClicked);
}

BorrowScreen::~BorrowScreen()
{
    delete ui;
}

void BorrowScreen::onBorrowButtonClicked()
{
    QString studentId = ui->lineEdit->text();
    QString bookISBN = ui->lineEdit_2->text();

    if (studentId.isEmpty() || bookISBN.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter both Student ID and Book ISBN.");
        return;
    }

    // Check if the student exists
    QSqlQuery query;
    query.prepare("SELECT id FROM students WHERE student_id = :student_id");
    query.bindValue(":student_id", studentId);
    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", "Failed to query the database: " + query.lastError().text());
        return;
    }

    if (!query.next()) {
        QMessageBox::warning(this, "Error", "Student ID not found.");
        return;
    }
    int studentDbId = query.value(0).toInt();

    // Check if the book exists using the ISBN
    query.prepare("SELECT id FROM books WHERE isbn = :isbn");
    query.bindValue(":isbn", bookISBN);
    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", "Failed to query the database: " + query.lastError().text());
        return;
    }

    if (!query.next()) {
        QMessageBox::warning(this, "Error", "Book ISBN not found.");
        return;
    }
    int bookDbId = query.value(0).toInt();

    // Calculate borrow and return dates
    QString borrowDate = QDate::currentDate().toString("yyyy-MM-dd");
    QString returnDate = QDate::currentDate().addDays(30).toString("yyyy-MM-dd");

    // Record the borrowing
    query.prepare(R"(
        INSERT INTO borrowed_books (student_id, book_id, borrow_date, return_date)
        VALUES (:student_id, :book_id, :borrow_date, :return_date)
    )");
    query.bindValue(":student_id", studentDbId);
    query.bindValue(":book_id", bookDbId);
    query.bindValue(":borrow_date", borrowDate);
    query.bindValue(":return_date", returnDate);

    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", "Failed to record borrowing: " + query.lastError().text());
    } else {
        QMessageBox::information(this, "Success", "Book borrowed successfully!");
    }
}



