#include "Invoice.h"

Invoice::Invoice() : roomNumber(0), tenantID(0), oldElectricIndex(0), newElectricIndex(0), 
               oldWaterIndex(0), newWaterIndex(0), surcharge(0), month(0), year(0), total(0) {}

Invoice::Invoice(int roomNumber, int tenantID, int oldElectricIndex, int newElectricIndex, 
           int oldWaterIndex, int newWaterIndex, double surcharge, int month, int year)
    : roomNumber(roomNumber), tenantID(tenantID), oldElectricIndex(oldElectricIndex), 
      newElectricIndex(newElectricIndex), oldWaterIndex(oldWaterIndex), newWaterIndex(newWaterIndex), 
      surcharge(surcharge), month(month), year(year) {
    calculateTotal();
}

Invoice::~Invoice() {}

int Invoice::getRoomNumber() const {
    return roomNumber;
}

int Invoice::getTenantID() const {
    return tenantID;
}

int Invoice::getOldElectricIndex() const {
    return oldElectricIndex;
}

int Invoice::getNewElectricIndex() const {
    return newElectricIndex;
}

int Invoice::getOldWaterIndex() const {
    return oldWaterIndex;
}

int Invoice::getNewWaterIndex() const {
    return newWaterIndex;
}

double Invoice::getSurcharge() const {
    return surcharge;
}

int Invoice::getMonth() const {
    return month;
}

int Invoice::getYear() const {
    return year;
}

double Invoice::getTotal() const {
    return total;
}

void Invoice::setRoomNumber(int roomNumber) {
    this->roomNumber = roomNumber;
}

void Invoice::setTenantID(int tenantID) {
    this->tenantID = tenantID;
}

void Invoice::setOldElectricIndex(int oldElectricIndex) {
    this->oldElectricIndex = oldElectricIndex;
}

void Invoice::setNewElectricIndex(int newElectricIndex) {
    this->newElectricIndex = newElectricIndex;
    calculateTotal();
}

void Invoice::setOldWaterIndex(int oldWaterIndex) {
    this->oldWaterIndex = oldWaterIndex;
}

void Invoice::setNewWaterIndex(int newWaterIndex) {
    this->newWaterIndex = newWaterIndex;
    calculateTotal();
}

void Invoice::setSurcharge(double surcharge) {
    this->surcharge = surcharge;
    calculateTotal();
}

void Invoice::setMonth(int month) {
    this->month = month;
}

void Invoice::setYear(int year) {
    this->year = year;
}

void Invoice::calculateTotal() {
    double electricCost = (newElectricIndex - oldElectricIndex) * 3.5; 
    double waterCost = (newWaterIndex - oldWaterIndex) * 7; 
    total = electricCost + waterCost + surcharge;
}
bool Invoice::operator!=(const Invoice& other) const {
    return roomNumber != other.roomNumber || month != other.month || year != other.year;
}

istream &operator>>(istream &in, Invoice &invoice){
    cout << "Enter room number: ";
    in >> invoice.roomNumber;
    cout << "Enter tenant ID: ";
    in >> invoice.tenantID;
    cout << "Enter old electric index: ";
    in >> invoice.oldElectricIndex;
    cout << "Enter new electric index: ";
    in >> invoice.newElectricIndex;
    cout << "Enter old water index: ";
    in >> invoice.oldWaterIndex;
    cout << "Enter new water index: ";
    in >> invoice.newWaterIndex;
    cout << "Enter surcharge: ";
    in >> invoice.surcharge;
    cout << "Enter month: ";
    in >> invoice.month;
    cout << "Enter year: ";
    in >> invoice.year;
    invoice.calculateTotal();
    return in;
}

ostream &operator<<(ostream &out, const Invoice &invoice) {
    out << "Room Number: " << invoice.roomNumber << endl;
    out << "Tenant ID: " << invoice.tenantID << endl;
    out << "Old Electric Index: " << invoice.oldElectricIndex << endl;
    out << "New Electric Index: " << invoice.newElectricIndex << endl;
    out << "Old Water Index: " << invoice.oldWaterIndex << endl;
    out << "New Water Index: " << invoice.newWaterIndex << endl;
    out << "Surcharge: " << invoice.surcharge << endl;
    out << "Month: " << invoice.month << endl;
    out << "Year: " << invoice.year << endl;
    out << "Total: " << invoice.total << endl;
    return out;
}
