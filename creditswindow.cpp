#include "creditswindow.h"
#include "ui_creditswindow.h"

creditswindow::creditswindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::creditswindow)
{
    ui->setupUi(this);
}

creditswindow::~creditswindow()
{
    delete ui;
}
