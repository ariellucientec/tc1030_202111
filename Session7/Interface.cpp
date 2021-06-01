#include<iostream>
using namespace std;

class Interface
{
public:
    virtual void foo() = 0;
    virtual ~Interface()
    {
        cout << "estoy en el destructor de Interface " << endl;
    }
};

class Implements : public Interface
{
public:
    void foo(){}
    ~Implements()
    {
        cout << "estoy en el destructor de Implements " << endl;
    }
};

int main()
{
    Interface* i = new Implements;
    delete i;
}