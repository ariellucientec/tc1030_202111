#include"LinkedList.h"
#include"Teacher.h"
#include"Student.h"


class SchoolManager
{
protected:
    ListInterface* listEmployees;
public:
    SchoolManager() : listEmployees(new LinkedList){}
    void addTeacher()
    {
        listEmployees->add(new Teacher("Juan", "00001"));
    }
    void addStudent()
    {
        listEmployees->add(new Student("Pedro", "10000"));
    }
    void print()
    {
        listEmployees->print();
    }
    void printNominas()
    {
        int numElements = listEmployees->size();
        for (int i = 1; i <= numElements; i++)
        {       
            Teacher* teacher = dynamic_cast<Teacher*>(listEmployees->get(i));
            if(teacher != 0)
            {
                cout << teacher->getNomina() << endl;
            }
        }
    }

    int getNumberOfEmployees()
    {
        return listEmployees->size();
    }
    
    ~SchoolManager()
    {
        delete listEmployees;
    }
};

int main()
{
    SchoolManager s;
    s.addStudent();
    s.addTeacher();
    s.addStudent();
    s.addTeacher();
    s.printNominas();
}