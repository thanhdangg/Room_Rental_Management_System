#ifndef TENANTCONTROLLER_H
#define TENANTCONTROLLER_H

#include <string>
#include "../data_structures/LinkedList.h"
#include "../models/Tenant.h"
#include "../views/TenantView.h"
#include "BaseController.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class TenantController : public BaseController {
public:
    TenantController(LinkedList<Tenant> &tenantList);
    void addTenant();
    void deleteTenant();
    void searchTenant(int iD);
    void tenantStatistics();
    void updateTenant(int id);

    void updateCSV() override;

private:
    LinkedList<Tenant> &tenantList;
};

#endif // TENANTCONTROLLER_H