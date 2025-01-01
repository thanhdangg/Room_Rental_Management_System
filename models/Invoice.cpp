#include "Invoice.h"

Invoice::Invoice() : invoiceId(0), roomNumber(0), tenantID(0), oldElectricIndex(0), newElectricIndex(0),
                     oldWaterIndex(0), newWaterIndex(0), surcharge(0.0), month(0), year(0), total(0.0), isCharged(false) {}

Invoice::Invoice(int roomNumber, int tenantID, int oldElectricIndex, int newElectricIndex,
                 int oldWaterIndex, int newWaterIndex, double surcharge, int month, int year)
    : roomNumber(roomNumber), tenantID(tenantID), oldElectricIndex(oldElectricIndex), 
      newElectricIndex(newElectricIndex), oldWaterIndex(oldWaterIndex), 
      newWaterIndex(newWaterIndex), surcharge(surcharge), month(month), year(year), 
      isCharged(false), total(0.0), invoiceId(0) {
    calculateTotal(); 
}


Invoice::~Invoice() {}

int Invoice::getInvoiceID() const {
    return invoiceId;
}

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

bool Invoice::getCharged() const {
    return isCharged;
}

void Invoice::setInvoiceID(int invoiceId) {
    this->invoiceId = invoiceId;
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
}

void Invoice::setOldWaterIndex(int oldWaterIndex) {
    this->oldWaterIndex = oldWaterIndex;
}

void Invoice::setNewWaterIndex(int newWaterIndex) {
    this->newWaterIndex = newWaterIndex;
}

void Invoice::setSurcharge(double surcharge) {
    this->surcharge = surcharge;
}

void Invoice::setMonth(int month) {
    this->month = month;
}

void Invoice::setYear(int year) {
    this->year = year;
}

void Invoice::setCharged(bool isCharged) {
    this->isCharged = isCharged;
}

void Invoice::calculateTotal() {
    total = (newElectricIndex - oldElectricIndex) * 3.5 + (newWaterIndex - oldWaterIndex) * 7 + surcharge;
}

istream &operator>>(istream &in, Invoice &invoice) {
    cout << "Enter Room Number: ";
    in >> invoice.roomNumber;
    cout << "Enter Tenant ID: ";
    in >> invoice.tenantID;
    cout << "Enter Old Electric Index: ";
    in >> invoice.oldElectricIndex;
    cout << "Enter New Electric Index: ";
    in >> invoice.newElectricIndex;
    cout << "Enter Old Water Index: ";
    in >> invoice.oldWaterIndex;
    cout << "Enter New Water Index: ";
    in >> invoice.newWaterIndex;
    cout << "Enter Surcharge: ";
    in >> invoice.surcharge;
    cout << "Enter Month: ";
    in >> invoice.month;
    cout << "Enter Year: ";
    in >> invoice.year;
    cout << "Is charged? (1: Yes, 0: No): ";
    in >> invoice.isCharged;
    
    invoice.calculateTotal();
    return in;
}

ostream &operator<<(ostream &out, const Invoice &invoice) {
    out << "Invoice ID: " << invoice.invoiceId << "\n"
        << "Room Number: " << invoice.roomNumber << "\n"
        << "Tenant ID: " << invoice.tenantID << "\n"
        << "Old Electric Index: " << invoice.oldElectricIndex << "\n"
        << "New Electric Index: " << invoice.newElectricIndex << "\n"
        << "Old Water Index: " << invoice.oldWaterIndex << "\n"
        << "New Water Index: " << invoice.newWaterIndex << "\n"
        << "Surcharge: " << invoice.surcharge << "\n"
        << "Month: " << invoice.month << "\n"
        << "Year: " << invoice.year << "\n"
        << "Total: " << invoice.total << "\n"
        << "Charged: " << (invoice.isCharged ? "Yes" : "No") << "\n";
    return out;
}

bool Invoice::operator!=(const Invoice& other) const {
    return invoiceId != other.invoiceId || roomNumber != other.roomNumber || tenantID != other.tenantID ||
           oldElectricIndex != other.oldElectricIndex || newElectricIndex != other.newElectricIndex ||
           oldWaterIndex != other.oldWaterIndex || newWaterIndex != other.newWaterIndex ||
           surcharge != other.surcharge || month != other.month || year != other.year || total != other.total ||
           isCharged != other.isCharged;
}

bool Invoice::operator==(const Invoice& other) const {
    return !(*this != other);
}