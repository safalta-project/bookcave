#ifndef STUDENTREGISTRATIONSCREEN_H
#define STUDENTREGISTRATIONSCREEN_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class StudentRegistrationScreen; }
QT_END_NAMESPACE

class StudentRegistrationScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentRegistrationScreen(QWidget *parent = nullptr);
    ~StudentRegistrationScreen();

private slots:
    void on_studentRegistrationButton_clicked();
    void toggleFullscreen();

private:
    Ui::StudentRegistrationScreen *ui;
};

#endif // STUDENTREGISTRATIONSCREEN_H

