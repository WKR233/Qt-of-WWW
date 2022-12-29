#include "editbook.h"
#include <cmath>
#include <QString>
#include <cstdlib>

EditBook::EditBook()
{
    /*
     * QVBoxLayout 局部工具中放置 QFormLayout 和 QHBoxLayout
     * QFormLayout 中放置多个单行输入框
     * QHBoxLayout 中放置两个按钮
    */
    setWindowIcon(QIcon(":/logo.ico"));
   // setWindowFlags(Qt::Dialog);
    setWindowTitle("添加书籍信息");
    QVBoxLayout * VBox = new QVBoxLayout;

    QFormLayout *FormLayout = new QFormLayout;
    nameofbook = new QLineEdit;
    writer = new QLineEdit;
    numofbook = new QLineEdit;

    FormLayout->addRow("书名：",nameofbook);
    FormLayout->addRow("作者：",writer);
    FormLayout->addRow("数量：",numofbook);
    FormLayout->setRowWrapPolicy(QFormLayout::WrapLongRows);

    QHBoxLayout * HBox = new QHBoxLayout;
    submit = new QPushButton("提交");
    cancel = new QPushButton("取消");
    HBox->addWidget(submit);
    HBox->addWidget(cancel);

    VBox->addLayout(FormLayout,4);
    VBox->addLayout(HBox,1);
    this->setLayout(VBox);
    //点击提交按钮时，将新书信息保存到文件中
    QObject::connect(submit,&QPushButton::clicked,this,&EditBook::saveBookMess);
    //点击取消按钮时，关闭添加信息窗口
    QObject::connect(cancel,&QPushButton::clicked,this,&EditBook::close);
}

//当用户添加提交按钮时，保存学生信息
void EditBook::saveBookMess()
{
    //确保所有信息填写后，将信息写入到文件中，否则提示用户将信息填写完整
    if(this->nameofbook->text()!="" && this->writer->text()!="" && this->numofbook->text()!="")
    {
        book bo;
        bo.setName(this->nameofbook->text());
        bo.setWriter(this->writer->text());
        bo.setNum(this->numofbook->text().toInt());

        QFile file(file_name);
        file.open(QIODevice::WriteOnly|QIODevice::Append);
        QDataStream dataStr(&file);
        dataStr << bo.getName() << bo.getWriter() << bo.getNum() << bo.getBorrowed();
        file.close();
        this->close();
        emitCloseBox();
    }
    else
    {
        QMessageBox::warning(this,"提示","请将信息填写完整",QMessageBox::Ok);
    }

}

void EditBook::emitCloseBox()
{
    emit closeBox();
}
