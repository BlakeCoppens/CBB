#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "MovieTree.h"
#include "MovieClass.h"
#include <QFile>
#include <QTextStream>
#include <vector>
#include <chrono>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->tableWidget->setColumnCount(4);
    QStringList headers = {"Movie Title", "Rating", "Genre", "Year"};
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); // Make the table read-only
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Adjust column sizes
    ui->tableWidget->setColumnWidth(0, 500);
    ui->tableWidget->setColumnWidth(2, 150);
    ui->tableWidget->setColumnWidth(1, 100);
    ui->tableWidget->setColumnWidth(3, 100);

    // Align header styles with the palette
    ui->tableWidget->horizontalHeader()->setStyleSheet(
        "QHeaderView::section {"
        "background-color: #39594A;" // Darker background
        "color: #E8EAE5;"           // Light text
        "padding: 5px;"             // Padding inside the header
        "border: none;"             // Remove borders
        "}"
        );

    // Overall table style
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->setStyleSheet(
        "QTableWidget { background-color: #ADB6A8; color: #2B3D35; }"
        );

    // Define the stylesheet for the main window
    QString styleSheet = R"(
        QWidget {
            background-color: #2B3D35; /* Main dark green background */
            color: #E8EAE5; /* Light text color */
        }
        QLabel {
            color: #F5F5F5; /* Bright white for better readability */
            border: none; /* Remove borders for labels */
            background-color: #39594A; /* Slightly darker green for contrast */
            padding: 5px; /* Add some spacing inside the label */
            border-radius: 3px; /* Rounded corners for labels */
        }
        QLabel#HeadingLabel {
            border: none; /* No border for the header label */
            background-color: transparent; /* Transparent background for the header */
            color: #E8EAE5; /* Light text for the header */
        }
        QPushButton {
            background-color: #39594A; /* Mid-green for buttons */
            color: #E8EAE5; /* Light text on buttons */
            border: 2px solid #D5DDD8; /* Border matches label text color */
            border-radius: 5px;
        }
    )";
    this->setStyleSheet(styleSheet); // Apply the stylesheet to the MainWindow

    // Connect the Generate New List button to a slot
    connect(ui->Credits, &QPushButton::clicked, this, &MainWindow::onCreditsClicked);
    connect(ui->GenerateButton, &QPushButton::clicked, this, &MainWindow::onGenerateNewListClicked);
    connect(ui->SortButton, &QPushButton::clicked, this, &MainWindow::onSortClicked);
}

void MainWindow::onGenerateNewListClicked()
{
    ui->tableWidget->setRowCount(0);

    // Generate the list of movies
    movies = Movie::generateRandom();

    // Populate the table with unsorted data
    for (const auto& movie : movies) {
        int row = ui->tableWidget->rowCount(); // Get the current number of rows
        ui->tableWidget->insertRow(row);       // Insert a new row

        // Populate the row with data from the Movie object
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(movie.getName())));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(movie.getRating(), 'f', 5)));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(movie.getGenre())));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(movie.getYear())));
    }
}

void MainWindow::onSortClicked()
{
    ui->tableWidget->setRowCount(0);

    // Insert movies into the BST for sorting
    MovieBST movieBST;
    for (const auto& movie : movies) {
        movieBST.insert(movie);
    }

    // Measure the time taken for traversal
    auto start = std::chrono::high_resolution_clock::now(); // Start timer

    // Get sorted movies in descending order from the BST
    vector<Movie> sortedMovies = movieBST.getSortedMoviesDescending();

    auto end = std::chrono::high_resolution_clock::now(); // End timer

    // Calculate elapsed time in milliseconds
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // Update the BSTTimeLabel with the time taken
    QString timeText = QString("BST Time: %1 ms").arg(duration.count());
    ui->BSTTimeLabel->setText(timeText); // Set the text on the label

    // Populate the table with sorted data
    for (const auto& movie : sortedMovies) {
        int row = ui->tableWidget->rowCount(); // Get the current number of rows
        ui->tableWidget->insertRow(row);       // Insert a new row

        // Populate the row with data from the Movie object
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(movie.getName())));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(movie.getRating(), 'f', 5)));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(movie.getGenre())));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(movie.getYear())));
    }
}

void MainWindow::onCreditsClicked()
{
    //placeholder asf until i feel like doing ts
}
MainWindow::~MainWindow()
{
    delete ui;
}
