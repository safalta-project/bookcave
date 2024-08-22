#ifndef BORROWEDBOOKSSCREEN_H
#define BORROWEDBOOKSSCREEN_H

#include <QMainWindow>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>
#include <QString>
#include <QPushButton>  // Add this include for QPushButton
#include <QSqlQuery>

namespace Ui {
class BorrowedBooksScreen;
}

class BorrowedBooksScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit BorrowedBooksScreen(const QString &studentId, QWidget *parent = nullptr);
    ~BorrowedBooksScreen();

private:
    void displayBorrowedBooks();
    void createBookWidget(const QSqlQuery &query);
    void clearLayout(QLayout *layout);
    void returnBooks(const QList<int>& bookIds);

    Ui::BorrowedBooksScreen *ui;
    QScrollArea *scrollArea;
    QWidget *scrollContent;
    QVBoxLayout *scrollLayout;
    QString studentId; // Store student ID
    QPushButton *returnButton; // Declare returnButton

private slots:
    void onReturnButtonClicked();
};

#endif // BORROWEDBOOKSSCREEN_H
