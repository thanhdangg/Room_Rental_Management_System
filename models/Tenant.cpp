#include "Tenant.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <regex>
#include "../utils/utils.h"

Tenant::Tenant() : Person(), id(0), sex(""), email(""), dateOfBirth("") {}

Tenant::Tenant(int id, const string &name, const string &sex, const string &dateOfBirth,
               const string &email, const string &phone, const string &address)
    : Person(name, address, phone), id(id), sex(sex), email(email), dateOfBirth(dateOfBirth) {}

int Tenant::getId() const
{
    return id;
}

string Tenant::getEmail() const
{
    return email;
}

string Tenant::getSex() const
{
    return sex;
}

string Tenant::getDateOfBirth() const
{
    return dateOfBirth;
}

void Tenant::setId(int id)
{
    this->id = id;
}

void Tenant::setEmail(const string &email)
{
    this->email = email;
}

void Tenant::setSex(const string &sex)
{
    this->sex = sex;
}

void Tenant::setDateOfBirth(const string &dateOfBirth)
{
    this->dateOfBirth = dateOfBirth;
}

istream &operator>>(istream &in, Tenant &tenant)
{
    tenant.id = inputNumber("Enter ID");

    string name = inputString("Enter Name");
    tenant.setName(name);

    string sex = inputString("Enter Sex");
    tenant.setSex(sex);

    string dateOfBirth = inputDate("Enter Date of Birth");
    tenant.setDateOfBirth(dateOfBirth);

    string email = inputEmail("Enter Email");
    tenant.setEmail(email);

    string phone = inputPhone("Enter Phone");
    tenant.setPhone(phone);

    string address = inputString("Enter Address");
    tenant.setAddress(address);

    return in;
}

ostream &operator<<(ostream &out, const Tenant &tenant)
{
    out << "ID: " << tenant.getId() << endl;
    out << "Name: " << tenant.getName() << endl;
    out << "Sex: " << tenant.getSex() << endl;
    out << "Date of Birth: " << tenant.getDateOfBirth() << endl;
    out << "Email: " << tenant.getEmail() << endl;
    out << "Phone: " << tenant.getPhone() << endl;
    out << "Address: " << tenant.getAddress() << endl;
    return out;
}

bool Tenant::operator==(const Tenant &other) const
{
    return id == other.id && email == other.email && sex == other.sex && dateOfBirth == other.dateOfBirth;
}

bool Tenant::operator!=(const Tenant &other) const
{
    return !(*this == other);
}
