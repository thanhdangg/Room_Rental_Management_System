#include "TenantView.h"

using namespace std;

void TenantView::displayTenantDetails(const Tenant& tenant) {
    cout << tenant ;
}

void TenantView::displayAllTenants(const LinkedList<Tenant>& tenantList) {
    for (auto it = tenantList.begin(); it != tenantList.end(); ++it) {
        displayTenantDetails(*it);
    }
}