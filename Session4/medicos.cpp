//#include"../Session3/Date.h"

#include<string>
#include<iostream>
using namespace std;

class Person
{
protected:
    string name;
public:
    Person(){}
    Person(string name) : name(name){}
    string getName();
};

string Person::getName()
{
    return name;
}

class Employee : public Person
{
protected:
    int id_employee;
    string position;
    double salary;
public:
    Employee(){}
    Employee(int id, string pos, double sal, string name) : id_employee(id), position(pos), salary(sal), Person(name){}
};

class Patient : public Person
{
protected:
    int id_patient;
public:
    Patient(){}
    Patient(int id, string name) : id_patient(id), Person(name){} 
};

class Doctor : public Employee
{
protected:
    int licence_number;
    bool busy;
    Patient patient;
public:
    Doctor(){}
    Doctor(int ln, int id, string name, string position, double salary) : busy(false), licence_number(ln), Employee(id, position, salary, name){} 
    bool isBusy();
    void consult(Patient patient);
    Patient getPatient();
};

Patient Doctor::getPatient()
{
    return patient;
}

void Doctor::consult(Patient patient)
{
    busy = true;
    this->patient = patient;  // THIS es un apuntador a la instancia de la clase
    // . y -> operadores de dereferenciación
    // . punto se utiliza cuando no hay un apuntador
    // -> flecha se utiliza cuando SÍ hay un apuntador
}


bool Doctor::isBusy()
{
    return busy;
}




class MedicalAssistant : public Employee
{
public:
    MedicalAssistant(){}
    MedicalAssistant(int id, string name, string position, double salary) : Employee(id, position, salary, name){} 
protected:

};



int main()
{
    Doctor who;
    Doctor* other = &who;
    who.getName();
    other->getName();
}
