#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QFile>
#include "tool.h"
#include <QMap>

using namespace std;
class AdminWindow;
class UserWindow;
class Wrong;
class LoginWindow : public QMainWindow
{
    Q_OBJECT

private:
    QString taccount;
    QString tpassword;
    QComboBox *identity;
    QLineEdit *account;
    QLineEdit *password;
    QLabel *l1;
    QMap<QString,QString> xzzadmin;
    QMap<QString,QString> xzzuser;

private slots:
    void getaccount();
    void getpassword();
    void gettype(const QString &s);
    void next();
    void open();

public:
    AdminWindow* A;
    UserWindow* U;
    Wrong* W;
    QPushButton *confirm;
    QPushButton *qregister;
    QString type="Admin";
    bool right=false;
    LoginWindow(AdminWindow* a,UserWindow* u,QWidget *parent = 0);
    ~LoginWindow();

};
