#include "studentprofilescreen.h"
#include "ui_studentprofilescreen.h"
#include "borrowedbooksscreen.h"
#include <QVBoxLayout>
#include <QFont>

StudentProfileScreen::StudentProfileScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentProfileScreen) // Initialize the UI pointer
{
    ui->setupUi(this); // Set up the UI elements from the .ui file

    QVBoxLayout *layout = new QVBoxLayout(ui->centralwidget);

    // Title label
    QLabel *titleLabel = new QLabel("Student Profile", this);
    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(26); // Set font size
    titleFont.setBold(true); // Make font bold
    titleLabel->setFont(titleFont);
    titleLabel->setAlignment(Qt::AlignCenter);

    // Student detail labels
    nameLabel = new QLabel(this);
    emailLabel = new QLabel(this);
    studentIdLabel = new QLabel(this);
    phoneLabel = new QLabel(this);
    departmentLabel = new QLabel(this);
    borrowedBooksCountLabel = new QLabel(this);

    // Button to view borrowed books
    viewBorrowedBooksButton = new QPushButton("View Borrowed Books", this);

    // Add widgets to layout
    layout->addWidget(titleLabel);
    layout->addWidget(nameLabel);
    layout->addWidget(emailLabel);
    layout->addWidget(studentIdLabel);
    layout->addWidget(phoneLabel);
    layout->addWidget(departmentLabel);
    layout->addWidget(borrowedBooksCountLabel);
    layout->addWidget(viewBorrowedBooksButton);

    // Connect button signal
    connect(viewBorrowedBooksButton, &QPushButton::clicked, this, &StudentProfileScreen::onViewBorrowedBooksButtonClicked);
}

void StudentProfileScreen::setStudentDetails(const QString &name, const QString &email, const QString &studentId, const QString &phone, const QString &department) {
    this->studentId = studentId; // Store the student ID
    nameLabel->setText("Name: " + name);
    emailLabel->setText("Email: " + email);
    studentIdLabel->setText("Student ID: " + studentId);
    phoneLabel->setText("Phone: " + phone);
    departmentLabel->setText("Department: " + department);
}

void StudentProfileScreen::setBorrowedBooksCount(int count) {
    borrowedBooksCountLabel->setText("Number of borrowed books: " + QString::number(count));
}

void StudentProfileScreen::onViewBorrowedBooksButtonClicked() {
    // Open BorrowedBooksScreen and pass the student ID
    BorrowedBooksScreen *b = new BorrowedBooksScreen(studentId, this);
    this->close();
    b->show();
}

StudentProfileScreen::~StudentProfileScreen()
{
    delete ui; // Clean up the UI object
}

