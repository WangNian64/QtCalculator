/********************************************************************************
** Form generated from reading UI file 'calculator.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_H
#define UI_CALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calculator
{
public:
    QWidget *centralWidget;
    QPushButton *number1;
    QPushButton *number2;
    QPushButton *number3;
    QPushButton *number4;
    QPushButton *number5;
    QPushButton *number6;
    QPushButton *number7;
    QPushButton *number9;
    QPushButton *number8;
    QPushButton *equalButton;
    QPushButton *number0;
    QPushButton *addButton;
    QPushButton *substractButton;
    QPushButton *multiplyButton;
    QPushButton *divideButton;
    QPushButton *rBracketButton;
    QPushButton *lBracketButton;
    QLineEdit *lineEdit;
    QPushButton *zhengfuButton;
    QPushButton *deleteButton;
    QPushButton *clearButton;
    QPushButton *chengfangButton;
    QPushButton *jiechengButton;
    QPushButton *aboutButton;
    QPushButton *tanButton;
    QPushButton *cosButton;
    QPushButton *sinButton;
    QPushButton *percentButton;
    QPushButton *pointButton;
    QPushButton *helpButton;

    void setupUi(QMainWindow *Calculator)
    {
        if (Calculator->objectName().isEmpty())
            Calculator->setObjectName(QStringLiteral("Calculator"));
        Calculator->resize(311, 441);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Calculator->sizePolicy().hasHeightForWidth());
        Calculator->setSizePolicy(sizePolicy);
        Calculator->setMaximumSize(QSize(1000000, 10000000));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(67, 67, 67, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        QBrush brush2(QColor(128, 202, 196, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush3(QColor(0, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush3);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush1);
        palette.setBrush(QPalette::Active, QPalette::Link, brush1);
        palette.setBrush(QPalette::Active, QPalette::LinkVisited, brush1);
        QBrush brush4(QColor(33, 33, 33, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush1);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Link, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush3);
        QBrush brush5(QColor(51, 153, 255, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Link, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush3);
        Calculator->setPalette(palette);
        centralWidget = new QWidget(Calculator);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        number1 = new QPushButton(centralWidget);
        number1->setObjectName(QStringLiteral("number1"));
        number1->setGeometry(QRect(10, 80, 50, 50));
        number2 = new QPushButton(centralWidget);
        number2->setObjectName(QStringLiteral("number2"));
        number2->setGeometry(QRect(70, 80, 50, 50));
        number3 = new QPushButton(centralWidget);
        number3->setObjectName(QStringLiteral("number3"));
        number3->setGeometry(QRect(130, 80, 50, 50));
        number4 = new QPushButton(centralWidget);
        number4->setObjectName(QStringLiteral("number4"));
        number4->setGeometry(QRect(10, 140, 50, 50));
        number5 = new QPushButton(centralWidget);
        number5->setObjectName(QStringLiteral("number5"));
        number5->setGeometry(QRect(70, 140, 50, 50));
        number6 = new QPushButton(centralWidget);
        number6->setObjectName(QStringLiteral("number6"));
        number6->setGeometry(QRect(130, 140, 50, 50));
        number7 = new QPushButton(centralWidget);
        number7->setObjectName(QStringLiteral("number7"));
        number7->setGeometry(QRect(10, 200, 50, 50));
        number9 = new QPushButton(centralWidget);
        number9->setObjectName(QStringLiteral("number9"));
        number9->setGeometry(QRect(130, 200, 50, 50));
        number8 = new QPushButton(centralWidget);
        number8->setObjectName(QStringLiteral("number8"));
        number8->setGeometry(QRect(70, 200, 50, 50));
        equalButton = new QPushButton(centralWidget);
        equalButton->setObjectName(QStringLiteral("equalButton"));
        equalButton->setGeometry(QRect(190, 380, 110, 50));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(equalButton->sizePolicy().hasHeightForWidth());
        equalButton->setSizePolicy(sizePolicy1);
        equalButton->setAutoFillBackground(false);
        number0 = new QPushButton(centralWidget);
        number0->setObjectName(QStringLiteral("number0"));
        number0->setGeometry(QRect(70, 260, 50, 50));
        addButton = new QPushButton(centralWidget);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(190, 140, 50, 50));
        substractButton = new QPushButton(centralWidget);
        substractButton->setObjectName(QStringLiteral("substractButton"));
        substractButton->setGeometry(QRect(250, 140, 50, 50));
        multiplyButton = new QPushButton(centralWidget);
        multiplyButton->setObjectName(QStringLiteral("multiplyButton"));
        multiplyButton->setGeometry(QRect(190, 200, 50, 50));
        divideButton = new QPushButton(centralWidget);
        divideButton->setObjectName(QStringLiteral("divideButton"));
        divideButton->setGeometry(QRect(250, 200, 50, 50));
        rBracketButton = new QPushButton(centralWidget);
        rBracketButton->setObjectName(QStringLiteral("rBracketButton"));
        rBracketButton->setGeometry(QRect(250, 320, 50, 50));
        lBracketButton = new QPushButton(centralWidget);
        lBracketButton->setObjectName(QStringLiteral("lBracketButton"));
        lBracketButton->setGeometry(QRect(190, 320, 50, 50));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(0, 0, 311, 61));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        lineEdit->setPalette(palette1);
        zhengfuButton = new QPushButton(centralWidget);
        zhengfuButton->setObjectName(QStringLiteral("zhengfuButton"));
        zhengfuButton->setGeometry(QRect(10, 260, 50, 50));
        deleteButton = new QPushButton(centralWidget);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setGeometry(QRect(190, 80, 50, 50));
        clearButton = new QPushButton(centralWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setGeometry(QRect(250, 80, 50, 50));
        chengfangButton = new QPushButton(centralWidget);
        chengfangButton->setObjectName(QStringLiteral("chengfangButton"));
        chengfangButton->setGeometry(QRect(190, 260, 50, 50));
        jiechengButton = new QPushButton(centralWidget);
        jiechengButton->setObjectName(QStringLiteral("jiechengButton"));
        jiechengButton->setGeometry(QRect(250, 260, 50, 50));
        aboutButton = new QPushButton(centralWidget);
        aboutButton->setObjectName(QStringLiteral("aboutButton"));
        aboutButton->setGeometry(QRect(10, 320, 50, 50));
        tanButton = new QPushButton(centralWidget);
        tanButton->setObjectName(QStringLiteral("tanButton"));
        tanButton->setGeometry(QRect(130, 380, 50, 50));
        cosButton = new QPushButton(centralWidget);
        cosButton->setObjectName(QStringLiteral("cosButton"));
        cosButton->setGeometry(QRect(70, 380, 50, 50));
        sinButton = new QPushButton(centralWidget);
        sinButton->setObjectName(QStringLiteral("sinButton"));
        sinButton->setGeometry(QRect(10, 380, 50, 50));
        percentButton = new QPushButton(centralWidget);
        percentButton->setObjectName(QStringLiteral("percentButton"));
        percentButton->setGeometry(QRect(70, 320, 50, 50));
        pointButton = new QPushButton(centralWidget);
        pointButton->setObjectName(QStringLiteral("pointButton"));
        pointButton->setGeometry(QRect(130, 260, 50, 50));
        helpButton = new QPushButton(centralWidget);
        helpButton->setObjectName(QStringLiteral("helpButton"));
        helpButton->setGeometry(QRect(130, 320, 50, 50));
        Calculator->setCentralWidget(centralWidget);

        retranslateUi(Calculator);

        QMetaObject::connectSlotsByName(Calculator);
    } // setupUi

    void retranslateUi(QMainWindow *Calculator)
    {
        Calculator->setWindowTitle(QApplication::translate("Calculator", "\346\234\261\344\277\212\346\235\260\347\232\204\350\256\241\347\256\227\345\231\250", 0));
        number1->setText(QApplication::translate("Calculator", "1", 0));
        number2->setText(QApplication::translate("Calculator", "2", 0));
        number3->setText(QApplication::translate("Calculator", "3", 0));
        number4->setText(QApplication::translate("Calculator", "4", 0));
        number5->setText(QApplication::translate("Calculator", "5", 0));
        number6->setText(QApplication::translate("Calculator", "6", 0));
        number7->setText(QApplication::translate("Calculator", "7", 0));
        number9->setText(QApplication::translate("Calculator", "9", 0));
        number8->setText(QApplication::translate("Calculator", "8", 0));
        equalButton->setText(QApplication::translate("Calculator", "=", 0));
        number0->setText(QApplication::translate("Calculator", "0", 0));
        addButton->setText(QApplication::translate("Calculator", "+", 0));
        substractButton->setText(QApplication::translate("Calculator", "-", 0));
        multiplyButton->setText(QApplication::translate("Calculator", "*", 0));
        divideButton->setText(QApplication::translate("Calculator", "/", 0));
        rBracketButton->setText(QApplication::translate("Calculator", ")", 0));
        lBracketButton->setText(QApplication::translate("Calculator", "(", 0));
        zhengfuButton->setText(QApplication::translate("Calculator", "+/-", 0));
        deleteButton->setText(QApplication::translate("Calculator", "<-", 0));
        clearButton->setText(QApplication::translate("Calculator", "c", 0));
        chengfangButton->setText(QApplication::translate("Calculator", "^", 0));
        jiechengButton->setText(QApplication::translate("Calculator", "!", 0));
        aboutButton->setText(QApplication::translate("Calculator", "\302\256", 0));
        tanButton->setText(QApplication::translate("Calculator", "tan", 0));
        cosButton->setText(QApplication::translate("Calculator", "cos", 0));
        sinButton->setText(QApplication::translate("Calculator", "sin", 0));
        percentButton->setText(QApplication::translate("Calculator", "%", 0));
        pointButton->setText(QApplication::translate("Calculator", ".", 0));
        helpButton->setText(QApplication::translate("Calculator", "?", 0));
    } // retranslateUi

};

namespace Ui {
    class Calculator: public Ui_Calculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_H
