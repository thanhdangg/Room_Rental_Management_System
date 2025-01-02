#ifndef UTILS_H
#define UTILS_H

#include "../models/Landlord.h"
#include "../models/Tenant.h"
#include "../models/Room.h"
#include "../models/Invoice.h"
#include "../models/Contract.h"
#include "../models/User.h"

#include "../controllers/RoomController.h"
#include "../controllers/InvoiceController.h"
#include "../controllers/TenantController.h"
#include "../controllers/ContractController.h"
#include "../controllers/UserController.h"

#include "../views/RoomView.h"
#include "../views/InvoiceView.h"
#include "../views/TenantView.h"

#include "../data_structures/LinkedList.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
#include <conio.h>
#include <openssl/sha.h>
#include <string>
#include <regex>
#include <vector>


using namespace std;

// Utility functions
string trim(const string& str);
string getHiddenPassword();
string hashPassword(const string& password);
bool login(const LinkedList<User>& userList, int& userRole, int& userId);
bool isNumber(const string& str);
int inputNumber(const string& prompt);
int inputRoomType();
double inputDouble(const string& prompt);
bool inputBool(const string& prompt);
string inputDate(const string& prompt);
bool isValidDate(const string &date);
string inputEmail(const string& prompt);
string inputString(const string& prompt);
bool isValidEmail(const string &email);
string inputPhone(const string &prompt);
bool isValidPhone(const string &phone);

// Menu display functions
void displayMainMenu();
void displayRoomManagementMenu();
void displayTenantManagementMenu();
void displayInvoiceManagementMenu();
void displayContractManagementMenu();
void displayAccountManagementMenu();
void displayTenantMenu();
void logProjectInfo();

// Load data from CSV files     
void loadRoomsFromCSV(RoomLinkedList& roomList, const string& filename);
void loadTenantsFromCSV(LinkedList<Tenant> &tenantList, const string& filename); 
void loadUsersFromCSV(LinkedList<User>& userList, const string& filename);
void loadContractsFromCSV(LinkedList<Contract>& contractList, const string& filename);
void loadInvoicesFromCSV(LinkedList<Invoice>& invoiceList, const string& filename);

#endif // UTILS_H