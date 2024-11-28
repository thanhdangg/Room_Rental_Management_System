#include <iostream>

#include "../data_structures/LinkedList.h"
#include "../models/Room.h"
#include "RoomView.h"

using namespace std;

void RoomView::displayRoomDetails(const Room &room)
{
    cout << "Room Number: " << room.getRoomNumber() << endl;
    cout << "Price: " << room.getRoomPrice() << endl;
    cout << "Available: " << (room.getIsAvailable() ? "Yes" : "No") << endl;
    cout << "Type: ";
    if (room.getRoomType() == 1)
        cout << "Single" << endl;
    else if (room.getRoomType() == 2)
        cout << "Double" << endl;
    else if (room.getRoomType() == 3)
        cout << "Suite" << endl;
    else
        cout << "Invalid" << endl;
}
