#include<iostream>
#include<string>
using namespace std;

class Integer
{
    int val;
public:
    Integer() : val(0){}
    Integer(int val) : val(val) {}

    Integer operator+(Integer& objeto)
    {
        return Integer(val + objeto.val);
    }

    friend ostream& operator<<(ostream& os, Integer& object);
};

ostream& operator<<(ostream& os, Integer& object)
{
    os << object.val << endl;
    return os;
}

template<typename T> 
class AddOperations
{
public:
    T add(T a, T b)
    {
        return a + b; 
    }
};

//especialización de la plantilla
template<>
class AddOperations<string>
{
public:
    string add(string a, string b)
    {
        return "ya fue especializado para strings"; 
    }
};



int main()
{
    AddOperations<int> operations;
    cout << operations.add(3, 5) << endl;

    AddOperations<double> b;
    cout << b.add(3.2, 6.8) << endl;

    AddOperations<string> c;
    cout << c.add("hola", "cómo estás");   // CONCATENAR

    Integer num1(2);
    Integer num2(22);
    
    AddOperations<Integer> d;
    Integer num3 = d.add(num1, num2);
    cout << num3;

    //static_cast<Integer*>(loquequiero);
}

template<typename T>
class Array
{
protected:
    T* array = new T[10];
};

/*
    * CLASS TEMPLATES    - Plantillas para clases específicas
    * FUNCTION TEMPLATES - funciones externas que no están relacionadas con clases
    * 
    * 
    * Template specification
*/