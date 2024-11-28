#include "RoomController.h"
#include "../views/RoomView.h"
#include <iostream>

using namespace std;

RoomController::RoomController(LinkedList<Room>& roomList) : roomList(roomList) {}

void RoomController::addRoom(const Room& room) {
    roomList.add(room);
    ofstream file("rooms.csv", ios::app); 
    if (!file.is_open())
    {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    file << room.getRoomNumber()
         << "," << room.getRoomType()
         << "," << room.getIsAvailable()
         << "," << room.getRoomPrice()
         << "\n";

    file.close();
    cout << "Room added successfully and saved to rooms.csv!" << endl;
}

void RoomController::bookRoom(int roomNumber) {
    Room* room = roomList.findRoomNumber(roomNumber);
    if (room && room->getIsAvailable()) {
        room->setAvailability(false);
        cout << "Room " << roomNumber << " booked successfully." << endl;
    } else {
        cout << "Room is unavailable." << endl;
    }
}

void RoomController::cancelRoomBooking(int roomNumber) {
    Room* room = roomList.findRoomNumber(roomNumber);
    if (room && !room->getIsAvailable()) {
        room->setAvailability(true);
        cout << "Booking for Room " << roomNumber << " has been canceled." << endl;
    } else {
        cout << "Room is already available." << endl;
    }
}

void RoomController::deleteRoom(int roomNumber) {
    Room* room = roomList.findRoomNumber(roomNumber);
    if (room) {
        roomList.remove(*room);
        cout << "Room " << roomNumber << " has been deleted." << endl;
    } else {
        cout << "Room not found!" << endl;
    }
}
