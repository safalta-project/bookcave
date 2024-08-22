#ifndef STUDENTSEARCHSCREEN_H
#define STUDENTSEARCHSCREEN_H

#include <QMainWindow>
#include <QSqlDatabase>

namespace Ui {
class StudentSearchScreen;
}

class StudentSearchScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentSearchScreen(QWidget *parent = nullptr);
    ~StudentSearchScreen();

private slots:
    void onSearchButtonClicked();

private:
    Ui::StudentSearchScreen *ui;
    QSqlDatabase db;
    void searchStudent(const QString &studentID);
    void redirectToNextPage();
    void displayError(const QString &message);
};

#endif // STUDENTSEARCHSCREEN_H
