#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include "libdata.cpp"
using namespace std;

class LoginWindow : public QMainWindow
{
    Q_OBJECT

private:
    QString taccount;
    QString tpassword;
    QPushButton *confirm;
    QComboBox *identity;
    QLineEdit *account;
    QLineEdit *password;
    QLabel *l1;


private slots:
    void getaccount();
    void getpassword();
    void gettype(const QString &s);
    void next();

public:
    QString type;
    bool right=false;
    LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

};
