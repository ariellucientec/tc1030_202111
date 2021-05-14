#include<iostream>
#include<string>
using namespace std;

class Person
{
protected:
    string name;
    int age;
    Person* parent;
public:
    //Person(){}            //default contructor
    Person() = default;     
    Person(string, int);    //params constructor
    Person(const Person&);  //copy constructor
};

Person::Person(string theName, int theAge)
{
    name = theName;
    age = theAge;
}

int main()
{
    Person john("john", 75);
    Person dave = john;
}
