#include "gamewindow.h"
#include<QMenuBar>
#include<QPainter>
#include"mypushbutton.h"
#include"rulewindow.h"
gamewindow::gamewindow(QWidget *parent) : QMainWindow(parent)
{
    //配置游戏页面场景
    this->setFixedSize(1000,600);
    //设置图标
    this->setWindowIcon(QIcon(":/res/windowicon.jpg"));
    setWindowTitle("游戏页面：红黑夜法官");
    //开始创建菜单栏
    QMenuBar *bar = menuBar();
    setMenuBar(bar);

    //创建开始菜单
    QMenu * startMenu=bar->addMenu("开始");

    //创建暂停、退出菜单项
    QAction * stopAction = startMenu->addAction("暂停");



    QAction * quitAction = startMenu->addAction("退出");
    connect(quitAction,&QAction::triggered,[=](){
        this->close();
    });
    //创建规则菜单
    QMenu * ruleMenu=bar->addMenu("信息");
    QAction *ruleAction = ruleMenu->addAction("规则");
    ruleScene = new rulewindow;
    connect(ruleAction,&QAction::triggered,[=](){

        ruleScene->show();
    });




    //返回按钮
    MyPushbutton * backbtn= new MyPushbutton(":/res/back.jpg", ":/res/back.jpg");
    backbtn->setParent(this);
    backbtn->move(this->width()-backbtn->width(),this->height()-backbtn->height());






}
void gamewindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/mainscense.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

}










