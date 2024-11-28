#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include "BaseController.h"
#include "../models/User.h"
#include "../views/UserView.h"
#include <vector>
#include <iostream>

class UserController : public BaseController {
private:
    vector<User> users;
    UserView view;

public:
    UserController(const vector<User>& users, const UserView& userView) 
        : users(users), view(userView) {}

    void login(const string& username, const string& password) {
        bool isValid = false;
        for (const auto& user : users) {
            if (user.validateLogin(username, password)) {
                isValid = true;
                view.displayMessage("Login successful!");
                break;
            }
        }

        if (!isValid) {
            view.displayMessage("Invalid username or password.");
        }
    }

    void changePassword(const string& oldPassword, const string& newPassword) {
        
    }

    void deleteAccount(const string& email) {
    }

    void execute() override {
    }
};

#endif // USERCONTROLLER_H
