#include "login.h"

void LoginWindow::getaccount()
{
    taccount = account->text();
}
void LoginWindow::getpassword()
{
    tpassword = password->text();
}
void LoginWindow::gettype(const QString &str)
{
    type = str;
}
LoginWindow::LoginWindow(QWidget *parent):QMainWindow(parent)
{
    this->resize(800,600);
    confirm = new QPushButton("确定",this);
    identity = new QComboBox(this);
    account = new QLineEdit(this);
    password = new QLineEdit(this);
    l1 = new QLabel("请选择登入身份：",this);
    identity->addItem("Admin");
    identity->addItem("User");
    account->setPlaceholderText("Please type in your account");
    password->setPlaceholderText("Please type in your password");
    password->setEchoMode(QLineEdit::Password);
    l1->setGeometry(300,200,200,100);
    identity->setGeometry(500,220,100,50);
    account->setGeometry(400,300,400,50);
    password->setGeometry(400,400,400,50);
    confirm->setGeometry(600,500,100,50);
    connect(account,SIGNAL(textchanged),this,SLOT(getaccount));
    connect(password,SIGNAL(textchanged),this,SLOT(getpassword));
    connect(identity,SIGNAL(currenTextChanged),this,SLOT(gettype));
    connect(confirm,SIGNAL(clicked),this,SLOT(next));
}
LoginWindow::~LoginWindow()
{
    taccount=QString();
    tpassword=QString();
}
void LoginWindow::next()
{
    if(type=="Admin"&&taccount=="WKR"&&tpassword=="WWW")
        right=true;
    else
        right=false;
}
