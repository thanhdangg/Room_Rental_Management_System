#include "RoomController.h"
#include <fstream>

using namespace std;

RoomController::RoomController(RoomLinkedList &roomList, const RoomView &roomView)
    : roomList(roomList), view(roomView) {}

void RoomController::addRoom()
{
    Room room;
    cin >> room;
    roomList.add(room);

    ofstream file("data/rooms.csv", ios::app);
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
    view.displayMessage("Room added successfully and saved to rooms.csv!");
}

void RoomController::deleteRoom()
{
    int roomNumber;
    cout << "Enter room number to delete: ";
    cin >> roomNumber;

    Room *room = roomList.findRoomNumber(roomNumber);
    if (room)
    {
        roomList.remove(*room);
        updateCSV();
        cout << "Room deleted successfully!" << endl;
    }
    else
    {
        cout << "Room not found!" << endl;
    }
}

void RoomController::updateRoom()
{
    int roomNumber;
    cout << "Enter room number to update: ";
    cin >> roomNumber;
    bool found = false;

    for (auto &room : roomList)
    {
        if (room.getRoomNumber() == roomNumber)
        {
            cout << "Current room details:" << endl;
            view.displayRoomDetails(room);

            cout << "Enter new details for the room:" << endl;
            cout << "Enter room type: (1 for small room , 2 for medium room, or 3 large room): ";
            int roomType;
            cin >> roomType;
            room.setRoomType(roomType);
            cout << "Enter room availability (true for available, false for unavailable): ";
            bool isAvailable;
            cin >> isAvailable;
            room.setAvailability(isAvailable);
            cout << "Enter room price: ";
            double roomPrice;
            cin >> roomPrice;
            room.setRoomPrice(roomPrice);

            found = true;
            updateCSV();
            cout << "Room updated successfully!" << endl;
        }
    }
    if (!found)
    {
        cout << "Room not found!" << endl;
    }
}

void RoomController::searchRoom(int roomNumber)
{
    Room *room = roomList.findRoomNumber(roomNumber);
    if (room)
    {
        view.displayRoomDetails(*room);
    }
    else
    {
        cout << "Room not found!" << endl;
    }
}

void RoomController::bookRoom(int roomNumber)
{
    Room *room = roomList.findRoomNumber(roomNumber);
    if (room && room->getIsAvailable())
    {
        room->setAvailability(false);
        updateCSV();
        view.displayMessage("Room booked successfully!");
    }
    else
    {
        view.displayMessage("Room is unavailable!");
    }
}

void RoomController::cancelRoomBooking(int roomNumber)
{
    Room *room = roomList.findRoomNumber(roomNumber);
    if (room && !room->getIsAvailable())
    {
        room->setAvailability(true);
        updateCSV();
        view.displayMessage("Booking canceled successfully!");
    }
    else
    {
        view.displayMessage("Room is already available!");
    }
}

void RoomController::roomStatistics()
{
    cout << "---------------------------- Room Statistics ----------------------------" << endl;
    cout << left
         << "| " << setw(15) << "Room Number"
         << "| " << setw(15) << "Room Type"
         << "| " << setw(15) << "Status"
         << "| " << setw(15) << "Room Price"
         << "|" << endl;

    for (const auto &room : roomList)
    {
        cout << left
             << "| " << setw(15) << room.getRoomNumber()
             << "| " << setw(15) << (room.getRoomType() == 1 ? "Small room " : room.getRoomType() == 2 ? "Medium room "
                                                                                                       : "Large room ")
             << "| " << setw(15) << (room.getIsAvailable() ? "Available" : "Booked")
             << "| " << setw(15) << room.getRoomPrice()
             << "|" << endl;
    }
}

void RoomController::updateCSV()
{
    ofstream file("data/rooms.csv", ios::out);
    if (!file.is_open())
    {
        cerr << "Error opening file for writing!" << endl;
        return;
    }
    file << "roomNumber,roomType,isAvailable,roomPrice\n";
    for (const auto &r : roomList)
    {
        file << r.getRoomNumber() << ","
             << r.getRoomType() << ","
             << r.getIsAvailable() << ","
             << r.getRoomPrice() << "\n";
    }
    file.close();
}