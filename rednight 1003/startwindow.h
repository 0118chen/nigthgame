#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"gamewindow.h"
#include <QMainWindow>
extern int num;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //重写paintEvent事件画背景图
    void paintEvent(QPaintEvent *);
   gamewindow * gameScene=NULL;
    rulewindow * rulescene=NULL;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
