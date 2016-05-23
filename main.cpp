#include "calculator.h"
#include "help.h"
#include <QApplication>
#include <QFontDatabase>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calculator w;
    QFont font=a.font();
    font.setPixelSize(18);
    font.setBold(true);
    font.setFamily("Microsoft Yahei");
    a.setFont(font);

    w.setWindowIcon(QIcon("C:/Users/junjie/Desktop/calcuIcon.png"));
    w.show();
    return a.exec();
}
