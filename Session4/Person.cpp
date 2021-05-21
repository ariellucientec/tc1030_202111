
#include"Person.h"

string Person::getName()
{
    return name;
}

Person::Person(){      }

Person::Person(string name) : name(name){     }