#include "TenantController.h"

using namespace std;

TenantController::TenantController(LinkedList<Tenant>& tenantList) : tenantList(tenantList) {}

void TenantController::addTenant() {
    Tenant tenant;
    cin >> tenant;
    tenantList.add(tenant);

    ofstream file("data/tenants.csv", ios::app);
    if (!file.is_open())
    {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    file << tenant.getId()
         << "," << tenant.getName()
         << "," << tenant.getAddress()
         << "," << tenant.getPhone()
         << "," << tenant.getEmail()
         << "," << tenant.getSex()
         << "," << tenant.getDateOfBirth()
         << "\n";

    file.close();
    cout << "Tenant added successfully and saved to tenants.csv!" << endl;

}

void TenantController::updateTenant(int id) {

    for (auto& tenant : tenantList) {
        if (tenant.getId() == id) {
            cout << "Current tenant details:" << endl;
            cout << tenant;
            cout << "Enter new tenant details:" << endl;
            cin >> tenant;
            updateCSV();
            cout << "Tenant updated successfully!" << endl;
            return;
        }
    }
}

void TenantController::updateCSV()
{
    ofstream file("data/tenants.csv");
    if (!file.is_open()) {
        cerr << "Error opening file for writing!" << endl;
        return ;
    }

    for (const auto& tenant : tenantList) {
        file << tenant.getId() << ","
             << tenant.getName() << ","
             << tenant.getAddress() << ","
             << tenant.getPhone() << ","
             << tenant.getEmail() << ","
             << tenant.getSex() << ","
             << tenant.getDateOfBirth() << "\n";
    }

    file.close();
}

void TenantController::deleteTenant() {
    int id;
    cout << "Enter tenant ID to delete: ";
    cin >> id;

    for (auto& tenant : tenantList) {
        if (tenant.getId() == id) {
            tenantList.remove(tenant);
            updateCSV();
            cout << "Tenant deleted successfully!" << endl;
            return;
        }
    }
}

void TenantController::searchTenant(int id) {

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

    for (const auto& tenant : tenantList) {
        cout << "| " << left << setw(15) << tenant.getId() 
             << "| " << left << setw(30) << tenant.getName() 
             << "| " << left << setw(15) << tenant.getPhone() 
             << "| " << left << setw(25) << tenant.getEmail() 
             << "| " << left << setw(30) << tenant.getAddress() << " |" << endl;
    }
    cout << "-------------------------------------------------------------------------" << endl;
}
