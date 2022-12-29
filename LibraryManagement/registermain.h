#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include "tool.h"
using namespace std;

class RegisterWindow : public QMainWindow
{
    Q_OBJECT

private:
    QString taccount;
    QString tpassword;
    QComboBox *identity;
    QLineEdit *account;
    QLineEdit *password;
    QLabel *l1;

private slots:
    void getaccount();
    void getpassword();
    void gettype(const QString &s);
    void open();
    void saveRegister();

public:
    QPushButton *qregister;
    QString type="Admin";
    bool right=false;
    RegisterWindow(QWidget *parent = 0);
    ~RegisterWindow();
};
