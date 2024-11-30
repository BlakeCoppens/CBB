#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize the table widget
    ui->tableWidget->setColumnCount(5); // Five columns for Movie Title, Rating, Genre, Year, Additional Info
    QStringList headers = {"Movie Title", "Rating", "Genre", "Year", "Additional Info"};
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); // Make the table read-only
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); // Select entire rows

    // Adjust column sizes
    ui->tableWidget->setColumnWidth(0, 300); // Largest for Movie Title
    ui->tableWidget->setColumnWidth(1, 100); // Rating
    ui->tableWidget->setColumnWidth(2, 150); // Genre
    ui->tableWidget->setColumnWidth(3, 100); // Year
    ui->tableWidget->setColumnWidth(4, 200); // Additional Info

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
        "QTableWidget { background-color: #ADB6A8; color: #2B3D35; }" // Table background and text colors
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
    connect(ui->GenerateButton, &QPushButton::clicked, this, &MainWindow::onGenerateNewListClicked);
}

void MainWindow::onGenerateNewListClicked()
{
    // Add a new row to the table
    int row = ui->tableWidget->rowCount(); // Get the current number of rows
    ui->tableWidget->insertRow(row); // Insert a new row

    // Example movie data
    QString movieTitle = "Movie " + QString::number(row + 1);
    QString rating = QString::number(rand() % 10 + 1) + "/10"; // Random rating from 1-10
    QString genre = (rand() % 2 == 0) ? "Action" : "Comedy"; // Random genre
    QString year = QString::number(2000 + rand() % 23); // Random year between 2000 and 2022
    QString additionalInfo = "Info " + QString::number(row + 1);

    // Populate the row with data
    ui->tableWidget->setItem(row, 0, new QTableWidgetItem(movieTitle));
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(rating));
    ui->tableWidget->setItem(row, 2, new QTableWidgetItem(genre));
    ui->tableWidget->setItem(row, 3, new QTableWidgetItem(year));
    ui->tableWidget->setItem(row, 4, new QTableWidgetItem(additionalInfo));
}

MainWindow::~MainWindow()
{
    delete ui;
}
