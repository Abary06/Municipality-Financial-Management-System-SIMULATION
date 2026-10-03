#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define MAX_BUDGETS 50
#define MAX_SUPPLIERS 100
#define MAX_ASSETS 100

typedef struct
{
    int id;
    char name[50];
    char department[50];
    float basicSalary;
    float housingAllowance;
    float transportAllowance;
} Employee;

typedef struct
{
    int id;
    char department[50];
    float allocated;
    float expenditure;
} Budget;

typedef struct
{
    int id;
    char name[50];
    char email[100];
    char telephone[30];
    char town[50];
} Supplier;

typedef struct
{
    int id;
    char name[50];
    char type[50];
    float purchaseValue;
    char department[50];
    char condition[30];
} Asset;

Employee employees[MAX_EMPLOYEES];
Budget budgets[MAX_BUDGETS];
Supplier suppliers[MAX_SUPPLIERS];
Asset assets[MAX_ASSETS];

int employeeCount = 0;
int budgetCount = 0;
int supplierCount = 0;
int assetCount = 0;

/* Function prototypes */
void mainMenu(void);

void employeeMenu(void);
void addEmployee(void);
void displayEmployees(void);
void searchEmployee(void);
void calculateSalary(void);

void budgetMenu(void);
void addBudget(void);
void displayBudgets(void);
void searchBudget(void);
void calculateRemainingBudget(void);

void supplierMenu(void);
void addSupplier(void);
void displaySuppliers(void);
void searchSupplier(void);

void assetMenu(void);
void addAsset(void);
void displayAssets(void);
void searchAsset(void);

void reportMenu(void);
void employeeReport(void);
void budgetReport(void);
void supplierReport(void);
void assetReport(void);

int main(void)
{
    mainMenu();

    return 0;
}

/* Main Menu */
void mainMenu(void)
{
    int choice;

    do
    {
        printf("\n===== MUNICIPAL FINANCIAL MANAGEMENT SYSTEM =====\n");
        printf("1. Employee Management\n");
        printf("2. Budget Management\n");
        printf("3. Supplier Management\n");
        printf("4. Asset Management\n");
        printf("5. Reports\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
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
                supplierMenu();
                break;

            case 4:
                assetMenu();
                break;

            case 5:
                reportMenu();
                break;

            case 0:
                printf("\nExiting system...\n");
                break;

            default:
                printf("\nInvalid choice.\n");
        }

    } while (choice != 0);
}

/* Employee Management */
void employeeMenu(void)
{
    int choice;

    do
    {
        printf("\n===== EMPLOYEE MANAGEMENT =====\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Calculate Salary\n");
        printf("0. Back\n");
        printf("Enter choice: ");
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
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 0);
}

void addEmployee(void)
{
    if (employeeCount >= MAX_EMPLOYEES)
    {
        printf("Employee storage is full.\n");
        return;
    }

    printf("\nEnter Employee ID: ");
    scanf("%d", &employees[employeeCount].id);

    printf("Enter Employee Name: ");
    scanf(" %[^\n]", employees[employeeCount].name);

    printf("Enter Department: ");
    scanf(" %[^\n]", employees[employeeCount].department);

    printf("Enter Basic Salary: ");
    scanf("%f", &employees[employeeCount].basicSalary);

    printf("Enter Housing Allowance: ");
    scanf("%f", &employees[employeeCount].housingAllowance);

    printf("Enter Transport Allowance: ");
    scanf("%f", &employees[employeeCount].transportAllowance);

    employeeCount++;

    printf("Employee added successfully.\n");
}

void displayEmployees(void)
{
    int i;

    if (employeeCount == 0)
    {
        printf("\nNo employees available.\n");
        return;
    }

    printf("\n===== EMPLOYEE LIST =====\n");

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

void searchEmployee(void)
{
    int id;
    int i;
    int found = 0;

    printf("\nEnter Employee ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < employeeCount; i++)
    {
        if (employees[i].id == id)
        {
            printf("\nEmployee found!\n");
            printf("ID: %d\n", employees[i].id);
            printf("Name: %s\n", employees[i].name);
            printf("Department: %s\n", employees[i].department);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Employee not found.\n");
    }
}

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
            printf("Total Salary: %.2f\n", totalSalary);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Employee not found.\n");
    }
}

/* Budget Management */
void budgetMenu(void)
{
    int choice;

    do
    {
        printf("\n===== BUDGET MANAGEMENT =====\n");
        printf("1. Add Budget\n");
        printf("2. Display Budgets\n");
        printf("3. Search Budget\n");
        printf("4. Calculate Remaining Budget\n");
        printf("0. Back\n");
        printf("Enter choice: ");
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
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 0);
}

void addBudget(void)
{
    if (budgetCount >= MAX_BUDGETS)
    {
        printf("Budget storage is full.\n");
        return;
    }

    printf("\nEnter Budget ID: ");
    scanf("%d", &budgets[budgetCount].id);

    printf("Enter Department: ");
    scanf(" %[^\n]", budgets[budgetCount].department);

    printf("Enter Allocated Budget: ");
    scanf("%f", &budgets[budgetCount].allocated);

    printf("Enter Expenditure: ");
    scanf("%f", &budgets[budgetCount].expenditure);

    budgetCount++;

    printf("Budget added successfully.\n");
}

void displayBudgets(void)
{
    int i;

    if (budgetCount == 0)
    {
        printf("\nNo budgets available.\n");
        return;
    }

    printf("\n===== BUDGET LIST =====\n");

    for (i = 0; i < budgetCount; i++)
    {
        printf("\nBudget ID: %d\n", budgets[i].id);
        printf("Department: %s\n", budgets[i].department);
        printf("Allocated Budget: %.2f\n", budgets[i].allocated);
        printf("Expenditure: %.2f\n", budgets[i].expenditure);
    }
}

void searchBudget(void)
{
    int id;
    int i;
    int found = 0;

    printf("\nEnter Budget ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < budgetCount; i++)
    {
        if (budgets[i].id == id)
        {
            printf("\nBudget found!\n");
            printf("ID: %d\n", budgets[i].id);
            printf("Department: %s\n", budgets[i].department);
            printf("Allocated Budget: %.2f\n", budgets[i].allocated);
            printf("Expenditure: %.2f\n", budgets[i].expenditure);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Budget not found.\n");
    }
}

void calculateRemainingBudget(void)
{
    int id;
    int i;
    int found = 0;
    float remaining;

    printf("\nEnter Budget ID: ");
    scanf("%d", &id);

    for (i = 0; i < budgetCount; i++)
    {
        if (budgets[i].id == id)
        {
            remaining = budgets[i].allocated - budgets[i].expenditure;

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
        printf("Budget not found.\n");
    }
}

/* Supplier Management */
void supplierMenu(void)
{
    int choice;

    do
    {
        printf("\n===== SUPPLIER MANAGEMENT =====\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("0. Back\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

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

            case 0:
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 0);
}

void addSupplier(void)
{
    if (supplierCount >= MAX_SUPPLIERS)
    {
        printf("Supplier storage is full.\n");
        return;
    }

    printf("\nEnter Supplier ID: ");
    scanf("%d", &suppliers[supplierCount].id);

    printf("Enter Supplier Name: ");
    scanf(" %[^\n]", suppliers[supplierCount].name);

    printf("Enter Email: ");
    scanf(" %[^\n]", suppliers[supplierCount].email);

    printf("Enter Telephone: ");
    scanf(" %[^\n]", suppliers[supplierCount].telephone);

    printf("Enter Town/Location: ");
    scanf(" %[^\n]", suppliers[supplierCount].town);

    supplierCount++;

    printf("Supplier added successfully.\n");
}

void displaySuppliers(void)
{
    int i;

    if (supplierCount == 0)
    {
        printf("\nNo suppliers available.\n");
        return;
    }

    printf("\n===== SUPPLIER LIST =====\n");

    for (i = 0; i < supplierCount; i++)
    {
        printf("\nSupplier ID: %d\n", suppliers[i].id);
        printf("Name: %s\n", suppliers[i].name);
        printf("Email: %s\n", suppliers[i].email);
        printf("Telephone: %s\n", suppliers[i].telephone);
        printf("Town/Location: %s\n", suppliers[i].town);
    }
}

void searchSupplier(void)
{
    int id;
    int i;
    int found = 0;

    printf("\nEnter Supplier ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < supplierCount; i++)
    {
        if (suppliers[i].id == id)
        {
            printf("\nSupplier found!\n");
            printf("ID: %d\n", suppliers[i].id);
            printf("Name: %s\n", suppliers[i].name);
            printf("Email: %s\n", suppliers[i].email);
            printf("Telephone: %s\n", suppliers[i].telephone);
            printf("Town/Location: %s\n", suppliers[i].town);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Supplier not found.\n");
    }
}

/* Asset Management */
void assetMenu(void)
{
    int choice;

    do
    {
        printf("\n===== ASSET MANAGEMENT =====\n");
        printf("1. Add Asset\n");
        printf("2. Display Assets\n");
        printf("3. Search Asset\n");
        printf("0. Back\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

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
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 0);
}

void addAsset(void)
{
    if (assetCount >= MAX_ASSETS)
    {
        printf("Asset storage is full.\n");
        return;
    }

    printf("\nEnter Asset ID: ");
    scanf("%d", &assets[assetCount].id);

    printf("Enter Asset Name: ");
    scanf(" %[^\n]", assets[assetCount].name);

    printf("Enter Asset Type: ");
    scanf(" %[^\n]", assets[assetCount].type);

    printf("Enter Purchase Value: ");
    scanf("%f", &assets[assetCount].purchaseValue);

    printf("Enter Department: ");
    scanf(" %[^\n]", assets[assetCount].department);

    printf("Enter Condition: ");
    scanf(" %[^\n]", assets[assetCount].condition);

    assetCount++;

    printf("Asset added successfully.\n");
}

void displayAssets(void)
{
    int i;

    if (assetCount == 0)
    {
        printf("\nNo assets available.\n");
        return;
    }

    printf("\n===== ASSET LIST =====\n");

    for (i = 0; i < assetCount; i++)
    {
        printf("\nAsset ID: %d\n", assets[i].id);
        printf("Name: %s\n", assets[i].name);
        printf("Type: %s\n", assets[i].type);
        printf("Purchase Value: %.2f\n", assets[i].purchaseValue);
        printf("Department: %s\n", assets[i].department);
        printf("Condition: %s\n", assets[i].condition);
    }
}

void searchAsset(void)
{
    int id;
    int i;
    int found = 0;

    printf("\nEnter Asset ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < assetCount; i++)
    {
        if (assets[i].id == id)
        {
            printf("\nAsset found!\n");
            printf("ID: %d\n", assets[i].id);
            printf("Name: %s\n", assets[i].name);
            printf("Type: %s\n", assets[i].type);
            printf("Purchase Value: %.2f\n", assets[i].purchaseValue);
            printf("Department: %s\n", assets[i].department);
            printf("Condition: %s\n", assets[i].condition);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Asset not found.\n");
    }
}

/* Reports */
void reportMenu(void)
{
    int choice;

    do
    {
        printf("\n===== REPORTS =====\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("0. Back\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

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
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 0);
}

/* Employee Report */
void employeeReport(void)
{
    int i;
    float totalSalary = 0;
    float averageSalary;
    float highestSalary = 0;
    float lowestSalary = 0;
    float salary;

    if (employeeCount == 0)
    {
        printf("\nNo employee data available.\n");
        return;
    }

    for (i = 0; i < employeeCount; i++)
    {
        salary = employees[i].basicSalary
               + employees[i].housingAllowance
               + employees[i].transportAllowance;

        totalSalary += salary;

        if (i == 0)
        {
            highestSalary = salary;
            lowestSalary = salary;
        }

        if (salary > highestSalary)
        {
            highestSalary = salary;
        }

        if (salary < lowestSalary)
        {
            lowestSalary = salary;
        }
    }

    averageSalary = totalSalary / employeeCount;

    printf("\n===== EMPLOYEE REPORT =====\n");
    printf("Total Employees: %d\n", employeeCount);
    printf("Average Salary: %.2f\n", averageSalary);
    printf("Highest Salary: %.2f\n", highestSalary);
    printf("Lowest Salary: %.2f\n", lowestSalary);
}

/* Budget Report */
void budgetReport(void)
{
    int i;
    float totalAllocated = 0;
    float totalExpenditure = 0;
    float totalRemaining;
    int overBudget = 0;

    if (budgetCount == 0)
    {
        printf("\nNo budget data available.\n");
        return;
    }

    for (i = 0; i < budgetCount; i++)
    {
        totalAllocated += budgets[i].allocated;
        totalExpenditure += budgets[i].expenditure;

        if (budgets[i].expenditure > budgets[i].allocated)
        {
            overBudget++;
        }
    }

    totalRemaining = totalAllocated - totalExpenditure;

    printf("\n===== BUDGET REPORT =====\n");
    printf("Total Allocated: %.2f\n", totalAllocated);
    printf("Total Expenditure: %.2f\n", totalExpenditure);
    printf("Total Remaining: %.2f\n", totalRemaining);
    printf("Departments Over Budget: %d\n", overBudget);

    if (overBudget > 0)
    {
        printf("\nDepartments Exceeding Budget:\n");

        for (i = 0; i < budgetCount; i++)
        {
            if (budgets[i].expenditure > budgets[i].allocated)
            {
                printf("- %s\n", budgets[i].department);
            }
        }
    }
}

/* Supplier Report */
void supplierReport(void)
{
    int i;

    if (supplierCount == 0)
    {
        printf("\nNo supplier data available.\n");
        return;
    }

    printf("\n===== SUPPLIER REPORT =====\n");
    printf("Total Suppliers: %d\n", supplierCount);

    for (i = 0; i < supplierCount; i++)
    {
        printf("\nSupplier ID: %d\n", suppliers[i].id);
        printf("Name: %s\n", suppliers[i].name);
        printf("Email: %s\n", suppliers[i].email);
        printf("Telephone: %s\n", suppliers[i].telephone);
        printf("Town/Location: %s\n", suppliers[i].town);
    }
}

/* Asset Report */
void assetReport(void)
{
    int i;
    float totalValue = 0;

    if (assetCount == 0)
    {
        printf("\nNo asset data available.\n");
        return;
    }

    for (i = 0; i < assetCount; i++)
    {
        totalValue += assets[i].purchaseValue;
    }

    printf("\n===== ASSET REPORT =====\n");
    printf("Total Assets: %d\n", assetCount);
    printf("Total Purchase Value: %.2f\n", totalValue);

    for (i = 0; i < assetCount; i++)
    {
        printf("\nAsset ID: %d\n", assets[i].id);
        printf("Name: %s\n", assets[i].name);
        printf("Type: %s\n", assets[i].type);
        printf("Department: %s\n", assets[i].department);
        printf("Condition: %s\n", assets[i].condition);
    }
}