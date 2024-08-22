#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginScreen; }
QT_END_NAMESPACE

class LoginScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginScreen(QWidget *parent = nullptr);
    ~LoginScreen();

private slots:
    void toggleFullscreen();
    void onLoginButtonClicked();    // Declare the toggleFullscreen slot

private:
    Ui::LoginScreen *ui;
};

#endif // LOGINSCREEN_H
