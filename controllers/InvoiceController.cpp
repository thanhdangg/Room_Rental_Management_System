#include "InvoiceController.h"


using namespace std;

InvoiceController::InvoiceController(LinkedList<Invoice> &invoices, const InvoiceView &invoiceView)
    : invoiceList(invoices), view(invoiceView) {}

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
    view.displayAllInvoices(invoiceList);
}

void InvoiceController::displayInvoicesByMonth(int month, int year, int roomNumber) const {
    for (const auto &invoice : invoiceList) {
        if (invoice.getMonth() == month && invoice.getYear() == year && invoice.getRoomNumber() == roomNumber) {
            view.displayInvoiceDetails(invoice);
        }
    }
}

void InvoiceController::editInvoice() {
    int roomNumber;
    cout << "Enter room number to edit: ";
    cin >> roomNumber;

    for (auto &invoice : invoiceList) {
        if (invoice.getRoomNumber() == roomNumber) {
            view.displayInvoiceDetails(invoice);
            cout << "Enter new details: " << endl;
            cin >> invoice;
            cout << "Invoice updated successfully!" << endl;
            return;
        }
    }
    cout << "Invoice not found for room number " << roomNumber << "!" << endl;
}

void InvoiceController::deleteInvoice() {
    int roomNumber;
    cout << "Enter room number to delete: ";
    cin >> roomNumber;

    for (auto it = invoiceList.begin(); it != invoiceList.end(); ++it) {
        if (it->getRoomNumber() == roomNumber) {
            invoiceList.remove(*it);
            cout << "Invoice deleted successfully!" << endl;
            return;
        }
    }
    cout << "Invoice not found for room number " << roomNumber << "!" << endl;
}

void InvoiceController::markInvoiceAsPaid() {
    int invoiceId;
    cout << "Enter Invoice ID to mark as paid: ";
    cin >> invoiceId;

    for (auto &invoice : invoiceList) {
        if (invoice.getInvoiceID() == invoiceId) {
            if (!invoice.getCharged()) {
                invoice.setCharged(true);
                cout << "Invoice ID " << invoiceId << " marked as Paid successfully!" << endl;
            } else {
                cout << "Invoice ID " << invoiceId << " is already Paid!" << endl;
            }
            return;
        }
    }
    cout << "Invoice with ID " << invoiceId << " not found!" << endl;
}

void InvoiceController::searchInvoice() {
    int invoiceId;
    cout << "Enter Invoice ID to search: ";
    cin >> invoiceId;
    for (const auto &invoice : invoiceList) {
        if (invoice.getInvoiceID() == invoiceId) {
            InvoiceView::displayInvoiceDetails(invoice);
            return;
        }
    }
    cout << "Invoice with ID " << invoiceId << " not found!" << endl;
}

void InvoiceController::invoiceStatistics() const {
    cout << "--------------------------- Invoice Statistics ----------------------------" << endl;
    
    cout << left 
         << setw(15) << "| Invoice ID" 
         << setw(15) << "| Room Number" 
         << setw(15) << "| Tenant ID" 
         << setw(20) << "| Old Electric Index" 
         << setw(20) << "| New Electric Index" 
         << setw(20) << "| Old Water Index" 
         << setw(20) << "| New Water Index" 
         << setw(15) << "| Surcharge" 
         << setw(10) << "| Month" 
         << setw(10) << "| Year" 
         << setw(15) << "| Total" 
         << setw(15) << "| Charged" 
         << "|" << endl;
    
    cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
    
    for (const auto &invoice : invoiceList) {
        cout << left 
             << setw(15) << "| " << invoice.getInvoiceID() 
             << setw(15) << "| " << invoice.getRoomNumber() 
             << setw(15) << "| " << invoice.getTenantID() 
             << setw(20) << "| " << invoice.getOldElectricIndex() 
             << setw(20) << "| " << invoice.getNewElectricIndex() 
             << setw(20) << "| " << invoice.getOldWaterIndex() 
             << setw(20) << "| " << invoice.getNewWaterIndex() 
             << setw(15) << "| " << invoice.getSurcharge() 
             << setw(10) << "| " << invoice.getMonth() 
             << setw(10) << "| " << invoice.getYear() 
             << setw(15) << "| " << invoice.getTotal() 
             << setw(15) << "| " << (invoice.getCharged() ? "Paid" : "Unpaid")
             << "|" << endl;
    }

    cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
}

void InvoiceController::revenueStatistics() const {
    double totalRevenue = 0.0;

    for (const auto &invoice : invoiceList) {
        if (invoice.getCharged()) {
            totalRevenue += invoice.getTotal();
        }
    }

    cout << "------------------------- Revenue Statistics ----------------------------" << endl;
    cout << "Total Revenue: " << totalRevenue << endl;
    cout << "-------------------------------------------------------------------------" << endl;
}

void InvoiceController::execute() {
    // Implementation of execute method
}