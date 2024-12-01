#ifndef INVOICE_H
#define INVOICE_H

#include <string>
#include <iostream>
using namespace std;

class Invoice {
private:
    int invoiceId;
    int roomNumber;
    int tenantID;
    int oldElectricIndex;
    int newElectricIndex;
    int oldWaterIndex;
    int newWaterIndex;
    double surcharge;
    int month;
    int year;
    double total;
    bool isCharged;

public:
    Invoice();
    Invoice(int roomNumber, int tenantID, int oldElectricIndex, int newElectricIndex, 
            int oldWaterIndex, int newWaterIndex, double surcharge, int month, int year);
    ~Invoice();

    int getInvoiceID() const;
    int getRoomNumber() const;
    int getTenantID() const;
    int getOldElectricIndex() const;
    int getNewElectricIndex() const;
    int getOldWaterIndex() const;
    int getNewWaterIndex() const;
    double getSurcharge() const;
    int getMonth() const;
    int getYear() const;
    double getTotal() const;
    bool getCharged() const;

    void setInvoiceID(int invoiceId);
    void setRoomNumber(int roomNumber);
    void setTenantID(int tenantID);
    void setOldElectricIndex(int oldElectricIndex);
    void setNewElectricIndex(int newElectricIndex);
    void setOldWaterIndex(int oldWaterIndex);
    void setNewWaterIndex(int newWaterIndex);
    void setSurcharge(double surcharge);
    void setMonth(int month);
    void setYear(int year);
    void setCharged(bool isCharged);
    void calculateTotal();

    friend istream &operator>>(istream &in, Invoice &invoice);
    friend ostream &operator<<(ostream &out, const Invoice &invoice);

    bool operator!=(const Invoice& other) const;
    bool operator==(const Invoice& other) const;    
};

#endif // INVOICE_H