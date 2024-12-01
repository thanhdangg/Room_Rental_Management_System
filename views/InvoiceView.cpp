#include "InvoiceView.h"

using namespace std;

void InvoiceView::displayInvoiceDetails(const Invoice &invoice) {
    cout << invoice;
}

void InvoiceView::displayAllInvoices(const LinkedList<Invoice> &invoiceList) {
    for (auto it = invoiceList.begin(); it != invoiceList.end(); ++it) {
        displayInvoiceDetails(*it);
    }
}
