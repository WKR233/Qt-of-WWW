#include "searchbooks.h"
#include "editbook.h"
#include "adminmain.h"
#include "usermain.h"
#include "wrong.h"
#include <QMainWindow>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QSettings>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QStringList>
#include <QHeaderView>
#include <QDebug>
#include <QTextStream>
#include <QFile>
#include <QMessageBox>
using namespace std;

void SearchWindow::getbookname()
{
    tempbookname = cinthename->text();
}
SearchWindow::SearchWindow(UserWindow* u, QWidget *parent):QMainWindow(parent),U(u)
{
    this->resize(800,800);
    Bookrecord = new QTableWidget(8, 4, this);
    cinthename = new QLineEdit(this);
    Searchthebook = new QPushButton("搜索", this);

    returntowindow = new QPushButton("返回", this);
    cinthename->setPlaceholderText("请输入您想搜索的书籍名称");
    cinthename->setGeometry(100, 100, 475, 50);
    Searchthebook->setGeometry(600, 100, 100, 50);

    returntowindow->setGeometry(600,725, 100, 50);
    Bookrecord->setGeometry(100, 200, 600, 500);
    connect(Searchthebook, SIGNAL(clicked()), this, SLOT(Searchsomebook()));
    connect(returntowindow, SIGNAL(clicked()), this, SLOT(returnbefore1()));
    Bookrecord->setRowCount(8);
    Bookrecord->setColumnCount(4);
    Bookrecord->verticalHeader()->setDefaultSectionSize(25);
    Bookrecord->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    Bookrecord->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QStringList header;
    header<<"书籍名称"<<"作者"<<"书籍数目"<<"书籍状态";
    Bookrecord->setHorizontalHeaderLabels(header);
}
SearchWindow::SearchWindow(AdminWindow* a, QWidget *parent): QMainWindow(parent),A(a)
{
    this->resize(800,800);
    Bookrecord = new QTableWidget(8, 4, this);
    cinthename = new QLineEdit(this);
    Searchthebook = new QPushButton("搜索", this);
    Editbook = new QPushButton("添加",this);
    returntowindow = new QPushButton("返回", this);
    cinthename->setGeometry(100, 100, 375, 50);
    cinthename->setPlaceholderText("请输入您想搜索的书籍名称");
    Searchthebook->setGeometry(500, 100, 100, 50);
    Editbook->setGeometry(600, 100, 100, 50);
    returntowindow->setGeometry(600,725, 100, 50);
    Bookrecord->setGeometry(100, 200, 600, 500);
    connect(Searchthebook, SIGNAL(clicked()), this, SLOT(Searchsomebook()));
    connect(Editbook, SIGNAL(clicked()), this, SLOT(addBook()));
    connect(returntowindow, SIGNAL(clicked()), this, SLOT(returnbefore2()));
    Bookrecord->setRowCount(8);
    Bookrecord->setColumnCount(4);
    Bookrecord->verticalHeader()->setDefaultSectionSize(25);
    Bookrecord->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    Bookrecord->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QStringList header;
    header<<"书籍名称"<<"作者"<<"书籍数目"<<"书籍状态";
    Bookrecord->setHorizontalHeaderLabels(header);
}
void SearchWindow::returnbefore1()
{
    U->show();
    this->close();
}
void SearchWindow::returnbefore2()
{
    A->show();
    this->close();
}
void SearchWindow::Searchsomebook()
{
    this->getbookname();
    if(tempbookname == "")
    {
        QMessageBox::information(this,"提示","您还未输入您要查找的书名，请重新输入");
        return;
    }
    QFile record(file_name);
    record.open(QIODevice::ReadOnly);
    QTextStream dataStr(&record);
    QString bookname, writer;
    qint32 booknumber, circumstance;
    qint32 rowcount=1;
    qint32 condition=0;
    while(!dataStr.atEnd())
    {
        dataStr>>bookname>>writer>>booknumber>>circumstance;
        QMessageBox::information(this,"提示",bookname);
        if(bookname == tempbookname)
        {
            Bookrecord->setItem(rowcount,1,new QTableWidgetItem(bookname));
            Bookrecord->setItem(rowcount,2,new QTableWidgetItem(writer));
            Bookrecord->setItem(rowcount,3,new QTableWidgetItem(booknumber));
            QString have = "在馆藏",nothave = "已借出";
            if(circumstance==1)
            {
                Bookrecord->setItem(rowcount,4,new QTableWidgetItem(have));
            }
            else if(circumstance==0)
            {
                Bookrecord->setItem(rowcount,4,new QTableWidgetItem(nothave));
            }
            condition=1;
        }
        rowcount++;
    }
    record.close();
    if(condition == 0)
    {
        QMessageBox::information(this,"提示","抱歉，未找到此书");
    }
}
void SearchWindow::addBook()
{
    messbox=new EditBook;
    messbox->exec();
}
