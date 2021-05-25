/* este programa permite ejemplificar varias cosas
    
    a) Uso del pointer THIS para hacer referencia a la misma clase (apuntador a la instancia actual)

    b) Uso de Forward Declaration para la definición de Manager (Seat la necesita para definirse porque tiene un atributo de la clase Manager)

    c) Friend Classes porque necesito que Manager sea amigo de Seat, así puede modificar atributos privados (precio)

    d) Herencia porque el nombre y el método getName para el Manager los heredo de Person

    e) Métodos virtuales porque la clase Person (padre de Manager) tiene el método print que quiero que el Manager Sobrescriba


    NOTA: inscrucción para compilar:    g++ thisPointer.cpp Person.cpp
*/

#include<iostream>
#include"Person.h"
using namespace std;

class Manager;  //Forward Declaration of Manager class

class Seat
{
protected:
    Manager* m;
    bool reserved;
    void reserve(Manager* m);
public:
    Seat():reserved(false), m(0){}  // Por default NO está reservado y no tiene Manager
    void print();

    friend class Manager;  //esto permite que SÓLO Seat y el Manager tengan acceso al método reserve
};

class Manager : public Person
{
    Seat* s;  //no quiero copias
public:
    Manager(){}
    Manager(string name, Seat* seats2Manage) : Person(name), s(seats2Manage){}
    void reserve();
};

// Aquí inician las implementaciones de las clases ---------------------------------------------

void Seat::reserve(Manager* m)
{
    if (reserved == false)
    {
        reserved = true;
        this->m = m;
    }
}

void Seat::print()
{
    if (reserved==false)
        cout << "I´m the only available seat " << endl;
    else    
        cout << "I´m the only available seat and I was reserved by the Manager " << m->getName() << endl;
}

void Manager::reserve()
{
    s->reserve(this);   //reserve es el reserve de la clase Seat y le paso un apuntador a MÍ MISMO (this)
}

int main()
{
    Seat onlySeat;
    Manager chuchito("chuchito", &onlySeat);
    chuchito.reserve();
    
    onlySeat.print(); //para revisar que sí haya sido reservado por chuchito
}

// & es para referenciar -> Obtener la dirección
// * es para De Referencias -> Quitar la dirección -> Acceder al contenido
// THIS es un apuntador a la instancia en la que estoy -> NO A LA CLASE
