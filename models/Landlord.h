#ifndef LANDLORD_H
#define LANDLORD_H

#include <iostream>
#include "Person.h"
using namespace std;
class Landlord : public Person
{
public:
    Landlord();
    Landlord(const string name, const string address, const string phone);
    ~Landlord();

    friend istream &operator>>(istream &in, Landlord &landlord);
    friend ostream &operator<<(ostream &out, const Landlord &landlord);
};

#endif
