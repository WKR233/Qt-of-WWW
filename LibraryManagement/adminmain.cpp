#include "adminmain.h"
#include "searchbooks.h"
#define PEOPLE_WIDTH 200
AdminWindow::AdminWindow(QWidget *parent):QMainWindow(parent)
{
    this->resize(1000,800);
    Bookadmin = new QPushButton("书籍管理",this);
    Endsystem = new QPushButton("退出系统",this);
    S = new SearchWindow(this);
    Bookadmin->setGeometry(350,250,300,100);
    Endsystem->setGeometry(350,400,300,100);
    connect(Endsystem,SIGNAL(clicked()),this,SLOT(close()));
    connect(Bookadmin,SIGNAL(clicked()),this,SLOT(aopen()));
}

void AdminWindow::aopen()
{
    S->show();
    this->close();
}

AdminWindow::~AdminWindow()
{

}
