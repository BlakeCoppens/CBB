#ifndef CREDITS_H
#define CREDITS_H

#include <QMainWindow>

namespace Ui {
class credits;
}

class credits : public QMainWindow
{
    Q_OBJECT

public:
    explicit credits(QWidget *parent = nullptr);
    ~credits();

signals:
    void backToMain();

private:
    Ui::credits *ui;
};

#endif // CREDITS_H
