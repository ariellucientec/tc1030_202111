#include<string>
#include<iostream>
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

    //soy un método virtual para permitir que toooodos mis hijos lo cambien si quieren
    virtual void print();
};
