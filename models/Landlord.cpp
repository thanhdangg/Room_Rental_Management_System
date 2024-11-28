#include "Landlord.h"

Landlord::Landlord() : Person() {}

Landlord::Landlord(const string name, const string address, const string phone)
    : Person(name, address, phone) {}

Landlord::~Landlord() {}

istream &operator>>(istream &in, Landlord &landlord)
{
    in >> static_cast<Person &>(landlord); 
    return in;
}

ostream &operator<<(ostream &out,const Landlord &landlord)
{
    out << static_cast<const Person &>(landlord); 
    return out;
}