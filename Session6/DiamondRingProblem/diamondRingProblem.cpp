#include<iostream>
using namespace std;
class Base
{
public:
    virtual void oneOperation() = 0;
    virtual void bothOperations() = 0;
};

class ClassA : public virtual Base
{
public:
    void bothOperations()
    {
        oneOperation();
        cout << "doing second operation" << endl;
    }
};

class ClassB : public virtual Base
{
public:
    void oneOperation()
    {
        cout << "doing the one operation" << endl;
    }
};

class ClassC : public ClassA, public ClassB
{
public:

};

int main()
{
    ClassC c;
    c.bothOperations();
}