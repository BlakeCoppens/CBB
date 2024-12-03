#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma once
#include "MovieClass.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void onGenerateNewListClicked();
    void onCreditsClicked();    // Declare the slot for the button click
    void onSortClicked();

private:
    Ui::MainWindow *ui;
    std::vector<Movie> movies;
};
#endif // MAINWINDOW_H
