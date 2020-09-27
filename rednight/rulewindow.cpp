#include "rulewindow.h"
#include"mypushbutton.h"
#include"QPainter"
#include"QLabel"
#include"QString"
rulewindow::rulewindow(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(400,200);
    this->setWindowIcon(QIcon(":/res/windowicon.jpg"));
    setWindowTitle("规则：红黑夜法官");
    rule =new QLabel;
    rule->setParent(this);
    rule->setText("");
    rule->show();
}
