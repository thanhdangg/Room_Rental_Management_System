#ifndef ROOMCONTROLLER_H
#define ROOMCONTROLLER_H

#include "BaseController.h"
#include "../models/Room.h"
#include "../views/RoomView.h"

class RoomController : public BaseController {
private:
    Room model;
    RoomView view;

public:
    RoomController(const Room& roomModel, const RoomView& roomView) : model(roomModel), view(roomView) {}

    void addRoom(const Room& newRoom) {
        if (model.add(newRoom)) {
            view.displayMessage("Thêm phòng thành công!");
        } else {
            view.displayMessage("Thêm phòng thất bại.");
        }
    }

    void deleteRoom(int roomNumber) {
        if (model.remove(roomNumber)) {
            view.displayMessage("Xóa phòng thành công!");
        } else {
            view.displayMessage("Không tìm thấy phòng để xóa.");
        }
    }

    void updateRoom(const Room& updatedRoom) {
        if (model.update(updatedRoom)) {
            view.displayMessage("Cập nhật thông tin phòng thành công!");
        } else {
            view.displayMessage("Không thể cập nhật thông tin phòng.");
        }
    }

    void searchRoom(int roomNumber) {
        Room* foundRoom = model.find(roomNumber);
        if (foundRoom) {
            view.displayRoomDetails(*foundRoom);
        } else {
            view.displayMessage("Không tìm thấy phòng.");
        }
    }

    void execute() override {
        
    }
    void roomStatistics() {
        cout << "---------------------------- Room Statistics ----------------------------" << endl;
        cout << "| Room ID | Room Number | Status    | Tenant ID | Contract ID |" << endl;
        cout << "--------------------------------------------------------" << endl;

        for (const auto& room : rooms) {
            cout << "| " << room.getRoomID() << "      | " << room.getRoomNumber() << "        | " << room.getStatus() 
                 << "      | " << room.getTenantID() << "        | " << room.getContractID() << "        |" << endl;
        }

        cout << "-------------------------------------------------------------------------" << endl;
    }
};

#endif // ROOMCONTROLLER_H
