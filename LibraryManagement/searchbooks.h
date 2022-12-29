#define SEARCHBOOKS_H
#include <QMainWindow>
#include <QLabel>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QPushButton>
#include <QLineEdit>
#include <QDebug>
#include <QStringList>
#include <QList>
#include <QString>
#include "editbook.h"
class AdminWindow;
class UserWindow;
class Wrong;

class SearchWindow:public QMainWindow
{
    Q_OBJECT
public:
    QString tempbookname;
    QTableWidget *Bookrecord;
    QPushButton *Searchthebook;
    QPushButton *Editbook;
    QLineEdit *cinthename;
    QPushButton *returntowindow;
    AdminWindow* A;
    UserWindow* U;
    Wrong* W;
    SearchWindow(AdminWindow* a, QWidget *parent = nullptr);
    SearchWindow(UserWindow* u, QWidget *parent = nullptr);
    ~SearchWindow(){};
private:
    EditBook * messbox;
public slots:
    void Searchsomebook();
    void getbookname();
    void returnbefore1();
    void returnbefore2();
    void addBook();
};
