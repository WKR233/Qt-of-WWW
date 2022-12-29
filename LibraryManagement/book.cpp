#include "book.h"

book::book()
{

}

QString book::getName()//获取名字
{
    return nameOfBook;
}

QString book::getWriter()//获取作者
{
    return writer;
}

void book::setName(const QString &s)//存储名字
{
    nameOfBook=s;
}

void book::setWriter(const QString &s)//存储作者
{
    writer=s;
}

void book::setNum(int k)
{
    numOfBook=k;
}

void book::setRaw()
{
    isBorrowed=0;
}

void book::setBorrowed()
{
    isBorrowed=1;
}

qint32 book::getNum()
{
    return numOfBook;
}

qint32 book::getBorrowed()
{
    return isBorrowed;
}
