#ifndef CREDITSWINDOW_H
#define CREDITSWINDOW_H

#include <QDialog>

namespace Ui {
class creditswindow;
}

class creditswindow : public QDialog
{
    Q_OBJECT

public:
    explicit creditswindow(QWidget *parent = nullptr);
    ~creditswindow();

private:
    Ui::creditswindow *ui;
};

#endif // CREDITSWINDOW_H
