#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QComboBox>

class SearchWindow;
class AdminWindow : public QMainWindow
{
    Q_OBJECT
private:
    QPushButton *Bookadmin;
    QPushButton *Endsystem;
    QPushButton *confirm1;
    QComboBox *Manadminchoose;
    SearchWindow* S;
private slots:
    void aopen();
public:
    AdminWindow(QWidget *parent = 0);
    ~AdminWindow();

};
