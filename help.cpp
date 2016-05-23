#include "help.h"
#include "ui_help.h"
#include <QGridLayout>
#include <QHBoxLayout>
help::help(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::help)
{
    textEdit=new QTextEdit(this);
    textEdit->setGeometry(0,0,360,260);
    textEdit->append(tr("||||||||||||||||||||||||||||this is a help file||||||||||||||||||||||||||||"));
    textEdit->append(tr("1.you can input from keyborads or buttons."));
    textEdit->append(tr("2.It's OK if you input wrong,software will tell you"));
    textEdit->append(tr("3.Maybe there are some faults,you can tell me the bugs."));
    textEdit->append(tr("Last,thankyou for using my first software!!!"));
    textEdit->append(tr("^O^ ^O^ ^O^ ^O^ ^O^ ^O^ ^O^ "));
    QPalette pals;
    pals.setColor(QPalette::Background,QColor(43,43,43));
    this->setPalette(pals);
	QFont fonts;
    fonts.setBold(false);
    fonts.setPointSize(12);
    textEdit->setFont(fonts);
    ui->setupUi(this);
}

help::~help()
{
    delete ui;
}
