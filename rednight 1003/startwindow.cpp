#include "startwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include"mypushbutton.h"
#include<QTimer>
#include<QInputDialog>
#include<QDebug>
#include<QTableWidget>
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
    rulescene = new rulewindow;//实例化规则场景
    connect(ui->actionxxsadsadada,&QAction::triggered,[=](){
        rulescene->show();
    });

    //监听选择关卡的返回按钮信号
    connect(gameScene,&gamewindow::gameBack,this,[=](){
       gameScene->hide();//将游戏页面隐藏
       this->show();//重新显示开始页面
    });

    connect(startBtn,&MyPushbutton::clicked,[=](){
        startBtn->zoom1();
        startBtn->zoom2();
        //延时进入到游戏页面中
        QTimer::singleShot(350,this,[=](){
            this->hide();//自身隐藏
            bool ok;
                int num  = QInputDialog::getInt(this, tr("游戏人数"),
                                                 tr("人数："), 5, 1, 12, 1, &ok);

            gameScene->show();//显示游戏页面  
            QTableWidget *table = new QTableWidget(4,2);  //新建一4行2列的表格


                    //设置表格行标题
                    QStringList headerLabels;
                    headerLabels << "C1" << "C2";
                    table->setHorizontalHeaderLabels(headerLabels);


                    //设置表格行标题的对齐方式
                    table->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);

                    //设置行表题
                    QStringList rowLabels;
                    rowLabels << "Line1" << "Line2" << "Line3" << "Line4";
                    table->setVerticalHeaderLabels(rowLabels);


                    //设置每一行的高度
                    for(int i = 0; i < 4; i++)
                        table->setRowHeight(i, 22);

                    //自动调整最后一列的宽度使它和表格的右边界对齐
                    table->horizontalHeader()->setStretchLastSection(true);

                    //设置表格的选择方式
                    table->setSelectionBehavior(QAbstractItemView::SelectItems);

                    //设置编辑方式
                    table->setEditTriggers(QAbstractItemView::DoubleClicked);

                    //设置表格的内容
                    for (int row = 0; row < 4; ++row)
                    {
                        QTableWidgetItem *item0, *item1;
                        item0 = new QTableWidgetItem;
                        item1 = new QTableWidgetItem;

                        QString txt = QString("%1").arg(row + 1);
                        item0->setText(txt);
                        table->setItem(row, 0, item0);

                        txt = QString("%1").arg((row + 1) * 2);
                        item1->setText(txt);
                        table->setItem(row, 1, item1);

                    }

                    //增加一行
                    table->setRowCount(5);
                    QTableWidgetItem *vHeader5 = new QTableWidgetItem("Line5");
                    table->setVerticalHeaderItem(4, vHeader5);

                    QTableWidgetItem *item5_0, *item5_1;
                    item5_0 = new QTableWidgetItem;
                    item5_1 = new QTableWidgetItem;
                    item5_0->setText(QString("%1").arg(5));
                    item5_1->setText(QString("%1").arg(5 * 2));
                    table->setItem(4, 0, item5_0);
                    table->setItem(4, 1, item5_1);
                    table->show();


            });

        } );





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


