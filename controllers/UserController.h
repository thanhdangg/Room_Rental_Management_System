#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include "BaseController.h"
#include "../models/User.h"
#include "../views/UserView.h"
#include "../data_structures/LinkedList.h"
#include <string>
#include <iostream>

using namespace std;

class UserController : public BaseController {
private:
    LinkedList<User>& users;
    UserView view;

public:
    UserController(LinkedList<User>& users, const UserView& userView);

    void login(const string& username, const string& password);
    void changePassword(const string& email, const string& oldPassword, const string& newPassword);
    void deleteAccount(const string& email);
    void updateCSV() override;
};

#endif // USERCONTROLLER_H