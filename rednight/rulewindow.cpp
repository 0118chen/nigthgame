#include "rulewindow.h"
#include"mypushbutton.h"
#include"QPainter"
#include"QLabel"
#include"QString"
rulewindow::rulewindow(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(800,250);
    this->setWindowIcon(QIcon(":/res/windowicon.jpg"));
    setWindowTitle("规则：红黑夜法官");
    rule =new QLabel;
    rule->setFixedSize(800,200);
    rule->setParent(this);
    rule->setWordWrap(true);
    QString strText = QStringLiteral("玩家人数为偶数，则红牌身份与黑牌身份各占一半；若为奇数，则红牌身份多1；每个玩家都有自己的身份第一天，从1-n号玩家顺序发言，一轮发言后从1-n号顺序投票选举村长，得票最多的玩家当选村长，若总人数为偶数，村长拥有1.5票，总人数为奇数，村长拥有0.5票。白天：村长决定从村长左边或者右边开始发言的顺序，发言顺序构成为k-1~村长k~k+1的回环，最后从1-n号玩家进行匿名投票，得票最多的人被放逐出游戏，并且显示身份，若村长被放逐则要移交下一任村长。夜晚：随机进入红夜或黑夜，所有玩家可以自由睁眼。红夜时：睁眼的红牌为偶数则第二天村长拥有1票；黑夜时：睁眼的黑牌为偶数则第二天村长拥有1票游戏结束：所有的红牌或者所有的黑牌被放逐。");
    QString strHeightText = "<p style=\"line-height:%1%\">%2<p>";
    strText = strHeightText.arg(200).arg(strText);
    rule->setText(strText);



}
