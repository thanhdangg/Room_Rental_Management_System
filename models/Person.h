#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

using namespace std;

class Person {
private:
    string name;
    string address;
    string phone;

public:
    Person();
    Person(const string& name, const string& address, const string& phone);

    string getName() const;
    string getAddress() const;
    string getPhone() const;

    void setName(const string& name);
    void setAddress(const string& address);
    void setPhone(const string& phone);

    friend istream& operator>>(istream& in, Person& person);
    friend ostream& operator<<(ostream& out, const Person& person);
};

#endif // PERSON_H