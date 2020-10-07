#include "person.h"

person::person()
{

}
QString person::getword()const//返回说的话
{
    return word;
}
int person::getid()const
{
    return id;
}
int person::getnumber()const
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


