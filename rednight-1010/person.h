#ifndef PERSON_H
#define PERSON_H
#include<QString>


class person
{
protected:

public:
    person();
    int statue=1;//活着为1淘汰为0
    QString word;//上一次的发言内容
    int number;//编号
    int id;//红牌为1黑牌为0
    float piao=0.0;//票数
    bool head=0;//判断是否为村长，是为1；否为0
    void sethead(bool);
    bool gethead()const;
    void setstatue(const int);
   int getstatue()const;
    void setnumber(const int);
    int getnumber();
    void setid(const int);
    int getid()const;
    QString getword()const;
   void setword(QString);
     person(bool statue,int number,bool head);//构造函数
};

#endif // PERSON_H
