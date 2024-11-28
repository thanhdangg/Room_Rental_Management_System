#ifndef BASECONTROLLER_H
#define BASECONTROLLER_H

class BaseController {
public:
    virtual void execute() = 0; 
    virtual ~BaseController() = default;
};

#endif // BASECONTROLLER_H
