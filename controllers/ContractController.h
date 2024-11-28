#ifndef CONTRACTCONTROLLER_H
#define CONTRACTCONTROLLER_H

#include "Contract.h"
#include <vector>
#include <iostream>
#include <ctime>

using namespace std;

class ContractController {
private:
    vector<Contract> contracts;

public:
    void createContract() {
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
        contracts.push_back(newContract);
        cout << "Contract created successfully!" << endl;
    }

    void updateContract() {
        int contractID, tenantID, roomNumber;
        time_t startDate, endDate;
        string status;

        cout << "Enter contract ID to update: ";
        cin >> contractID;

        bool found = false;
        for (auto& contract : contracts) {
            if (contract.getContractID() == contractID) {
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

                contract.setTenantID(tenantID);
                contract.setRoomNumber(roomNumber);
                contract.setStartDate(startDate);
                contract.setEndDate(endDate);
                contract.setStatus(status);

                cout << "Contract updated successfully!" << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Contract not found!" << endl;
        }
    }

    void endContract() {
        int contractID;
        cout << "Enter contract ID to end: ";
        cin >> contractID;

        bool found = false;
        for (auto& contract : contracts) {
            if (contract.getContractID() == contractID) {
                contract.setStatus("Ended");
                cout << "Contract ended successfully!" << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Contract not found!" << endl;
        }
    }

    void searchContract() {
        int contractID;
        cout << "Enter contract ID to search: ";
        cin >> contractID;

        bool found = false;
        for (const auto& contract : contracts) {
            if (contract.getContractID() == contractID) {
                cout << "Contract found: " << endl;
                cout << contract << endl;  // In thông tin hợp đồng
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Contract not found!" << endl;
        }
    }

    ~ContractController() {}
};

#endif // CONTRACTCONTROLLER_H
