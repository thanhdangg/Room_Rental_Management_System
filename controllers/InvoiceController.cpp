#include "InvoiceController.h"

using namespace std;

InvoiceController::InvoiceController(LinkedList<Invoice> &invoices, const InvoiceView &invoiceView)
    : invoiceList(invoices), view(invoiceView) {}

void InvoiceController::addInvoice()
{
    Invoice invoice;
    cin >> invoice;

    int newInvoiceId = 1;
    if (invoiceList.size() != 0)
    {
        Invoice lastInvoice = invoiceList.back();

        newInvoiceId = lastInvoice.getInvoiceID() + 1;
    }
    invoice.setInvoiceID(newInvoiceId);

    invoiceList.add(invoice);

    ofstream file("data/invoices.csv", ios::app);
    if (!file.is_open())
    {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    file << invoice.getInvoiceID() << ","
         << invoice.getRoomNumber() << ","
         << invoice.getTenantID() << ","
         << invoice.getOldElectricIndex() << ","
         << invoice.getNewElectricIndex() << ","
         << invoice.getOldWaterIndex() << ","
         << invoice.getNewWaterIndex() << ","
         << invoice.getSurcharge() << ","
         << invoice.getMonth() << ","
         << invoice.getYear() << ","
         << invoice.getTotal() << ","
         << (invoice.getCharged() ? "true" : "false") << "\n";

    file.close();
    cout << "Invoice added successfully and saved to invoices.csv!" << endl;
}

void InvoiceController::displayInvoiceDetails() const
{
    view.displayAllInvoices(invoiceList);
}

void InvoiceController::displayInvoicesByMonth(int month, int year, int roomNumber) const
{
    for (const auto &invoice : invoiceList)
    {
        if (invoice.getMonth() == month && invoice.getYear() == year && invoice.getRoomNumber() == roomNumber)
        {
            view.displayInvoiceDetails(invoice);
        }
    }
}

void InvoiceController::displayInvoicesByTenant(int tenantID) const
{
    cout << left
         << "| " << setw(15) << "Invoice ID"
         << "| " << setw(15) << "Room Number"
         << "| " << setw(20) << "Old Electric Index"
         << "| " << setw(20) << "New Electric Index"
         << "| " << setw(20) << "Old Water Index"
         << "| " << setw(20) << "New Water Index"
         << "| " << setw(15) << "Surcharge"
         << "| " << setw(10) << "Month"
         << "| " << setw(10) << "Year"
         << "| " << setw(15) << "Total"
         << "| " << setw(15) << "Charged"
         << "|" << endl;

    for (const auto &invoice : invoiceList)
    {
        if (invoice.getTenantID() == tenantID)
        {
            cout << left
                 << "| " << setw(15) << invoice.getInvoiceID()
                 << "| " << setw(15) << invoice.getRoomNumber()
                 << "| " << setw(20) << invoice.getOldElectricIndex()
                 << "| " << setw(20) << invoice.getNewElectricIndex()
                 << "| " << setw(20) << invoice.getOldWaterIndex()
                 << "| " << setw(20) << invoice.getNewWaterIndex()
                 << "| " << setw(15) << invoice.getSurcharge()
                 << "| " << setw(10) << invoice.getMonth()
                 << "| " << setw(10) << invoice.getYear()
                 << "| " << setw(15) << invoice.getTotal()
                 << "| " << setw(15) << (invoice.getCharged() ? "Paid" : "Unpaid")
                 << "|" << endl;
        }
    }
}

void InvoiceController::editInvoice()
{
    int roomNumber;
    cout << "Enter room number to edit: ";
    cin >> roomNumber;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid room number." << endl;
        return;
    }

    for (auto &invoice : invoiceList)
    {
        if (invoice.getRoomNumber() == roomNumber)
        {
            view.displayInvoiceDetails(invoice);
            cout << "Enter new details: " << endl;
            cin >> invoice;

            updateCSV();
            cout << "Invoice updated successfully!" << endl;

            return;
        }
    }
    cout << "Invoice not found for room number " << roomNumber << "!" << endl;
}

void InvoiceController::deleteInvoice()
{
    int roomNumber, month, year;
    cout << "Enter room number to delete: ";
    cin >> roomNumber;
    cout << "Enter month to delete: ";
    cin >> month;
    cout << "Enter year to delete: ";
    cin >> year;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid room number." << endl;
        return;
    }
    bool found = false;

    for (auto it = invoiceList.begin(); it != invoiceList.end(); ++it)
    {
        if (it->getRoomNumber() == roomNumber && it->getMonth() == month && it->getYear() == year)
        {
            invoiceList.remove(*it);
            updateCSV();
            cout << "Invoice deleted successfully! " << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Invoice not found for: " << roomNumber << "with month: " << month << " year: " << year << endl;
    }
}

void InvoiceController::markInvoiceAsPaid()
{
    int invoiceId;
    cout << "Enter Invoice ID to mark as paid: ";
    cin >> invoiceId;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Invalid input! Please enter a valid Invoice ID." << endl;
        return;
    }

    for (auto &invoice : invoiceList)
    {
        if (invoice.getInvoiceID() == invoiceId)
        {
            if (!invoice.getCharged())
            {
                invoice.setCharged(true);
                cout << "Invoice ID " << invoiceId << " marked as Paid successfully!" << endl;

                updateCSV();
            }
            else
            {
                cout << "Invoice ID " << invoiceId << " is already Paid!" << endl;
            }

            return;
        }
    }
    cout << "Invoice with ID " << invoiceId << " not found!" << endl;
}

void InvoiceController::searchInvoice(int roomNumber)
{
    int month, year;
    cout << "Enter month to search: ";
    cin >> month;
    cout << "Enter year to search: ";
    cin >> year;

    for (const auto &invoice : invoiceList)
    {
        if (invoice.getRoomNumber() == roomNumber && invoice.getMonth() == month && invoice.getYear() == year)
        {
            InvoiceView::displayInvoiceDetails(invoice);
            return;
        }
    }
    cout << "Invoice for " << roomNumber << "in month" << month << ", " << year << " not found!" << endl;
}

void InvoiceController::invoiceStatistics() const
{
    cout << "--------------------------- Invoice Statistics ----------------------------" << endl;

    cout << left
         << "| " << setw(15) << "Invoice ID"
         << "| " << setw(15) << "Room Number"
         << "| " << setw(15) << "Tenant ID"
         << "| " << setw(20) << "Old Electric Index"
         << "| " << setw(20) << "New Electric Index"
         << "| " << setw(20) << "Old Water Index"
         << "| " << setw(20) << "New Water Index"
         << "| " << setw(15) << "Surcharge"
         << "| " << setw(10) << "Month"
         << "| " << setw(10) << "Year"
         << "| " << setw(15) << "Total"
         << "| " << setw(15) << "Charged"
         << "|" << endl;

    for (const auto &invoice : invoiceList)
    {
        cout << left
             << "| " << setw(15) << invoice.getInvoiceID()
             << "| " << setw(15) << invoice.getRoomNumber()
             << "| " << setw(15) << invoice.getTenantID()
             << "| " << setw(20) << invoice.getOldElectricIndex()
             << "| " << setw(20) << invoice.getNewElectricIndex()
             << "| " << setw(20) << invoice.getOldWaterIndex()
             << "| " << setw(20) << invoice.getNewWaterIndex()
             << "| " << setw(15) << invoice.getSurcharge()
             << "| " << setw(10) << invoice.getMonth()
             << "| " << setw(10) << invoice.getYear()
             << "| " << setw(15) << invoice.getTotal()
             << "| " << setw(15) << (invoice.getCharged() ? "Paid" : "Unpaid")
             << "|" << endl;
    }
}

void InvoiceController::revenueStatistics() const
{
    double totalRevenue = 0.0;
    int month, year;
    cout << "Enter month to calculate revenue: ";
    cin >> month;
    cout << "Enter year to calculate revenue: ";
    cin >> year;

    cout << "------------------------- Revenue Statistics ----------------------------" << endl;

    for (const auto &invoice : invoiceList)
    {
        if (invoice.getMonth() == month && invoice.getYear() == year)
        {
            if (invoice.getCharged())
            {
                totalRevenue += invoice.getTotal();
            }
            else
            {
                cout << "Invoice for room:  " << invoice.getRoomNumber() << " is not Paid!" << endl;
                continue;
            }
        }
    }

    cout << "Total Revenue: " << totalRevenue << endl;
    cout << "-------------------------------------------------------------------------" << endl;
}

void InvoiceController::updateCSV()
{
    ofstream file("data/invoices.csv", ios::out);
    if (!file.is_open())
    {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    file << "invoiceId,roomNumber,tenantID,oldElectricIndex,newElectricIndex,oldWaterIndex,newWaterIndex,surcharge,month,year,total,isCharged\n";

    for (const auto &invoice : invoiceList)
    {
        file << invoice.getInvoiceID() << ","
             << invoice.getRoomNumber() << ","
             << invoice.getTenantID() << ","
             << invoice.getOldElectricIndex() << ","
             << invoice.getNewElectricIndex() << ","
             << invoice.getOldWaterIndex() << ","
             << invoice.getNewWaterIndex() << ","
             << invoice.getSurcharge() << ","
             << invoice.getMonth() << ","
             << invoice.getYear() << ","
             << invoice.getTotal() << ","
             << (invoice.getCharged() ? "true" : "false") << "\n";
    }

    file.close();
    cout << "CSV file updated successfully!" << endl;
}

InvoiceController::~InvoiceController()
{
}
