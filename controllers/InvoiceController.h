#ifndef INVOICECONTROLLER_H
#define INVOICECONTROLLER_H

#include "BaseController.h"
#include "../models/Invoice.h"
#include "../views/InvoiceView.h"

class InvoiceController : public BaseController {
private:
    Invoice model;
    InvoiceView view;

public:
    InvoiceController(const Invoice& invoiceModel, const InvoiceView& invoiceView) 
        : model(invoiceModel), view(invoiceView) {}

    void createInvoice(const Invoice& newInvoice) {
        if (model.add(newInvoice)) {
            view.displayMessage("Tạo hóa đơn thành công!");
        } else {
            view.displayMessage("Tạo hóa đơn thất bại.");
        }
    }

    void payInvoice(int invoiceId) {
        if (model.pay(invoiceId)) {
            view.displayMessage("Thanh toán hóa đơn thành công!");
        } else {
            view.displayMessage("Không thể thanh toán hóa đơn.");
        }
    }

    void deleteInvoice(int invoiceId) {
        if (model.remove(invoiceId)) {
            view.displayMessage("Xóa hóa đơn thành công!");
        } else {
            view.displayMessage("Không tìm thấy hóa đơn để xóa.");
        }
    }

    void searchInvoice(int invoiceId) {
        Invoice* foundInvoice = model.find(invoiceId);
        if (foundInvoice) {
            view.displayInvoiceDetails(*foundInvoice);
        } else {
            view.displayMessage("Không tìm thấy hóa đơn.");
        }
    }

    void execute() override {

    }

    void invoiceStatistics() {
        cout << "--------------------------- Invoice Statistics ----------------------------" << endl;
        cout << "| Invoice ID | Tenant ID | Amount  | Due Date   | Status    |" << endl;
        cout << "--------------------------------------------------------" << endl;

        for (const auto& invoice : invoices) {
            cout << "| " << invoice.getInvoiceID() << "         | " << invoice.getTenantID() << "        | " << invoice.getAmount() 
                 << "       | " << invoice.getDueDate() << "      | " << invoice.getStatus() << "      |" << endl;
        }

        cout << "-------------------------------------------------------------------------" << endl;
    }

    void revenueStatistics() {
        double totalRevenue = 0.0;

        for (const auto& invoice : invoices) {
            if (invoice.getStatus() == "Paid") {
                totalRevenue += invoice.getAmount();
            }
        }

        cout << "------------------------- Revenue Statistics ----------------------------" << endl;
        cout << "Total Revenue: " << totalRevenue << endl;
        cout << "-------------------------------------------------------------------------" << endl;
    }
};

#endif // INVOICECONTROLLER_H
