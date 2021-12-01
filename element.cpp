#include "element.h"
Element::Element()
{
    this->x=-1;
    this->y=-1;
    this->name="";
}

Element::Element(int x, int y,int SIZE)
{
    this->x=x;
    this->y=y;
    this->name=get_name_of(x,y,SIZE);
}

int Element::getX() const
{
    return x;
}

int Element::getY() const
{
    return y;
}

string Element::getName() const
{
    return name;
}
void Element::setName(const string &value)
{
    name = value;
}

string Element::get_name_of(int x, int y,int SIZE)
{
    string name="";
    switch (x) {
    case 0:
        name+="a";
        break;
    case 1:
        name+="b";
        break;
    case 2:
        name+="c";
        break;
    case 3:
        name+="d";
        break;
    case 4:
        name+="e";
        break;
    case 5:
        name+="f";
        break;
    case 6:
        name+="g";
        break;
    case 7:
        name+="h";
        break;

    default:
        name+="N";

        break;
    }
    name+=(char(SIZE-y+'0'));
    return name;
}

