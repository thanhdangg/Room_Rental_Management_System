#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include "BaseController.h"
#include "../models/User.h"
#include "../views/UserView.h"
#include "../data_structures/LinkedList.h"
#include <string>
#include <iostream>

class UserController : public BaseController {
private:
    LinkedList<User>& users;
    UserView view;

public:
    UserController(LinkedList<User>& users, const UserView& userView);

    void login(const std::string& username, const std::string& password);
    void changePassword(const std::string& email, const std::string& oldPassword, const std::string& newPassword);
    void deleteAccount(const std::string& email);
    void execute() override;
};

#endif // USERCONTROLLER_H