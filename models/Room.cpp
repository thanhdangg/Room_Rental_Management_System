#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <iostream>

using namespace std;

class Room
{
private:
    string roomNumber;
    string roomType;
    string roomStatus;
    double roomPrice;

public:
    Room();
    ~Room();
    Room(string roomNumber, string roomType, string roomStatus, double roomPrice);
    string getRoomNumber();
    string getRoomType();
    string getRoomStatus();
    double getRoomPrice();
    void setRoomNumber(string roomNumber);
    void setRoomType(string roomType);
    void setRoomStatus(string roomStatus);
    void setRoomPrice(double roomPrice);
    
    friend istream &operator>>(istream &in, Room &room);
    friend ostream &operator<<(ostream &out, Room &room);
};

Room::Room()
{
}

Room::~Room()
{
}

Room::Room(string roomNumber, string roomType, string roomStatus, double roomPrice)
{
    this->roomNumber = roomNumber;
    this->roomType = roomType;
    this->roomStatus = roomStatus;
    this->roomPrice = roomPrice;
}

string Room::getRoomNumber()
{
    return this->roomNumber;
}

string Room::getRoomType()
{
    return this->roomType;
}

string Room::getRoomStatus()
{
    return this->roomStatus;
}

double Room::getRoomPrice()
{
    return this->roomPrice;
}

void Room::setRoomNumber(string roomNumber)
{
    this->roomNumber = roomNumber;
}

void Room::setRoomType(string roomType)
{
    this->roomType = roomType;
}

void Room::setRoomStatus(string roomStatus)
{
    this->roomStatus = roomStatus;
}

void Room::setRoomPrice(double roomPrice)
{
    this->roomPrice = roomPrice;
}

istream &operator>>(istream &in, Room &room)
{
    cout << "Enter Information for Room: " << endl;
    cout << "Enter Room Number: ";
    getline(in , room.roomNumber);
    cout << "Enter Room Type: ";
    getline(in, room.roomType);
    cout << "Enter Room Status: ";
    getline(in, room.roomStatus);
    cout << "Enter Room Price: ";
    in >> room.roomPrice;
    return in;
}

ostream &operator<<(ostream &out, Room &room)
{
    out << "Information for Room: " << endl;
    out << "Room Number: " << room.roomNumber << endl;
    out << "Room Type: " << room.roomType << endl;
    out << "Room Status: " << room.roomStatus << endl;
    out << "Room Price: " << room.roomPrice << endl;
    return out;
}


#endif // ROOM_H