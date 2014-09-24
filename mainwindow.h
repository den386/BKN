#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}
class PortControl;
class BKN;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void fillparam();
    struct test1 {
        QString name;
        qint32 baudRat9600;
    };
int t;
private:
    Ui::MainWindow *ui;
    PortControl *m_control;
    BKN *control;
public slots:
     void soed();
private slots:

 void saveport(QString str);
 void savespeed(QString str);
 void savestopbits(QString str);
 void error(QString error1);
 void test(test1 t);

};

#endif // MAINWINDOW_H
