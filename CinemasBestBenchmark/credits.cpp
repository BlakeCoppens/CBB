#include "credits.h"
#include "ui_credits.h"

credits::credits(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::credits)
{
    ui->setupUi(this);

    // Apply styles and ensure they persist
    QString styleSheet = R"(
        QMainWindow {
            background-color: #2B3D35;
        }
        QLabel {
            color: #F5F5F5;
            background-color: #39594A;
            padding: 10px;
            border-radius: 5px;
        }
        QLabel#HeadingLabel {
            font-size: 24px;
            font-weight: bold;
            background-color: transparent;
            color: #E8EAE5;
            margin-bottom: 20px;
        }
        QPushButton {
            background-color: #39594A;
            color: #E8EAE5;
            border: 2px solid #D5DDD8;
            border-radius: 5px;
            padding: 5px;
        }
        QPushButton:hover {
            background-color: #65897A;
        }
    )";
    this->setStyleSheet(styleSheet);

    // Connect the "Back" button to emit the signal and hide the credits window
    connect(ui->BackButton, &QPushButton::clicked, this, [=]() {
        this->hide();      // Hide the credits window
    });
}

credits::~credits()
{
    delete ui;
}
