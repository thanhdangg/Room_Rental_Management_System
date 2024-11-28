#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

class User {
private:
    string email;
    string password; 
    int role; // Role can be Owner or Tenant

public:
    User();
    User(const string& email, const string& password, int role);

    string getEmail() const;
    string getPassword() const;
    int getRole() const;

    void setEmail(const string& email);
    void setPassword(const string& password);
    void setRole(int role);

    static vector<User> loadUsersFromCSV(const string& filename);
    bool validateLogin(const string& username, const string& password) const;

    friend istream& operator>>(istream& in, User& user);
    friend ostream& operator<<(ostream& out, const User& user);

    bool operator==(const User& other) const;
    bool operator!=(const User& other) const;
};

#endif
