#ifndef USERVIEW_H
#define USERVIEW_H

#include "../models/User.h"
#include <iostream>

using namespace std;

class UserView {
public:
    void displayMessage(const string& message) const;
};

#endif // USERVIEW_H