#include "loginscreen.h"
#include "ui_loginscreen.h"
#include <QMessageBox>  // Include this to show message boxes
#include "dashboardscreen.h"

LoginScreen::LoginScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginScreen)
{
    ui->setupUi(this);

    // Set the background color of the central widget to light blue using QPalette
    QPalette palette = ui->centralwidget->palette();
    palette.setColor(QPalette::Window, QColor(0, 0, 0)); // Light blue RGB color
    ui->centralwidget->setAutoFillBackground(true);
    ui->centralwidget->setPalette(palette);
    ui->loginButton->setStyleSheet("background-color:#0657f8;");

    // Make the title_label bold and increase font size to 28
    QFont font = ui->title_label->font();
    font.setPointSize(28);
    font.setBold(true);
    ui->title_label->setFont(font);

    // Set the password field to hide the input text
    ui->password_field->setEchoMode(QLineEdit::Password);

    // Connect the fullscreen toggle button to the slot
    connect(ui->toggleFullscreenButton, &QPushButton::clicked, this, &LoginScreen::toggleFullscreen);

    // Connect the login button to the slot
    connect(ui->loginButton, &QPushButton::clicked, this, &LoginScreen::onLoginButtonClicked);
}

LoginScreen::~LoginScreen()
{
    delete ui;
}

void LoginScreen::toggleFullscreen()
{
    if (isFullScreen()) {
        showNormal(); // Exit fullscreen mode
    } else {
        showFullScreen(); // Enter fullscreen mode
    }
}

void LoginScreen::onLoginButtonClicked()
{
    // Hardcoded username and password
    QString correctUsername = "admin";
    QString correctPassword = "p";

    // Get the input from the user
    QString enteredUsername = ui->username_field->text();
    QString enteredPassword = ui->password_field->text();

    // Check if the entered username and password match the hardcoded ones
    if (enteredUsername == correctUsername && enteredPassword == correctPassword) {
        QMessageBox::information(this, "Login Successful", "Welcome!");
        DashboardScreen * d = new DashboardScreen(this);
        this->close();
        d->show();

    } else {
        QMessageBox::warning(this, "Login Failed", "Incorrect username or password.");
    }
}
