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

    QPushButton Manadmin("人员管理", &w);
    QPushButton Bookadmin("书籍管理",&w);
    QPushButton Endsystem("退出系统",&w);
    QPushButton confirm1("确定",&w);
    Manadmin.setGeometry(175,100,300,100);
    Bookadmin.setGeometry(175,250,300,100);
    Endsystem.setGeometry(175,400, 300, 100);
    confirm1.setGeometry(625,125,50,50);
    QComboBox Manadminchoose(&w);
    Manadminchoose.addItem("用户名单");
    Manadminchoose.addItem("新增用户");
    Manadminchoose.addItem("删除用户");
    Manadminchoose.setGeometry(500,125,100,50);
    w.show();
    return a.exec();
}
