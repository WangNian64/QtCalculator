#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "Stack.h"
#include "help.h"
#include <QMainWindow>
#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QTextCodec>
#include <QMessageBox>
#define MAX 10000
#include <iostream>
using namespace std;
namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow
{
    Q_OBJECT
public:
    explicit Calculator(QWidget *parent = 0);
    ~Calculator();

    bool isDigit(char num);
    bool isSign(char sign);
    bool isSign1(char sign);
    bool isSign2(char sign);
    bool isSign1l(char sign);
    bool isSign1r(char sign);
	bool isPoint(char point);
    bool wrongOper(char oper);
    double dealDigit(char num);
    void dealSign(char sn, int &i, Stack<double> &num, Stack<char> &sign);
    char check_pri(char a, char b);
    double calcu1(double a, char sign);
    double calcu2(double a, double b, char sign);
    double get_num(char *expre, int n);

    void findFalse(char *expre);
private slots:
    void on_number1_clicked();
    void on_number2_clicked();
    void on_number3_clicked();
    void on_number4_clicked();
    void on_number5_clicked();
    void on_number6_clicked();
    void on_number7_clicked();
    void on_number8_clicked();
    void on_number9_clicked();
    void on_number0_clicked();

    void on_addButton_clicked();
    void on_substractButton_clicked();
    void on_zhengfuButton_clicked();
    void on_multiplyButton_clicked();
    void on_divideButton_clicked();
    void on_jiechengButton_clicked();//8!
    void on_chengfangButton_clicked();//a^b

    void on_percentButton_clicked();
    void on_sinButton_clicked();
    void on_cosButton_clicked();
    void on_tanButton_clicked();

    void on_equalButton_clicked();
    void on_rBracketButton_clicked();
    void on_lBracketButton_clicked();

    void on_deleteButton_clicked();
    void on_clearButton_clicked();
    void on_pointButton_clicked();

    void on_aboutButton_clicked();
    void on_helpButton_clicked();
private:
    Ui::Calculator *ui;
    double total;
    int zhengfu_times;
    help *helpDialog;

};

#endif // CALCULATOR_H
