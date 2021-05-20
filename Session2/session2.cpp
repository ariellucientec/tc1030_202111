#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
    string name;
    int age;
    Person* parent;
    int* numeroParaDestructor;

public:
    Person() : name("generic"), age(50), parent(0), numeroParaDestructor(new int) {}            //default contructor
    //Person() = default;     
    Person(string, int, Person*);    //params constructor
    Person(const Person&);  //copy constructor
    string getName()
    {
        return name;
    }

    ~Person()
    {
        cout << "estoy en el destructor";
        delete numeroParaDestructor;
    }
};

Person::Person(string name, int age, Person* parent) : name(name), age(age), parent(parent){}

Person::Person(const Person& original)   //Deep Copy
{
    name = "generico";
    //age = origin.getAge();
    parent = new Person("otherName", 40, 0);   // Deep Copy
    numeroParaDestructor=new int;
}

int main()
{
    Person* joseph = new Person("joseph", 40, 0);
    Person andrew("andrew", 60, 0);
    Person john("john", 75, &andrew);
    Person dave = john;
    cout << dave.name;
    cout << john.parent << endl;
    cout << dave.parent << endl;
    
    cout << dave.parent->name;
    cout << dave.name;
    delete joseph;
}
