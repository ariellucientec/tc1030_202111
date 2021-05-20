#include<iostream>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

    int current_day;
    int current_month;
    int current_year;
public:
    Date(){}
    Date(int dayy, int monthh, int yearr, int cdayy, int cmonthh, int cyearr) : day(dayy), month(monthh), year(yearr), \
    current_day(cdayy), current_month(cmonthh), current_year(cyearr){}
    int getYear();
    int getCurrentYear();
};

int Date::getCurrentYear()
{
    return current_year;
}

int Date::getYear()
{
    return year;
}

class Person
{
private:
    string name;
    Date birthDate;
    Person* dad;
    Person* mom;
public:
    Person(){}
    Person(string namee, Date birthDatee, Person* dadd, Person* momm) :  name(namee), birthDate(birthDatee), dad(dadd), mom(momm){}
    string getName();
    int getAge();
    Person* getDad();
    Person* getMom();
    int getNumAnt();
    Person* getOldest();
};

Person* Person::getOldest()
{
    Person* temporal_mom = getMom(); 
    Person* oldest = getMom(); 
    while (temporal_mom != 0)
    {
        if (temporal_mom->getAge() > oldest->getAge())
        {
            oldest = temporal_mom;
        }
        temporal_mom = temporal_mom->getMom();
    }
    return oldest;
}

int Person::getNumAnt(){
    int count_antecesors = 0;
    Person* temporal_mom = getMom(); 
    while (temporal_mom != 0)
    {
        count_antecesors = count_antecesors + 1; 
        temporal_mom = temporal_mom->getMom();
    }
    return count_antecesors;
}

Person* Person::getDad()
{
    return dad;
}

Person* Person::getMom()
{
    return mom;
}

int Person::getAge()
{
     return (birthDate.getCurrentYear() - birthDate.getYear());
}

string Person::getName()
{
    return name;
}

int main()
{
    Date nacimientoCamila(14,01,1980, 18,05,2021);
    Date nacimientoPedro(14,01,1980, 18,05,2021);
    Date nacimientoSoledad(14,01,1980, 18,05,2021);
    Date nacimientoLaura(14,01,1960, 18,05,2021);
    Person laura("laura", nacimientoLaura, 0, 0);
    Person pedro("pedro", nacimientoPedro, 0, 0);
    Person soledad("Soledad", nacimientoSoledad, 0, &laura);
    Person camila("camila", nacimientoCamila, &pedro, &soledad);

    cout << camila.getOldest()->getName();   

    
}