#include "studentsearchscreen.h"
#include "studentprofilescreen.h"
#include "ui_studentsearchscreen.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

StudentSearchScreen::StudentSearchScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StudentSearchScreen)
{
    ui->setupUi(this);
    QFont font = ui->label->font();
    font.setPointSize(28);
    font.setBold(true);
    ui->label->setFont(font);

    connect(ui->pushButton, &QPushButton::clicked, this, &StudentSearchScreen::onSearchButtonClicked);
}

StudentSearchScreen::~StudentSearchScreen()
{
    delete ui;
}

void StudentSearchScreen::onSearchButtonClicked()
{
    QString studentId = ui->lineEdit->text();

    if (studentId.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a student ID.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT name, email, student_id, phone, department FROM students WHERE student_id = :student_id");
    query.bindValue(":student_id", studentId);

    if (query.exec()) {
        if (query.next()) {
            QString name = query.value(0).toString();
            QString email = query.value(1).toString();
            QString id = query.value(2).toString();
            QString phone = query.value(3).toString();
            QString department = query.value(4).toString();

            // Create and show StudentProfileScreen
            StudentProfileScreen *profileScreen = new StudentProfileScreen(this);
            profileScreen->setStudentDetails(name, email, id, phone, department);
            this->close();
            profileScreen->show();
        // Close the search screen
        } else {
            QMessageBox::warning(this, "Not Found", "Student ID not found. Please try again.");
        }
    } else {
        QMessageBox::critical(this, "Error", "Failed to execute query: " + query.lastError().text());
    }
}
