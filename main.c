#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "budgets.h"
#include "suppliers.h"

#define MAX_ASSETS 100


// Asset structure
typedef struct
{
    int id;
    char name[100];
    char type[100];
    float purchaseValue;
    char department[100];
    char condition[100];
} Asset;


// Asset data
Asset assets[MAX_ASSETS];
int assetCount = 0;


// Menu functions
void mainMenu(void);
void assetMenu(void);
void reportMenu(void);


// Asset functions
void addAsset(void);
void displayAssets(void);
void searchAsset(void);


// Report functions
void employeeReport(void);
void budgetReport(void);
void supplierReport(void);
void assetReport(void);


// Input functions
int readInt(void);
float readFloat(void);
void readNonEmptyString(char text[], int size);


// String functions
void copyText(char destination[], const char source[]);


// Duplicate ID functions
int assetIDExists(int id);


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


// ==================== DUPLICATE ID CHECKS ====================

int assetIDExists(int id)
{
    int i;

    for (i = 0; i < assetCount; i++)
    {
        if (assets[i].id == id)
        {
            return 1;
        }
    }

    return 0;
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


// ==================== ASSET MENU ====================

void assetMenu(void)
{
    int choice;

    do
    {
        printf("\n========== ASSET MANAGEMENT ==========\n");
        printf("1. Add Asset\n");
        printf("2. Display Assets\n");
        printf("3. Search Asset\n");
        printf("0. Back\n");
        printf("Enter your choice: ");

        choice = readInt();

        switch (choice)
        {
            case 1:
                addAsset();
                break;

            case 2:
                displayAssets();
                break;

            case 3:
                searchAsset();
                break;

            case 0:
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);
}


// ==================== ASSET FUNCTIONS ====================

void addAsset(void)
{
    if (assetCount >= MAX_ASSETS)
    {
        printf("Asset limit reached.\n");
        return;
    }

    do
    {
        printf("Enter Asset ID: ");
        assets[assetCount].id = readInt();

        if (assets[assetCount].id <= 0)
        {
            printf("Asset ID must be greater than 0.\n");
        }
        else if (assetIDExists(assets[assetCount].id))
        {
            printf("Asset ID already exists. Enter a different ID.\n");
        }

    } while (assets[assetCount].id <= 0 ||
             assetIDExists(assets[assetCount].id));

    printf("Enter Asset Name: ");
    readNonEmptyString(assets[assetCount].name,
                       sizeof(assets[assetCount].name));

    printf("Enter Asset Type: ");
    readNonEmptyString(assets[assetCount].type,
                       sizeof(assets[assetCount].type));

    do
    {
        printf("Enter Purchase Value: ");
        assets[assetCount].purchaseValue = readFloat();

        if (assets[assetCount].purchaseValue < 0)
        {
            printf("Purchase value cannot be negative.\n");
        }

    } while (assets[assetCount].purchaseValue < 0);

    printf("Enter Department: ");
    readNonEmptyString(assets[assetCount].department,
                       sizeof(assets[assetCount].department));

    printf("Enter Condition: ");
    readNonEmptyString(assets[assetCount].condition,
                       sizeof(assets[assetCount].condition));

    assetCount++;

    printf("Asset added successfully.\n");
}


void displayAssets(void)
{
    int i;

    if (assetCount == 0)
    {
        printf("No assets available.\n");
        return;
    }

    printf("\n========== ASSETS ==========\n");

    for (i = 0; i < assetCount; i++)
    {
        printf("\nAsset ID: %d\n", assets[i].id);
        printf("Name: %s\n", assets[i].name);
        printf("Type: %s\n", assets[i].type);
        printf("Purchase Value: %.2f\n",
               assets[i].purchaseValue);
        printf("Department: %s\n", assets[i].department);
        printf("Condition: %s\n", assets[i].condition);
    }
}


void searchAsset(void)
{
    int id;
    int i;

    printf("Enter Asset ID to search: ");
    id = readInt();

    for (i = 0; i < assetCount; i++)
    {
        if (assets[i].id == id)
        {
            printf("\nAsset Found\n");
            printf("ID: %d\n", assets[i].id);
            printf("Name: %s\n", assets[i].name);
            printf("Type: %s\n", assets[i].type);
            printf("Purchase Value: %.2f\n",
                   assets[i].purchaseValue);
            printf("Department: %s\n", assets[i].department);
            printf("Condition: %s\n", assets[i].condition);
            return;
        }
    }

    printf("Asset not found.\n");
}


// ==================== REPORT MENU ====================

void reportMenu(void)
{
    int choice;

    do
    {
        printf("\n========== REPORTS ==========\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("0. Back\n");
        printf("Enter your choice: ");

        choice = readInt();

        switch (choice)
        {
            case 1:
                employeeReport();
                break;

            case 2:
                budgetReport();
                break;

            case 3:
                supplierReport();
                break;

            case 4:
                assetReport();
                break;

            case 0:
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);
}


// ==================== REPORTS ====================

void employeeReport(void)
{
    int i;
    float total = 0;
    float average;
    float highest;
    float lowest;

    if (employeeCount == 0)
    {
        printf("No employees available for report.\n");
        return;
    }

    highest = calculateSalary(employees[0]);
    lowest = calculateSalary(employees[0]);

    for (i = 0; i < employeeCount; i++)
    {
        float salary = calculateSalary(employees[i]);

        total += salary;

        if (salary > highest)
        {
            highest = salary;
        }

        if (salary < lowest)
        {
            lowest = salary;
        }
    }

    average = total / employeeCount;

    printf("\n========== EMPLOYEE REPORT ==========\n");
    printf("Total Employees: %d\n", employeeCount);
    printf("Average Salary: %.2f\n", average);
    printf("Highest Salary: %.2f\n", highest);
    printf("Lowest Salary: %.2f\n", lowest);
}


void budgetReport(void)
{
    int i;
    float totalAllocated = 0;
    float totalExpenditure = 0;
    float totalRemaining = 0;

    if (budgetCount == 0)
    {
        printf("No budgets available for report.\n");
        return;
    }

    for (i = 0; i < budgetCount; i++)
    {
        totalAllocated += budgets[i].allocatedBudget;
        totalExpenditure += budgets[i].expenditure;
        totalRemaining += budgets[i].allocatedBudget -
                           budgets[i].expenditure;
    }

    printf("\n========== BUDGET REPORT ==========\n");
    printf("Total Allocated: %.2f\n", totalAllocated);
    printf("Total Expenditure: %.2f\n", totalExpenditure);
    printf("Total Remaining: %.2f\n", totalRemaining);

    printf("\nDepartments Exceeding Budget:\n");

    for (i = 0; i < budgetCount; i++)
    {
        if (budgets[i].expenditure > budgets[i].allocatedBudget)
        {
            printf("- %s\n", budgets[i].department);
        }
    }
}


void supplierReport(void)
{
    int i;

    printf("\n========== SUPPLIER REPORT ==========\n");
    printf("Total Suppliers: %d\n", supplierCount);

    for (i = 0; i < supplierCount; i++)
    {
        printf("%d. %s - %s\n",
               suppliers[i].id,
               suppliers[i].name,
               suppliers[i].location);
    }
}


void assetReport(void)
{
    int i;

    printf("\n========== ASSET REPORT ==========\n");
    printf("Total Assets: %d\n", assetCount);

    for (i = 0; i < assetCount; i++)
    {
        printf("%d. %s - %.2f - %s\n",
               assets[i].id,
               assets[i].name,
               assets[i].purchaseValue,
               assets[i].condition);
    }
}