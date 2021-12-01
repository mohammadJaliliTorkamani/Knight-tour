#ifndef ELEMENT_H
#define ELEMENT_H
#include <iostream>
using namespace std;

class Element
{
public:
    //Constructos(s)
    Element();
    Element(int x,int y,int SIZE);

    //Getters
    int getX() const;
    int getY() const;
    string getName() const;
    void setName(const string &value);

private:
    int x,y;
    string name;

    string get_name_of(int x,int y,int SIZE);
};

#endif // ELEMENT_H
