#ifndef ROOMVIEW_H
#define ROOMVIEW_H

#include "BaseView.h"
#include "../models/Room.h"
#include <string>
#include <iostream>

class RoomView : public BaseView {
public:
    void displayRoomDetails(const Room& room);
};

#endif // ROOMVIEW_H
