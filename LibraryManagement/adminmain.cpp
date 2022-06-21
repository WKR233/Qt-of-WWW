#include "adminmain.h"

AdminWindow::AdminWindow(QWidget *parent):QMainWindow(parent)
{
    this->resize(800,600);
    Manadmin = new QPushButton("人员管理",this);
    Bookadmin = new QPushButton("书籍管理",this);
    Endsystem = new QPushButton("退出系统",this);
    confirm1 = new QPushButton("确定",this);
    Manadminchoose = new QComboBox(this);
    Manadmin->setGeometry(175,100,300,100);
    Bookadmin->setGeometry(175,250,300,100);
    Endsystem->setGeometry(175,400,300,100);
    confirm1->setGeometry(625,125,50,50);
    Manadminchoose->setGeometry(500,125,100,50);
    Manadminchoose->addItem("用户名单");
    Manadminchoose->addItem("新增用户");
    Manadminchoose->addItem("删除用户");
}

AdminWindow::~AdminWindow()
{

}
