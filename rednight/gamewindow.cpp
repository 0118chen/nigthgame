#include "gamewindow.h"
#include<QMenuBar>
#include<QPainter>
#include"mypushbutton.h"
#include"rulewindow.h"
#include<QDialog>
#include<QMessageBox>
#include<QInputDialog>
#include<QHeaderView>
#include"startwindow.h"
#include<QTableWidget>
#include"messagewindow.h"
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
    //QAction * stopAction = startMenu->addAction("暂停");

    //创建分隔符
    //startMenu->addSeparator();

    QAction * quitAction = startMenu->addAction("退出");
    connect(quitAction,&QAction::triggered,[=](){
        this->close();
    });




    //创建规则菜单
    QMenu * ruleMenu=bar->addMenu("内容");
    QAction *ruleAction = ruleMenu->addAction("规则");
    QAction *messageAction=ruleMenu->addAction("信息");
    ruleScene = new rulewindow;
    messageScene = new messagewindow;
    connect(messageAction,&QAction::triggered,[=](){
        messageScene->show();
    });
    connect(ruleAction,&QAction::triggered,[=](){

        ruleScene->show();
    });



    //返回按钮
    MyPushbutton * backbtn= new MyPushbutton(":/res/back.jpg", ":/res/back.jpg");
    backbtn->setParent(this);
    backbtn->move(this->width()-backbtn->width(),this->height()-backbtn->height());

    //点击返回
    connect(backbtn,&MyPushbutton::clicked,[=](){
       emit this->gameBack();
    });

    //开始设置游戏人数
    bool ok;
        int num  = QInputDialog::getInt(this, tr("游戏人数"),
                                         tr("人数："), 5, 1, 12, 1, &ok);

        MyPushbutton * messbtn = new MyPushbutton(":/res/tim.jpg",":/res/tim.jpg");
        messbtn->setParent(this);
        messbtn->move(this->width()-messbtn->width(),30);
        connect(messbtn,&MyPushbutton::clicked,[=](){
             nullscene =new messagewindow;


            QTableWidget *table = new QTableWidget(num,5);  //新建一4行2列的表格
            table->setParent(nullscene);
            table->resize(600,250);

                    //设置表格行标题
                    QStringList headerLabels;

                    headerLabels << "存活状态" << "身份"<<"是否为村长"<<"发言位置"<<"发言内容";
                    table->setHorizontalHeaderLabels(headerLabels);


                    //设置表格行标题的对齐方式
                    table->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);

                    //设置行表题
                    QStringList rowLabels;
                   // rowLabels << "Line1" << "Line2" << "Line3" << "Line4";




                    table->setVerticalHeaderLabels(rowLabels);




                    //设置每一行的高度
                    for(int i = 0; i < num; i++)
                        table->setRowHeight(i, 35);

                    //自动调整最后一列的宽度使它和表格的右边界对齐
                    table->horizontalHeader()->setStretchLastSection(true);

                    //设置表格的选择方式
                    table->setSelectionBehavior(QAbstractItemView::SelectItems);

                    //设置编辑方式
                    table->setEditTriggers(QAbstractItemView::DoubleClicked);

                    //设置表格的内容
                    for (int row = 0; row < num; ++row)
                    {
                        QTableWidgetItem *item0, *item1;
                        item0 = new QTableWidgetItem;
                        item1 = new QTableWidgetItem;

                        QString txt = QString("%1").arg(row);
                        item0->setText(txt);
                        table->setItem(row, 0, item0);

                        txt = QString("%1").arg((row + 1) * 2);
                        item1->setText(txt);
                        table->setItem(row, 1, item1);

                    }//初始化状态表
                    nullscene->show();
                    table->show();
        });




          int rednum,blacknum;
          if(num%2==0)
          {
              rednum=num/2;
              blacknum=num/2;
          }
          else
          {
              rednum=num/2+1;
              blacknum=num/2;
          }



















}
void gamewindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/mainscense.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

}










