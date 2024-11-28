#include <iostream>
#include <fstream>  
#include "InvoiceController.h"

using namespace std;

InvoiceController::InvoiceController(LinkedList<Invoice>& invoiceList) : invoiceList(invoiceList) {}

void InvoiceController::addInvoice() {
    Invoice invoice;
    cin >> invoice;  

    invoiceList.add(invoice); 

    ofstream file("invoices.csv", ios::app);
    if (!file.is_open()) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    file << invoice.getRoomNumber() << "," 
         << invoice.getTenantID() << "," 
         << invoice.getOldElectricIndex() << "," 
         << invoice.getNewElectricIndex() << "," 
         << invoice.getOldWaterIndex() << "," 
         << invoice.getNewWaterIndex() << "," 
         << invoice.getSurcharge() << "," 
         << invoice.getMonth() << "," 
         << invoice.getYear() << ","
         << invoice.getTotal() << "\n";

    file.close();  
    cout << "Invoice added successfully and saved to invoices.csv!" << endl;
}

void InvoiceController::displayInvoiceDetails() const {
    InvoiceView::displayAllInvoices(invoiceList);  
}

void InvoiceController::displayInvoicesByMonth(int month, int year, int roomNumber) const {
    for (auto it = invoiceList.begin(); it != invoiceList.end(); ++it) {
        if (it->getMonth() == month && it->getYear() == year && it->getRoomNumber() == roomNumber) {
            cout << *it << endl;
        }
    }
}


void InvoiceController::editInvoice() {
    int roomNumber;
    cout << "Enter room number to edit: ";
    cin >> roomNumber;

    for (auto it = invoiceList.begin(); it != invoiceList.end(); ++it) {
        if (it->getRoomNumber() == roomNumber) {
            InvoiceView::displayInvoiceDetails(*it);  
            cout << "Enter new details: " << endl;
            cin >> *it;
            cout << "Invoice updated successfully!" << endl;
            break;
        }
    }
}

void InvoiceController::deleteInvoice() {
    int roomNumber;
    cout << "Enter room number to delete: ";
    cin >> roomNumber;

    for (auto it = invoiceList.begin(); it != invoiceList.end(); ++it) {
        if (it->getRoomNumber() == roomNumber) {
            invoiceList.remove(*it);
            cout << "Invoice deleted successfully!" << endl;
            break;
        }
    }
}
