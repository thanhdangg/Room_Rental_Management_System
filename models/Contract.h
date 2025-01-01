#ifndef CONTRACT_H
#define CONTRACT_H

#include <string>
#include <iostream>

using namespace std;
class Contract {
private:
    int contractID;      
    int tenantID;        
    int roomNumber;      
    string startDate;    
    string endDate;     
    int status;  

public:
    Contract();
    Contract(int contractID, int tenantID, int roomNumber, string startDate, string endDate, int status);

    int getContractID() const;
    int getTenantID() const;
    int getRoomNumber() const;
    string getStartDate() const;
    string getEndDate() const;
    int getStatus() const;

    void setContractID(int contractID);
    void setTenantID(int tenantID);
    void setRoomNumber(int roomNumber);
    void setStartDate(string startDate);
    void setEndDate(string endDate);
    void setStatus(int status);

    friend ostream& operator<<(ostream& os, const Contract& contract);
    friend istream& operator>>(istream& is, Contract& contract);     
    
    bool operator==(const Contract& other) const;                             
    bool operator!=(const Contract& other) const;                               

    ~Contract();
};

#endif 
