#ifndef ROOMCONTROLLER_H
#define ROOMCONTROLLER_H

#include "BaseController.h"
#include "../models/Room.h"
#include "../views/RoomView.h"
#include "../data_structures/LinkedList.h"
#include <iostream>
#include <fstream>
#include <iomanip> 
#include <string>

using namespace std; 
class RoomController : public BaseController {
private:
    RoomLinkedList& roomList; 
    RoomView view;

public:
    RoomController(RoomLinkedList& roomList, const RoomView& roomView);

    void addRoom();
    void deleteRoom();
    void updateRoom();
    void searchRoom(int roomNumber);
    void bookRoom(int roomNumber);
    void cancelRoomBooking(int roomNumber);
    void roomStatistics();
    
    void updateCSV() override;
};

#endif // ROOMCONTROLLER_H
