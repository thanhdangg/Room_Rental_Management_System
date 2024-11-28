#include "User.h"

User::User() : role(0) {}

User::User(const string& email, const string& password, int role) 
    : email(email), password(password), role(role) {}

string User::getEmail() const {
    return email;
}

string User::getPassword() const {
    return password;
}

int User::getRole() const {
    return role;
}

void User::setEmail(const string& email) {
    this->email = email;
}

void User::setPassword(const string& password) {
    this->password = password;
}

void User::setRole(int role) {
    this->role = role;
}

bool User::validateLogin(const string& username, const string& password) const {
    return (email == username && this->password == password);
}

vector<User> User::loadUsersFromCSV(const string& filename) {
    vector<User> users;
    ifstream file(filename);
    string line;

    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return users;
    }

    while (getline(file, line)) {
        stringstream ss(line);
        string email, password, roleStr;
        int role;

        getline(ss, email, ',');
        getline(ss, password, ',');
        getline(ss, roleStr, ',');
        role = stoi(roleStr);

        users.push_back(User(email, password, role));
    }

    file.close();
    return users;
}

istream& operator>>(istream& in, User& user) {
    in >> user.email >> user.password >> user.role;
    return in;
}

ostream& operator<<(ostream& out, const User& user) {
    out << user.email << ", " << user.password << ", " << user.role;
    return out;
}

bool User::operator==(const User& other) const {
    return email == other.email && password == other.password && role == other.role;
}

bool User::operator!=(const User& other) const {
    return !(*this == other);
}
