#include "Tenant.h"

Tenant::Tenant() : Person(), id(0), sex(""), dateOfBirth(""), email("") {}

Tenant::Tenant(int id, const string& name, const string& sex, const string& dateOfBirth, 
               const string& email, const string& address, const string& phone)
    : Person(name, address, phone), id(id), sex(sex), dateOfBirth(dateOfBirth), email(email) {}

int Tenant::getId() const { return id; }
string Tenant::getEmail() const { return email; }
string Tenant::getSex() const { return sex; }
string Tenant::getDateOfBirth() const { return dateOfBirth; }

void Tenant::setId(int id) { this->id = id; }
void Tenant::setEmail(const string& email) { this->email = email; }
void Tenant::setSex(const string& sex) { this->sex = sex; }
void Tenant::setDateOfBirth(const string& dob) { this->dateOfBirth = dob; }

istream& operator>>(istream& in, Tenant& tenant) {
    in >> static_cast<Person&>(tenant);
    cout << "Enter ID: ";
    in >> tenant.id;
    cout << "Enter Sex: ";
    in.ignore();
    getline(in, tenant.sex);
    cout << "Enter Date of Birth: ";
    getline(in, tenant.dateOfBirth);
    cout << "Enter Email: ";
    getline(in, tenant.email);
    return in;
}

ostream& operator<<(ostream& out, const Tenant& tenant) {
    out << static_cast<const Person&>(tenant);
    out << "ID: " << tenant.id << endl;
    out << "Sex: " << tenant.sex << endl;
    out << "Date of Birth: " << tenant.dateOfBirth << endl;
    out << "Email: " << tenant.email << endl;
    return out;
}
