#include "Contract.h"

Contract::Contract() : contractID(0), tenantID(0), roomNumber(0), startDate(""), endDate(""), status(0) {}

Contract::Contract(int contractID, int tenantID, int roomNumber, string startDate, string endDate, int status)
    : contractID(contractID), tenantID(tenantID), roomNumber(roomNumber), startDate(startDate), endDate(endDate), status(status) {}

int Contract::getContractID() const {
    return contractID;
}

int Contract::getTenantID() const {
    return tenantID;
}

int Contract::getRoomNumber() const {
    return roomNumber;
}

string Contract::getStartDate() const {
    return startDate;
}

string Contract::getEndDate() const {
    return endDate;
}

int Contract::getStatus() const {
    return status;
}

void Contract::setContractID(int contractID) {
    this->contractID = contractID;
}

void Contract::setTenantID(int tenantID) {
    this->tenantID = tenantID;
}

void Contract::setRoomNumber(int roomNumber) {
    this->roomNumber = roomNumber;
}

void Contract::setStartDate(string startDate) {
    this->startDate = startDate;
}

void Contract::setEndDate(string endDate) {
    this->endDate = endDate;
}

void Contract::setStatus(int status) {
    this->status = status;
}

ostream& operator<<(ostream& os, const Contract& contract) {
    os << "Contract ID: " << contract.contractID << "\n"
       << "Tenant ID: " << contract.tenantID << "\n"
       << "Room Number: " << contract.roomNumber << "\n"
       << "Start Date: " << contract.startDate << "\n"
       << "End Date: " << contract.endDate << "\n"
       << "Status: " << (contract.status ? "Active" : "Expired") << "\n";
    return os;
}

istream& operator>>(istream& is, Contract& contract) {
    cout << "Enter Contract ID: ";
    is >> contract.contractID;
    cout << "Enter Tenant ID: ";
    is >> contract.tenantID;
    cout << "Enter Room Number: ";
    is >> contract.roomNumber;

    cout << "Enter Start Date (yyyy-mm-dd): ";
    is >> contract.startDate;

    cout << "Enter End Date (yyyy-mm-dd): ";
    is >> contract.endDate;

    cout << "Enter Status: (1 for Active, 0 for Expired): ";
    is >> contract.status;

    return is;
}

bool Contract::operator==(const Contract& other) const {
    return contractID == other.contractID &&
           tenantID == other.tenantID &&
           roomNumber == other.roomNumber &&
           startDate == other.startDate &&
           endDate == other.endDate &&
           status == other.status;
}

bool Contract::operator!=(const Contract& other) const {
    return !(*this == other);
}

Contract::~Contract() {}
