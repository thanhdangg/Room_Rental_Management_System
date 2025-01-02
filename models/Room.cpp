#include "Room.h"
#include "../utils/utils.h"
using namespace std;
Room::Room() {}

Room::~Room() {}

Room::Room(int roomNumber, int roomType, bool isAvailable, double roomPrice)
{
    this->roomNumber = roomNumber;
    this->roomType = roomType;
    this->isAvailable = isAvailable;
    this->roomPrice = roomPrice;
}

int Room::getRoomNumber() const { return this->roomNumber; }
int Room::getRoomType() const { return this->roomType; }
bool Room::getIsAvailable() const { return this->isAvailable; }
double Room::getRoomPrice() const { return this->roomPrice; }

void Room::setRoomNumber(int roomNumber) { this->roomNumber = roomNumber; }
void Room::setRoomType(int roomType) { this->roomType = roomType; }
void Room::setAvailability(bool isAvailable) { this->isAvailable = isAvailable; }
void Room::setRoomPrice(double roomPrice) { this->roomPrice = roomPrice; }

istream &operator>>(istream &in, Room &room)
{
    room.roomNumber = inputNumber("Enter Room Number");
    if (room.roomNumber <= 0) {
        cout << "Invalid room number. Please enter a positive integer." << endl;
        return in;
    }

    room.roomType = inputRoomType();

    room.isAvailable = inputBool("Enter Room Status (1 for available, 0 for unavailable)");

    room.roomPrice = inputDouble("Enter Room Price");
    if (room.roomPrice < 0) {
        cout << "Invalid price. Please enter a non-negative value." << endl;
        return in;
    }

    return in;
}

ostream &operator<<(ostream &out, const Room &room)
{
    out << "Information for Room: " << endl;
    out << "Room Number: " << room.roomNumber << endl;
    out << "Room Type: ";
    switch (room.roomType)
    {
    case 1:
        out << "Small Room" << endl;
        break;
    case 2:
        out << "Medium Room" << endl;
        break;
    case 3:
        out << "Large Room" << endl;
        break;
    }
    out << "Room Status: " << (room.isAvailable ? "Available" : "Unavailable") << endl;
    out << "Room Price: " << room.roomPrice << endl;
    return out;
}

bool Room::operator==(const Room& other) const {
    return roomNumber == other.roomNumber &&
           roomType == other.roomType &&
           isAvailable == other.isAvailable &&
           roomPrice == other.roomPrice;
}

bool Room::operator!=(const Room& other) const {
    return !(*this == other);
}
