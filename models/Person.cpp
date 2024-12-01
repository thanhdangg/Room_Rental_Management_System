#include "Person.h"

Person::Person() : name(""), address(""), phone("") {}

Person::Person(const string& name, const string& address, const string& phone)
    : name(name), address(address), phone(phone) {}

string Person::getName() const {
    return name;
}

string Person::getAddress() const {
    return address;
}

string Person::getPhone() const {
    return phone;
}

void Person::setName(const string& name) {
    this->name = name;
}

void Person::setAddress(const string& address) {
    this->address = address;
}

void Person::setPhone(const string& phone) {
    this->phone = phone;
}

istream& operator>>(istream& in, Person& person) {
    getline(in, person.name);
    getline(in, person.address);
    getline(in, person.phone);
    return in;
}

ostream& operator<<(ostream& out, const Person& person) {
    out << "Name: " << person.name << endl;
    out << "Address: " << person.address << endl;
    out << "Phone: " << person.phone << endl;
    return out;
}