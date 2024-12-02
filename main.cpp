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
#include <algorithm>
#include <ctime>
#include <iomanip>  
#include <conio.h>
#include <openssl/sha.h>
#include <string>

using namespace std;

string trim(const string &str)
{
    size_t first = str.find_first_not_of(' ');
    if (first == string::npos)
        return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);
}
bool parseDate(const string &dateStr, tm &date) {
    if (dateStr.length() != 10 || dateStr[4] != '-' || dateStr[7] != '-') {
        return false; 
    }

    try {
        date.tm_year = stoi(dateStr.substr(0, 4)) - 1900; 
        date.tm_mon = stoi(dateStr.substr(5, 2)) - 1;     
        date.tm_mday = stoi(dateStr.substr(8, 2));       
        date.tm_hour = 0;
        date.tm_min = 0;
        date.tm_sec = 0;
        return true;
    } catch (...) {
        return false;
    }
}
string getHiddenPassword() {
    string password;
    char ch;

    while ((ch = _getch()) != '\r') { // '\r' is Enter
        if (ch == '\b') { // Backspace
            if (!password.empty()) {
                cout << "\b \b";
                password.pop_back();
            }
        } else {
            password.push_back(ch);
            cout << '*'; // show *
        }
    }
    cout << endl;

    return password;
}

string hashPassword(const string &password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char *>(password.c_str()), password.size(), hash);

    ostringstream os;
    for (size_t i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        os << hex << setw(2) << setfill('0') << static_cast<int>(hash[i]);
    }
    return os.str();
}

bool login(const LinkedList<User> &userList) {
    string email, password;

    cout << "Enter email: ";
    cin >> email;

    cout << "Enter password: ";
    password = getHiddenPassword(); 

    for (auto it = userList.begin(); it != userList.end(); ++it) {
        if (it->getEmail() == email && it->getPassword() == hashPassword(password)) {
            cout << "Login successful!" << endl;
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
    cout << "20. Contract Statistics" << endl;
    cout << "21. Revenue Statistics" << endl;
    cout << "22. Logout" << endl;
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

void loadRoomsFromCSV(RoomLinkedList &roomList, const string &filename)
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
            try
            {
                int roomNumber = stoi(number);
                int roomType = stoi(type);
                bool isAvailable = (available == "1");
                double roomPrice = stod(price);
                Room room(roomNumber, roomType, isAvailable, roomPrice);
                roomList.add(room);
            }
            catch (const invalid_argument &e)
            {
                cerr << "Invalid data in file Room: " << e.what() << endl;
            }
            catch (const out_of_range &e)
            {
                cerr << "Data out of range in file: " << e.what() << endl;
            }
        }
    }
    file.close();
    cout << "Rooms loaded from " << filename << " successfully!" << endl;

    for (auto it = roomList.begin(); it != roomList.end(); ++it)
    {
        cout << *it << endl;
    }
}

void loadContractsFromCSV(LinkedList<Contract> &contractList, const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    string line;
    getline(file, line); 
    while (getline(file, line)) {
        stringstream ss(line);
        string contractIDStr, tenantIDStr, roomNumberStr, startDateStr, endDateStr, status;

        getline(ss, contractIDStr, ',');
        getline(ss, tenantIDStr, ',');
        getline(ss, roomNumberStr, ',');
        getline(ss, startDateStr, ',');
        getline(ss, endDateStr, ',');
        getline(ss, status, ',');

        contractIDStr = trim(contractIDStr);
        tenantIDStr = trim(tenantIDStr);
        roomNumberStr = trim(roomNumberStr);
        startDateStr = trim(startDateStr);
        endDateStr = trim(endDateStr);
        status = trim(status);

        try {
            int contractID = stoi(contractIDStr);
            int tenantID = stoi(tenantIDStr);
            int roomNumber = stoi(roomNumberStr);

            tm startDate = {}, endDate = {};
            if (!parseDate(startDateStr, startDate) || !parseDate(endDateStr, endDate)) {
                throw invalid_argument("Invalid date format");
            }

            time_t start = mktime(&startDate);
            time_t end = mktime(&endDate);

            Contract contract(contractID, tenantID, roomNumber, start, end, status);
            contractList.add(contract);
        } catch (const exception &e) {
            cerr << "Error processing line: " << line << "\nReason: " << e.what() << endl;
        }
    }

    file.close();
    cout << "Contracts loaded from " << filename << " successfully! Count: " << contractList.size() << endl;
    for (auto it = contractList.begin(); it!= contractList.end(); ++it) {
        cout << *it << endl;
    }
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
    bool isFirstLine = true;
    while (getline(file, line))
    {
        if (isFirstLine)
        {
            isFirstLine = false;
            continue; // Skip the header line
        }

        stringstream ss(line);
        string invoiceIdStr, roomNumberStr, tenantIDStr, oldElectricIndexStr,
            newElectricIndexStr, oldWaterIndexStr, newWaterIndexStr, surchargeStr,
            monthStr, yearStr, totalStr, isChargedStr;

        if (getline(ss, invoiceIdStr, ',') &&
            getline(ss, roomNumberStr, ',') &&
            getline(ss, tenantIDStr, ',') &&
            getline(ss, oldElectricIndexStr, ',') &&
            getline(ss, newElectricIndexStr, ',') &&
            getline(ss, oldWaterIndexStr, ',') &&
            getline(ss, newWaterIndexStr, ',') &&
            getline(ss, surchargeStr, ',') &&
            getline(ss, monthStr, ',') &&
            getline(ss, yearStr, ',') &&
            getline(ss, totalStr, ',') &&
            getline(ss, isChargedStr, ','))
        {

            try
            {
                int invoiceId = stoi(trim(invoiceIdStr));
                int roomNumber = stoi(trim(roomNumberStr));
                int tenantID = stoi(trim(tenantIDStr));
                int oldElectricIndex = stoi(trim(oldElectricIndexStr));
                int newElectricIndex = stoi(trim(newElectricIndexStr));
                int oldWaterIndex = stoi(trim(oldWaterIndexStr));
                int newWaterIndex = stoi(trim(newWaterIndexStr));
                double surcharge = stod(trim(surchargeStr));
                int month = stoi(trim(monthStr));
                int year = stoi(trim(yearStr));
                double total = stod(trim(totalStr));
                bool isCharged = trim(isChargedStr) == "true";

                Invoice invoice(roomNumber, tenantID, oldElectricIndex, newElectricIndex,
                                oldWaterIndex, newWaterIndex, surcharge, month, year);
                invoice.setInvoiceID(invoiceId);
                invoice.setCharged(isCharged);
                invoiceList.add(invoice);
            }
            catch (const exception &e)
            {
                cerr << "Error processing line: " << line << " - " << e.what() << endl;
            }
        }
        else
        {
            cerr << "Error reading line: " << line << endl;
        }
    }
    file.close();
    cout << "Invoices loaded from " << filename << " successfully!" << endl;

    for (auto it = invoiceList.begin(); it != invoiceList.end(); ++it)
    {
        cout << *it << endl;
    }
}

void loadTenantsFromCSV(LinkedList<Tenant> &tenantList, const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    string line;
    getline(file, line); 
    while (getline(file, line)) {
        stringstream ss(line);
        string idStr, name, address, phone, email, sex, dateOfBirth;

        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, address, ',');
        getline(ss, phone, ',');
        getline(ss, email, ',');
        getline(ss, sex, ',');
        getline(ss, dateOfBirth, ',');

        idStr = trim(idStr);
        name = trim(name);
        address = trim(address);
        phone = trim(phone);
        email = trim(email);
        sex = trim(sex);
        dateOfBirth = trim(dateOfBirth);

        try {
            int id = stoi(idStr);

            Tenant tenant(id, name, sex, dateOfBirth, email, phone, address);
            tenantList.add(tenant);
        } catch (const exception &e) {
            cerr << "Error processing line: " << line << "\nReason: " << e.what() << endl;
        }
    }

    file.close();
    cout << "Tenants loaded from " << filename << " successfully!" << endl;

    for (auto it = tenantList.begin(); it != tenantList.end(); ++it) {
        cout << *it << endl;
    }
}


void loadUsersFromCSV(LinkedList<User> &userList, const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    string line;
    getline(file, line);
    while (getline(file, line)) {
        stringstream ss(line);
        string email, password, roleStr;
        int role;

        getline(ss, email, ',');
        getline(ss, password, ',');
        getline(ss, roleStr, ',');

        email = trim(email);
        password = trim(password);
        roleStr = trim(roleStr);

        try {
            role = (roleStr == "Admin") ? 1 : (roleStr == "User" ? 2 : 0);

            if (role == 0) {
                throw invalid_argument("Invalid role value: " + roleStr);
            }

            User user(email, password, role);
            userList.add(user);
        } catch (const exception &e) {
            cerr << "Error processing line: " << line << "\nReason: " << e.what() << endl;
        }
    }

    file.close();
    cout << "Users loaded from " << filename << " successfully!" << endl;

    for (auto it = userList.begin(); it != userList.end(); ++it) {
        cout << *it << endl;
    }
}

int main()
{
    system("cls");
    RoomLinkedList roomList;
    LinkedList<Tenant> tenantList;
    LinkedList<Invoice> invoiceList;
    LinkedList<Contract> contractList;
    LinkedList<User> userList;

    loadContractsFromCSV(contractList, "contract.csv");
    loadInvoicesFromCSV(invoiceList, "invoice.csv");
    loadRoomsFromCSV(roomList, "rooms.csv");
    loadTenantsFromCSV(tenantList, "tenant.csv");
    loadUsersFromCSV(userList, "user.csv");

    RoomController roomController(roomList, RoomView());
    InvoiceController invoiceController(invoiceList, InvoiceView());
    TenantController tenantController(tenantList);
    ContractController contractController(contractList);
    UserController userController(userList, UserView());

    int choice;
    int userType;

    cout << "Select user type: \n1 for Owner, \n2 for Tenant: \n";
    cout << "Enter your choice: ";
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

            if (choice == 22)
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
                contractController.contractStatistics();
                break;  
            case 21:
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