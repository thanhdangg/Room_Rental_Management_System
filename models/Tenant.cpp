#ifndef TENANT_H
#define TENANT_H

#include <string>
#include "Person.cpp"
#include <iostream>

using namespace std;

class Tenant : public Person
{
private:
    string id;
    string sex;
    string dateOfBirth;
    string email;
    string occupation;
    string income;
public:
    Tenant();
    Tenant(string id, string name, string address, string phone , string sex, string dateOfBirth, string email, string occupation, string income);
    ~Tenant();
    string getId();
    string getSex();
    string getDateOfBirth();
    string getEmail();
    string getOccupation();
    string getIncome();
    void setId(string id);
    void setSex(string sex);
    void setDateOfBirth(string dateOfBirth);
    void setEmail(string email);
    void setOccupation(string occupation);
    void setIncome(string income);

    friend istream &operator >> (istream &in, Tenant &tenant);
    friend ostream &operator << (ostream &out, Tenant &tenant);
};

Tenant::Tenant()
{
    this->id = "";
    this->name = "";
    this->address = "";
    this->phone = "";
    this->sex = "";
    this->dateOfBirth = "";
    this->email = "";
    this->occupation = "";
    this->income = "";
}

Tenant::Tenant(string id, string name, string address, string phone, string sex, string dateOfBirth, string email, string occupation, string income)
{
    this->id = id;
    this->name = name;
    this->address = address;
    this->phone = phone;
    this->sex = sex;
    this->dateOfBirth = dateOfBirth;
    this->email = email;
    this->occupation = occupation;
    this->income = income;
}

Tenant::~Tenant()
{
}

string Tenant::getId()
{
    return this->id;
}

string Tenant::getSex()
{
    return this->sex;
}

string Tenant::getDateOfBirth()
{
    return this->dateOfBirth;
}

string Tenant::getEmail()
{
    return this->email;
}

string Tenant::getOccupation()
{
    return this->occupation;
}

string Tenant::getIncome()
{
    return this->income;
}

void Tenant::setId(string id)
{
    this->id = id;
}

void Tenant::setSex(string sex)
{
    this->sex = sex;
}

void Tenant::setDateOfBirth(string dateOfBirth)
{
    this->dateOfBirth = dateOfBirth;
}

void Tenant::setEmail(string email)
{
    this->email = email;
}
void Tenant::setOccupation(string occupation)
{
    this->occupation = occupation;
}

void Tenant::setIncome(string income)
{
    this->income = income;
}

istream &operator>>(istream &in, Tenant &tenant)
{
    cout << "Enter Information for Tenant: " << endl;
    cout << "Enter ID: ";
    getline(in, tenant.id);
    cout << "Enter Name: ";
    getline(in, tenant.name);
    cout << "Enter Address: ";
    getline(in, tenant.address);
    cout << "Enter Phone: ";
    getline(in, tenant.phone);
    cout << "Enter sex: ";
    getline(in, tenant.sex);
    cout << "Enter Date of Birth: ";
    getline(in, tenant.dateOfBirth);
    cout << "Enter Email: ";
    getline(in, tenant.email);
    cout << "Enter Occupation: ";
    getline(in, tenant.occupation);
    cout << "Enter Income: ";
    getline(in, tenant.income);
    return in;
}

ostream &operator << (ostream &out, Tenant &tenant)
{
    out << "Information for Tenant: " << endl;
    out << "ID: " << tenant.id << endl;
    out << "Name: " << tenant.name << endl;
    out << "Address: " << tenant.address << endl;
    out << "Phone: " << tenant.phone << endl;
    out << "Sex: " << tenant.sex << endl;
    out << "Date of Birth: " << tenant.dateOfBirth << endl;
    out << "Email: " << tenant.email << endl;
    out << "Occupation: " << tenant.occupation << endl;
    out << "Income: " << tenant.income << endl;
    return out;
}

#endif // TENANT_H