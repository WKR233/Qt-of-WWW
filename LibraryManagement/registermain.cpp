#include "registermain.h"
#include "tool.h"

void RegisterWindow::getaccount()
{
    taccount = account->text();
}
void RegisterWindow::getpassword()
{
    tpassword = password->text();
}
void RegisterWindow::gettype(const QString &str)
{
    type = str;
}
RegisterWindow::RegisterWindow(QWidget *parent):QMainWindow(parent)
{
    this->resize(1100,800);
    qregister = new QPushButton("注册",this);
    identity = new QComboBox(this);
    account = new QLineEdit(this);
    password = new QLineEdit(this);
    l1 = new QLabel("请选择注册身份：",this);
    identity->addItem("Admin");
    identity->addItem("User");
    account->setPlaceholderText("Please type in your account");
    password->setPlaceholderText("Please type in your password");
    password->setEchoMode(QLineEdit::Password);
    l1->setGeometry(300,200,200,100);
    identity->setGeometry(600,220,100,50);
    account->setGeometry(300,300,400,50);
    password->setGeometry(300,400,400,50);
    qregister->setGeometry(600,500,100,50);
    connect(account,SIGNAL(textChanged(const QString &)),this,SLOT(getaccount()));
    connect(password,SIGNAL(textChanged(const QString &)),this,SLOT(getpassword()));
    connect(identity,SIGNAL(currentTextChanged(const QString &)),this,SLOT(gettype(const QString &)));
    connect(qregister,SIGNAL(clicked()),this,SLOT(saveRegister()));
}

void RegisterWindow::saveRegister()
{
    if(this->taccount!=""&&this->tpassword!="")
    {
        if(type=="Admin")
        {
            QFile file(admin_file);
            file.open(QIODevice::WriteOnly|QIODevice::Append);
            QTextStream dataStr(&file);
            dataStr<<taccount<<" "<<tpassword;
            file.close();
            this->close();
        }
        else
        {
            QFile file(user_file);
            file.open(QIODevice::WriteOnly|QIODevice::Append);
            QTextStream dataStr(&file);
            dataStr<<taccount<<" "<<tpassword;
            file.close();
            this->close();
        }
    }
    else
    {
        QMessageBox::warning(this,"提示","请将注册信息填写完整",QMessageBox::Ok);
    }
}

RegisterWindow::~RegisterWindow()
{
    taccount=QString();
    tpassword=QString();
}
void RegisterWindow::open()
{
    this->show();
}
