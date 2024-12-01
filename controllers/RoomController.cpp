#include "RoomController.h"
#include <fstream>


using namespace std;

RoomController::RoomController(RoomLinkedList& roomList, const RoomView& roomView)
    : roomList(roomList), view(roomView) {}
    
void RoomController::addRoom() {
    Room room; 
    cin >> room; 
    roomList.add(room); 

    ofstream file("rooms.csv", ios::app);
    if (!file.is_open()) {
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


void RoomController::deleteRoom() {
    int roomNumber;
    cout << "Enter room number to delete: ";
    cin >> roomNumber;

    Room* room = roomList.findRoomNumber(roomNumber);
    if (room) {
        roomList.remove(*room);

        ofstream file("rooms.csv");
        if (!file.is_open()) {
            cerr << "Error opening file for writing!" << endl;
            return;
        }

        for (const auto& r : roomList) {
            file << r.getRoomNumber() << ","
                 << r.getRoomType() << ","
                 << r.getIsAvailable() << ","
                 << r.getRoomPrice() << "\n";
        }
        file.close();
        cout << "Room deleted successfully!" << endl;
    } else {
        cout << "Room not found!" << endl;
    }
}

void RoomController::updateRoom() {
    int roomNumber;
    cout << "Enter room number to update: ";
    cin >> roomNumber;

    Room* room = roomList.findRoomNumber(roomNumber);
    if (room) {
        cout << "Current room details:" << endl;
        view.displayRoomDetails(*room);

        cout << "Enter new details for the room:" << endl;
        cin >> *room; 

        ofstream file("rooms.csv");
        if (!file.is_open()) {
            cerr << "Error opening file for writing!" << endl;
            return;
        }

        for (const auto& r : roomList) {
            file << r.getRoomNumber() << ","
                 << r.getRoomType() << ","
                 << r.getIsAvailable() << ","
                 << r.getRoomPrice() << "\n";
        }
        file.close();
        cout << "Room updated successfully!" << endl;
    } else {
        cout << "Room not found!" << endl;
    }
}


void RoomController::searchRoom() {
    int roomNumber;
    cout << "Enter room number to search: ";
    cin >> roomNumber;

    Room* room = roomList.findRoomNumber(roomNumber);
    if (room) {
        view.displayRoomDetails(*room);
    } else {
        cout << "Room not found!" << endl;
    }
}


void RoomController::bookRoom(int roomNumber) {
    Room* room = roomList.findRoomNumber(roomNumber);
    if (room && room->getIsAvailable()) {
        room->setAvailability(false);
        view.displayMessage("Room booked successfully!");
    } else {
        view.displayMessage("Room is unavailable!");
    }
}

void RoomController::cancelRoomBooking(int roomNumber) {
    Room* room = roomList.findRoomNumber(roomNumber);
    if (room && !room->getIsAvailable()) {
        room->setAvailability(true);
        view.displayMessage("Booking canceled successfully!");
    } else {
        view.displayMessage("Room is already available!");
    }
}

void RoomController::roomStatistics() {
    cout << "---------------------------- Room Statistics ----------------------------" << endl;
    cout << "| Room Number | Room Type | Status     | Room Price |" << endl;
    cout << "--------------------------------------------------------------------------" << endl;

    for (const auto& room : roomList) {
        cout << "| " << room.getRoomNumber() << "        | " << room.getRoomType()
             << "         | " << (room.getIsAvailable() ? "Available" : "Booked")
             << "   | " << room.getRoomPrice() << "       |" << endl;
    }

    cout << "--------------------------------------------------------------------------" << endl;
}

void RoomController::execute() {
    // Placeholder for additional functionality.
}
