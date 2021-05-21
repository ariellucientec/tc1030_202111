#include<string>
using namespace std;

#pragma once
class Person
{
protected:
    string name;
public:
    Person();
    Person(string name);
    string getName();
};
