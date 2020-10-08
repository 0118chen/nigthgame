#include "person.h"
person::person(bool statue,int number,bool head )
{
    setstatue(statue);
    setnumber(number);
    sethead(head);
    //setword(word);
}
person::person()
{

}

QString person::getword()const//返回说的话
{
    return word;
}
void person::sethead(bool head)
{
    this->head=head;
}
bool person::gethead()const
{
    return head;
}
int person::getid()const
{
    return id;
}
int person::getnumber()
{
    return number;
}
int person::getstatue()const
{
    return statue;
}
void person::setid(const int id)
{
    this->id=id;
}
void person::setnumber(const int number)
{
    this->number=number;
}
void person::setstatue(const int statue)
{
    this->statue=statue;
}
void person::setword(QString word)
{
    this->word=word;
}


