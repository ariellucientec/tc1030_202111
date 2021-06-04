#include"ListInterface.h"
#include"LinkedList.h"
int main()
{
    ListInterface* l = new LinkedList;
    l->add(new Element("a"));
    l->add(new Element("b"));
    l->add(new Element("c"));
    l->add(new Element("d"));
    l->add(new Element("e"));
    l->add(3, new Element("f"));
    l->print();
}