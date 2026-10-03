#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

// Employee data
struct Employee
{
    int id;
    char name[50];
    char department[50];
    float basicSalary;
    float housingAllowance;
    float transportAllowance;
};

// Store employee data
struct Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

// Menu functions
void mainMenu(void);
void employeeMenu(void);

// Employee functions
void addEmployee(void);
void displayEmployees(void);
void searchEmployee(void);
void calculateSalary(void);

// Main function
int main(void)
{
    mainMenu();

    return 0;
}

// Display main menu
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
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                employeeMenu();
                break;

            case 2:
                printf("\nBudget Management is not available yet.\n");
                break;

            case 3:
                printf("\nSupplier Management is not available yet.\n");
                break;

            case 4:
                printf("\nAsset Management is not available yet.\n");
                break;

            case 5:
                printf("\nReports are not available yet.\n");
                break;

            case 0:
                printf("\nExiting system...\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 0);
}

// Employee menu
void employeeMenu(void)
{
    int choice;

    do
    {
        printf("\n====================================\n");
        printf("       EMPLOYEE MANAGEMENT\n");
        printf("====================================\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Calculate Salary\n");
        printf("0. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addEmployee();
                break;

            case 2:
                displayEmployees();
                break;

            case 3:
                searchEmployee();
                break;

            case 4:
                calculateSalary();
                break;

            case 0:
                printf("\nReturning to main menu...\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 0);
}

// Add employee
void addEmployee(void)
{
    if (employeeCount >= MAX_EMPLOYEES)
    {
        printf("\nEmployee storage is full.\n");
        return;
    }

    printf("\nEnter Employee ID: ");
    scanf("%d", &employees[employeeCount].id);

    printf("Enter Employee Name: ");
    scanf(" %49[^\n]", employees[employeeCount].name);

    printf("Enter Department: ");
    scanf(" %49[^\n]", employees[employeeCount].department);

    printf("Enter Basic Salary: ");
    scanf("%f", &employees[employeeCount].basicSalary);

    printf("Enter Housing Allowance: ");
    scanf("%f", &employees[employeeCount].housingAllowance);

    printf("Enter Transport Allowance: ");
    scanf("%f", &employees[employeeCount].transportAllowance);

    employeeCount++;

    printf("\nEmployee added successfully.\n");
}

// Display employees
void displayEmployees(void)
{
    int i;

    if (employeeCount == 0)
    {
        printf("\nNo employees available.\n");
        return;
    }

    printf("\n========== EMPLOYEE LIST ==========\n");

    for (i = 0; i < employeeCount; i++)
    {
        printf("\nEmployee ID: %d\n", employees[i].id);
        printf("Name: %s\n", employees[i].name);
        printf("Department: %s\n", employees[i].department);
        printf("Basic Salary: %.2f\n", employees[i].basicSalary);
        printf("Housing Allowance: %.2f\n", employees[i].housingAllowance);
        printf("Transport Allowance: %.2f\n", employees[i].transportAllowance);
    }
}

// Search employee
void searchEmployee(void)
{
    char name[50];
    int i;
    int found = 0;

    printf("\nEnter employee name to search: ");
    scanf(" %49[^\n]", name);

    for (i = 0; i < employeeCount; i++)
    {
        if (strcmp(employees[i].name, name) == 0)
        {
            printf("\nEmployee found!\n");
            printf("Employee ID: %d\n", employees[i].id);
            printf("Name: %s\n", employees[i].name);
            printf("Department: %s\n", employees[i].department);
            printf("Basic Salary: %.2f\n", employees[i].basicSalary);
            printf("Housing Allowance: %.2f\n", employees[i].housingAllowance);
            printf("Transport Allowance: %.2f\n", employees[i].transportAllowance);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nEmployee not found.\n");
    }
}

// Calculate salary
void calculateSalary(void)
{
    int id;
    int i;
    int found = 0;
    float totalSalary;

    printf("\nEnter Employee ID: ");
    scanf("%d", &id);

    for (i = 0; i < employeeCount; i++)
    {
        if (employees[i].id == id)
        {
            totalSalary = employees[i].basicSalary
                        + employees[i].housingAllowance
                        + employees[i].transportAllowance;

            printf("\nEmployee: %s\n", employees[i].name);
            printf("Basic Salary: %.2f\n", employees[i].basicSalary);
            printf("Housing Allowance: %.2f\n", employees[i].housingAllowance);
            printf("Transport Allowance: %.2f\n", employees[i].transportAllowance);
            printf("Total Salary: %.2f\n", totalSalary);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nEmployee not found.\n");
    }
}