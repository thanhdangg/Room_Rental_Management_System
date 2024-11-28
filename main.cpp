#include "models/Landlord.h"
#include "models/Tenant.h"
#include "models/Room.h"
#include "models/Invoice.h"

#include "controllers/RoomController.h"
#include "controllers/InvoiceController.h"
#include "controllers/TenantController.h"
#include "views/RoomView.h"
#include "views/InvoiceView.h"
#include "views/TenantView.h"

#include "data_structures/LinkedList.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>

using namespace std;

unordered_map<string, string> ownerCredentials = {{"owner", "owner123"}};
unordered_map<string, string> tenantCredentials = {{"tenant", "tenant123"}};

bool login(const unordered_map<string, string> &credentials)
{
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    auto it = credentials.find(username);
    if (it != credentials.end() && it->second == password)
    {
        return true;
    }
    cout << "Invalid username or password!" << endl;
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
    cout << "3. Delete Invoice" << endl;
    cout << "4. Display Personal Information" << endl;
    cout << "5. Edit Personal Information" << endl;
    cout << "6. Exit" << endl;
    cout << "=========================" << endl;
    cout << "Enter your choice: ";
}

void loadRoomsFromCSV(LinkedList<Room> &roomList, const string &filename)
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
        RoomView::displayRoomDetails(*it);
    }
}
int main()
{
    system("cls");
    LinkedList<Room> roomList;
    LinkedList<Tenant> tenantList;
    LinkedList<Invoice> invoiceList;

    RoomController roomController(roomList);
    TenantController tenantController(tenantList);
    InvoiceController invoiceController(invoiceList);

    int choice;
    int userType;

    cout << "Select user type: \n1 for Owner, \n2 for Tenant: ";
    cin >> userType;

    if (userType == 1)
    {
        if (!login(ownerCredentials))
        {
            return 1;
        }

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
                roomController.updateRoomInfo();
                break;
            case 3:
                roomController.deleteRoom();
                break;
            case 4:
                roomController.searchRoomInfo();
                break;
            case 5:
                tenantController.addTenant();
                break;
            case 6:
                tenantController.updateTenantInfo();
                break;
            case 7:
                tenantController.deleteTenant();
                break;
            case 8:
                tenantController.searchTenantInfo();
                break;
            case 9:
                invoiceController.createInvoice();
                break;
            case 10:
                invoiceController.processInvoicePayment();
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
        if (!login(tenantCredentials))
        {
            return 1;
        }

        while (true)
        {
            displayTenantMenu();
            cin >> choice;

            if (choice == 6)
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
                invoiceController.deleteInvoice();
                break;
            case 4:
                tenantController.displayTenantDetails();
                break;
            case 5:
                tenantController.editTenant();
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