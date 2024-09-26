#ifndef LANDLORD_H
#define LANDLORD_H

#include <iostream>
#include "Person.cpp"
using namespace std;

class Landlord : public Person
{
private:

public:
    Landlord();
    ~Landlord();
    Landlord(const string name, const string address, const string phone);

    friend istream &operator>>(istream &in, Landlord &landlord);
    friend ostream &operator<<(ostream &out, Landlord &landlord);
};

Landlord::Landlord()
{
}

Landlord::~Landlord()
{
}

Landlord::Landlord(const string name, const string address, const string phone)
{
    this->name = name;
    this->address = address;
    this->phone = phone;
}

istream &operator>>(istream &in, Landlord &landlord)
{
    cout << "Enter Information for Landlord: " << endl;
    cout << "Enter Name: ";
    getline(in, landlord.name);
    cout << "Enter Address: ";
    getline(in, landlord.address);
    cout << "Enter Phone: ";
    getline(in, landlord.phone);
    return in;
}

ostream &operator<<(ostream &out, Landlord &landlord)
{
    out << "Information for Landlord: " << endl;
    out << "Name: " << landlord.name << endl;
    out << "Address: " << landlord.address << endl;
    out << "Phone: " << landlord.phone << endl;
    return out;
}

#endif // LANDLORD_H