#include "usermain.h"
#include "searchbooks.h"
#include "changebook.h"
UserWindow::UserWindow(QWidget *parent):QMainWindow(parent)
{
    this->resize(800,800);
    BookSearch = new QPushButton("书籍查询",this);
    BookBorrow = new QPushButton("书籍借阅",this);
    BookReturn = new QPushButton("归还图书",this);
    Endsystem = new QPushButton("退出",this);
    S = new SearchWindow(this);
    C1 = new ChangeBook(1);
    C2 = new ChangeBook(2);
    BookSearch->setGeometry(250,100,300,100);
    BookBorrow->setGeometry(250,250,300,100);
    BookReturn->setGeometry(250,400,300,100);
    Endsystem->setGeometry(250,550,300,100);
    connect(Endsystem,SIGNAL(clicked()),this,SLOT(close()));
    connect(BookSearch,SIGNAL(clicked()),this,SLOT(uopen()));
    connect(BookReturn,SIGNAL(clicked()),this,SLOT(copen1()));
    connect(BookBorrow,SIGNAL(clicked()),this,SLOT(copen2()));
}
void UserWindow::uopen()
{
    S->show();
    this->close();
}
void UserWindow::copen1()
{
    C1->show();
}
void UserWindow::copen2()
{
    C2->show();
}
UserWindow::~UserWindow()
{

}
