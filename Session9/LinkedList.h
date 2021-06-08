#include"ListInterface.h"
#include"Element.h"
#include<iostream>
using namespace std;

#pragma once
class LinkedList : public ListInterface
{
    Element* firstElement;
public:
    LinkedList():firstElement(0){}
    void add(Element*);
    void add(int position, Element*);
    Element* get(int index);
    void remove(int index);
    void remove(Element*);
    int size();
    void print();
    ~LinkedList()
    {
        Element* temp = firstElement;
        
        while(temp->getNext() != 0)
        {
            Element* prev = temp;
            temp = temp->getNext();
            delete prev;
        }     
        delete temp;   
    }
};

void LinkedList::print()
{
    Element* temp = firstElement;
    while(temp != 0)
    {
        temp->print();
        temp = temp->getNext();
    }
}

void LinkedList::add(Element* element)
{
    if (firstElement == 0)
    {
        firstElement = element;
        firstElement->setNext(0);
    }
    else
    {
        Element* temp = firstElement;
        while(temp->getNext() != 0)
        {
            temp = temp->getNext();
        }
        element->setNext(0);
        temp->setNext(element);
    }
}
void LinkedList::add(int position, Element* element)
{
    if (firstElement == 0)
    {
        firstElement = element;
        firstElement->setNext(0);
    }
    else
    {
        Element* temp = firstElement;
        int pos = 1;
        while(pos != position-1 && temp->getNext()!= 0)
        {
            pos++;
            temp = temp->getNext();
        }
        element->setNext(temp->getNext());
        temp->setNext(element);
    }
}
Element* LinkedList::get(int index)
{
    int cont = 1;
    Element* temp = firstElement;
    while(cont <= index)
    {
        temp = temp->getNext();
        cont+=1;
    }
    return temp;
}
void LinkedList::remove(int index)
{

}
void LinkedList::remove(Element*)
{

}
int LinkedList::size()
{
    int i=1;
    Element* temp = firstElement;
    while(temp->getNext() != 0)
    {
        temp = temp->getNext();
        i+=1;
    }
    return i;
}
