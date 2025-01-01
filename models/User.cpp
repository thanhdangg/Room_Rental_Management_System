#include "User.h"

User::User() : role(0) {}

User::User(int userId, const string& email, const string& password, int role) 
    : userId(userId), email(email), password(password), role(role) {}

string User::getEmail() const {
    return email;
}

string User::getPassword() const {
    return password;
}

int User::getRole() const {
    return role;
}

int User::getUserId() const
{
    return userId;
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

void User::setUserId(int userId)
{
    this->userId = userId;
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
        string email, password, roleStr, userIdStr;
        int role, userId;

        getline(ss, userIdStr, ',');
        getline(ss, email, ',');
        getline(ss, password, ',');
        getline(ss, roleStr, ',');
        role = stoi(roleStr);
        userId = stoi(userIdStr);

        users.push_back(User(userId, email, password, role));
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
