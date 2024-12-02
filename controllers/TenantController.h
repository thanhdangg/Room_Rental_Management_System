#ifndef TENANTCONTROLLER_H
#define TENANTCONTROLLER_H

#include <string>
#include "../data_structures/LinkedList.h"
#include "../models/Tenant.h"
#include "../views/TenantView.h"
#include <iostream>
#include <fstream>
#include <iomanip>

class TenantController {
public:
    TenantController(LinkedList<Tenant>& tenantList);
    void addTenant();
    void deleteTenant();
    void searchTenant();
    void tenantStatistics();
    void updateTenant();    

private:
    LinkedList<Tenant>& tenantList;
};

#endif // TENANTCONTROLLER_H