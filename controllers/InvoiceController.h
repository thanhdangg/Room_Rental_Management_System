#ifndef INVOICECONTROLLER_H
#define INVOICECONTROLLER_H

#include "BaseController.h"
#include "../models/Invoice.h"
#include "../views/InvoiceView.h"
#include "../data_structures/LinkedList.h" 
#include <iostream>
#include <fstream>
#include <iomanip> 

class InvoiceController : public BaseController {
private:
    LinkedList<Invoice> invoiceList; 
    InvoiceView view;              

public:
    InvoiceController(LinkedList<Invoice>& invoices, const InvoiceView& invoiceView);

    void addInvoice();                      
    void displayInvoiceDetails() const;        
    void displayInvoicesByMonth(int month, int year, int roomNumber) const; 
    void editInvoice();                       
    void deleteInvoice();   
    void markInvoiceAsPaid();   
    void searchInvoice();
                

    void invoiceStatistics() const;           
    void revenueStatistics() const;          

    void execute() override;
};

#endif // INVOICECONTROLLER_H
