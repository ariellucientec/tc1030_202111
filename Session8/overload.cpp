#include<iostream>
using namespace std;

class Integer
{
    int val;
public:
    Integer(){}
    Integer(int val)  : val(val){}

    friend ostream& operator<<(ostream& out, Integer& integer);
};

ostream& operator<<(ostream& out, Integer& integer)
{
    out << integer.val;
    return out;
}

int main()
{
    Integer num(18);
    
    cout << num;
    
}

