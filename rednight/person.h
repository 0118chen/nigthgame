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
    void setstatue(const int);
   int getstatue()const;
    void setnumber(const int);
    int getnumber()const;
    void setid(const int);
    int getid()const;
    QString getword()const;
   void setword(QString);
};

#endif // PERSON_H
