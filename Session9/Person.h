#pragma once
class Person
{
public:
    int age;
    string name;
    //Person parent;
public:
    Person(){}
    Person(string name, int age) : name(name), age(age){}
	string getName(){return name;}
	int getAge(){ return age;}
};