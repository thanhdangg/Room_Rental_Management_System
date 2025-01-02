#include "utils.h"
using namespace std;

string trim(const string &str)
{
    size_t first = str.find_first_not_of(' ');
    if (first == string::npos)
        return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);
}
bool parseDate(const string &dateStr, tm &date)
{
    if (dateStr.length() != 10 || dateStr[4] != '-' || dateStr[7] != '-')
    {
        return false;
    }

    try
    {
        date.tm_year = stoi(dateStr.substr(0, 4)) - 1900;
        date.tm_mon = stoi(dateStr.substr(5, 2)) - 1;
        date.tm_mday = stoi(dateStr.substr(8, 2));
        date.tm_hour = 0;
        date.tm_min = 0;
        date.tm_sec = 0;
        return true;
    }
    catch (...)
    {
        return false;
    }
}
string getHiddenPassword()
{
    string password;
    char ch;

    while ((ch = _getch()) != '\r')
    { // '\r' is Enter
        if (ch == '\b')
        { // Backspace
            if (!password.empty())
            {
                cout << "\b \b";
                password.pop_back();
            }
        }
        else
        {
            password.push_back(ch);
            cout << '*'; // show *
        }
    }
    cout << endl;

    return password;
}

string hashPassword(const string &password)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char *>(password.c_str()), password.size(), hash);

    ostringstream os;
    for (size_t i = 0; i < SHA256_DIGEST_LENGTH; ++i)
    {
        os << hex << setw(2) << setfill('0') << static_cast<int>(hash[i]);
    }
    return os.str();
}

bool login(const LinkedList<User> &userList, int &role, int &userId)
{
    string email, password;
    int try_count = 5;
    do
    {
        system("cls");
        cout << "========================= Login =========================" << endl;
        cout << "Welcome to Room Rental Management System" << endl;
        cout << "Please enter your email and password to login" << endl;
        cout << "Enter email: ";
        cin >> email;

        cout << "Enter password: ";
        password = getHiddenPassword();

        for (auto it = userList.begin(); it != userList.end(); ++it)
        {
            if (it->getEmail() == email && it->getPassword() == hashPassword(password))
            {
                role = it->getRole();
                userId = it->getUserId();
                cout << "Login successful!" << endl;
                return true;
            }
        }

        cout << "Invalid email or password!. You have " << --try_count << " more tries left!" << endl;
    } while (try_count > 0);
    return false;
}
bool isNumber(const string &str)
{
    if (str.empty())
        return false;
    for (char c : str)
    {
        if (!isdigit(c))
            return false;
    }
    return true;
}
int inputNumber(const string &prompt)
{
    string input;
    while (true)
    {
        cout << prompt << ": ";
        if (cin.peek() == '\n')
            cin.ignore();

        getline(cin, input);
        if (isNumber(input))
        {
            return stoi(input);
        }
        else
        {
            cout << "Invalid input! Please enter a number." << endl;
        }
    }
    return 0;
}
int inputRoomType()
{
    int roomType;
    while (true)
    {
        cout << "Enter room type: (1 for small room, 2 for medium room, or 3 for large room): ";
        cin >> roomType;

        if (cin.fail() || roomType < 1 || roomType > 3)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter 1, 2, or 3." << endl;
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return roomType;
        }
    }
}

double inputDouble(const string &prompt)
{
    double value;
    while (true)
    {
        cout << prompt << ": ";
        cin >> value;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a valid number." << endl;
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

bool inputBool(const string &prompt)
{
    string input;
    while (true)
    {
        cout << prompt << ": ";
        getline(cin, input);

        if (input == "1" || input == "true" || input == "True")
        {
            return true;
        }
        else if (input == "0" || input == "false" || input == "False")
        {
            return false;
        }
        else
        {
            cout << "Invalid input! Please enter 1 (true) or 0 (false)." << endl;
        }
    }
}

bool isValidDate(const string &date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    try
    {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));

        if (month < 1 || month > 12 || day < 1 || day > 31)
            return false;

        vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
        {
            daysInMonth[1] = 29;
        }

        return day <= daysInMonth[month - 1];
    }
    catch (...)
    {
        return false;
    }
}

string inputEmail(const string &prompt)
{
    string email;
    while (true)
    {
        cout << prompt << ": ";
        if (cin.peek() == '\n')
            cin.ignore();
        getline(cin, email);

        if (isValidEmail(email))
        {
            return email;
        }
        else
        {
            cout << "Invalid email format! Please enter a valid email." << endl;
        }
    }
}
bool isValidEmail(const string &email)
{
    const regex pattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    return regex_match(email, pattern);
}

string inputPhone(const string &prompt)
{
    string phone;
    while (true)
    {
        cout << prompt << ": ";
        if (cin.peek() == '\n')
            cin.ignore();
        getline(cin, phone);

        if (isValidPhone(phone))
        {
            return phone;
        }
        else
        {
            cout << "Invalid phone number format! Please enter a valid phone number." << endl;
        }
    }
}

bool isValidPhone(const string &phone)
{
    const regex pattern(R"(\d{10})");
    return regex_match(phone, pattern);
}

string inputString(const string &prompt)
{
    string input;
    cout << prompt << ": ";
    if (cin.peek() == '\n')
            cin.ignore();

    getline(cin, input);
    return input;
}

string inputDate(const string &prompt)
{
    string date;
    while (true)
    {
        cout << prompt << " (yyyy-mm-dd): ";
        if (cin.peek() == '\n')
            cin.ignore();
        cin >> date;

        if (isValidDate(date))
        {
            return date;
        }
        else
        {
            cout << "Invalid date! Please enter a valid date in the format yyyy-mm-dd." << endl;
        }
    }
}
string inputPassword(const string &prompt)
{
    string password;
    while (true)
    {
        cout << prompt << ": ";
        if (cin.peek() == '\n')
            cin.ignore();
        getline(cin, password);

        if (password.length() < 6)
        {
            cout << "Password must be at least 6 characters long." << endl;
        }
        else
        {
            return password;
        }
    }
}

void logProjectInfo()
{
    cout << " ____________________________________________________________________________" << endl;
    cout << "|                                                                            |" << endl;
    cout << "|                          DO AN CO SO LAP TRINH                             |" << endl;
    cout << "|                  XAY DUNG HE THONG QUAN LY PHONG TRO                       |" << endl;
    cout << "|                      HOC KI 1 - NAM HOC 2024-2025                          |" << endl;
    cout << "|                  Supervisor: Dr. Nguyen Nang Hung Van                      |" << endl;
    cout << "|              Developer: Nguyen Thanh Dang, Student ID: 102210310           |" << endl;
    cout << "|____________________________________________________________________________|" << endl;
    cout << endl;
    system("pause");
}

void displayMainMenu()
{
    system("cls");
    cout << "========================= Main Menu =========================" << endl;
    cout << "1. Room Management" << endl;
    cout << "2. Tenant Management" << endl;
    cout << "3. Invoice Management" << endl;
    cout << "4. Contract Management" << endl;
    cout << "5. Account Management" << endl;
    cout << "6. Logout" << endl;
    cout << "=============================================================" << endl;
    cout << "Enter your choice: ";
}

void displayRoomManagementMenu()
{
    system("cls");
    cout << "========================= Room Management =========================" << endl;
    cout << "1. Add Room" << endl;
    cout << "2. Update Room Information" << endl;
    cout << "3. Delete Room" << endl;
    cout << "4. Search Room Information" << endl;
    cout << "5. Room Statistics" << endl;
    cout << "6. Back to Main Menu" << endl;
    cout << "===================================================================" << endl;
    cout << "Enter your choice: ";
}

void displayTenantManagementMenu()
{
    system("cls");
    cout << "========================= Tenant Management =========================" << endl;
    cout << "1. Add Tenant" << endl;
    cout << "2. Update Tenant Information" << endl;
    cout << "3. Delete Tenant" << endl;
    cout << "4. Search Tenant Information" << endl;
    cout << "5. Tenant Statistics" << endl;
    cout << "6. Back to Main Menu" << endl;
    cout << "=====================================================================" << endl;
    cout << "Enter your choice: ";
}

void displayInvoiceManagementMenu()
{
    system("cls");
    cout << "========================= Invoice Management =========================" << endl;
    cout << "1. Create Invoice" << endl;
    cout << "2. Process Invoice Payment" << endl;
    cout << "3. Delete Invoice" << endl;
    cout << "4. Search Invoice" << endl;
    cout << "5. Invoice Statistics" << endl;
    cout << "6. Revenue Statistics" << endl;
    cout << "7. Back to Main Menu" << endl;
    cout << "======================================================================" << endl;
    cout << "Enter your choice: ";
}

void displayContractManagementMenu()
{
    system("cls");
    cout << "========================= Contract Management =========================" << endl;
    cout << "1. Create Contract" << endl;
    cout << "2. Update Contract" << endl;
    cout << "3. End Contract" << endl;
    cout << "4. Search Contract" << endl;
    cout << "5. Contract Statistics" << endl;
    cout << "6. Back to Main Menu" << endl;
    cout << "=======================================================================" << endl;
    cout << "Enter your choice: ";
}
void displayAccountManagementMenu()
{
    system("cls");
    cout << "========================= Account Management =========================" << endl;
    cout << "1. Add Account" << endl;
    cout << "2. Delete Account" << endl;
    cout << "3. Change Password" << endl;
    cout << "4. Back to Main Menu" << endl;
    cout << "======================================================================" << endl;
    cout << "Enter your choice: ";
}
void displayTenantMenu()
{
    system("cls");
    cout << "========================= Tenant Menu =========================" << endl;
    cout << "1. Display Invoice Details" << endl;
    cout << "2. Search Invoice" << endl;
    cout << "3. Display Contract Details" << endl;
    cout << "4. Display Room  Info" << endl;
    cout << "5. Display User Info" << endl;
    cout << "6. Update User Info" << endl;
    cout << "7. Change Password" << endl;
    cout << "8. Back to Main Menu" << endl;
    cout << "===============================================================" << endl;
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
    getline(file, line);
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
}

void loadContractsFromCSV(LinkedList<Contract> &contractList, const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    string line;
    getline(file, line);
    while (getline(file, line))
    {
        stringstream ss(line);
        string contractIDStr, tenantIDStr, roomNumberStr, startDateStr, endDateStr, statusStr;

        getline(ss, contractIDStr, ',');
        getline(ss, tenantIDStr, ',');
        getline(ss, roomNumberStr, ',');
        getline(ss, startDateStr, ',');
        getline(ss, endDateStr, ',');
        getline(ss, statusStr, ',');

        contractIDStr = trim(contractIDStr);
        tenantIDStr = trim(tenantIDStr);
        roomNumberStr = trim(roomNumberStr);
        startDateStr = trim(startDateStr);
        endDateStr = trim(endDateStr);
        statusStr = trim(statusStr);

        try
        {
            int contractID = stoi(contractIDStr);
            int tenantID = stoi(tenantIDStr);
            int roomNumber = stoi(roomNumberStr);
            int status = stoi(statusStr);

            Contract contract(contractID, tenantID, roomNumber, startDateStr, endDateStr, status);
            contractList.add(contract);
        }
        catch (const exception &e)
        {
            cerr << "Error processing line: " << line << "\nReason: " << e.what() << endl;
        }
    }

    file.close();
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
    // cout << "Invoices loaded from " << filename << " successfully!" << endl;

    // for (auto it = invoiceList.begin(); it != invoiceList.end(); ++it)
    // {
    //     cout << *it << endl;
    // }
}

void loadTenantsFromCSV(LinkedList<Tenant> &tenantList, const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    string line;
    getline(file, line);
    while (getline(file, line))
    {
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

        try
        {
            int id = stoi(idStr);

            Tenant tenant(id, name, sex, dateOfBirth, email, phone, address);
            tenantList.add(tenant);
        }
        catch (const exception &e)
        {
            cerr << "Error processing line: " << line << "\nReason: " << e.what() << endl;
        }
    }

    file.close();
    // cout << "Tenants loaded from " << filename << " successfully!" << endl;

    // for (auto it = tenantList.begin(); it != tenantList.end(); ++it) {
    //     cout << *it << endl;
    // }
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
    getline(file, line);
    while (getline(file, line))
    {
        stringstream ss(line);
        string email, password, roleStr, userIDStr;
        int role, userID;
        getline(ss, userIDStr, ',');
        getline(ss, email, ',');
        getline(ss, password, ',');
        getline(ss, roleStr, ',');

        email = trim(email);
        password = trim(password);
        roleStr = trim(roleStr);
        userIDStr = trim(userIDStr);

        try
        {
            role = (roleStr == "Admin") ? 1 : (roleStr == "User" ? 2 : 0);
            userID = stoi(userIDStr);

            if (role == 0)
            {
                throw invalid_argument("Invalid role value: " + roleStr);
            }

            User user(userID, email, password, role);
            userList.add(user);
        }
        catch (const exception &e)
        {
            cerr << "Error processing line: " << line << "\nReason: " << e.what() << endl;
        }
    }

    file.close();
    // cout << "Users loaded from " << filename << " successfully!" << endl;

    // for (auto it = userList.begin(); it != userList.end(); ++it) {
    //     cout << *it << endl;
    // }
}
