#include "Invoice.h"
#include "../utils/utils.h"
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

istream& operator>>(istream& in, Invoice& invoice) {
    invoice.roomNumber = inputNumber("Enter Room Number");
    if (invoice.roomNumber <= 0) {
        cout << "Invalid Room Number. Please enter a positive integer." << endl;
        return in;
    }

    invoice.tenantID = inputNumber("Enter Tenant ID");
    if (invoice.tenantID <= 0) {
        cout << "Invalid Tenant ID. Please enter a positive integer." << endl;
        return in;
    }

    invoice.oldElectricIndex = inputNumber("Enter Old Electric Index");
    if (invoice.oldElectricIndex < 0) {
        cout << "Invalid Electric Index. Please enter a non-negative integer." << endl;
        return in;
    }

    invoice.newElectricIndex = inputNumber("Enter New Electric Index");
    if (invoice.newElectricIndex < 0) {
        cout << "Invalid Electric Index. Please enter a non-negative integer." << endl;
        return in;
    }

    invoice.oldWaterIndex = inputNumber("Enter Old Water Index");
    if (invoice.oldWaterIndex < 0) {
        cout << "Invalid Water Index. Please enter a non-negative integer." << endl;
        return in;
    }

    invoice.newWaterIndex = inputNumber("Enter New Water Index");
    if (invoice.newWaterIndex < 0) {
        cout << "Invalid Water Index. Please enter a non-negative integer." << endl;
        return in;
    }

    invoice.surcharge = inputNumber("Enter Surcharge");
    if (invoice.surcharge < 0) {
        cout << "Invalid Surcharge. Please enter a non-negative value." << endl;
        return in;
    }

    invoice.month = inputNumber("Enter Month");
    if (invoice.month < 1 || invoice.month > 12) {
        cout << "Invalid Month. Please enter a value between 1 and 12." << endl;
        return in;
    }

    invoice.year = inputNumber("Enter Year");
    if (invoice.year <= 0) {
        cout << "Invalid Year. Please enter a positive integer." << endl;
        return in;
    }

    while (true) {
        cout << "Is charged? (1: Yes, 0: No): ";
        in >> invoice.isCharged;
        if (in.fail() || (invoice.isCharged != 0 && invoice.isCharged != 1)) {
            cout << "Invalid input. Enter 1 for Yes or 0 for No." << endl;
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }

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