#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

class SearchWindow;
class ChangeBook;
class UserWindow : public QMainWindow
{
    Q_OBJECT
private:
    QPushButton *BookSearch;
    QPushButton *BookBorrow;
    QPushButton *BookReturn;
    QPushButton *Endsystem;
    ChangeBook *C1,*C2;
    SearchWindow *S;
private slots:
    void uopen();
    void copen1();
    void copen2();
public:
    UserWindow(QWidget *parent = 0);
    ~UserWindow();

};
