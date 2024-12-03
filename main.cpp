#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <ctime>
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

    loadContractsFromCSV(contractList, "data/contract.csv");
    loadInvoicesFromCSV(invoiceList, "data/invoice.csv");
    loadRoomsFromCSV(roomList, "data/rooms.csv");
    loadTenantsFromCSV(tenantList, "data/tenant.csv");
    loadUsersFromCSV(userList, "data/user.csv");

    RoomController roomController(roomList, RoomView());
    InvoiceController invoiceController(invoiceList, InvoiceView());
    TenantController tenantController(tenantList);
    ContractController contractController(contractList);
    UserController userController(userList, UserView());

    int choice;
    int userRole;

    logProjectInfo();

    while (true)
    {
        if (!login(userList, userRole))
        {
            return 1;
        }

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
                            roomController.searchRoom();
                            break;
                        case 5:
                            roomController.roomStatistics();
                            break;
                        default:
                            cout << "Invalid choice. Please try again." << endl;
                            break;
                        }
                    }
                    break;
                case 2:
                    while (true)
                    {
                        displayTenantManagementMenu();
                        cin >> choice;
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
                            tenantController.updateTenant();
                            break;
                        case 3:
                            tenantController.deleteTenant();
                            break;
                        case 4:
                            tenantController.searchTenant();
                            break;
                        case 5:
                            tenantController.tenantStatistics();
                            break;
                        default:
                            cout << "Invalid choice. Please try again." << endl;
                            break;
                        }
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
                            invoiceController.searchInvoice();
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
                            contractController.searchContract();
                            break;
                        case 5:
                            contractController.contractStatistics();
                            break;
                        default:
                            cout << "Invalid choice. Please try again." << endl;
                            break;
                        }
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
    }

    return 0;
}