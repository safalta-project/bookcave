#ifndef BORROWSCREEN_H
#define BORROWSCREEN_H

#include <QMainWindow>

namespace Ui {
class BorrowScreen;
}

class BorrowScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit BorrowScreen(QWidget *parent = nullptr);
    ~BorrowScreen();

private slots:
    void onBorrowButtonClicked();  // Slot for the borrow button


private:
    Ui::BorrowScreen *ui;
};

#endif // BORROWSCREEN_H
