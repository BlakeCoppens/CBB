/********************************************************************************
** Form generated from reading UI file 'credits.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDITS_H
#define UI_CREDITS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_credits
{
public:
    QWidget *centralwidget;
    QLabel *HeadingLabel;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *BackButton;

    void setupUi(QMainWindow *credits)
    {
        if (credits->objectName().isEmpty())
            credits->setObjectName("credits");
        credits->resize(1513, 771);
        centralwidget = new QWidget(credits);
        centralwidget->setObjectName("centralwidget");
        HeadingLabel = new QLabel(centralwidget);
        HeadingLabel->setObjectName("HeadingLabel");
        HeadingLabel->setGeometry(QRect(20, 40, 1481, 91));
        QFont font;
        font.setPointSize(72);
        HeadingLabel->setFont(font);
        HeadingLabel->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        HeadingLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 270, 1481, 61));
        QFont font1;
        font1.setPointSize(16);
        label_4->setFont(font1);
        label_4->setTextFormat(Qt::TextFormat::PlainText);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 390, 1481, 61));
        label_6->setFont(font1);
        label_6->setTextFormat(Qt::TextFormat::PlainText);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 330, 1481, 61));
        label_5->setFont(font1);
        label_5->setTextFormat(Qt::TextFormat::PlainText);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 160, 1481, 61));
        label_2->setFont(font1);
        label_2->setTextFormat(Qt::TextFormat::PlainText);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 210, 1481, 61));
        label_3->setFont(font1);
        label_3->setTextFormat(Qt::TextFormat::PlainText);
        BackButton = new QPushButton(centralwidget);
        BackButton->setObjectName("BackButton");
        BackButton->setGeometry(QRect(680, 680, 141, 51));
        credits->setCentralWidget(centralwidget);

        retranslateUi(credits);

        QMetaObject::connectSlotsByName(credits);
    } // setupUi

    void retranslateUi(QMainWindow *credits)
    {
        credits->setWindowTitle(QCoreApplication::translate("credits", "Credits", nullptr));
        HeadingLabel->setText(QCoreApplication::translate("credits", "Credits", nullptr));
        label_4->setText(QCoreApplication::translate("credits", "QT Creator Documentation:  https://doc.qt.io/tools.html ", nullptr));
        label_6->setText(QCoreApplication::translate("credits", "Name Generator Inspiration:  https://stackoverflow.com/questions/49331701/c-random-name-generator-giving-repeat-string", nullptr));
        label_5->setText(QCoreApplication::translate("credits", "QT Creator Setup Video & Guide:  https://www.youtube.com/watch?v=cXojtB8vS2E&t=36s&ab_channel=Sciber", nullptr));
        label_2->setText(QCoreApplication::translate("credits", "Color Pallate: https://colorhunt.co/palette/e7f0dc597445658147729762 ", nullptr));
        label_3->setText(QCoreApplication::translate("credits", "Words Used for Titles: https://www.oxfordlearnersdictionaries.com/us/wordlists/oxford3000-5000", nullptr));
        BackButton->setText(QCoreApplication::translate("credits", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class credits: public Ui_credits {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDITS_H
