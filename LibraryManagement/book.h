#ifndef BOOK_H
#define BOOK_H

#include <QString>

class book
{
public:
    book();

    QString getName();
    void setName(const QString &s);

    QString getWriter();
    void setWriter(const QString &s);

    void setNum(int);
    int getNum();

    void setBorrowed();
    void setRaw();
    qint32 getBorrowed();

private:
    QString nameOfBook;//书名
    QString writer;    //作者
    qint32 numOfBook;     //书的总数
    qint32 isBorrowed;   //状态
};

#endif // BOOK_H
