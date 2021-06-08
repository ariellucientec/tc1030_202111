#include<string>
using namespace std;

#pragma once
class Element
{
protected:
    Element* next;
    string s;
public:
    Element(){}
    Element(string s):s(s){}
    void setNext(Element*);
    Element* getNext();
    string getS(){ return s;}
    virtual void print(){};
    virtual ~Element(){}
};

void Element::setNext(Element* element)
{
    next = element;
}
Element* Element::getNext()
{
    return next;
}
