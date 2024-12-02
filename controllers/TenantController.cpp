#include "TenantController.h"

using namespace std;

TenantController::TenantController(LinkedList<Tenant>& tenantList) : tenantList(tenantList) {}

void TenantController::addTenant() {
    Tenant tenant;
    cin >> tenant;
    tenantList.add(tenant);
    ofstream file("tenants.csv", ios::app);
    if (!file.is_open())
    {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    file << tenant.getId()
         << "," << tenant.getName()
         << "," << tenant.getPhone()
         << "," << tenant.getEmail()
         << "," << tenant.getAddress()
         << "\n";

    file.close();
    cout << "Tenant added successfully and saved to tenants.csv!" << endl;

}

void TenantController::updateTenant() {
    int id;
    cout << "Enter tenant ID to update: ";
    cin >> id;
    auto tenant = tenantList.find([id](const Tenant& t) { return t.getId() == id; });

    if (tenant) {
        string name, phone;
        cout << "Enter new name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter new phone: ";
        cin >> phone;

        tenant->setName(name);
        tenant->setPhone(phone);
        cout << "Tenant updated successfully!" << endl;
    } else {
        cout << "Tenant not found!" << endl;
    }
}

void TenantController::deleteTenant() {
    int id;
    cout << "Enter tenant ID to delete: ";
    cin >> id;

    Tenant* tenant = tenantList.find([id](const Tenant& t) { return t.getId() == id; });
    if (tenant && tenantList.remove(*tenant)) {
        cout << "Tenant deleted successfully!" << endl;
    } else {
        cout << "Tenant not found!" << endl;
    }
}

void TenantController::searchTenant() {
    int id;
    cout << "Enter tenant ID to search: ";
    cin >> id;
    auto tenant = tenantList.find([id](const Tenant& t) { return t.getId() == id; });
    if (tenant) {
        cout << *tenant;
    } else {
        cout << "Tenant not found!" << endl;
    }
}    

void TenantController::tenantStatistics() {
    cout << "---------------------------- Tenant Statistics ----------------------------" << endl;
    cout << "| " << left << setw(15) << "Tenant ID" 
         << "| " << left << setw(30) << "Name"
         << "| " << left << setw(15) << "Phone Number"
         << "| " << left << setw(25) << "Email"
         << "| " << left << setw(30) << "Address" << " |" << endl;
    cout << "-------------------------------------------------------------------------" << endl;

    for (const auto& tenant : tenantList) {
        cout << "| " << left << setw(15) << tenant.getId() 
             << "| " << left << setw(30) << tenant.getName() 
             << "| " << left << setw(15) << tenant.getPhone() 
             << "| " << left << setw(25) << tenant.getEmail() 
             << "| " << left << setw(30) << tenant.getAddress() << " |" << endl;
    }
    cout << "-------------------------------------------------------------------------" << endl;
}
