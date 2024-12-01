#include "ContractController.h"
#include <iostream>
#include <ctime>

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

ContractController::~ContractController() {}
