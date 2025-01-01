#ifndef BASEVIEW_H
#define BASEVIEW_H

#include <iostream>
#include <string>

using namespace std;
class BaseView {
public:
    virtual void displayMessage(const string& message) {
        cout << message << endl;
    }

    virtual ~BaseView() = default;
};

#endif // BASEVIEW_H
