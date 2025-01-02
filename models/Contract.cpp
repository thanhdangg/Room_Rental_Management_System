#include "Contract.h"
#include "../utils/utils.h"

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

istream& operator>>(istream& is, Contract& contract)
{
    contract.tenantID = inputNumber("Enter Tenant ID");
    if (contract.tenantID <= 0) {
        cout << "Invalid Tenant ID. Please enter a positive integer." << endl;
        return is;
    }

    contract.roomNumber = inputNumber("Enter Room Number");
    if (contract.roomNumber <= 0) {
        cout << "Invalid Room Number. Please enter a positive integer." << endl;
        return is;
    }

    cout << "Enter Start Date (yyyy-mm-dd): ";
    while (!(is >> contract.startDate) || !isValidDate(contract.startDate)) {
        cout << "Invalid Start Date. Please enter a date in the format yyyy-mm-dd: ";
        is.clear();
        is.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter End Date (yyyy-mm-dd): ";
    while (!(is >> contract.endDate) || !isValidDate(contract.endDate)) {
        cout << "Invalid End Date. Please enter a date in the format yyyy-mm-dd: ";
        is.clear();
        is.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    contract.status = inputBool("Enter Status (1 for Active, 0 for Expired)");

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
