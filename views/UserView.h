#ifndef USERVIEW_H
#define USERVIEW_H

#include "BaseView.h"
#include <iostream>

class UserView : public BaseView {
public:
    void displayLoginScreen() {
        std::cout << "Enter username and password:" << std::endl;
    }

    void displayMessage(const std::string& message) {
        std::cout << message << std::endl;
    }
};

#endif // USERVIEW_H
