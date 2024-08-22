#ifndef ALLBOOKSSCREEN_H
#define ALLBOOKSSCREEN_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QSqlQuery>
#include <QComboBox>

namespace Ui {
class AllBooksScreen;
}

class AllBooksScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit AllBooksScreen(QWidget *parent = nullptr);
    ~AllBooksScreen();

private:
    Ui::AllBooksScreen *ui;
    QVBoxLayout *scrollLayout;
    QScrollArea *scrollArea;
    QWidget *scrollContent;
    QComboBox *sortComboBox;

    void displayBooks(const QString &searchTerm = "");
    void createBookWidget(const QSqlQuery &query);
    void clearLayout(QLayout *layout);

private slots:
    void borrowBook();
    void sortBooks();
};

#endif // ALLBOOKSSCREEN_H
