#ifndef INVOICEVIEW_H
#define INVOICEVIEW_H

#include "../models/Invoice.h"
#include "../data_structures/LinkedList.h"
#include <iostream>

class InvoiceView {
public:
    static void displayInvoiceDetails(const Invoice &invoice);
    static void displayAllInvoices(const LinkedList<Invoice> &invoiceList);
};

#endif // INVOICEVIEW_H
