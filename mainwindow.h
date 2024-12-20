#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma once
#include "MovieClass.h"
#include "credits.h"
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
    void onCreditsClicked();
    void onSortClicked();

private:
    Ui::MainWindow *ui;
    std::vector<Movie> movies;
    credits *creditsWindow;
};
#endif // MAINWINDOW_H
