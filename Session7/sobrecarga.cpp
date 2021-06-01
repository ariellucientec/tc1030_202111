#include<iostream>
using namespace std;
class Integer
{
protected:
   int value;

public:
   Integer(): value(0){}
   Integer(int value): value(value){}
   Integer operator+(Integer a);
   // Sobrecargar es cambiar LA FIRMA en la parte de los parámetros
};

int main()
{
    Integer* a;
    cout << a->suma(3,4);

    //sobrecarga de operadores -> decirle al compilador qué hacer cuando tiene un operador y uno o más objetos
    int i = 0;
    return i;
}