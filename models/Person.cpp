#include "Person.h"

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
    getline(in, person.name);
    cout << "Enter Address: ";
    getline(in, person.address);
    cout << "Enter Phone: ";
    getline(in, person.phone);
    return in;
}

ostream &operator << (ostream &out, const Person &person)
{
    out << "Information for Person: " << endl;
    out << "Name: " << person.name << endl;
    out << "Address: " << person.address << endl;
    out << "Phone: " << person.phone << endl;
    return out;
}

string Person::getName() const
{
    return this->name;
}

string Person::getAddress() const
{
    return this->address;
}

string Person::getPhone() const
{
    return this->phone;
}

void Person::setName(const string& name)
{
    this->name = name;
}

void Person::setAddress(const string& address)
{
    this->address = address;
}

void Person::setPhone(const string& phone)
{
    this->phone = phone;
}

Person::~Person()
{
}
