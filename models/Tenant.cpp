#include "Tenant.h"
#include <iostream>

Tenant::Tenant() : Person(), id(0), sex(""), email(""), dateOfBirth("") {}

Tenant::Tenant(int id, const std::string& name, const std::string& sex, const std::string& dateOfBirth,
               const std::string& email, const std::string& phone, const std::string& address)
    : Person(name, address, phone), id(id), sex(sex), email(email), dateOfBirth(dateOfBirth) {}

int Tenant::getId() const {
    return id;
}

std::string Tenant::getEmail() const {
    return email;
}

std::string Tenant::getSex() const {
    return sex;
}

std::string Tenant::getDateOfBirth() const {
    return dateOfBirth;
}

void Tenant::setId(int id) {
    this->id = id;
}

void Tenant::setEmail(const std::string& email) {
    this->email = email;
}

void Tenant::setSex(const std::string& sex) {
    this->sex = sex;
}

void Tenant::setDateOfBirth(const std::string& dateOfBirth) {
    this->dateOfBirth = dateOfBirth;
}

std::istream& operator>>(std::istream& in, Tenant& tenant) {
    std::getline(in, tenant.email);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Tenant& tenant) {
    out << static_cast<const Person&>(tenant); 
    out << "ID: " << tenant.id << std::endl;
    out << "Sex: " << tenant.sex << std::endl;
    out << "Date of Birth: " << tenant.dateOfBirth << std::endl;
    out << "Email: " << tenant.email << std::endl;
    return out;
}

bool Tenant::operator==(const Tenant& other) const {
    return id == other.id && email == other.email && sex == other.sex && dateOfBirth == other.dateOfBirth;
}

bool Tenant::operator!=(const Tenant& other) const {
    return !(*this == other);
}
