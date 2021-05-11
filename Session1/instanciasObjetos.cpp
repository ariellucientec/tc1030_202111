/* Sesión 1 creación de instancias   

El siguiente código NO compila porque falta definir la clase Person (sus atributos, métodos y constructores)
Sólo es para que identifiques en qué líneas se crean instancias

*/

#include<string>
#include<iostream>
using namespace std;

int main()
{
    Person john;                                        //Instancia
    Person july("july", "smith");                       //Instancia con parámetros
    Person* point2John;                                 //No es una instancia
    Person johnTheSecond = john;                        //Sí es una instancia (copy constructor)
    Person* pointer2OtherJohn = new Person;             //pointer points to an instance
    john = july;                                        //NO
    Person* judy = new Person(john);                    //pointer points to an instance
    pointer2OtherJohn = new Person("John", "Baptiste"); //pointer points to an instance
    int number = 7;                                     //NO
    int* magicNumber = new int(7);                      //NO
}

