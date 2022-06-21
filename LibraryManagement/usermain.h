#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "libdata.cpp"
class UserWindow : public QMainWindow
{
    Q_OBJECT

public:
    UserWindow(QWidget *parent = 0);
    ~UserWindow();

};
