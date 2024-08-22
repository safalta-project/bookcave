#ifndef BOOKLISTSCREEN_H
#define BOOKLISTSCREEN_H

#include <QLabel>
#include <QMainWindow>
#include <QScrollArea>
#include <QSqlQuery>
#include <QVBoxLayout>

namespace Ui {
class BookListScreen;
}

class BookListScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit BookListScreen(QWidget *parent = nullptr);
    ~BookListScreen();
    void displayBooks(const QString& genre, const QString& searchTerm = QString());

private:
    Ui::BookListScreen *ui;
    QScrollArea *scrollArea;
    QWidget *scrollContent;
    QVBoxLayout *scrollLayout;
    QString currentGenre;
    QLabel *genreLabel;

    void createBookWidget(const QSqlQuery& query);
    void borrowBook();
    void clearLayout(QLayout *layout);
};

#endif // BOOKLISTSCREEN_H
