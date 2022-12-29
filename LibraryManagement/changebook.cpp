#include "changebook.h"
void ChangeBook::getnumber()
{
    std::string s;
    const char* tnumber;
    s=number->text().toStdString();
    tnumber=s.c_str();
    inumber = atoi(tnumber);
}
void ChangeBook::getname()
{
    tname=name->text();
}
void ChangeBook::next()
{
    //把改变反映到数据文件中
}
ChangeBook::ChangeBook(int a,QWidget *parent):QMainWindow(parent),cof(a)
{
    this->resize(1000,800);
    numberhint = new QLabel("请输入借书数量",this);
    if(a==1)//return
        numberhint->setText("请输入还书数量");
    namehint = new QLabel("请输入书籍名称",this);
    confirm = new QPushButton("确定",this);
    number = new QLineEdit(this);
    name = new QLineEdit(this);
    namehint->setGeometry(300,200,200,50);
    numberhint->setGeometry(300,300,200,50);
    name->setGeometry(500,200,200,50);
    number->setGeometry(500,300,200,50);
    confirm->setGeometry(600,400,100,50);
    connect(number,SIGNAL(textChanged(const QString &)),this,SLOT(getnumber()));
    connect(name,SIGNAL(textChanged(const QString &)),this,SLOT(getname()));
    connect(confirm,SIGNAL(clicked()),this,SLOT(next()));
    connect(confirm,SIGNAL(clicked()),this,SLOT(close()));
}

ChangeBook::~ChangeBook()
{

}
