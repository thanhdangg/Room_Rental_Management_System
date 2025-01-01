#include "ContractController.h"
#include <iostream>
#include <iomanip>
#include <chrono>

using namespace std;

ContractController::ContractController(LinkedList<Contract> &contracts) : contracts(contracts) {}

void ContractController::createContract()
{
    Contract contract;
    cin >> contract;

    contracts.add(contract);
    cout << "Contract created successfully!" << endl;

    ofstream file("data/contracts.csv", ios::app);
    if (!file.is_open())
    {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    file << contract.getContractID()
         << "," << contract.getTenantID()
         << "," << contract.getRoomNumber()
         << "," << contract.getStartDate()
         << "," << contract.getEndDate()
         << "," << contract.getStatus() << "\n";

    file.close();
    cout << "Contract created and saved to contracts.csv!" << endl;
}

void ContractController::updateContract()
{
    int contractID, tenantID, roomNumber, status;
    string startDate, endDate;

    cout << "Enter contract ID to update: ";
    cin >> contractID;

    bool found = false;
    for (auto it = contracts.begin(); it != contracts.end(); ++it)
    {
        if (it->getContractID() == contractID)
        {
            cout << "Current contract details:" << endl;
            cout << *it;
            cout << "Enter new contract details:" << endl;
            cout << "Enter room number: ";
            cin >> roomNumber;
            cout << "Enter start date (yyyy-mm-dd): ";
            cin >> startDate;
            cout << "Enter end date (yyyy-mm-dd): ";
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

    if (!found)
    {
        cout << "Contract not found!" << endl;
    }
    updateCSV();
}

void ContractController::endContract()
{
    int contractID;
    cout << "Enter contract ID to end: ";
    cin >> contractID;

    bool found = false;
    for (auto it = contracts.begin(); it != contracts.end(); ++it)
    {
        if (it->getContractID() == contractID)
        {
            it->setStatus(0);
            cout << "Contract ended successfully!" << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Contract not found!" << endl;
    }
    updateCSV();
}

void ContractController::searchContract(int userId)
{
    bool found = false;
    for (const auto &contract : contracts)
    {
        if (contract.getTenantID() == userId)
        {
            cout << "Contract info: " << endl;
            cout << contract << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Contract not found!" << endl;
    }
}
void ContractController::contractStatistics()
{
    cout << "------------------------------ Contract Statistics ------------------------------" << endl;

    cout << left
         << "| " << setw(15) << "Contract ID"
         << "| " << setw(15) << "Tenant ID"
         << "| " << setw(15) << "Room Number"
         << "| " << setw(20) << "Start Date"
         << "| " << setw(20) << "End Date"
         << "| " << setw(15) << "Status"
         << "|" << endl;

    for (const auto &contract : contracts)
    {

        cout << left
             << "| " << setw(15) << contract.getContractID()
             << "| " << setw(15) << contract.getTenantID()
             << "| " << setw(15) << contract.getRoomNumber()
             << "| " << setw(20) << contract.getStartDate()
             << "| " << setw(20) << contract.getEndDate()
             << "| " << setw(15) << contract.getStatus()
             << "|" << endl;
    }
}

void ContractController::updateCSV()
{
    ofstream file("data/contracts.csv", ios::trunc);
    if (!file.is_open())
    {
        cerr << "Error opening file for updating!" << endl;
        return;
    }
    file << "contractID,tenantID,roomNumber,startDate,endDate,status" << endl;
    for (const auto &contract : contracts)
    {
        file << contract.getContractID()
             << "," << contract.getTenantID()
             << "," << contract.getRoomNumber()
             << "," << contract.getStartDate()
             << "," << contract.getEndDate()
             << "," << contract.getStatus() << "\n";
    }

    file.close();
    cout << "Contracts CSV updated successfully!" << endl;
}

int ContractController::getRoomByTenant(int tenantID)
{
    for (const auto &contract : contracts)
    {
        if (contract.getTenantID() == tenantID)
        {
            return contract.getRoomNumber();
        }
    }
    return -1;

}

ContractController::~ContractController() {}
