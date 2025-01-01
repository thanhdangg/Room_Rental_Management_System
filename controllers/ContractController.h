#ifndef CONTRACTCONTROLLER_H
#define CONTRACTCONTROLLER_H

#include "../models/Contract.h"
#include "../data_structures/LinkedList.h"
#include "BaseController.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip> 

using namespace std;

class ContractController : public BaseController {
private:
    LinkedList<Contract>& contracts;

public:
    ContractController(LinkedList<Contract>& contracts);

    void createContract();
    void updateContract();
    void endContract();
    void searchContract(int userId);
    void contractStatistics();  

    void updateCSV() override;
    int getRoomByTenant(int tenantID);


    ~ContractController();
};

#endif // CONTRACTCONTROLLER_H
