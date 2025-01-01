#include "UserController.h"

UserController::UserController(LinkedList<User>& users, const UserView& userView)
    : users(users), view(userView) {}

void UserController::login(const string& username, const string& password) {
    bool isValid = false;
    for (const auto& user : users) {
        if (user.getEmail() == username && user.getPassword() == password) {
            isValid = true;
            view.displayMessage("Login successful!");
            break;
        }
    }

    if (!isValid) {
        view.displayMessage("Invalid username or password.");
    }
}

void UserController::changePassword(const string& email, const string& oldPassword, const string& newPassword) {
    for (auto& user : users) {
        if (user.getEmail() == email && user.getPassword() == oldPassword) {
            user.setPassword(newPassword);
            view.displayMessage("Password changed successfully!");
            return;
        }
    }
    view.displayMessage("Invalid email or old password.");
}

void UserController::deleteAccount(const string& email) {
    for (auto it = users.begin(); it != users.end(); ++it) {
        if (it->getEmail() == email) {
            users.remove(*it);
            view.displayMessage("Account deleted successfully!");
            return;
        }
    }
    view.displayMessage("Account not found.");
}

void UserController::updateCSV()
{
}
