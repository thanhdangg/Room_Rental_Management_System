#ifndef TENANT_H
#define TENANT_H

#include <string>
#include "Person.h"

class Tenant : public Person {
private:
    int id;
    std::string sex;
    std::string email;
    std::string dateOfBirth;

public:
    Tenant();
    Tenant(int id, const std::string& name, const std::string& sex, const std::string& dateOfBirth,
           const std::string& email, const std::string& phone, const std::string& address);

    int getId() const;
    std::string getEmail() const;
    std::string getSex() const;
    std::string getDateOfBirth() const;

    void setId(int id);
    void setEmail(const std::string& email);
    void setSex(const std::string& sex);
    void setDateOfBirth(const std::string& dateOfBirth);

    friend std::istream& operator>>(std::istream& in, Tenant& tenant);
    friend std::ostream& operator<<(std::ostream& out, const Tenant& tenant);

    bool operator==(const Tenant& other) const;
    bool operator!=(const Tenant& other) const;
};

#endif // TENANT_H
