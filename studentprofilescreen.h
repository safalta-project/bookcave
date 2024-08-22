#ifndef STUDENTPROFILESCREEN_H
#define STUDENTPROFILESCREEN_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class StudentProfileScreen; }
QT_END_NAMESPACE

class StudentProfileScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentProfileScreen(QWidget *parent = nullptr);
    ~StudentProfileScreen();

    void setStudentDetails(const QString &name, const QString &email, const QString &studentId, const QString &phone, const QString &department);
    void setBorrowedBooksCount(int count);

private slots:
    void onViewBorrowedBooksButtonClicked();

private:
    Ui::StudentProfileScreen *ui;
    QLabel *nameLabel;
    QLabel *emailLabel;
    QLabel *studentIdLabel;
    QLabel *phoneLabel;
    QLabel *departmentLabel;
    QLabel *borrowedBooksCountLabel;
    QPushButton *viewBorrowedBooksButton;
    QString studentId; // Add this line to store the student ID
};

#endif // STUDENTPROFILESCREEN_H
