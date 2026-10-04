#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "budgets.h"
#include "suppliers.h"
#include "assets.h"

// Menu functions
void mainMenu(void);
void reportMenu(void);

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