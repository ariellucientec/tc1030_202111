#include"../ListaGenérica/Element.h"
#include<string>
#include<iostream>
using namespace std;

#pragma once
class Teacher : public Element
{
protected:
    string nomina;
public:
    Teacher(string nombre, string nomina) : Element(nombre), nomina(nomina){}
    string getNomina();
    void print()
    {
        cout << "soy " << getS() << " y mi nómina es " << getNomina() << endl;
    }
};

string Teacher::getNomina()
{
    return nomina;
}