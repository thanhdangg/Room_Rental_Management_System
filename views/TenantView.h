#ifndef TENANTVIEW_H
#define TENANTVIEW_H

#include "../models/Tenant.h"
#include "../data_structures/LinkedList.h"
#include <iostream>

class TenantView {
public:
    static void displayTenantDetails(const Tenant& tenant);
    static void displayAllTenants(const LinkedList<Tenant>& tenantList);
};

#endif // TENANTVIEW_H