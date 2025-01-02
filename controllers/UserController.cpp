#include "UserController.h"
#include "../utils/utils.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

UserController::UserController(LinkedList<User> &users, const UserView &userView)
    : users(users), view(userView) {}

void UserController::login(const string &username, const string &password)
{
    bool isValid = false;
    for (const auto &user : users)
    {
        if (user.getEmail() == username && user.getPassword() == password)
        {
            isValid = true;
            view.displayMessage("Login successful!");
            break;
        }
    }

    if (!isValid)
    {
        view.displayMessage("Invalid username or password.");
    }
}

void UserController::changePassword(int userId)
{
    int tryCount = 5;
    while (true)
    {
        cout << "Enter old password: ";
        string oldPassword = getHiddenPassword();

        bool passwordMatched = false;
        for (auto &user : users)
        {
            if (user.getUserId() == userId && user.getPassword() == oldPassword)
            {
                cout << "Enter new password: Password must be at least 8 characters long, "
                        "include at least one uppercase letter, one lowercase letter, "
                        "one digit, and one special character. \nPlease enter here";
                string newPassword = getHiddenPassword();
                user.setPassword(newPassword);
                view.displayMessage("Password changed successfully!");
                return;
            }
        }

        cout << "Old password does not match. You have " << tryCount << " times to change password!!!" << endl;
        tryCount--;
        if (tryCount == 0)
        {
            break;
        }
    }

    view.displayMessage("Invalid email or old password.");
}

void UserController::deleteAccount(int userId)
{
    for (auto it = users.begin(); it != users.end(); ++it)
    {
        if (it->getUserId() == userId)
        {
            users.remove(*it);
            view.displayMessage("Account deleted successfully!");
            return;
        }
    }
    view.displayMessage("Account not found.");
}

void UserController::addAccount()
{
    User user;

    cout << "Add account for: " << endl;
    cout << "1. Landlord" << endl;
    cout << "2. User" << endl;
    do
    {
        cout << "Enter choice: ";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            user.setRole(1);
            break;
        }
        else if (choice == 2)
        {
            user.setRole(2);
            break;
        }

        else
        {
            cout << "Invalid choice! Please enter 1 or 2." << endl;
        }
    } while (true);

    user.setUserId(inputNumber("Enter user ID"));
    user.setEmail(inputEmail("Enter email"));
    string hassPassword = hashPassword("Account@123");
    user.setPassword(hassPassword);
    users.add(user);
    view.displayMessage("Account added successfully!");
    cout << "This password has been set for the account: Account@123" << endl;
    cout << "Please change the password after login." << endl;
    updateCSV();
}

void UserController::updateCSV()
{
    ofstream file("data/users.csv");
    if (!file.is_open())
    {
        cerr << "Error opening file for writing!" << endl;
        return;
    }
    file << "userId,email,password,role\n";
    for (const auto &user : users)
    {
        file << user.getUserId() << ","
             << user.getEmail() << ","
             << user.getPassword() << ","
             << (user.getRole() == 1 ? "Admin" : "User") << "\n";
    }
}
