#ifndef TENANTCONTROLLER_H
#define TENANTCONTROLLER_H

#include <string>
#include "../data_structures/LinkedList.h"
#include "../models/Tenant.cpp"

class TenantController {
public:
    TenantController(LinkedList<Tenant>& tenantList);
    void addTenant();
    void displayTenantDetails() const;
    void editTenant();
    void deleteTenant();
    void tenantStatistics();


private:
    LinkedList<Tenant>& tenantList;
};

#endif // TENANTCONTROLLER_H