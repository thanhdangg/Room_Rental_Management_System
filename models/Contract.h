#ifndef CONTRACT_H
#define CONTRACT_H

#include <string>
#include <iostream>
#include <ctime> 

using namespace std;
class Contract {
private:
    int contractID;      
    int tenantID;        
    int roomNumber;      
    time_t startDate;    
    time_t endDate;     
    string status;  

public:
    Contract(int contractID = 0, int tenantID = 0, int roomNumber = 0, time_t startDate = 0, time_t endDate = 0, const string& status = "");

    int getContractID() const;
    int getTenantID() const;
    int getRoomNumber() const;
    time_t getStartDate() const;
    time_t getEndDate() const;
    string getStatus() const;

    void setContractID(int contractID);
    void setTenantID(int tenantID);
    void setRoomNumber(int roomNumber);
    void setStartDate(time_t startDate);
    void setEndDate(time_t endDate);
    void setStatus(const string& status);

    friend ostream& operator<<(ostream& os, const Contract& contract);
    friend istream& operator>>(istream& is, Contract& contract);     
    
    bool operator==(const Contract& other) const;                             
    bool operator!=(const Contract& other) const;                               

    ~Contract();
};

#endif 
