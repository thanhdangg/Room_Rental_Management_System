#include "models/Landlord.h"
#include "models/Tenant.h"
#include "models/Room.h"
#include "models/Invoice.h"
#include "models/Contract.h"
#include "models/User.h"    

#include "controllers/RoomController.h"
#include "controllers/InvoiceController.h"
#include "controllers/TenantController.h"
#include "controllers/ContractController.h"
#include "controllers/UserController.h"

#include "views/RoomView.h"
#include "views/InvoiceView.h"
#include "views/TenantView.h"

#include "data_structures/LinkedList.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>

using namespace std;

bool login(const LinkedList<User> &userList)
{
    string email, password;
    cout << "Enter email: ";
    cin >> email;
    cout << "Enter password: ";
    cin >> password;

    for (auto it = userList.begin(); it != userList.end(); ++it)
    {
        if (it->getEmail() == email && it->getPassword() == password)
        {
            return true;
        }
    }
    cout << "Invalid email or password!" << endl;
    return false;
}

void displayOwnerMenu()
{
    cout << "========================= Owner Menu =========================" << endl;
    cout << "1. Add Room" << endl;
    cout << "2. Update Room Information" << endl;
    cout << "3. Delete Room" << endl;
    cout << "4. Search Room Information" << endl;
    cout << "5. Add Tenant" << endl;
    cout << "6. Update Tenant Information" << endl;
    cout << "7. Delete Tenant" << endl;
    cout << "8. Search Tenant Information" << endl;
    cout << "9. Create Invoice" << endl;
    cout << "10. Process Invoice Payment" << endl;
    cout << "11. Delete Invoice" << endl;
    cout << "12. Search Invoice" << endl;
    cout << "13. Create Contract" << endl;
    cout << "14. Update Contract" << endl;
    cout << "15. End Contract" << endl;
    cout << "16. Search Contract" << endl;
    cout << "17. Room Statistics" << endl;
    cout << "18. Tenant Statistics" << endl;
    cout << "19. Invoice Statistics" << endl;
    cout << "20. Revenue Statistics" << endl;
    cout << "21. Logout" << endl;
    cout << "==============================================================" << endl;
    cout << "Enter your choice: ";
}

void displayTenantMenu()
{
    cout << "=========================" << endl;
    cout << "1. Display Invoice Details" << endl;
    cout << "2. Edit Invoice" << endl;
    cout << "3. Display Personal Information" << endl;
    cout << "4. Edit Personal Information" << endl;
    cout << "5. Exit" << endl;
    cout << "=========================" << endl;
    cout << "Enter your choice: ";
}

void loadRoomsFromCSV(RoomLinkedList& roomList, const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error opening file for reading!" << endl;
        return;
    }
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string number, type, available, price;
        if (getline(ss, number, ',') && getline(ss, type, ',') &&
            getline(ss, available, ',') && getline(ss, price, ','))
        {
            int roomType = stoi(type);
            Room room(stoi(number), roomType, available == "1", stod(price));
            roomList.add(room);
        }
    }
    file.close();
    cout << "Rooms loaded from " << filename << " successfully!" << endl;

    for (auto it = roomList.begin(); it != roomList.end(); ++it)
    {
        cout << *it << endl;
    }
}
void loadContractsFromCSV(LinkedList<Contract>& contractList, const string& filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error opening file for reading!" << endl;
        return;
    }
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        int contractID, tenantID, roomNumber;
        int startMonth, startYear, endMonth, endYear;
        string status;

        if (ss >> contractID >> tenantID >> roomNumber >> startMonth >> startYear >> endMonth >> endYear >> status)
        {
            std::tm startDate = {};
            startDate.tm_mon = startMonth - 1; 
            startDate.tm_year = startYear - 1900; 
            time_t start = std::mktime(&startDate);

            std::tm endDate = {};
            endDate.tm_mon = endMonth - 1;
            endDate.tm_year = endYear - 1900;
            time_t end = std::mktime(&endDate);

            Contract contract(contractID, tenantID, roomNumber, start, end, status);
            contractList.add(contract);
        }
    }
    file.close();
    cout << "Contracts loaded from " << filename << " successfully!" << endl;
}

void loadInvoicesFromCSV(LinkedList<Invoice> &invoiceList, const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error opening file for reading!" << endl;
        return;
    }
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        int roomNumber, tenantID, oldElectricIndex, newElectricIndex, oldWaterIndex, newWaterIndex, month, year;
        double surcharge;
        if (ss >> roomNumber >> tenantID >> oldElectricIndex >> newElectricIndex >> oldWaterIndex >> newWaterIndex >> surcharge >> month >> year)
        {
            Invoice invoice(roomNumber, tenantID, oldElectricIndex, newElectricIndex, oldWaterIndex, newWaterIndex, surcharge, month, year);
            invoiceList.add(invoice);
        }
    }
    file.close();
    cout << "Invoices loaded from " << filename << " successfully!" << endl;
}

void loadTenantsFromCSV(LinkedList<Tenant>& tenantList, const string& filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error opening file for reading!" << endl;
        return;
    }
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        int id;
        string name, sex, dateOfBirth, email, phone, address;
        if (ss >> id >> name >> sex >> dateOfBirth >> email >> phone >> address)
        {
            Tenant tenant(id, name, sex, dateOfBirth, email, phone, address);
            tenantList.add(tenant);
        }
    }
    file.close();
    cout << "Tenants loaded from " << filename << " successfully!" << endl;
}

void loadUsersFromCSV(LinkedList<User> &userList, const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error opening file for reading!" << endl;
        return;
    }
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string email, password;
        int role;
        if (ss >> email >> password >> role)
        {
            User user(email, password, role);
            userList.add(user);
        }
    }
    file.close();
    cout << "Users loaded from " << filename << " successfully!" << endl;
}
int main()
{
    system("cls");
    RoomLinkedList roomList;
    LinkedList<Tenant> tenantList;
    LinkedList<Invoice> invoiceList;
    LinkedList<Contract> contractList;
    LinkedList<User> userList;

    RoomController roomController(roomList, RoomView());    
    InvoiceController invoiceController(invoiceList, InvoiceView());    
    TenantController tenantController(tenantList);
    ContractController contractController(contractList);    
    UserController userController(userList, UserView());
    

    loadContractsFromCSV(contractList, "contract.csv");
    loadInvoicesFromCSV(invoiceList, "invoice.csv");
    loadRoomsFromCSV(roomList, "rooms.csv");
    loadTenantsFromCSV(tenantList, "tenant.csv");
    loadUsersFromCSV(userList, "user.csv");

    int choice;
    int userType;

    cout << "Select user type: \n1 for Owner, \n2 for Tenant: ";
    cin >> userType;

    if (!login(userList))
    {
        return 1;
    }

    if (userType == 1)
    {
        while (true)
        {
            displayOwnerMenu();
            cin >> choice;

            if (choice == 21)
            {
                break; // Logout
            }

            switch (choice)
            {
            case 1:
                roomController.addRoom();
                break;
            case 2:
                roomController.updateRoom();
                break;
            case 3:
                roomController.deleteRoom();
                break;
            case 4:
                roomController.searchRoom();
                break;
            case 5:
                tenantController.addTenant();
                break;
            case 6:
                tenantController.updateTenant();
                break;
            case 7:
                tenantController.deleteTenant();
                break;
            case 8:
                tenantController.searchTenant();
                break;
            case 9:
                invoiceController.addInvoice();
                break;
            case 10:
                invoiceController.markInvoiceAsPaid();
                break;
            case 11:
                invoiceController.deleteInvoice();
                break;
            case 12:
                invoiceController.searchInvoice();
                break;
            case 13:
                contractController.createContract();
                break;
            case 14:
                contractController.updateContract();
                break;
            case 15:
                contractController.endContract();
                break;
            case 16:
                contractController.searchContract();
                break;
            case 17:
                roomController.roomStatistics();
                break;
            case 18:
                tenantController.tenantStatistics();
                break;
            case 19:
                invoiceController.invoiceStatistics();
                break;
            case 20:
                invoiceController.revenueStatistics();
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
            }
            cout << endl;
            system("pause");
        }
    }
    else if (userType == 2)
    {
        while (true)
        {
            displayTenantMenu();
            cin >> choice;

            if (choice == 5)
            {
                break; // Exit
            }

            switch (choice)
            {
            case 1:
                invoiceController.displayInvoiceDetails();
                break;
            case 2:
                invoiceController.editInvoice();
                break;
            case 3:
                // tenantController.displayTenantDetails();
                break;
            case 4:
                tenantController.updateTenant();
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Invalid user type!" << endl;
        return 1;
    }

    return 0;
}