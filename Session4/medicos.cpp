//#include"../Session3/Date.h"

#include<string>
#include<iostream>
#include"Person.h"

using namespace std;

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
    Doctor* doctor;
public:
    MedicalAssistant(){}
    MedicalAssistant(Doctor* doctor, int id, string name, string position, double salary) : doctor(doctor), Employee(id, position, salary, name){} 
public:
    void setAnAppointment(Patient patient);
};

void MedicalAssistant::setAnAppointment(Patient patient)
{
    if(doctor->isBusy() == true)
    cout << "el doctor está ocupado atendiendo a " << doctor->getPatient().getName() << " llama después" << endl;
    else
    {
        doctor->consult(patient);
        cout<< "el doctor " << doctor->getName() << " te va a dar consulta. Adelante!!" << endl;
    }
}

int main()
{
    Doctor who(3838, 1, "Walter", "médico", 100000);
    MedicalAssistant a1(&who, 2, "mike", "asistente", 10000);
    MedicalAssistant a2(&who, 3, "mary", "asistente", 10000);
    Patient pedrito(1, "pedrito");

    a1.setAnAppointment(pedrito);
    a2.setAnAppointment(pedrito);

}
