#ifndef TENANT_H
#define TENANT_H

#include <string>
#include "Person.h"

using namespace std;

class Tenant : public Person {
private:
    int id;
    string sex;
    string email;
    string dateOfBirth;

public:
    Tenant();
    Tenant(int id, const string& name, const string& sex, const string& dateOfBirth,
           const string& email, const string& phone, const string& address);

    int getId() const;
    string getEmail() const;
    string getSex() const;
    string getDateOfBirth() const;

    void setId(int id);
    void setEmail(const string& email);
    void setSex(const string& sex);
    void setDateOfBirth(const string& dateOfBirth);

    friend istream& operator>>(istream& in, Tenant& tenant);
    friend ostream& operator<<(ostream& out, const Tenant& tenant);

    bool operator==(const Tenant& other) const;
    bool operator!=(const Tenant& other) const;
};

#endif // TENANT_H
