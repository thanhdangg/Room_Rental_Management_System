#include "Contract.h"

Contract::Contract(int contractID, int tenantID, int roomNumber, time_t startDate, time_t endDate, const std::string& status)
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

time_t Contract::getStartDate() const {
    return startDate;
}

time_t Contract::getEndDate() const {
    return endDate;
}

std::string Contract::getStatus() const {
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

void Contract::setStartDate(time_t startDate) {
    this->startDate = startDate;
}

void Contract::setEndDate(time_t endDate) {
    this->endDate = endDate;
}

void Contract::setStatus(const std::string& status) {
    this->status = status;
}

std::ostream& operator<<(std::ostream& os, const Contract& contract) {
    os << "Contract ID: " << contract.contractID << "\n"
       << "Tenant ID: " << contract.tenantID << "\n"
       << "Room Number: " << contract.roomNumber << "\n"
       << "Start Date: " << ctime(&contract.startDate)
       << "End Date: " << ctime(&contract.endDate)
       << "Status: " << contract.status << "\n";
    return os;
}

std::istream& operator>>(std::istream& is, Contract& contract) {
    std::cout << "Enter Contract ID: ";
    is >> contract.contractID;
    std::cout << "Enter Tenant ID: ";
    is >> contract.tenantID;
    std::cout << "Enter Room Number: ";
    is >> contract.roomNumber;

    std::cout << "Enter Start Date (as timestamp): ";
    is >> contract.startDate;

    std::cout << "Enter End Date (as timestamp): ";
    is >> contract.endDate;

    std::cout << "Enter Status: ";
    is.ignore(); 
    std::getline(is, contract.status);

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
