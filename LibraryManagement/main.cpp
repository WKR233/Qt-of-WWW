#include "mainwindow.h"

#include <QApplication>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QPushButton confirm("确定",&w);
    QComboBox identity(&w);
    QLineEdit account(&w),password(&w);
    QLabel l1("请选择登入身份：",&w);
    identity.addItem("Admin");
    identity.addItem("User");
    account.setPlaceholderText("Please type in your account");
    password.setPlaceholderText("Please type in your password");
    password.setEchoMode(QLineEdit::Password);
    l1.setGeometry(300,200,200,100);
    identity.setGeometry(500,220,100,50);
    account.setGeometry(400,300,400,50);
    password.setGeometry(400,400,400,50);
    confirm.setGeometry(600,500,100,50);
    w.show();
    return a.exec();
}
