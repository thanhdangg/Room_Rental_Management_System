#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <iostream>

using namespace std;

class Room
{
private:
    int roomNumber;
    int roomType;
    bool isAvailable;
    double roomPrice;

public:
    Room();
    ~Room();
    Room(int roomNumber, int roomType, bool isAvailable, double roomPrice);

    int getRoomNumber() const;
    int getRoomType() const;
    bool getIsAvailable() const;
    double getRoomPrice() const;

    void setRoomNumber(int roomNumber);
    void setRoomType(int roomType);
    void setAvailability(bool isAvailable);
    void setRoomPrice(double roomPrice);

    friend istream &operator>>(istream &in, Room &room);
    friend ostream &operator<<(ostream &out,const Room &room);

    bool operator!=(const Room& other) const;
    bool operator==(const Room& other) const;
};

#endif // ROOM_H
