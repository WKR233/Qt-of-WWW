#include "login.h"
#include "adminmain.h"
#include "usermain.h"
#include "wrong.h"
#include <QTextStream>

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
LoginWindow::LoginWindow(AdminWindow* a,UserWindow* u,QWidget *parent):QMainWindow(parent),A(a),U(u)
{
    this->resize(1100,800);
    confirm = new QPushButton("确定",this);
    qregister = new QPushButton("注册",this);
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
    identity->setGeometry(600,220,100,50);
    account->setGeometry(300,300,400,50);
    password->setGeometry(300,400,400,50);
    confirm->setGeometry(600,500,100,50);
    qregister->setGeometry(300,500,100,50);
    connect(account,SIGNAL(textchanged()),this,SLOT(getaccount()));
    connect(password,SIGNAL(textchanged()),this,SLOT(getpassword()));
    connect(identity,SIGNAL(currentTextChanged(const QString &)),this,SLOT(gettype(const QString &)));
    connect(confirm,SIGNAL(clicked()),this,SLOT(next()));
    connect(qregister,SIGNAL(clicked()),this,SLOT());
}
LoginWindow::~LoginWindow()
{
    taccount=QString();
    tpassword=QString();
}
void LoginWindow::next()
{
    if(type=="Admin")
    {
        QString a,b;
        QFile file(admin_file);
        file.open(QIODevice::ReadOnly);
        QTextStream dataStr(&file);
        QString all=dataStr.readAll();
        for(int i=0;i<all.length();i++)
        {
            QString acc;
            for(int j=i;all[j]!=" ";j++)
            {
                acc=acc+all[j];
                i=j;
            }
            QString pas;
            for(int j=i;all[j]!=" ";j++)
            {
                pas=pas+all[j];
                i=j;
            }
            xzzadmin.insert(acc,pas);
        }
        if(xzzadmin.find(taccount)==xzzadmin.end())
        {
            W = new Wrong("账号输入错误");
            W->show();
            W->exec();
        }
        else
        {
            if(xzzadmin[taccount]==tpassword)
            {
                A->show();
                this->close();
            }
            else
            {
                W = new Wrong("密码输入错误");
                W->show();
                W->exec();
            }
        }
    }
    else
    {
        QString a,b;
        QFile file(user_file);
        file.open(QIODevice::ReadOnly);
        QTextStream dataStr(&file);
        while(!dataStr.atEnd())
        {
            dataStr>>a>>b;
            xzzuser.insert(a,b);
        }
        if(xzzuser.find(taccount)==xzzuser.end())
        {
            W = new Wrong("账号输入错误");
            W->show();
            W->exec();
        }
        else
        {
            if(xzzuser[taccount]==tpassword)
            {
                U->show();
                this->close();
            }
            else
            {
                W = new Wrong("密码输入错误");
                W->show();
                W->exec();
            }
        }
    }
}
void LoginWindow::open()
{
    this->show();
}
