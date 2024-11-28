#include "../models/Invoice.h"
#include "../data_structures/LinkedList.h"
#include <iostream>

class InvoiceView {
public:
    static void displayInvoiceDetails(const Invoice &invoice) {
        std::cout << invoice;
    }

    static void displayAllInvoices(const LinkedList<Invoice> &invoiceList) {
        for (auto it = invoiceList.begin(); it != invoiceList.end(); ++it) {
            displayInvoiceDetails(*it);
        }
    }
};
