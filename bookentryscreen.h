#ifndef BOOKENTRYSCREEN_H
#define BOOKENTRYSCREEN_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class BookEntryScreen;
}

class BookEntryScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit BookEntryScreen(QWidget *parent = nullptr);
    ~BookEntryScreen();

private slots:
    void onUploadButtonClicked();
    void onSaveButtonClicked();
    void onGenreRadioButtonClicked();
    void toggleFullscreen();

private:
    Ui::BookEntryScreen *ui;
    QString selectedGenre;
    QString imageFilePath;
};

#endif // BOOKENTRYSCREEN_H
