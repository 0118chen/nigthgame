#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushbutton : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyPushbutton(QWidget *parent = nullptr);
    MyPushbutton(QString normalImg,QString pressImg="");//构造函数
    QString normalImgPath;//成员属性，保存用户传入的成员属性
    QString pressImgPath;//按下后的显示的照片路径
    //弹跳特效
    void zoom1();//向下
    void zoom2();//向上



signals:

public slots:
};

#endif // MYPUSHBUTTON_H
