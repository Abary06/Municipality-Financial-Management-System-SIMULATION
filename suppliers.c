#include <stdio.h>
#include <string.h>
#include "suppliers.h"

// Supplier data
Supplier suppliers[MAX_SUPPLIERS];
int supplierCount = 0;


// Build supplier contact
void buildSupplierContact(char result[], Supplier supplier)
{
    strcpy(result, supplier.email);
    strcat(result, " | ");
    strcat(result, supplier.telephone);
}


// Check if Supplier ID already exists
int supplierIDExists(int id)
{
    int i;

    for (i = 0; i < supplierCount; i++)
    {
        if (suppliers[i].id == id)
        {
            return 1;
        }
    }

    return 0;
}


// Supplier Menu
void supplierMenu(void)
{
    int choice;

    do
    {
        printf("\n========== SUPPLIER MANAGEMENT ==========\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Compare Suppliers\n");
        printf("0. Back\n");
        printf("Enter your choice: ");

        choice = readInt();

        switch (choice)
        {
            case 1:
                addSupplier();
                break;

            case 2:
                displaySuppliers();
                break;

            case 3:
                searchSupplier();
                break;

            case 4:
                compareSuppliers();
                break;

            case 0:
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);
}


// Add Supplier
void addSupplier(void)
{
    if (supplierCount >= MAX_SUPPLIERS)
    {
        printf("Supplier limit reached.\n");
        return;
    }

    do
    {
        printf("Enter Supplier ID: ");
        suppliers[supplierCount].id = readInt();

        if (suppliers[supplierCount].id <= 0)
        {
            printf("Supplier ID must be greater than 0.\n");
        }
        else if (supplierIDExists(suppliers[supplierCount].id))
        {
            printf("Supplier ID already exists. Enter a different ID.\n");
        }

    } while (suppliers[supplierCount].id <= 0 ||
             supplierIDExists(suppliers[supplierCount].id));

    printf("Enter Supplier Name: ");
    readNonEmptyString(suppliers[supplierCount].name,
                       sizeof(suppliers[supplierCount].name));

    printf("Enter Supplier Email: ");
    readNonEmptyString(suppliers[supplierCount].email,
                       sizeof(suppliers[supplierCount].email));

    printf("Enter Supplier Telephone: ");
    readNonEmptyString(suppliers[supplierCount].telephone,
                       sizeof(suppliers[supplierCount].telephone));

    printf("Enter Supplier Location/Town: ");
    readNonEmptyString(suppliers[supplierCount].location,
                       sizeof(suppliers[supplierCount].location));

    supplierCount++;

    printf("Supplier added successfully.\n");
}


// Display Suppliers
void displaySuppliers(void)
{
    int i;
    char contact[150];

    if (supplierCount == 0)
    {
        printf("No suppliers available.\n");
        return;
    }

    printf("\n========== SUPPLIERS ==========\n");

    for (i = 0; i < supplierCount; i++)
    {
        buildSupplierContact(contact, suppliers[i]);

        printf("\nSupplier ID: %d\n", suppliers[i].id);
        printf("Name: %s\n", suppliers[i].name);
        printf("Email / Telephone: %s\n", contact);
        printf("Location: %s\n", suppliers[i].location);
    }
}


// Search Supplier
void searchSupplier(void)
{
    int id;
    int i;

    printf("Enter Supplier ID to search: ");
    id = readInt();

    for (i = 0; i < supplierCount; i++)
    {
        if (suppliers[i].id == id)
        {
            printf("\nSupplier Found\n");
            printf("ID: %d\n", suppliers[i].id);
            printf("Name: %s\n", suppliers[i].name);
            printf("Email: %s\n", suppliers[i].email);
            printf("Telephone: %s\n", suppliers[i].telephone);
            printf("Location: %s\n", suppliers[i].location);
            return;
        }
    }

    printf("Supplier not found.\n");
}


// Compare Suppliers
void compareSuppliers(void)
{
    int id1;
    int id2;
    int i;
    int firstFound = 0;
    int secondFound = 0;

    printf("Enter first Supplier ID: ");
    id1 = readInt();

    printf("Enter second Supplier ID: ");
    id2 = readInt();

    for (i = 0; i < supplierCount; i++)
    {
        if (suppliers[i].id == id1)
        {
            firstFound = 1;
        }

        if (suppliers[i].id == id2)
        {
            secondFound = 1;
        }
    }

    if (!firstFound || !secondFound)
    {
        printf("One or both suppliers were not found.\n");
        return;
    }

    for (i = 0; i < supplierCount; i++)
    {
        if (suppliers[i].id == id1)
        {
            printf("\nSupplier 1: %s\n", suppliers[i].name);
            printf("Location: %s\n", suppliers[i].location);
        }

        if (suppliers[i].id == id2)
        {
            printf("Supplier 2: %s\n", suppliers[i].name);
            printf("Location: %s\n", suppliers[i].location);
        }
    }

    for (i = 0; i < supplierCount; i++)
    {
        if (suppliers[i].id == id1)
        {
            int j;

            for (j = 0; j < supplierCount; j++)
            {
                if (suppliers[j].id == id2)
                {
                    if (strcmp(suppliers[i].location,
                               suppliers[j].location) == 0)
                    {
                        printf("Both suppliers are in the same location.\n");
                    }
                    else
                    {
                        printf("The suppliers are in different locations.\n");
                    }

                    return;
                }
            }
        }
    }
}