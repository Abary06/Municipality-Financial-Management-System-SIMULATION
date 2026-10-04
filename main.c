#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "budgets.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"

// Menu functions
void mainMenu(void);

// Input functions
int readInt(void);
float readFloat(void);
void readNonEmptyString(char text[], int size);

// String functions
void copyText(char destination[], const char source[]);


// ==================== MAIN ====================

int main(void)
{
    mainMenu();

    return 0;
}


// ==================== INPUT VALIDATION ====================

// Read a whole number
int readInt(void)
{
    int value;

    while (scanf("%d", &value) != 1)
    {
        printf("Invalid input. Please enter a number: ");

        while (getchar() != '\n')
        {
        }
    }

    while (getchar() != '\n')
    {
    }

    return value;
}


// Read a decimal number
float readFloat(void)
{
    float value;

    while (scanf("%f", &value) != 1)
    {
        printf("Invalid input. Please enter a number: ");

        while (getchar() != '\n')
        {
        }
    }

    while (getchar() != '\n')
    {
    }

    return value;
}


// Read text that cannot be empty
void readNonEmptyString(char text[], int size)
{
    do
    {
        scanf(" %[^\n]", text);

        if (strlen(text) == 0)
        {
            printf("Input cannot be empty. Try again: ");
        }

    } while (strlen(text) == 0);
}


// ==================== STRING FUNCTIONS ====================

void copyText(char destination[], const char source[])
{
    strcpy(destination, source);
}


// ==================== MAIN MENU ====================

void mainMenu(void)
{
    int choice;

    do
    {
        printf("\n====================================\n");
        printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
        printf("====================================\n");
        printf("1. Employee Management\n");
        printf("2. Budget Management\n");
        printf("3. Supplier Management\n");
        printf("4. Asset Management\n");
        printf("5. Reports\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");

        choice = readInt();

        switch (choice)
        {
            case 1:
                employeeMenu();
                break;

            case 2:
                budgetMenu();
                break;

            case 3:
                supplierMenu();
                break;

            case 4:
                assetMenu();
                break;

            case 5:
                reportMenu();
                break;

            case 0:
                printf("Exiting system...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);
}