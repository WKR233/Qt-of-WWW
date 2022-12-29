#define MAINWINDOW_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QString>
class Wrong : public QDialog
{
    Q_OBJECT

private:
    QPushButton* confirm;
    QLabel* message;

public:
    Wrong(QString str,QWidget *parent = 0);
    ~Wrong();
};
