#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
using namespace std;
class Person
{
private:
    string name;
    string address;
    string phone;
public:
    Person();
    Person(string name, string address, string phone);
    ~Person();
    string getName();
    string getAddress();
    string getPhone();
    void setName(string name);
    void setAddress(string address);
    void setPhone(string phone);
    
    friend istream &operator >> (istream &in, Person &person);
    friend ostream &operator << (ostream &out, Person &person);
};

Person::Person()
{
    this->name = "";
    this->address = "";
    this->phone = "";
}

Person::Person(string name, string address, string phone)
{
    this->name = name;
    this->address = address;
    this->phone = phone;
}
istream &operator >> (istream &in, Person &person)
{
    cout << "Enter Information for Person: " << endl;
    cout << "Enter Name: ";
    in >> person.name;
    cout << "Enter Address: ";
    in >> person.address;
    cout << "Enter Phone: ";
    in >> person.phone;
    return in;
}
ostream &operator << (ostream &out, Person &person)
{
    out << "Information for Person: " << endl;
    out << "Name: " << person.name << endl;
    out << "Address: " << person.address << endl;
    out << "Phone: " << person.phone << endl;
    return out;
}
string Person::getName()
{
    return this->name;
}
string Person::getAddress()
{
    return this->address;
}
string Person::getPhone()
{
    return this->phone;
}
void Person::setName(string name)
{
    this->name = name;
}
void Person::setAddress(string address)
{
    this->address = address;
}
void Person::setPhone(string phone)
{
    this->phone = phone;
}
Person::~Person()
{
}

#endif 