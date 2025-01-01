#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
#include <conio.h>
#include <openssl/sha.h>
#include <string>
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
#include "utils/utils.h"

using namespace std;

int main()
{
    system("cls");
    RoomLinkedList roomList;
    LinkedList<Tenant> tenantList;
    LinkedList<Invoice> invoiceList;
    LinkedList<Contract> contractList;
    LinkedList<User> userList;

    loadContractsFromCSV(contractList, "data/contracts.csv");
    loadInvoicesFromCSV(invoiceList, "data/invoices.csv");
    loadRoomsFromCSV(roomList, "data/rooms.csv");
    loadTenantsFromCSV(tenantList, "data/tenants.csv");
    loadUsersFromCSV(userList, "data/users.csv");

    RoomController roomController(roomList, RoomView());
    InvoiceController invoiceController(invoiceList, InvoiceView());
    TenantController tenantController(tenantList);
    ContractController contractController(contractList);
    UserController userController(userList, UserView());

    int choice;
    int userRole;
    int userId;

    logProjectInfo();

    while (true)
    {
        if (!login(userList, userRole, userId))
        {
            return 1;
        }
        system("pause");

        if (userRole == 1)
        {
            while (true)
            {
                displayMainMenu();
                cin >> choice;

                if (choice == 5)
                {
                    break; // Logout
                }

                switch (choice)
                {
                case 1:
                    while (true)
                    {
                        displayRoomManagementMenu();
                        cin >> choice;
                        if (choice == 6)
                        {
                            break; // Back to Main Menu
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
                            int roomNumber;
                            cout << "Enter room number to search: ";
                            cin >> roomNumber;
                            roomController.searchRoom(roomNumber);
                            break;
                        case 5:
                            roomController.roomStatistics();
                            break;
                        default:
                            cout << "Invalid choice. Please try again." << endl;
                            break;
                        }
                        system("pause");
                    }
                    break;
                case 2:
                    while (true)
                    {
                        displayTenantManagementMenu();
                        cin >> choice;
                        int id;

                        if (choice == 6)
                        {
                            break; // Back to Main Menu
                        }
                        switch (choice)
                        {
                        case 1:
                            tenantController.addTenant();
                            break;
                        case 2:
                            cout << "Enter tenant ID to update: ";
                            tenantController.updateTenant(id);
                            break;
                        case 3:
                            tenantController.deleteTenant();
                            break;
                        case 4:
                            cout << "Enter tenant ID to search: ";
                            cin >> id;
                            tenantController.searchTenant(id);
                            break;
                        case 5:
                            tenantController.tenantStatistics();
                            break;
                        default:
                            cout << "Invalid choice. Please try again." << endl;
                            break;
                        }
                        system("pause");
                    }
                    break;
                case 3:
                    while (true)
                    {
                        displayInvoiceManagementMenu();
                        cin >> choice;
                        if (choice == 7)
                        {
                            break; // Back to Main Menu
                        }
                        switch (choice)
                        {
                        case 1:
                            invoiceController.addInvoice();
                            break;
                        case 2:
                            invoiceController.markInvoiceAsPaid();
                            break;
                        case 3:
                            invoiceController.deleteInvoice();
                            break;
                        case 4:
                            int roomNumber;
                            cout << "Enter room number to search: ";
                            cin >> roomNumber;
                            invoiceController.searchInvoice(roomNumber);
                            break;
                        case 5:
                            invoiceController.invoiceStatistics();
                            break;
                        case 6:
                            invoiceController.revenueStatistics();
                            break;
                        default:
                            cout << "Invalid choice. Please try again." << endl;
                            break;
                        }
                        system("pause");
                    }
                    break;
                case 4:
                    while (true)
                    {
                        displayContractManagementMenu();
                        cin >> choice;
                        if (choice == 6)
                        {
                            break; // Back to Main Menu
                        }
                        switch (choice)
                        {
                        case 1:
                            contractController.createContract();
                            break;
                        case 2:
                            contractController.updateContract();
                            break;
                        case 3:
                            contractController.endContract();
                            break;
                        case 4:
                            int userID;
                            cout << "Enter userID to search: ";
                            cin >> userID;
                            contractController.searchContract(userID);
                            break;
                        case 5:
                            contractController.contractStatistics();
                            break;
                        default:
                            cout << "Invalid choice. Please try again." << endl;
                            break;
                        }
                        system("pause");
                    }
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
                }
            }
        }
        else if (userRole == 2)
        {

            while (true)
            {
                int roomTenant;
                roomTenant = contractController.getRoomByTenant(userId);
                displayTenantMenu();
                cin >> choice;

                if (choice == 7)
                {
                    break; // Exit
                }

                switch (choice)
                {
                case 1:
                    invoiceController.displayInvoicesByTenant(userId);
                    break;
                case 2:
                    invoiceController.searchInvoice(roomTenant);
                    break;
                case 3:
                    contractController.searchContract(userId);
                    break;
                case 4:
                    roomController.searchRoom(roomTenant);
                    break;
                case 5:
                    tenantController.searchTenant(userId);
                    break;
                case 6:
                    tenantController.updateTenant(userId);
                    break;
                default:
                    cout << "Invalid choice! Please try again." << endl;
                }
                cout << endl;
                system("pause");
            }
        }
        else
        {
            cout << "Invalid user type!" << endl;
            return 1;
        }
    }

    return 0;
}