#ifndef EDITBOOK_H
#define EDITBOOK_H

#include "tool.h"
#include <QWidget>
#include <QLineEdit>
#include <QFormLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "book.h"
#include <QFile>
#include <QDataStream>
#include <QMessageBox>
#include <stdlib.h>
#include <QString>

class EditBook : public QDialog
{
    Q_OBJECT
public:
    //构建添加书籍信息界面
    EditBook();
signals:
    //自定义信号，当添加书籍信息完成后，更新主界面上的表格
    void closeBox();
public slots:
    //将新书的信息写入到文件中
    void saveBookMess();
public:
    //发出 closeBox 信号
    void emitCloseBox();
private:
    QLineEdit * nameofbook;
    QLineEdit * writer;
    QLineEdit * numofbook;
    QPushButton * submit;
    QPushButton * cancel;
};

#endif // EDITBOOK_H
