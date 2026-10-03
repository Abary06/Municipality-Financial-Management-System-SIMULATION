#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define MAX_BUDGETS 50

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

// Budget data
struct Budget
{
    char department[50];
    float allocatedBudget;
    float expenditure;
};

// Store data
struct Employee employees[MAX_EMPLOYEES];
struct Budget budgets[MAX_BUDGETS];

int employeeCount = 0;
int budgetCount = 0;

// Menu functions
void mainMenu(void);
void employeeMenu(void);
void budgetMenu(void);

// Employee functions
void addEmployee(void);
void displayEmployees(void);
void searchEmployee(void);
void calculateSalary(void);

// Budget functions
void addBudget(void);
void displayBudgets(void);
void searchBudget(void);
void calculateRemainingBudget(void);

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
                budgetMenu();
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

// Budget menu
void budgetMenu(void)
{
    int choice;

    do
    {
        printf("\n====================================\n");
        printf("         BUDGET MANAGEMENT\n");
        printf("====================================\n");
        printf("1. Add Budget\n");
        printf("2. Display Budgets\n");
        printf("3. Search Budget\n");
        printf("4. Calculate Remaining Budget\n");
        printf("0. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addBudget();
                break;

            case 2:
                displayBudgets();
                break;

            case 3:
                searchBudget();
                break;

            case 4:
                calculateRemainingBudget();
                break;

            case 0:
                printf("\nReturning to main menu...\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 0);
}

// Add budget
void addBudget(void)
{
    if (budgetCount >= MAX_BUDGETS)
    {
        printf("\nBudget storage is full.\n");
        return;
    }

    printf("\nEnter Department: ");
    scanf(" %49[^\n]", budgets[budgetCount].department);

    printf("Enter Allocated Budget: ");
    scanf("%f", &budgets[budgetCount].allocatedBudget);

    printf("Enter Expenditure: ");
    scanf("%f", &budgets[budgetCount].expenditure);

    budgetCount++;

    printf("\nBudget added successfully.\n");
}

// Display budgets
void displayBudgets(void)
{
    int i;
    float remaining;

    if (budgetCount == 0)
    {
        printf("\nNo budgets available.\n");
        return;
    }

    printf("\n========== BUDGET LIST ==========\n");

    for (i = 0; i < budgetCount; i++)
    {
        remaining = budgets[i].allocatedBudget - budgets[i].expenditure;

        printf("\nDepartment: %s\n", budgets[i].department);
        printf("Allocated Budget: %.2f\n", budgets[i].allocatedBudget);
        printf("Expenditure: %.2f\n", budgets[i].expenditure);
        printf("Remaining Budget: %.2f\n", remaining);

        if (remaining >= 0)
        {
            printf("Status: Within Budget\n");
        }
        else
        {
            printf("Status: Over Budget\n");
        }
    }
}

// Search budget
void searchBudget(void)
{
    char department[50];
    int i;
    int found = 0;

    printf("\nEnter Department to search: ");
    scanf(" %49[^\n]", department);

    for (i = 0; i < budgetCount; i++)
    {
        if (strcmp(budgets[i].department, department) == 0)
        {
            printf("\nBudget found!\n");
            printf("Department: %s\n", budgets[i].department);
            printf("Allocated Budget: %.2f\n", budgets[i].allocatedBudget);
            printf("Expenditure: %.2f\n", budgets[i].expenditure);
            printf("Remaining Budget: %.2f\n",
                   budgets[i].allocatedBudget - budgets[i].expenditure);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nBudget not found.\n");
    }
}

// Calculate remaining budget
void calculateRemainingBudget(void)
{
    char department[50];
    int i;
    int found = 0;
    float remaining;

    printf("\nEnter Department: ");
    scanf(" %49[^\n]", department);

    for (i = 0; i < budgetCount; i++)
    {
        if (strcmp(budgets[i].department, department) == 0)
        {
            remaining = budgets[i].allocatedBudget - budgets[i].expenditure;

            printf("\nDepartment: %s\n", budgets[i].department);
            printf("Remaining Budget: %.2f\n", remaining);

            if (remaining >= 0)
            {
                printf("Status: Within Budget\n");
            }
            else
            {
                printf("Status: Over Budget\n");
            }

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nBudget not found.\n");
    }
}