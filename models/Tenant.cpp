#include "Tenant.h"
#include <iostream>

Tenant::Tenant() : Person(), id(0), sex(""), email(""), dateOfBirth("") {}

Tenant::Tenant(int id, const string& name, const string& sex, const string& dateOfBirth,
               const string& email, const string& phone, const string& address)
    : Person(name, address, phone), id(id), sex(sex), email(email), dateOfBirth(dateOfBirth) {}

int Tenant::getId() const {
    return id;
}

string Tenant::getEmail() const {
    return email;
}

string Tenant::getSex() const {
    return sex;
}

string Tenant::getDateOfBirth() const {
    return dateOfBirth;
}

void Tenant::setId(int id) {
    this->id = id;
}

void Tenant::setEmail(const string& email) {
    this->email = email;
}

void Tenant::setSex(const string& sex) {
    this->sex = sex;
}

void Tenant::setDateOfBirth(const string& dateOfBirth) {
    this->dateOfBirth = dateOfBirth;
}

istream& operator>>(istream& in, Tenant& tenant) {
    string name, sex, dateOfBirth, email, phone, address;
    int ID;
    cout << "Enter ID: ";
    in >> ID;
    cout << "Enter Name: ";
    in.ignore();
    getline(in, name);
    tenant.setName(name);
    cout << "Enter Sex: ";
    getline(in, sex);
    tenant.setSex(sex);
    cout << "Enter Date of Birth (YYYY-MM-DD): ";
    getline(in, dateOfBirth);
    tenant.setDateOfBirth(dateOfBirth);
    cout << "Enter Email: ";
    in >> email;
    tenant.setEmail(email);
    cout << "Enter Phone: ";
    in >> phone;
    tenant.setPhone(phone);
    cout << "Enter Address: ";
    in.ignore();
    getline(in, address);
    tenant.setAddress(address);
    return in;
}

ostream& operator<<(ostream& out, const Tenant& tenant) {
    out << "ID: " << tenant.getId() << endl;
    out << "Name: " << tenant.getName() << endl;
    out << "Sex: " << tenant.getSex() << endl;
    out << "Date of Birth: " << tenant.getDateOfBirth() << endl;
    out << "Email: " << tenant.getEmail() << endl;
    out << "Phone: " << tenant.getPhone() << endl;
    out << "Address: " << tenant.getAddress() << endl;
    return out;
}

bool Tenant::operator==(const Tenant& other) const {
    return id == other.id && email == other.email && sex == other.sex && dateOfBirth == other.dateOfBirth;
}

bool Tenant::operator!=(const Tenant& other) const {
    return !(*this == other);
}
