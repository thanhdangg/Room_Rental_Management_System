#include "ContractController.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <ctime>
#include <chrono>

using namespace std;

ContractController::ContractController(LinkedList<Contract>& contracts) : contracts(contracts) {}

void ContractController::createContract() {
    int contractID, tenantID, roomNumber;
    time_t startDate, endDate;
    string status;

    cout << "Enter contract ID: ";
    cin >> contractID;
    cout << "Enter tenant ID: ";
    cin >> tenantID;
    cout << "Enter room number: ";
    cin >> roomNumber;
    cout << "Enter start date (Unix timestamp): ";
    cin >> startDate;
    cout << "Enter end date (Unix timestamp): ";
    cin >> endDate;
    cout << "Enter contract status: ";
    cin >> status;

    Contract newContract(contractID, tenantID, roomNumber, startDate, endDate, status);
    contracts.add(newContract);
    cout << "Contract created successfully!" << endl;
}

void ContractController::updateContract() {
    int contractID, tenantID, roomNumber;
    time_t startDate, endDate;
    string status;

    cout << "Enter contract ID to update: ";
    cin >> contractID;

    bool found = false;
    for (auto it = contracts.begin(); it != contracts.end(); ++it) {
        if (it->getContractID() == contractID) {
            cout << "Enter tenant ID: ";
            cin >> tenantID;
            cout << "Enter room number: ";
            cin >> roomNumber;
            cout << "Enter start date (Unix timestamp): ";
            cin >> startDate;
            cout << "Enter end date (Unix timestamp): ";
            cin >> endDate;
            cout << "Enter contract status: ";
            cin >> status;

            it->setTenantID(tenantID);
            it->setRoomNumber(roomNumber);
            it->setStartDate(startDate);
            it->setEndDate(endDate);
            it->setStatus(status);

            cout << "Contract updated successfully!" << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Contract not found!" << endl;
    }
}

void ContractController::endContract() {
    int contractID;
    cout << "Enter contract ID to end: ";
    cin >> contractID;

    bool found = false;
    for (auto it = contracts.begin(); it != contracts.end(); ++it) {
        if (it->getContractID() == contractID) {
            it->setStatus("Ended");
            cout << "Contract ended successfully!" << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Contract not found!" << endl;
    }
}

void ContractController::searchContract() {
    int contractID;
    cout << "Enter contract ID to search: ";
    cin >> contractID;

    bool found = false;
    for (const auto& contract : contracts) {
        if (contract.getContractID() == contractID) {
            cout << "Contract found: " << endl;
            cout << contract << endl; 
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Contract not found!" << endl;
    }
}
void ContractController::contractStatistics() {
   cout << "------------------------------ Contract Statistics ------------------------------" << endl;
    
    cout << left
         << setw(15) << "| Contract ID" 
         << setw(15) << "| Tenant ID" 
         << setw(15) << "| Room Number" 
         << setw(20) << "| Start Date" 
         << setw(20) << "| End Date" 
         << setw(15) << "| Status" 
         << "|" << endl;

    cout << "----------------------------------------------------------------------------------------------------" << endl;

    for (const auto& contract : contracts) {
        auto startDate = chrono::system_clock::from_time_t(contract.getStartDate());
        auto endDate = chrono::system_clock::from_time_t(contract.getEndDate());
        
        time_t startTime = chrono::system_clock::to_time_t(startDate);
        time_t endTime = chrono::system_clock::to_time_t(endDate);
        
        tm startTm = *localtime(&startTime);
        tm endTm = *localtime(&endTime);

        cout << left
             << setw(15) << "| " << contract.getContractID()
             << setw(15) << "| " << contract.getTenantID()
             << setw(15) << "| " << contract.getRoomNumber()
             << setw(20) << "| " << put_time(&startTm, "%d/%m/%Y")
             << setw(20) << "| " << put_time(&endTm, "%d/%m/%Y")
             << setw(15) << "| " << contract.getStatus()
             << "|" << endl;
    }

    cout << "----------------------------------------------------------------------------------------------------" << endl;

}

ContractController::~ContractController() {}
