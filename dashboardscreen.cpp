#include "dashboardscreen.h"
#include "ui_dashboardscreen.h"  // Include headers for the other screens
#include "genrescreen.h"
#include "borrowscreen.h"
#include "studentregistrationscreen.h"
#include "bookentryscreen.h"
#include "allbooksscreen.h"
#include "studentsearchscreen.h"

DashboardScreen::DashboardScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DashboardScreen)
{
    ui->setupUi(this);

    // Set the font size and boldness for titleLabel
    QFont titleFont = ui->titleLabel->font();
    titleFont.setPointSize(26); // Increase font size to 26
    titleFont.setBold(true);    // Set font to bold
    ui->titleLabel->setFont(titleFont);


    // Connect buttons to their respective slots
    connect(ui->commandLinkButton_4, &QCommandLinkButton::clicked, this, &DashboardScreen::on_allBooksButton_clicked);
    connect(ui->commandLinkButton, &QCommandLinkButton::clicked, this, &DashboardScreen::on_booksByGenreButton_clicked);
    connect(ui->commandLinkButton_2, &QCommandLinkButton::clicked, this, &DashboardScreen::on_bookBorrowPortalButton_clicked);
    connect(ui->commandLinkButton_5, &QCommandLinkButton::clicked, this, &DashboardScreen::on_studentInfoPortalButton_clicked);
    connect(ui->commandLinkButton_3, &QCommandLinkButton::clicked, this, &DashboardScreen::on_studentRegistrationPortalButton_clicked);
    connect(ui->commandLinkButton_6, &QCommandLinkButton::clicked, this, &DashboardScreen::on_bookEntryPortalButton_clicked);
}


DashboardScreen::~DashboardScreen()
{
    delete ui;
}

void DashboardScreen::on_allBooksButton_clicked()
{
    // Open All Books Screen
    AllBooksScreen *allBooksScreen = new AllBooksScreen(this);
    allBooksScreen->show();
}

void DashboardScreen::on_booksByGenreButton_clicked()
{
    // Open Books By Genre Screen
    GenreScreen *genreScreen = new GenreScreen(this);
    genreScreen->show();
}

void DashboardScreen::on_bookBorrowPortalButton_clicked()
{
    // Open Book Borrow Portal Screen
    BorrowScreen *bookBorrowPortal = new BorrowScreen(this);
    bookBorrowPortal->show();
}

void DashboardScreen::on_studentInfoPortalButton_clicked()
{
    // Open Student Info Portal Screen
    //StudentInfoPortal *studentInfoPortal = new StudentInfoPortal(this);
    // studentInfoPortal->show();
    StudentSearchScreen *studentSearch= new StudentSearchScreen(this);
    studentSearch->show();
}

void DashboardScreen::on_studentRegistrationPortalButton_clicked()
{
    // Open Student Registration Screen
    StudentRegistrationScreen *studentRegistrationScreen = new StudentRegistrationScreen(this);
    studentRegistrationScreen->show();
}

void DashboardScreen::on_bookEntryPortalButton_clicked()
{
    // Open Book Entry Screen
    BookEntryScreen *bookEntryScreen = new BookEntryScreen(this);
    bookEntryScreen->show();
}
