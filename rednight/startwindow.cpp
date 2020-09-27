#include "startwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include"mypushbutton.h"
#include<QTimer>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(1000,600);//设置主窗口页面
    setWindowIcon(QIcon(":/res/windowicon.jpg"));
    setWindowTitle("红黑夜法官");
    connect(ui->actionss_2,&QAction::triggered,[=](){this->close();});
    //开始按钮
    MyPushbutton *startBtn = new MyPushbutton(":/res/startbutton.jpg");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5-startBtn->width()*0.5,this->height()*0.8);
    //实例化游戏页面
    gameScene = new gamewindow;//实例化游戏场景


    connect(startBtn,&MyPushbutton::clicked,[=](){
        startBtn->zoom1();
        startBtn->zoom2();
        //延时进入到游戏页面中
        QTimer::singleShot(450,this,[=](){
            this->hide();
            gameScene->show();//显示游戏页面
        } );
        //隐藏当前页面

    });







}
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);//创建画家，指定绘画设备
    QPixmap pix;//创建QPixmap对象
    pix.load(":/res/startscense.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //画背景图标
    pix.load(":/res/starticon.jpg");
    pix=pix.scaled(pix.width()*0.2,pix.height()*0.2);
    painter.drawPixmap(0,27,pix);

}
MainWindow::~MainWindow()
{
    delete ui;
}
