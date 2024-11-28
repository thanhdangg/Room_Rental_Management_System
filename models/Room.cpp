#include "Room.h"
#include <limits>
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
    cout << "Enter Room Number: ";
    while (!(in >> room.roomNumber) || room.roomNumber < 0)
    {
        cout << "Invalid room number. Please enter a non-negative value: ";
        in.clear();
        in.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter Room Type (1, 2, or 3): ";
    while (!(in >> room.roomType) || (room.roomType < 1 || room.roomType > 3))
    {
        cout << "Invalid room type. Please enter a value (1, 2, or 3): ";
        in.clear();
        in.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter Room Status (1 for available, 0 for unavailable): ";
    while (!(in >> room.isAvailable) || (room.isAvailable != 0 && room.isAvailable != 1))
    {
        cout << "Invalid status. Enter 1 for available or 0 for unavailable: ";
        in.clear();
        in.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter Room Price: ";
    while (!(in >> room.roomPrice) || room.roomPrice < 0)
    {
        cout << "Invalid price. Please enter a non-negative value: ";
        in.clear();
        in.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return in;
}

ostream &operator<<(ostream &out, const Room &room)
{
    out << "Information for Room: " << endl;
    out << "Room Number: " << room.roomNumber << endl;
    out << "Room Type: " << room.roomType << endl;
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
