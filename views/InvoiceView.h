#ifndef INVOICEVIEW_H
#define INVOICEVIEW_H

#include "BaseView.h"
#include "../models/Invoice.h"

class InvoiceView : public BaseView {
public:
    void displayInvoiceDetails(const Invoice& invoice) {
        std::cout << "Thông tin hóa đơn: " << invoice.getDetails() << std::endl;
    }
};

#endif // INVOICEVIEW_H
