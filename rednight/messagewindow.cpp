#include "messagewindow.h"
#include"mypushbutton.h"
#include"QPainter"
#include"QLabel"
#include"QString"
messagewindow::messagewindow(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(600,250);
    this->setWindowIcon(QIcon(":/res/windowicon.jpg"));
    setWindowTitle("信息：红黑夜法官");
    message =new QLabel;
    message->setFixedSize(600,200);
    message->setParent(this);
    //message->setWordWrap(true);
    QString strText = "存活状态：存活为1;驱逐为0。身份:红牌为1;黑牌为0。村长:是为1;否为0。";
    QString strHeightText = "<p style=\"line-height:%1%\">%2<p>";
    strText = strHeightText.arg(200).arg(strText);
    message->setText(strText);
}
