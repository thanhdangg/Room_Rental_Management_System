# Room Rental Management System

## Project Overview
This project is a Room Rental Management System developed as a part of the Basic Programming Project. The system allows for the management of rooms, tenants, invoices, and contracts. It provides functionalities for both administrators (landlords) and tenants.

## Project Information
- **Project Title**: Basic Programming Project - Building a Room Management System
- **Developer**: Nguyen Thanh Dang
- **Student ID**: 102210310
- **Supervisor**: Dr. Nguyen Nang Hung Van

## Features
### Admin (Landlord) Features
- **Room Management**
  - Add Room
  - Update Room Information
  - Delete Room
  - Search Room Information
  - Room Statistics
- **Tenant Management**
  - Add Tenant
  - Update Tenant Information
  - Delete Tenant
  - Search Tenant Information
  - Tenant Statistics
- **Invoice Management**
  - Create Invoice
  - Process Invoice Payment
  - Delete Invoice
  - Search Invoice
  - Invoice Statistics
  - Revenue Statistics
- **Contract Management**
  - Create Contract
  - Update Contract
  - End Contract
  - Search Contract
  - Contract Statistics

### Tenant Features
- Display Invoice Details
- Edit Invoice
- Search Invoice
- Process Invoice Payment

## Setup Instructions
### Prerequisites
- C++ compiler (e.g., g++)
- OpenSSL library for password hashing

### Compilation
To compile the project, use the following command:
```sh
g++ main.cpp models/Person.cpp models/Landlord.cpp models/Tenant.cpp models/Room.cpp models/Invoice.cpp models/User.cpp models/Contract.cpp controllers/RoomController.cpp controllers/InvoiceController.cpp controllers/TenantController.cpp controllers/ContractController.cpp controllers/UserController.cpp views/RoomView.cpp views/InvoiceView.cpp views/TenantView.cpp views/UserView.cpp utils/utils.cpp -o main -lssl -lcrypto
```

### Running the Program
To run the compiled program, use the following command:
```
./main
```
## Usage
1. Login: Enter your email and password to log in. The system will check your role and direct you to the appropriate menu.
2. Admin Menu: If you are an admin, you will have access to room management, tenant management, invoice management, and contract management.
3. Tenant Menu: If you are a tenant, you will have access to view and manage your invoices.

## File Structure
- models/: Contains the data models (Person, Landlord, Tenant, Room, Invoice, User, Contract).
- controllers/: Contains the controllers for managing rooms, tenants, invoices, and contracts.
- views/: Contains the views for displaying information to the user.
- data_structures/: Contains custom data structures used in the project.
- utils/: Contains utility functions and menu display functions.
- main.cpp: The main entry point of the program.

