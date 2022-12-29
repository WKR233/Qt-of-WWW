#define CHANGEBOOK_H

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMainWindow>
#include <QString>
class ChangeBook : public QMainWindow
{
    Q_OBJECT

private:
    QLabel *numberhint;
    QLabel *namehint;
    QLineEdit *number;
    QLineEdit *name;
    QPushButton *confirm;
    int cof;
    QString tname;
    int inumber;

private slots:
    void getnumber();
    void getname();
    void next();

public:
    ChangeBook(int a,QWidget* parent=0);
    ~ChangeBook();
};
