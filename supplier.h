#ifndef SUPPLIER_H
#define SUPPLIER_H

#define MAX_SUPPLIERS 100

// Supplier structure
struct Supplier {
    char supplierID[20];
    char supplierName[100];
    char supplierEmail[50];
    char telephoneNumber[15];
    char location[50];
};

// Function prototypes
int addSupplier(struct Supplier suppliers[], int count);
void displaySuppliers(struct Supplier suppliers[], int count);
void searchSupplier(struct Supplier suppliers[], int count);

#endif