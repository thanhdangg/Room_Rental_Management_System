#ifndef BASEVIEW_H
#define BASEVIEW_H

#include <iostream>
#include <string>

class BaseView {
public:
    virtual void displayMessage(const std::string& message) {
        std::cout << message << std::endl;
    }

    virtual ~BaseView() = default;
};

#endif // BASEVIEW_H
