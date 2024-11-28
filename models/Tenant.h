#ifndef TENANT_H
#define TENANT_H

#include "Person.h"

class Tenant : public Person {
private:
    int id;
    string email;
    string sex;
    string dateOfBirth; // Using string for simplicity in this example

public:
    Tenant();
    Tenant(int id, const string& name, const string& sex, const string& dateOfBirth, 
           const string& email, const string& address, const string& phone);

    int getId() const;
    string getEmail() const;
    string getSex() const;
    string getDateOfBirth() const;

    void setId(int id);
    void setEmail(const string& email);
    void setSex(const string& sex);
    void setDateOfBirth(const string& dob);

    friend istream& operator>>(istream& in, Tenant& tenant);
    friend ostream& operator<<(ostream& out, const Tenant& tenant);
};

#endif
