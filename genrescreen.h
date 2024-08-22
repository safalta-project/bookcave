#ifndef GENRESCREEN_H
#define GENRESCREEN_H

#include <QMainWindow>

namespace Ui {
class GenreScreen;
}

class GenreScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit GenreScreen(QWidget *parent = nullptr);
    ~GenreScreen();



private:
    Ui::GenreScreen *ui;
    void setupGenreButtons();
};

#endif // GENRESCREEN_H
