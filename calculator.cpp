#include "calculator.h"
#include "stack.h"
#include "ui_calculator.h"
#include "help.h"
#include <cmath>
#include <QDebug>
#include <cstring>
double jiecheng(double n)
{
    double sum=1;
    while (n>=1)
    {
        sum*=n;
        n--;
    }
    return sum;
}

double Sin(double n)
{
    bool flag = true;//T减法，F加法
    n=3.14159265/(180/n);//换算成弧度
    double result = n;
    double a=0,b=0;
    double oddnum = 0;
    for(int i=0;i<12;i++)
    {//精度
        oddnum = 2*(i+1)+1;
        a=pow(n,oddnum);
        b= (double)jiecheng(oddnum);
        if(flag){
            result = result - (a/b);
            flag = false;
        }
        else{
            result = result + (a/b);
            flag = true;
        }
    }
    return result;
}
double Cos(double n)
{
    bool flag = true;//T减法，F加法
    n=3.14159265/(180/n)+3.141582653/2.0;//换算成弧度
    double result = n;
    double a=0,b=0;
    double oddnum = 0;
    for(int i=0;i<12;i++)
    {//精度
        oddnum = 2*(i+1)+1;
        a=pow(n,oddnum);
        b= (double)jiecheng(oddnum);
        if(flag){
            result = result - (a/b);
            flag = false;
        }
        else{
            result = result + (a/b);
            flag = true;
        }
    }
    return result;
}

double Tan(double n)
{
    return Sin(n)/Cos(n);
}

bool Calculator::isDigit(char num)
{
    if (num>='0'&& num<='9')
    {
        return true;
    }
    return false;
}//是不是数字

bool Calculator::isSign(char sign)
{
    if (sign == '+' || sign == '-' || sign == '*' || sign == '/' || sign == '^' || sign == '!'
            || sign == '%' ||  sign == 'S' || sign == 'C' || sign == 'T' ||
            sign == '(' || sign == ')' || sign == '\0')
        return true;
    return false;
}//是不是符号
bool Calculator::isSign1r(char sign)
{
    if (sign == '!' || sign == '%')
        return true;
    return false;
}
bool Calculator::isSign1l(char sign)
{
    if (sign == 'S' || sign == 'C' || sign == 'T')
        return true;
    return false;
}
bool Calculator::isSign1(char sign)
{
    if (sign == '!' || sign == '%' ||  sign == 'S' || sign == 'C' || sign == 'T')
        return true;
    return false;
}
bool Calculator::isSign2(char sign)
{
    if (sign == '+' || sign == '-' || sign == '*' || sign == '/' || sign == '^' ||
            sign == '(' || sign == ')' || sign == '\0')
        return true;
    return false;
}
double Calculator::dealDigit(char num)
{
    return num - '0';//把字符串转化为数字
}
bool Calculator::isPoint(char point)
{
    return point=='.';
}
bool Calculator::wrongOper(char oper)
{
    if ( (isSign2(oper) && oper!='(' && oper!='-') || isSign1r(oper))
        return true;
    return false;
}

void Calculator::dealSign(char sn, int &i,Stack<double> &num, Stack<char> &sign)//主要的难点
{
    char priority = check_pri(sign.top(),sn);//注意！
    switch (priority)
    {
    case '<':
    {
        sign.push(sn);
        if (isSign1l(sn))
            i+=3;
        else
            i++;
        break;
    }
    case '=':
    {
        sign.pop();
        i++;
        break;
    }
    case '>':
    {
        if (isSign1(sign.top()))
        {
            double a;//a、b存储栈顶的两个操作数
            char sign1 = sign.top();
            sign.pop();

            a = num.top();//取出a出栈
            num.pop();

            num.push(calcu1(a, sign1));
            break;
        }
        else
        {
            double a, b;//a、b存储栈顶的两个操作数
            char sign2 = sign.top();
            sign.pop();

            a = num.top();//取出a出栈
            num.pop();

            b = num.top();//取出b出栈
            num.pop();

            num.push(calcu2(a, b, sign2));
            break;
        }
    }
    default:
        break;
    }
}
double zhengfu=1.0;
double Calculator::get_num(char *expre, int n)
{
    Stack<char> sign;
    Stack<double> num;
    sign.push('\0');
    for (int i = 0; i < n;)
    {
        double number=0.0,total=0.0;
        int j = i;//记录i的值
        if (expre[j]=='-' && isDigit(expre[j+1]) && (isSign(expre[j-1]) || expre[j-1]=='n' || expre[j-1]=='s'))
        {
            zhengfu=-1.0;
            i++;
            continue;
        }
        if (isDigit(expre[i]))
        {
            while (isDigit(expre[i]))
                i++;
            for (int bit = i - j; bit >= 1; bit--)//j-i就是一个整数的位数
            {
                number = dealDigit(expre[i - bit]);
                for (int n = 1; n < bit; n++)
                    number *= 10 ;
                total += number;
            }//考虑到多位数的情况
            if (isPoint(expre[i]))
            {
                i++;
                int k=i;
                while (isDigit(expre[i]))
                    i++;
                for (int bit = i - k; bit >= 1; bit--)//j-i就是一个整数的位数
                {
                    number = dealDigit(expre[k+bit-1]);
                    for (int n = 1; n <= bit; n++)
                        number *= 0.1 ;
                    total += number;
                }//考虑到多位数的情况
            }
            num.push(total*zhengfu);
            zhengfu=1.0;
        }
        if (isSign(expre[i]))
            dealSign(expre[i], i, num, sign);
    }
    return num.top();
}
double Calculator::calcu1(double a,char sign)
{
    switch (sign)
    {
    case '!':
        return jiecheng(a);
    case '%':
        return a/100;
    case 'S':
        return Sin(a);
    case 'C':
        return Cos(a);
    case 'T':
        return Tan(a);
    default:
        break;
    }
}
double Calculator::calcu2(double a,double b,char sign)
{
    switch (sign)
    {
    case '+':
        return a + b;
    case '-':
        return b - a;
    case '*':
        return a * b;
    case '/':
        return b / a;
    case '^':
        return pow(b,a);
    default:
        break;
    }
}

char Calculator::check_pri(char a, char b)//检查优先级
{
    int m, n;
    char priority[13][13] = {//+ - * / ^ ! % sin cos tan ( ) \0
        /* + */{ '>', '>', '<', '<', '<', '<', '<', '<', '<', '<', '<', '>', '>' },//对于+和-运算符，按照栈的位置
        /* - */{ '>', '>', '<', '<', '<', '<', '<', '<', '<', '<', '<', '>', '>' },
        /* * */{ '>', '>', '>', '>', '<', '<', '<', '<', '<', '<', '<', '>', '>' },
        /* / */{ '>', '>', '>', '>', '<', '<', '<', '<', '<', '<', '<', '>', '>' },

        /* ^ */{ '>', '>', '>', '>', '<', '<', '<', '<', '<', '<', '<', '>', '>' },

        /* ! */{ '>', '>', '>', '>', '>', '>', '>', '>', '>', '>', ' ', '>', '>' },
        /* % */{ '>', '>', '>', '>', '>', '>', '>', '>', '>', '>', ' ', '>', '>' },
        /*sin*/{ '>', '>', '>', '>', '>', '>', '>', '>', '>', '>', ' ', '>', '>' },
        /*cos*/{ '>', '>', '>', '>', '>', '>', '>', '>', '>', '>', ' ', '>', '>' },
        /*tan*/{ '>', '>', '>', '>', '>', '>', '>', '>', '>', '>', ' ', '>', '>' },

        /* ( */{ '<', '<', '<', '<', '<', '<', '<', '<', '<', '<', '<', '=', '>' },
        /* ) */{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
        /* \0*/{ '<', '<', '<', '<', '<', '<', '<', '<', '<', '<', '<', '<', '=' },
    };
    switch (a)
    {
    case '+':
    {
                m = 0;
                break;
    }
    case '-':
    {
                m = 1;
                break;
    }
    case '*':
    {
                m = 2;
                break;
    }
    case '/':
    {
                m = 3;
                break;
    }
    case '^':
    {
                m = 4;
                break;
    }
    case '!':
    {
                m = 5;
                break;
    }
    case '%':
    {
                m = 6;
                break;
    }
    case 'S':
    {
                m = 7;
                break;
    }
    case 'C':
    {
                m = 8;
                break;
    }
    case 'T':
    {
                m = 9;
                break;
    }
    case '(':
    {
                m = 10;
                break;
    }
    case ')':
    {
                m = 11;
                break;
    }

    case '\0':
    {
                m = 12;
                break;
    }
    default:
        break;
    }


    switch (b)
    {
    case '+':
    {
                n = 0;
                break;
    }
    case '-':
    {
                n = 1;
                break;
    }
    case '*':
    {
                n = 2;
                break;
    }
    case '/':
    {
                n = 3;
                break;
    }
    case '^':
    {
                n = 4;
                break;
    }
    case '!':
    {
                n = 5;
                break;
    }
    case '%':
    {
                n = 6;
                break;
    }
    case 'S':
    {
                n = 7;
                break;
    }
    case 'C':
    {
                n = 8;
                break;
    }
    case 'T':
    {
                n = 9;
                break;
    }
    case '(':
    {
                n = 10;
                break;
    }
    case ')':
    {
                n = 11;
                break;
    }

    case '\0':
    {
                n = 12;
                break;
    }

    default:
        break;
    }
    return priority[m][n];

}

void Calculator::findFalse(char *expre)
{
    if (strlen(expre)==1 && !isDigit(expre[0]))
    {
        switch (QMessageBox::warning(this,tr("warnning"),tr("Your expression is too short!"
                                    "clear it or not?"),QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes))
        {
        case QMessageBox::Yes:
        {
            ui->lineEdit->clear();
            return;
        }
        case QMessageBox::No:
            break;
        default:
            break;
        }
        return;
    }

    if (wrongOper(expre[0]))
    {
        switch (QMessageBox::warning(this,tr("warnning"),tr("the first one is wrong,"
                                    "clear it or not?"),QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes))
        {
        case QMessageBox::Yes:
        {
            ui->lineEdit->clear();
            return;
        }
        case QMessageBox::No:
            break;
        default:
            break;
        }
        return;
    }
    int lbracket,rbracket;
    lbracket=rbracket=0;
    for (int i=0;i<strlen(expre);i++)
    {
        if (expre[i]=='(')
            lbracket++;
        if (expre[i]==')')
            rbracket++;
    }
    if (lbracket!=rbracket)
    {
        switch (QMessageBox::warning(this,tr("warnning"),tr("the ( ) are wrong,"
                                    "clear it or not?"),QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes))
        {
        case QMessageBox::Yes:
        {
            ui->lineEdit->clear();
            return;
        }
        case QMessageBox::No:
            break;
        default:
            break;
        }
    }
    for (int i=0;i<strlen(expre);)
    {

        bool a, b, c, d, e, f, g, h, j, k, A, B, C;
        a=isDigit(expre[i]) && isSign1l(expre[i+1]);
        b=isSign1l(expre[i]) && isSign1l(expre[i+3]);
        c=isSign1l(expre[i]) && isSign1r(expre[i+3]);
        d=isSign1l(expre[i]) && isSign2(expre[i+3]) && expre[i+3]!='(';
        if (expre[i+3]=='-' && isDigit(expre[i+4]))
            d=false;
        e=isSign1r(expre[i]) && isDigit(expre[i+1]);
        f=isSign1r(expre[i]) && isSign1l(expre[i+1]);
        g=isSign2(expre[i]) && isSign1r(expre[i+1]) && expre[i+1]!=')';
        h=isSign2(expre[i]) && isSign2(expre[i+1]);

        if (h==1)
        {
            if (expre[i+1]=='-' && isDigit(expre[i+2]))
                h=0;
        }
        if (h==1)
            if ((expre[i]!=')' && expre[i+1]=='(')||(expre[i]==')' && expre[i+1]!=')'))
                h=0;
        j=expre[i]=='.' && (!isDigit(expre[i-1]) && !isDigit(expre[i+1]));

        k=false;
        if (expre[i]=='.')
        {
            if (!isDigit(expre[i-1]) || !isDigit(expre[i+1]))
                k=true;
        }

        A=isDigit(expre[i]) && expre[i+1]=='(';
        B=isSign1r(expre[i]) && expre[i+1]=='(';
        C=isSign1l(expre[i+1]) && expre[i]==')';

        if (a||b||c||d||e||f||g||h||j||k||A||B||C)
        {
            switch (QMessageBox::warning(this,tr("warnning"),tr("Some operators are wrong!"
                                        "clear or not?"),QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes))
            {
            case QMessageBox::Yes:
            {
                ui->lineEdit->clear();
                return;
            }
            case QMessageBox::No:
                break;
            default:
                break;
            }
        }
        if (isSign1l(expre[i]))
            i+=3;
        else
            i++;
    }
    return;
}

Calculator::Calculator(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);
    helpDialog=new help(this);//创建帮助窗口
    ui->number0->setFlat(true);
    ui->number1->setFlat(true);
    ui->number2->setFlat(true);
    ui->number3->setFlat(true);
    ui->number4->setFlat(true);
    ui->number5->setFlat(true);
    ui->number6->setFlat(true);
    ui->number7->setFlat(true);
    ui->number8->setFlat(true);
    ui->number9->setFlat(true);

    ui->addButton->setFlat(true);
    ui->substractButton->setFlat(true);
    ui->zhengfuButton->setFlat(true);
    ui->multiplyButton->setFlat(true);
    ui->divideButton->setFlat(true);
    ui->jiechengButton->setFlat(true);
    ui->chengfangButton->setFlat(true);

    ui->percentButton->setFlat(true);
    ui->sinButton->setFlat(true);
    ui->cosButton->setFlat(true);
    ui->tanButton->setFlat(true);

    ui->equalButton->setFlat(true);
    ui->rBracketButton->setFlat(true);
    ui->lBracketButton->setFlat(true);

    ui->deleteButton->setFlat(true);
    ui->clearButton->setFlat(true);
    ui->pointButton->setFlat(true);
    ui->aboutButton->setFlat(true);
    ui->helpButton->setFlat(true);

    QPalette pal;
    pal.setColor(QPalette::Text,QColor(128,202,196));
    ui->lineEdit->setPalette(pal);

    total=0.0;
    zhengfu_times=0;
}

void Calculator::on_number0_clicked()
{
    zhengfu_times=0;
    if (ui->lineEdit->text().contains('=',Qt::CaseSensitive))
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"0");
}
void Calculator::on_number1_clicked()
{
    zhengfu_times=0;
    if (ui->lineEdit->text().contains('=',Qt::CaseSensitive))
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"1");
}
void Calculator::on_number2_clicked()
{
    zhengfu_times=0;
    if (ui->lineEdit->text().contains('=',Qt::CaseSensitive))
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"2");
}
void Calculator::on_number3_clicked()
{
    zhengfu_times=0;
    if (ui->lineEdit->text().contains('=',Qt::CaseSensitive))
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"3");
}
void Calculator::on_number4_clicked()
{
    zhengfu_times=0;
    if (ui->lineEdit->text().contains('=',Qt::CaseSensitive))
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"4");
}
void Calculator::on_number5_clicked()
{
    zhengfu_times=0;
    if (ui->lineEdit->text().contains('=',Qt::CaseSensitive))
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"5");
}
void Calculator::on_number6_clicked()
{
    zhengfu_times=0;
    if (ui->lineEdit->text().contains('=',Qt::CaseSensitive))
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"6");
}
void Calculator::on_number7_clicked()
{
    zhengfu_times=0;
    if (ui->lineEdit->text().contains('=',Qt::CaseSensitive))
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"7");
}
void Calculator::on_number8_clicked()
{
    zhengfu_times=0;
    if (ui->lineEdit->text().contains('=',Qt::CaseSensitive))
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"8");
}
void Calculator::on_number9_clicked()
{
    zhengfu_times=0;
    if (ui->lineEdit->text().contains('=',Qt::CaseSensitive))
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"9");
}
void Calculator::on_addButton_clicked()
{
    zhengfu_times=0;
    if (ui->lineEdit->text().contains('=',Qt::CaseSensitive))
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"+");
}
void Calculator::on_substractButton_clicked()
{
    zhengfu_times=0;
    if (ui->lineEdit->text().contains('=',Qt::CaseSensitive))
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"-");
}

void Calculator::on_multiplyButton_clicked()
{
    zhengfu_times=0;
    if (ui->lineEdit->text().contains('=',Qt::CaseSensitive))
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"*");
}
void Calculator::on_divideButton_clicked()
{
    zhengfu_times=0;
    if (ui->lineEdit->text().contains('=',Qt::CaseSensitive))
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"/");
}
void Calculator::on_jiechengButton_clicked()
{
    zhengfu_times=0;
    if (ui->lineEdit->text().contains('=',Qt::CaseSensitive))
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"!");
}

void Calculator::on_chengfangButton_clicked()
{
    zhengfu_times=0;
    if (ui->lineEdit->text().contains('=',Qt::CaseSensitive))
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"^");
}

void Calculator::on_percentButton_clicked()
{
    zhengfu_times=0;
    if (ui->lineEdit->text().contains('=',Qt::CaseSensitive))
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"%");
}

void Calculator::on_sinButton_clicked()
{
    zhengfu_times=0;
    if (ui->lineEdit->text().contains('=',Qt::CaseSensitive))
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"Sin");
}

void Calculator::on_cosButton_clicked()
{
    zhengfu_times=0;
    if (ui->lineEdit->text().contains('=',Qt::CaseSensitive))
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"Cos");
}

void Calculator::on_tanButton_clicked()
{
    zhengfu_times=0;
    if (ui->lineEdit->text().contains('=',Qt::CaseSensitive))
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"Tan");
}

void Calculator::on_zhengfuButton_clicked()
{
    if (zhengfu_times%2==0)
    {
         ui->lineEdit->setText(ui->lineEdit->text()+"-");
    }
    else
    {
         ui->lineEdit->backspace();
    }
    zhengfu_times++;
}
void Calculator::on_rBracketButton_clicked()
{
    zhengfu_times=0;
    if (ui->lineEdit->text().contains('=',Qt::CaseSensitive))
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+")");
}
void Calculator::on_lBracketButton_clicked()
{
    zhengfu_times=0;
    if (ui->lineEdit->text().contains('=',Qt::CaseSensitive))
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"(");
}


void Calculator::on_equalButton_clicked()
{

    zhengfu_times=0;
    if (ui->lineEdit->text().contains('=',Qt::CaseSensitive))
    {
        ui->lineEdit->clear();
        return ;
    }
    QByteArray ba = ui->lineEdit->text().toLatin1();
    char *chars=ba.data();//把QString转化为char*
    findFalse(chars);
    if (!ui->lineEdit->text().isEmpty())
    {
        total=get_num(chars, strlen(chars)+1);
        ui->lineEdit->setText(ui->lineEdit->text()+"="+QString::number(total,'g',16));
    }
}

void Calculator::on_deleteButton_clicked()
{
    zhengfu_times=0;
    if (ui->lineEdit->text().contains('=',Qt::CaseSensitive))
        ui->lineEdit->clear();
    ui->lineEdit->backspace();
}

void Calculator::on_clearButton_clicked()
{
    zhengfu_times=0;
    ui->lineEdit->clear();
}
void Calculator::on_pointButton_clicked()
{
    zhengfu_times=0;
    if (ui->lineEdit->text().contains('=',Qt::CaseSensitive))
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+".");
}

void Calculator::on_aboutButton_clicked()
{
    QMessageBox box;
    box.setText(tr("版权所有，盗版必究"));
    QPalette pal1;
    pal1.setColor(QPalette::Background,QColor(43,43,43));
    box.setPalette(pal1);
    box.setInformativeText(tr("本计算器Bug较多，你爱用不用(ˉ▽￣~) 切~~"));
    box.setIconPixmap(QPixmap("C:/Users/junjie/Desktop/calcuIcon.png"));
    box.setWindowIcon(QIcon("C:/Users/junjie/Desktop/calcuIcon.png"));
    box.exec();
}
void Calculator::on_helpButton_clicked()
{
    help *helps=new help(this);
    helps->exec();
}

Calculator::~Calculator()
{
    delete ui;
}
