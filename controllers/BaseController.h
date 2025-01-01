#ifndef BASECONTROLLER_H
#define BASECONTROLLER_H

#include <string> 

using namespace std;

class BaseController {
public:
    virtual void updateCSV() = 0; // Abstract method
    virtual ~BaseController() = default;
};

#endif // BASECONTROLLER_H
