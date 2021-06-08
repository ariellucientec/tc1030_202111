#include"Element.h"

#pragma once
class ListInterface
{
public:
    virtual void add(Element*) = 0;
    virtual void add(int position, Element*) = 0;
    virtual Element* get(int index) = 0;
    virtual void remove(int index) = 0;
    virtual int size() = 0;
    virtual void print() = 0;
    virtual ~ListInterface(){}
};