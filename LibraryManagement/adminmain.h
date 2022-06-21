#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QComboBox>
#include "libdata.cpp"
class AdminWindow : public QMainWindow
{
    Q_OBJECT
private:
    QPushButton *Manadmin;
    QPushButton *Bookadmin;
    QPushButton *Endsystem;
    QPushButton *confirm1;
    QComboBox *Manadminchoose;
public:
    AdminWindow(QWidget *parent = 0);
    ~AdminWindow();

};
