#include "usermain.h"

UserWindow::UserWindow(QWidget *parent):QMainWindow(parent)
{
    QPushButton *BookSearch = new QPushButton("书籍查询",this);
    QPushButton *BookBorrow = new QPushButton("书籍借阅",this);
    QPushButton *BookReturn = new QPushButton("归还图书",this);
    BookSearch->setGeometry(175,100,300,100);
    BookBorrow->setGeometry(175,250,300,100);
    BookReturn->setGeometry(175,400,300,100);
}

UserWindow::~UserWindow()
{

}
