#ifndef ROOMVIEW_H
#define ROOMVIEW_H

#include "BaseView.h"
#include "../models/Room.h"

class RoomView : public BaseView {
public:
    void displayRoomDetails(const Room& room) {
        std::cout << "Thông tin phòng: " << room.getDetails() << std::endl;
    }
};

#endif // ROOMVIEW_H
