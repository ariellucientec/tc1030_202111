/*
        FORWARD DECLARATION
    ¿qué pasa cuando una clase depende de otra y esa otra clase depende de la primera? un caos! Para resolver ese caos se usa Forward Declaration!

    Temas vistos en este ejemplo:

    a) Forward declaration (evitar referencias circulares)

    b) Herencia porque las clases Husband and Wife heredan de Persona (así tengo el name y getName en un único lugar)

    c) Method OVERRIDING la clase Persona tiene un método virtual (print) que quiero sobrescribir tanto en Wife como en Husband



    NOTA: inscrucción para compilar:    g++ thisPointer.cpp Person.cpp

*/

#include"Person.h"
#include<string>
#include<iostream>
using namespace std;

// Hago forward declaration de Husband para poder terminar de definir Wife sin que esté completamente definido Husband
class Husband;

class Wife : public Person
{
public:
    Wife(string name);
    void setHusband(Husband* h);
    void print();
protected:
    Husband* h;
};

class Husband : public Person
{
public:
    Husband(string name);
    void setWife(Wife* w);
    void print();
protected:
    Wife* w;
};

// Después de la definición de toooodas las clases, va la implementación de tooodos sus métodos

Wife::Wife(string name) : Person(name){}
Husband::Husband(string name) : Person(name){}
void Husband::setWife(Wife* w){this->w = w; }
void Wife::setHusband(Husband* h){this->h = h; }
void Wife::print(){ cout << "Soy "<< getName() <<" y mi esposo es " << h->getName() << endl;}
void Husband::print(){cout << "Soy "<< getName() <<" y mi esposa es " << w->getName() << endl;}

int main()
{
    Wife r("Rose");
    Husband m("Mary");

    r.setHusband(&m);
    m.setWife(&r);

    r.print();
    m.print();
}

