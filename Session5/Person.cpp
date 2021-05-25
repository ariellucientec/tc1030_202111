#include"Person.h"
Person::Person(){}

Person::Person(string name) : name(name){}

string Person::getName()
{
    return name;
}

void Person::print()
{
    cout << "I´m a person" << endl;
}