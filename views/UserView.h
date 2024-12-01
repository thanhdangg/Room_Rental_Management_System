#ifndef USERVIEW_H
#define USERVIEW_H

#include "../models/User.h"
#include <iostream>

class UserView {
public:
    void displayMessage(const std::string& message) const;
};

#endif // USERVIEW_H