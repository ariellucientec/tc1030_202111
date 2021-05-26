/* 
        CLASES AMIGAS

    Se necesita una forma en la que una clase tenga acceso a los atributos y métodos PRIVADOS o PROTEGIDOS
    de otra clase. La manera de hacerlo es haciendo clases amigas
    
*/
#include<iostream>
using namespace std;

class ClassA
{
private:
    int privateVal;
protected:
    int protectedVal;
public:
    void printValues(){cout << "privateVal = " << privateVal << " and protectedVal = " << protectedVal << endl;}
    friend class ClassB;
};

class ClassB
{
    ClassA* c;
public:   
    ClassB(){}
    ClassB(ClassA* c) : c(c){}
    void setPrivateVal()
    {
        c->privateVal = 10;
        c->protectedVal = 20;
    }
};

int main()
{
    ClassA a;
    ClassB b(&a);
    b.setPrivateVal(); 
    a.printValues();
}

