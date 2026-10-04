#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#define MAX_SUPPLIERS 100

// Supplier structure
typedef struct
{
    int id;
    char name[100];
    char email[100];
    char telephone[30];
    char location[100];
} Supplier;

// Supplier data
extern Supplier suppliers[MAX_SUPPLIERS];
extern int supplierCount;

// Supplier functions
void supplierMenu(void);
void addSupplier(void);
void displaySuppliers(void);
void searchSupplier(void);
void compareSuppliers(void);
int supplierIDExists(int id);

// Input functions from main.c
int readInt(void);
void readNonEmptyString(char text[], int size);

// String functions from main.c
void buildSupplierContact(char result[], Supplier supplier);

#endif