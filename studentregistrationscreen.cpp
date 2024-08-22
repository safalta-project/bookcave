#include "studentregistrationscreen.h"
#include "ui_studentregistrationscreen.h"
#include <QMessageBox>


StudentRegistrationScreen::StudentRegistrationScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StudentRegistrationScreen)
{
    ui->setupUi(this);

    // Set the background color of the central widget to sky blue using QPalette
    QPalette palette = ui->centralwidget->palette();
    palette.setColor(QPalette::Window, QColor(5, 5, 5)); // Sky blue RGB color
    ui->centralwidget->setAutoFillBackground(true);
    ui->centralwidget->setPalette(palette);

    // Make the titleText font size 26 and bold
    QFont font = ui->titleText->font();
    font.setPointSize(26);
    font.setBold(true);
    ui->titleText->setFont(font);

    // Connect the fullscreen toggle button to the toggleFullscreen slot
    connect(ui->ToggleFullScreen, &QPushButton::clicked, this, &StudentRegistrationScreen::toggleFullscreen);

    // Connect the register button to the registerStudent slot
    connect(ui->studentRegistrationButton, &QPushButton::clicked, this, &StudentRegistrationScreen::on_studentRegistrationButton_clicked);
}

StudentRegistrationScreen::~StudentRegistrationScreen()
{
    delete ui;
}

void StudentRegistrationScreen::toggleFullscreen()
{
    if (isFullScreen()) {
        showNormal(); // Exit fullscreen mode
    } else {
        showFullScreen(); // Enter fullscreen mode
    }
}

void StudentRegistrationScreen::on_studentRegistrationButton_clicked()
{
    QString name = ui->nameEditField->text();
    QString email = ui->emailEditField->text();
    QString studentId = ui->studentIdEditField->text();
    QString phoneNumber = ui->numberEditField->text();
    QString department = ui->departmentEditField->text();

    // Validate input fields
    if (name.isEmpty() || email.isEmpty() || studentId.isEmpty() || department.isEmpty()) {
        qDebug() << "All fields except phone number are required.";
        QMessageBox::warning(this, "Registration Failed", "All fields except phone number are required.");
        return;
    }

    // Insert data into the database
    QSqlQuery query;
    query.prepare("INSERT INTO students (name, email, student_id, phone, department) "
                  "VALUES (:name, :email, :student_id, :phone, :department)");
    query.bindValue(":name", name);
    query.bindValue(":email", email);
    query.bindValue(":student_id", studentId);
    query.bindValue(":phone", phoneNumber);
    query.bindValue(":department", department);

    if (!query.exec()) {
        qDebug() << "Error inserting data into students table:" << query.lastError().text();
        QMessageBox::critical(this, "Registration Failed", "Error inserting data into students table: " + query.lastError().text());
    } else {
        qDebug() << "Student registered successfully.";
        QMessageBox::information(this, "Registration Successful", "Student registered successfully.");
    }
}
