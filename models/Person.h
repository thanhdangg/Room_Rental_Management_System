#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
#include <limits> 

using namespace std;

class Person
{
protected:
    string name;
    string address;
    string phone;

public:
    Person();
    Person(string name, string address, string phone);
    ~Person();
    
    string getName() const;
    string getAddress() const;
    string getPhone() const;

    void setName(const string& name);
    void setAddress(const string& address);
    void setPhone(const string& phone);
    
    friend istream &operator >> (istream &in, Person &person);
    friend ostream &operator << (ostream &out, const Person &person);
};

#endif // PERSON_H
