/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *SortButton;
    QLabel *HeadingLabel;
    QPushButton *GenerateButton;
    QPushButton *Credits;
    QLabel *BSTTimeLabel;
    QLabel *MaxHeapTimeLabel;
    QTableWidget *tableWidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1299, 762);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        SortButton = new QPushButton(centralwidget);
        SortButton->setObjectName("SortButton");
        SortButton->setGeometry(QRect(890, 80, 221, 51));
        SortButton->setAutoFillBackground(false);
        SortButton->setAutoRepeat(false);
        HeadingLabel = new QLabel(centralwidget);
        HeadingLabel->setObjectName("HeadingLabel");
        HeadingLabel->setGeometry(QRect(10, 0, 611, 61));
        QFont font;
        font.setPointSize(36);
        HeadingLabel->setFont(font);
        GenerateButton = new QPushButton(centralwidget);
        GenerateButton->setObjectName("GenerateButton");
        GenerateButton->setGeometry(QRect(890, 140, 221, 51));
        GenerateButton->setAutoFillBackground(false);
        GenerateButton->setAutoRepeat(false);
        Credits = new QPushButton(centralwidget);
        Credits->setObjectName("Credits");
        Credits->setGeometry(QRect(1180, 700, 111, 31));
        Credits->setAutoFillBackground(false);
        Credits->setAutoRepeat(false);
        BSTTimeLabel = new QLabel(centralwidget);
        BSTTimeLabel->setObjectName("BSTTimeLabel");
        BSTTimeLabel->setGeometry(QRect(890, 560, 401, 51));
        QFont font1;
        font1.setPointSize(20);
        BSTTimeLabel->setFont(font1);
        MaxHeapTimeLabel = new QLabel(centralwidget);
        MaxHeapTimeLabel->setObjectName("MaxHeapTimeLabel");
        MaxHeapTimeLabel->setGeometry(QRect(890, 620, 401, 51));
        MaxHeapTimeLabel->setFont(font1);
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(10, 80, 871, 651));
        MainWindow->setCentralWidget(centralwidget);
        tableWidget->raise();
        SortButton->raise();
        HeadingLabel->raise();
        GenerateButton->raise();
        Credits->raise();
        BSTTimeLabel->raise();
        MaxHeapTimeLabel->raise();
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        SortButton->setText(QCoreApplication::translate("MainWindow", "Sort By Rating:", nullptr));
        HeadingLabel->setText(QCoreApplication::translate("MainWindow", "Cinemas Best Benchmark V1", nullptr));
        GenerateButton->setText(QCoreApplication::translate("MainWindow", "Generate New List", nullptr));
        Credits->setText(QCoreApplication::translate("MainWindow", "Credits", nullptr));
        BSTTimeLabel->setText(QCoreApplication::translate("MainWindow", "BST Time:", nullptr));
        MaxHeapTimeLabel->setText(QCoreApplication::translate("MainWindow", "Max Heap Time:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
