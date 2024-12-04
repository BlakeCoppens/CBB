#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "MovieTree.h"
#include "MovieClass.h"
#include <QFile>
#include <QTextStream>
#include <vector>
#include <chrono>
#include "credits.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create the credits window and keep it hidden
    creditsWindow = new credits(this);
    creditsWindow->hide(); // Keep it hidden initially

    // Connect the backToMain signal to hide the credits window and show the main window
    connect(creditsWindow, &credits::backToMain, this, [=]() {
        creditsWindow->hide(); // Hide the credits window
        this->show();          // Show the main window
    });

    // Connect the "Credits" button to show the credits window
    connect(ui->Credits, &QPushButton::clicked, this, &MainWindow::onCreditsClicked);

    ui->tableWidget->setColumnCount(4);
    QStringList headers = {"Movie Title", "Rating", "Genre", "Year"};
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);


    ui->tableWidget->setColumnWidth(0, 500);
    ui->tableWidget->setColumnWidth(2, 150);
    ui->tableWidget->setColumnWidth(1, 100);
    ui->tableWidget->setColumnWidth(3, 100);


    ui->tableWidget->horizontalHeader()->setStyleSheet(
        "QHeaderView::section {"
        "background-color: #39594A;"
        "color: #E8EAE5;"
        "padding: 5px;"
        "border: none;"
        "}"
        );


    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->setStyleSheet(
        "QTableWidget { background-color: #ADB6A8; color: #2B3D35; }"
        );


    QString styleSheet = R"(
        QWidget {
            background-color: #2B3D35;
            color: #E8EAE5;
        }
        QLabel {
            color: #F5F5F5;
            border: none;
            background-color: #39594A;
            padding: 5px;
            border-radius: 3px;
        }
        QLabel#HeadingLabel {
            border: none;
            background-color: transparent;
            color: #E8EAE5;
        }
        QPushButton {
            background-color: #39594A;
            color: #E8EAE5;
            border: 2px solid #D5DDD8;
            border-radius: 5px;
        }
    )";
    this->setStyleSheet(styleSheet);

    connect(ui->Credits, &QPushButton::clicked, this, &MainWindow::onCreditsClicked);
    connect(ui->GenerateButton, &QPushButton::clicked, this, &MainWindow::onGenerateNewListClicked);
    connect(ui->SortButton, &QPushButton::clicked, this, &MainWindow::onSortClicked);
}

void MainWindow::onGenerateNewListClicked()
{
    ui->tableWidget->setRowCount(0);

    movies = Movie::generateRandom();


    for (const auto& movie : movies) {
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(movie.getName())));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(movie.getRating(), 'f', 5)));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(movie.getGenre())));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(movie.getYear())));
    }
}

void MainWindow::onSortClicked()
{
    ui->tableWidget->setRowCount(0);

    MovieBST movieBST;
    for (const auto& movie : movies) {
        movieBST.insert(movie);
    }

    // Measure the time taken for traversal
    auto start = std::chrono::high_resolution_clock::now();


    vector<Movie> sortedMovies = movieBST.getSortedMoviesDescending();

    auto end = std::chrono::high_resolution_clock::now();


    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);


    QString timeText = QString("BST Time: %1 ms").arg(duration.count());
    ui->BSTTimeLabel->setText(timeText);


    for (const auto& movie : sortedMovies) {
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(movie.getName())));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(movie.getRating(), 'f', 5)));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(movie.getGenre())));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(movie.getYear())));
    }
}


#include "credits.h"

void MainWindow::onCreditsClicked()
{
    creditsWindow->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
