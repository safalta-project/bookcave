#ifndef DASHBOARDSCREEN_H
#define DASHBOARDSCREEN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class DashboardScreen; }
QT_END_NAMESPACE

class DashboardScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit DashboardScreen(QWidget *parent = nullptr);
    ~DashboardScreen();

private slots:
    void on_allBooksButton_clicked();
    void on_booksByGenreButton_clicked();
    void on_bookBorrowPortalButton_clicked();
    void on_studentInfoPortalButton_clicked();
    void on_studentRegistrationPortalButton_clicked();
    void on_bookEntryPortalButton_clicked();

private:
    Ui::DashboardScreen *ui;
};

#endif // DASHBOARDSCREEN_H
