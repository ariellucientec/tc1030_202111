#include"../ListaGenérica/Element.h"
#include<string>
#include<iostream>
using namespace std;

#pragma one
class Student : public Element
{
protected:
    string matricula;
public:
    Student(string nombre, string matricula) : Element(nombre), matricula(matricula){}
    string getMatricula();
    void print()
    {
        cout << "soy " << getS() << " y mi matrícula es " << getMatricula() << endl;
    }
};

string Student::getMatricula()
{
    return matricula;
}