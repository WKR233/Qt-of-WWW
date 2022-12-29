#include "adminmain.h"
#include "login.h"
#include "usermain.h"
#include "registermain.h"
#include "wrong.h"
#include "searchbooks.h"
#include "changebook.h"
#include <QApplication>
#include <QMap>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AdminWindow* A=new AdminWindow();
    UserWindow* U=new UserWindow();
    //SearchWindow* S=new SearchWindow(A);
    LoginWindow* L=new LoginWindow(A,U);
    RegisterWindow* R=new RegisterWindow();
    QObject::connect(L->qregister,SIGNAL(clicked()),L,SLOT(close()));//关闭L窗口
    QObject::connect(L->qregister,SIGNAL(clicked()),R,SLOT(open()));//打开R窗口
    QObject::connect(R->qregister,SIGNAL(clicked()),L,SLOT(open()));//打开L窗口
    QObject::connect(R->qregister,SIGNAL(clicked()),R,SLOT(close()));//关闭R窗口
    L->show();
    return a.exec();
}
