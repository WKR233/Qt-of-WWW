#include "adminmain.h"
#include "login.h"
#include "usermain.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWindow L;
    L.show();
    /*while(!L.right)
    {
        //输入错误，相关提示
    }*/
    AdminWindow A;
    UserWindow U;
    if(L.type=="admin")
    {
        A.show();
        L.close();
    }
    if(L.type=="user")
    {
        U.show();
        L.close();
    }
    return a.exec();
}
