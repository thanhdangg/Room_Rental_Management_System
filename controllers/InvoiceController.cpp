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
    cout << "| Invoice ID | Tenant ID | Amount  | Due Date   | Status    |" << endl;
    cout << "-------------------------------------------------------------------------" << endl;

    for (const auto &invoice : invoiceList) {
        cout << "| " << invoice.getInvoiceID() << "         | " << invoice.getTenantID() << "        | "
             << invoice.getTotal() << "       | " << invoice.getMonth() << "/" << invoice.getYear() << "      | "
             << (invoice.getCharged() ? "Paid" : "Unpaid") << "      |" << endl;
    }

    cout << "-------------------------------------------------------------------------" << endl;
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