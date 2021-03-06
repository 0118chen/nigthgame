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
#include"person.h"
#include<QDebug>
#include<QInputDialog>

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

        //实时计数器
        int sum=num;
    //动态创建对象数组
        person *ps=new person[num];

    //不重复随机数分配身份
        int arr[num]={0};
        int ra[num]={0};
        int t=0,i=0,k=0;
        srand((int)time(0));
        while(t<num)
        {
            i=rand()%(num+1)+1;
            if(arr[i-1]==0)
            {
                arr[i-1]=1;
                ra[k]=i;
                //qDebug()<<ra[k];
                ps[k].setnumber(ra[k]);
                t++;
                k++;
            }
        }
        for(int i=0;i<num;i++)
            ps[i].setnumber(i+1);


        //分配
        int rednum,blacknum;
        if(num%2==0)
        {
            rednum=num/2;
            blacknum=num/2;
        }
        else
        {
            rednum=(num+1)/2;
            blacknum=(num-1)/2;
        }








       //第一天发言选出村长

        MyPushbutton *gobtn= new MyPushbutton(":res/go.jpg",":res/go.jpg");
        gobtn->setParent(this);
        gobtn->move(this->width()*0.5-gobtn->width()*0.5,this->height()*0.8);
        int gonum=0;
        connect(gobtn,&MyPushbutton::clicked,[=](){
            headvoteEvent(num,ps);
        });



        //进入白天和黑夜的循环直到游戏结束
        //while(rednum!=0||blacknum!=0)


        //白天按钮的建立
        MyPushbutton * daybtn=new MyPushbutton(":/res/sun.jpg",":/res/sun.jpg");
        daybtn->setParent(this);
        daybtn->move(this->width()*0.5-daybtn->width()*0.5+100,this->height()*0.8);

        //黑夜按钮的建立
        MyPushbutton * nightbtn=new MyPushbutton(":/res/night.jpg",":/res/night.jpg");
        nightbtn->setParent(this);
        nightbtn->move(this->width()*0.5-nightbtn->width()*0.5+200,this->height()*0.8);




        //信息按钮的建立;
        MyPushbutton * messbtn = new MyPushbutton(":/res/tim.jpg",":/res/tim.jpg");
        messbtn->setParent(this);
        messbtn->move(this->width()-messbtn->width(),30);
        connect(messbtn,&MyPushbutton::clicked,[=](){
             nullscene =new messagewindow;
             //nullscene->resize(750,400);

            QTableWidget *table = new QTableWidget(num,5);  //新建一4行2列的表格
            table->setParent(nullscene);
            table->resize(750,300);

                    //设置表格行标题
                    QStringList headerLabels;

                    headerLabels << "存活状态" << "身份"<<"牌色"<<"是否为村长"<<"发言内容";
                    table->setHorizontalHeaderLabels(headerLabels);


                    //设置表格行标题的对齐方式
                    table->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);

                    //设置行表题
                    QStringList rowLabels;
                    table->setVerticalHeaderLabels(rowLabels);
                    //设置每一行的高度
                    for(int i = 0; i < num; i++)
                        table->setRowHeight(i, 60);

                    //自动调整最后一列的宽度使它和表格的右边界对齐

                    table->horizontalHeader()->setStretchLastSection(true);



                    //设置表格的选择方式
                    table->setSelectionBehavior(QAbstractItemView::SelectItems);

                    //设置编辑方式
                    table->setEditTriggers(QAbstractItemView::NoEditTriggers);

                    //设置表格的内容
                    for (int row = 0; row < num; ++row)
                    {
                        QTableWidgetItem *item0, *item1,*item2,*item3,*item4;
                        item0 = new QTableWidgetItem;
                        item1 = new QTableWidgetItem;
                        item2 = new QTableWidgetItem;
                        item3 = new QTableWidgetItem;
                        item4 = new QTableWidgetItem;

                        QString txt = QString("%1").arg(ps[row].getstatue());
                        item0->setText(txt);
                        table->setItem(row, 0, item0);

                        txt = QString("%1").arg(ps[row].getnumber());
                        item1->setText(txt);
                        table->setItem(row, 1, item1);

                        txt = QString("%1").arg(ps[row].getnumber()%2);
                        item2->setText(txt);
                        table->setItem(row, 2, item2);

                        txt = QString("%1").arg(ps[row].gethead());
                        item3->setText(txt);
                        table->setItem(row, 3, item3);

                        txt = QString("%1").arg(ps[row].getword());
                        item4->setText(txt);
                        table->setItem(row, 4, item4);



                    }//初始化状态表
                    nullscene->show();
                    table->show();
        });





}
void gamewindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/mainscense.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

}
//竞选发言投票函数
void gamewindow::headvoteEvent(int num,person ps[])
{
    int piao[num]={0};
    //开始发言
  for(int i=0;i<num;i++)
  {
    if(ps[i].getstatue()==1)
    {
            bool ok;
            QString text = QInputDialog::getText(NULL,"竞选村长","请"+QString::number(i+1)+"号发言",QLineEdit::Normal,"",&ok);
            ps[i].setword(text);
    }
  }



  //开始投票
  for(int i=0;i<num;i++)
  {
      if(ps[i].getstatue()==1)
      {
                  bool hi;
                  int select;
                  while(select  = QInputDialog::getInt(NULL,"投票页面","请"+QString::number(i+1)+"号投票",1,1,num,1,&hi))
                  {   if(ps[select-1].statue==0)
                      QMessageBox::critical(this,"critical",QString::number(select)+"已被驱逐");
                      else
                          break;
                  }
                  piao[select]++;


      }
  }
  int headpoint=0;
  for(int i=1;i<num;i++)
  {
      if(piao[headpoint]<piao[i])
          headpoint=i;
  }
  ps[headpoint-1].sethead(1);
  for(int i=0;i<num;i++)
  {
      if(ps[i].statue==1)
      {
          if(ps[i].head==1)
          { if(num%2==1)
              ps[i].piao=0.5;
            else
              ps[i].piao=1.5;
          }
       else
         ps[i].piao=1;

      }
  }
}



//白天函数











