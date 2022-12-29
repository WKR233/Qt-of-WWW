#include "wrong.h"

Wrong::Wrong(QString str,QWidget *parent):QDialog(parent)
{
    this->resize(400,200);
    Qt::WindowFlags flags = this->windowFlags();
    this->setWindowFlags(flags | Qt::CustomizeWindowHint | Qt::WindowStaysOnTopHint);
    confirm = new QPushButton("确定",this);
    message = new QLabel(str,this);
    message->setGeometry(150,50,200,50);
    confirm->setGeometry(150,100,100,50);
    connect(confirm,SIGNAL(clicked()),this,SLOT(close()));
}

Wrong::~Wrong()
{

}
