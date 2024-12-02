#ifndef CONTRACTCONTROLLER_H
#define CONTRACTCONTROLLER_H

#include "../models/Contract.h"
#include "../data_structures/LinkedList.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip> 

class ContractController {
private:
    LinkedList<Contract>& contracts;

public:
    ContractController(LinkedList<Contract>& contracts);

    void createContract();
    void updateContract();
    void endContract();
    void searchContract();
    void contractStatistics();  

    ~ContractController();
};

#endif // CONTRACTCONTROLLER_H
