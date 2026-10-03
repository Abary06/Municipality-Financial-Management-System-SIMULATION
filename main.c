#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define MAX_BUDGETS 50
#define MAX_SUPPLIERS 100
#define MAX_ASSETS 100

/* =========================
   STRUCTURES
   ========================= */

typedef struct {
    int id;
    char name[100];
    char department[100];
    float basicSalary;
    float housingAllowance;
    float transportAllowance;
} Employee;

typedef struct {
    int id;
    char department[100];
    float allocatedBudget;
    float expenditure;
} Budget;

typedef struct {
    int id;
    char name[100];
    char email[100];
    char telephone[30];
    char location[100];
} Supplier;

typedef struct {
    int id;
    char name[100];
    char type[100];
    float purchaseValue;
    char department[100];
    char condition[100];
} Asset;


/* =========================
   ARRAYS AND COUNTERS
   ========================= */

Employee employees[MAX_EMPLOYEES];
Budget budgets[MAX_BUDGETS];
Supplier suppliers[MAX_SUPPLIERS];
Asset assets[MAX_ASSETS];

int employeeCount = 0;
int budgetCount = 0;
int supplierCount = 0;
int assetCount = 0;


/* =========================
   FUNCTION DECLARATIONS
   ========================= */

/* Menus */
void mainMenu(void);
void employeeMenu(void);
void budgetMenu(void);
void supplierMenu(void);
void assetMenu(void);
void reportMenu(void);

/* Employees */
void addEmployee(void);
void displayEmployees(void);
void searchEmployee(void);
float calculateSalary(Employee employee);

/* Budgets */
void addBudget(void);
void displayBudgets(void);
void searchBudget(void);
float calculateRemainingBudget(Budget budget);

/* Suppliers */
void addSupplier(void);
void displaySuppliers(void);
void searchSupplier(void);
void compareSuppliers(void);

/* Assets */
void addAsset(void);
void displayAssets(void);
void searchAsset(void);

/* Reports */
void employeeReport(void);
void budgetReport(void);
void supplierReport(void);
void assetReport(void);

/* String / validation helpers */
void readNonEmptyString(char text[], int size);
void copyText(char destination[], char source[]);
void buildSupplierContact(Supplier supplier, char result[]);

/* Duplicate ID validation */
int employeeIDExists(int id);
int budgetIDExists(int id);
int supplierIDExists(int id);
int assetIDExists(int id);


/* =========================
   MAIN
   ========================= */

int main(void)
{
    mainMenu();

    return 0;
}


/* =========================
   MAIN MENU
   ========================= */

void mainMenu(void)
{
    int choice;

    do {
        printf("\n========================================\n");
        printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
        printf("========================================\n");
        printf("1. Employee Management\n");
        printf("2. Budget Management\n");
        printf("3. Supplier Management\n");
        printf("4. Asset Management\n");
        printf("5. Reports\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 0);
}


/* =========================
   EMPLOYEE MENU
   ========================= */

void employeeMenu(void)
{
    int choice;

    do {
        printf("\n========== EMPLOYEE MANAGEMENT ==========\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Calculate Employee Salary\n");
        printf("0. Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
                if (employeeCount == 0) {
                    printf("\nNo employees available.\n");
                } else {
                    int id;
                    int found = 0;

                    printf("\nEnter Employee ID: ");
                    scanf("%d", &id);

                    for (int i = 0; i < employeeCount; i++) {
                        if (employees[i].id == id) {
                            printf("\nEmployee: %s\n", employees[i].name);
                            printf("Total Salary: N$%.2f\n",
                                   calculateSalary(employees[i]));
                            found = 1;
                            break;
                        }
                    }

                    if (!found) {
                        printf("\nEmployee not found.\n");
                    }
                }
                break;

            case 0:
                break;

            default:
                printf("\nInvalid choice.\n");
        }

    } while (choice != 0);
}


/* =========================
   ADD EMPLOYEE
   ========================= */

void addEmployee(void)
{
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("\nEmployee storage is full.\n");
        return;
    }

    printf("\n========== ADD EMPLOYEE ==========\n");

    do {
        printf("Enter Employee ID: ");
        scanf("%d", &employees[employeeCount].id);

        if (employees[employeeCount].id <= 0) {
            printf("Employee ID must be greater than 0.\n");
        } else if (employeeIDExists(employees[employeeCount].id)) {
            printf("Employee ID already exists. Enter a different ID.\n");
        }

    } while (employees[employeeCount].id <= 0 ||
             employeeIDExists(employees[employeeCount].id));

    printf("Enter Employee Name: ");
    readNonEmptyString(employees[employeeCount].name, 100);

    printf("Enter Department: ");
    readNonEmptyString(employees[employeeCount].department, 100);

    do {
        printf("Enter Basic Salary: ");
        scanf("%f", &employees[employeeCount].basicSalary);

        if (employees[employeeCount].basicSalary < 0) {
            printf("Salary cannot be negative.\n");
        }

    } while (employees[employeeCount].basicSalary < 0);

    do {
        printf("Enter Housing Allowance: ");
        scanf("%f", &employees[employeeCount].housingAllowance);

        if (employees[employeeCount].housingAllowance < 0) {
            printf("Allowance cannot be negative.\n");
        }

    } while (employees[employeeCount].housingAllowance < 0);

    do {
        printf("Enter Transport Allowance: ");
        scanf("%f", &employees[employeeCount].transportAllowance);

        if (employees[employeeCount].transportAllowance < 0) {
            printf("Allowance cannot be negative.\n");
        }

    } while (employees[employeeCount].transportAllowance < 0);

    employeeCount++;

    printf("\nEmployee added successfully.\n");
}


/* =========================
   DISPLAY EMPLOYEES
   ========================= */

void displayEmployees(void)
{
    if (employeeCount == 0) {
        printf("\nNo employees available.\n");
        return;
    }

    printf("\n========== EMPLOYEE LIST ==========\n");

    for (int i = 0; i < employeeCount; i++) {
        printf("\nEmployee ID: %d\n", employees[i].id);
        printf("Name: %s\n", employees[i].name);
        printf("Department: %s\n", employees[i].department);
        printf("Basic Salary: N$%.2f\n", employees[i].basicSalary);
        printf("Housing Allowance: N$%.2f\n",
               employees[i].housingAllowance);
        printf("Transport Allowance: N$%.2f\n",
               employees[i].transportAllowance);
        printf("Total Salary: N$%.2f\n",
               calculateSalary(employees[i]));
    }
}


/* =========================
   SEARCH EMPLOYEE
   ========================= */

void searchEmployee(void)
{
    char searchName[100];
    int found = 0;

    if (employeeCount == 0) {
        printf("\nNo employees available.\n");
        return;
    }

    printf("\nEnter employee name to search: ");
    readNonEmptyString(searchName, 100);

    for (int i = 0; i < employeeCount; i++) {

        if (strcmp(employees[i].name, searchName) == 0) {
            printf("\nEmployee found!\n");
            printf("ID: %d\n", employees[i].id);
            printf("Name: %s\n", employees[i].name);
            printf("Department: %s\n", employees[i].department);
            printf("Total Salary: N$%.2f\n",
                   calculateSalary(employees[i]));

            found = 1;
        }
    }

    if (!found) {
        printf("\nEmployee not found.\n");
    }
}


/* =========================
   CALCULATE SALARY
   ========================= */

float calculateSalary(Employee employee)
{
    return employee.basicSalary
         + employee.housingAllowance
         + employee.transportAllowance;
}


/* =========================
   BUDGET MENU
   ========================= */

void budgetMenu(void)
{
    int choice;

    do {
        printf("\n========== BUDGET MANAGEMENT ==========\n");
        printf("1. Add Budget\n");
        printf("2. Display Budgets\n");
        printf("3. Search Budget\n");
        printf("4. Calculate Remaining Budget\n");
        printf("0. Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
                if (budgetCount == 0) {
                    printf("\nNo budgets available.\n");
                } else {
                    int id;
                    int found = 0;

                    printf("\nEnter Budget ID: ");
                    scanf("%d", &id);

                    for (int i = 0; i < budgetCount; i++) {
                        if (budgets[i].id == id) {
                            printf("\nRemaining Budget: N$%.2f\n",
                                   calculateRemainingBudget(budgets[i]));
                            found = 1;
                            break;
                        }
                    }

                    if (!found) {
                        printf("\nBudget not found.\n");
                    }
                }
                break;

            case 0:
                break;

            default:
                printf("\nInvalid choice.\n");
        }

    } while (choice != 0);
}


/* =========================
   ADD BUDGET
   ========================= */

void addBudget(void)
{
    if (budgetCount >= MAX_BUDGETS) {
        printf("\nBudget storage is full.\n");
        return;
    }

    printf("\n========== ADD BUDGET ==========\n");

    do {
        printf("Enter Budget ID: ");
        scanf("%d", &budgets[budgetCount].id);

        if (budgets[budgetCount].id <= 0) {
            printf("Budget ID must be greater than 0.\n");
        } else if (budgetIDExists(budgets[budgetCount].id)) {
            printf("Budget ID already exists. Enter a different ID.\n");
        }

    } while (budgets[budgetCount].id <= 0 ||
             budgetIDExists(budgets[budgetCount].id));

    printf("Enter Department: ");
    readNonEmptyString(budgets[budgetCount].department, 100);

    do {
        printf("Enter Allocated Budget: ");
        scanf("%f", &budgets[budgetCount].allocatedBudget);

        if (budgets[budgetCount].allocatedBudget < 0) {
            printf("Budget cannot be negative.\n");
        }

    } while (budgets[budgetCount].allocatedBudget < 0);

    do {
        printf("Enter Expenditure: ");
        scanf("%f", &budgets[budgetCount].expenditure);

        if (budgets[budgetCount].expenditure < 0) {
            printf("Expenditure cannot be negative.\n");
        }

    } while (budgets[budgetCount].expenditure < 0);

    budgetCount++;

    printf("\nBudget added successfully.\n");
}


/* =========================
   DISPLAY BUDGETS
   ========================= */

void displayBudgets(void)
{
    if (budgetCount == 0) {
        printf("\nNo budgets available.\n");
        return;
    }

    printf("\n========== BUDGET LIST ==========\n");

    for (int i = 0; i < budgetCount; i++) {
        float remaining =
            calculateRemainingBudget(budgets[i]);

        printf("\nBudget ID: %d\n", budgets[i].id);
        printf("Department: %s\n", budgets[i].department);
        printf("Allocated Budget: N$%.2f\n",
               budgets[i].allocatedBudget);
        printf("Expenditure: N$%.2f\n",
               budgets[i].expenditure);
        printf("Remaining Budget: N$%.2f\n", remaining);

        if (budgets[i].expenditure > budgets[i].allocatedBudget) {
            printf("Status: OVER BUDGET\n");
        } else {
            printf("Status: WITHIN BUDGET\n");
        }
    }
}


/* =========================
   SEARCH BUDGET
   ========================= */

void searchBudget(void)
{
    char department[100];
    int found = 0;

    if (budgetCount == 0) {
        printf("\nNo budgets available.\n");
        return;
    }

    printf("\nEnter department to search: ");
    readNonEmptyString(department, 100);

    for (int i = 0; i < budgetCount; i++) {

        if (strcmp(budgets[i].department, department) == 0) {
            printf("\nBudget found!\n");
            printf("ID: %d\n", budgets[i].id);
            printf("Department: %s\n", budgets[i].department);
            printf("Allocated: N$%.2f\n",
                   budgets[i].allocatedBudget);
            printf("Expenditure: N$%.2f\n",
                   budgets[i].expenditure);

            found = 1;
        }
    }

    if (!found) {
        printf("\nBudget not found.\n");
    }
}


/* =========================
   CALCULATE REMAINING BUDGET
   ========================= */

float calculateRemainingBudget(Budget budget)
{
    return budget.allocatedBudget - budget.expenditure;
}


/* =========================
   SUPPLIER MENU
   ========================= */

void supplierMenu(void)
{
    int choice;

    do {
        printf("\n========== SUPPLIER MANAGEMENT ==========\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Compare Suppliers\n");
        printf("0. Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
                printf("\nInvalid choice.\n");
        }

    } while (choice != 0);
}


/* =========================
   ADD SUPPLIER
   ========================= */

void addSupplier(void)
{
    if (supplierCount >= MAX_SUPPLIERS) {
        printf("\nSupplier storage is full.\n");
        return;
    }

    printf("\n========== ADD SUPPLIER ==========\n");

    do {
        printf("Enter Supplier ID: ");
        scanf("%d", &suppliers[supplierCount].id);

        if (suppliers[supplierCount].id <= 0) {
            printf("Supplier ID must be greater than 0.\n");
        } else if (supplierIDExists(suppliers[supplierCount].id)) {
            printf("Supplier ID already exists. Enter a different ID.\n");
        }

    } while (suppliers[supplierCount].id <= 0 ||
             supplierIDExists(suppliers[supplierCount].id));

    printf("Enter Supplier Name: ");
    readNonEmptyString(suppliers[supplierCount].name, 100);

    printf("Enter Email: ");
    readNonEmptyString(suppliers[supplierCount].email, 100);

    printf("Enter Telephone: ");
    readNonEmptyString(suppliers[supplierCount].telephone, 30);

    printf("Enter Town/Location: ");
    readNonEmptyString(suppliers[supplierCount].location, 100);

    supplierCount++;

    printf("\nSupplier added successfully.\n");
}


/* =========================
   DISPLAY SUPPLIERS
   ========================= */

void displaySuppliers(void)
{
    if (supplierCount == 0) {
        printf("\nNo suppliers available.\n");
        return;
    }

    printf("\n========== SUPPLIER LIST ==========\n");

    for (int i = 0; i < supplierCount; i++) {
        char contact[250];

        buildSupplierContact(suppliers[i], contact);

        printf("\nSupplier ID: %d\n", suppliers[i].id);
        printf("Name: %s\n", suppliers[i].name);
        printf("Email: %s\n", suppliers[i].email);
        printf("Telephone: %s\n", suppliers[i].telephone);
        printf("Location: %s\n", suppliers[i].location);
        printf("Contact Information: %s\n", contact);
    }
}


/* =========================
   SEARCH SUPPLIER
   ========================= */

void searchSupplier(void)
{
    char searchName[100];
    int found = 0;

    if (supplierCount == 0) {
        printf("\nNo suppliers available.\n");
        return;
    }

    printf("\nEnter supplier name to search: ");
    readNonEmptyString(searchName, 100);

    for (int i = 0; i < supplierCount; i++) {

        if (strcmp(suppliers[i].name, searchName) == 0) {
            printf("\nSupplier found!\n");
            printf("ID: %d\n", suppliers[i].id);
            printf("Name: %s\n", suppliers[i].name);
            printf("Email: %s\n", suppliers[i].email);
            printf("Telephone: %s\n", suppliers[i].telephone);
            printf("Location: %s\n", suppliers[i].location);

            found = 1;
        }
    }

    if (!found) {
        printf("\nSupplier not found.\n");
    }
}


/* =========================
   COMPARE SUPPLIERS
   ========================= */

void compareSuppliers(void)
{
    char name1[100];
    char name2[100];
    int firstFound = -1;
    int secondFound = -1;

    if (supplierCount < 2) {
        printf("\nAt least two suppliers are required.\n");
        return;
    }

    printf("\nEnter first supplier name: ");
    readNonEmptyString(name1, 100);

    printf("Enter second supplier name: ");
    readNonEmptyString(name2, 100);

    for (int i = 0; i < supplierCount; i++) {

        if (strcmp(suppliers[i].name, name1) == 0) {
            firstFound = i;
        }

        if (strcmp(suppliers[i].name, name2) == 0) {
            secondFound = i;
        }
    }

    if (firstFound == -1 || secondFound == -1) {
        printf("\nOne or both suppliers were not found.\n");
        return;
    }

    printf("\n========== SUPPLIER COMPARISON ==========\n");

    printf("\nSupplier 1:\n");
    printf("Name: %s\n", suppliers[firstFound].name);
    printf("Email: %s\n", suppliers[firstFound].email);
    printf("Telephone: %s\n", suppliers[firstFound].telephone);
    printf("Location: %s\n", suppliers[firstFound].location);

    printf("\nSupplier 2:\n");
    printf("Name: %s\n", suppliers[secondFound].name);
    printf("Email: %s\n", suppliers[secondFound].email);
    printf("Telephone: %s\n", suppliers[secondFound].telephone);
    printf("Location: %s\n", suppliers[secondFound].location);

    if (strcmp(suppliers[firstFound].location,
               suppliers[secondFound].location) == 0) {
        printf("\nBoth suppliers are located in the same town/location.\n");
    } else {
        printf("\nThe suppliers are located in different towns/locations.\n");
    }
}


/* =========================
   ASSET MENU
   ========================= */

void assetMenu(void)
{
    int choice;

    do {
        printf("\n========== ASSET MANAGEMENT ==========\n");
        printf("1. Add Asset\n");
        printf("2. Display Assets\n");
        printf("3. Search Asset\n");
        printf("0. Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
                printf("\nInvalid choice.\n");
        }

    } while (choice != 0);
}


/* =========================
   ADD ASSET
   ========================= */

void addAsset(void)
{
    if (assetCount >= MAX_ASSETS) {
        printf("\nAsset storage is full.\n");
        return;
    }

    printf("\n========== ADD ASSET ==========\n");

    do {
        printf("Enter Asset ID: ");
        scanf("%d", &assets[assetCount].id);

        if (assets[assetCount].id <= 0) {
            printf("Asset ID must be greater than 0.\n");
        } else if (assetIDExists(assets[assetCount].id)) {
            printf("Asset ID already exists. Enter a different ID.\n");
        }

    } while (assets[assetCount].id <= 0 ||
             assetIDExists(assets[assetCount].id));

    printf("Enter Asset Name: ");
    readNonEmptyString(assets[assetCount].name, 100);

    printf("Enter Asset Type: ");
    readNonEmptyString(assets[assetCount].type, 100);

    do {
        printf("Enter Purchase Value: ");
        scanf("%f", &assets[assetCount].purchaseValue);

        if (assets[assetCount].purchaseValue < 0) {
            printf("Purchase value cannot be negative.\n");
        }

    } while (assets[assetCount].purchaseValue < 0);

    printf("Enter Department: ");
    readNonEmptyString(assets[assetCount].department, 100);

    printf("Enter Condition: ");
    readNonEmptyString(assets[assetCount].condition, 100);

    assetCount++;

    printf("\nAsset added successfully.\n");
}


/* =========================
   DISPLAY ASSETS
   ========================= */

void displayAssets(void)
{
    if (assetCount == 0) {
        printf("\nNo assets available.\n");
        return;
    }

    printf("\n========== ASSET LIST ==========\n");

    for (int i = 0; i < assetCount; i++) {
        printf("\nAsset ID: %d\n", assets[i].id);
        printf("Name: %s\n", assets[i].name);
        printf("Type: %s\n", assets[i].type);
        printf("Purchase Value: N$%.2f\n",
               assets[i].purchaseValue);
        printf("Department: %s\n", assets[i].department);
        printf("Condition: %s\n", assets[i].condition);
    }
}


/* =========================
   SEARCH ASSET
   ========================= */

void searchAsset(void)
{
    char searchName[100];
    int found = 0;

    if (assetCount == 0) {
        printf("\nNo assets available.\n");
        return;
    }

    printf("\nEnter asset name to search: ");
    readNonEmptyString(searchName, 100);

    for (int i = 0; i < assetCount; i++) {

        if (strcmp(assets[i].name, searchName) == 0) {
            printf("\nAsset found!\n");
            printf("ID: %d\n", assets[i].id);
            printf("Name: %s\n", assets[i].name);
            printf("Type: %s\n", assets[i].type);
            printf("Purchase Value: N$%.2f\n",
                   assets[i].purchaseValue);
            printf("Department: %s\n", assets[i].department);
            printf("Condition: %s\n", assets[i].condition);

            found = 1;
        }
    }

    if (!found) {
        printf("\nAsset not found.\n");
    }
}


/* =========================
   REPORT MENU
   ========================= */

void reportMenu(void)
{
    int choice;

    do {
        printf("\n========== REPORTS ==========\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("0. Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
                printf("\nInvalid choice.\n");
        }

    } while (choice != 0);
}


/* =========================
   EMPLOYEE REPORT
   ========================= */

void employeeReport(void)
{
    float total = 0;
    float highest;
    float lowest;

    if (employeeCount == 0) {
        printf("\nNo employee data available.\n");
        return;
    }

    highest = calculateSalary(employees[0]);
    lowest = calculateSalary(employees[0]);

    for (int i = 0; i < employeeCount; i++) {
        float salary = calculateSalary(employees[i]);

        total += salary;

        if (salary > highest) {
            highest = salary;
        }

        if (salary < lowest) {
            lowest = salary;
        }
    }

    printf("\n========== EMPLOYEE REPORT ==========\n");
    printf("Total Employees: %d\n", employeeCount);
    printf("Average Salary: N$%.2f\n",
           total / employeeCount);
    printf("Highest Salary: N$%.2f\n", highest);
    printf("Lowest Salary: N$%.2f\n", lowest);
}


/* =========================
   BUDGET REPORT
   ========================= */

void budgetReport(void)
{
    float totalAllocated = 0;
    float totalExpenditure = 0;
    float totalRemaining = 0;
    int overBudget = 0;

    if (budgetCount == 0) {
        printf("\nNo budget data available.\n");
        return;
    }

    for (int i = 0; i < budgetCount; i++) {
        totalAllocated += budgets[i].allocatedBudget;
        totalExpenditure += budgets[i].expenditure;
        totalRemaining += calculateRemainingBudget(budgets[i]);

        if (budgets[i].expenditure > budgets[i].allocatedBudget) {
            overBudget++;
        }
    }

    printf("\n========== BUDGET REPORT ==========\n");
    printf("Total Allocated Budget: N$%.2f\n",
           totalAllocated);
    printf("Total Expenditure: N$%.2f\n",
           totalExpenditure);
    printf("Total Remaining Budget: N$%.2f\n",
           totalRemaining);
    printf("Departments Over Budget: %d\n",
           overBudget);

    if (overBudget > 0) {
        printf("\nDepartments exceeding budget:\n");

        for (int i = 0; i < budgetCount; i++) {
            if (budgets[i].expenditure >
                budgets[i].allocatedBudget) {

                printf("- %s\n", budgets[i].department);
            }
        }
    }
}


/* =========================
   SUPPLIER REPORT
   ========================= */

void supplierReport(void)
{
    if (supplierCount == 0) {
        printf("\nNo supplier data available.\n");
        return;
    }

    printf("\n========== SUPPLIER REPORT ==========\n");
    printf("Total Suppliers: %d\n", supplierCount);

    for (int i = 0; i < supplierCount; i++) {
        printf("\nSupplier %d\n", i + 1);
        printf("ID: %d\n", suppliers[i].id);
        printf("Name: %s\n", suppliers[i].name);
        printf("Email: %s\n", suppliers[i].email);
        printf("Telephone: %s\n", suppliers[i].telephone);
        printf("Location: %s\n", suppliers[i].location);
    }
}


/* =========================
   ASSET REPORT
   ========================= */

void assetReport(void)
{
    float totalValue = 0;

    if (assetCount == 0) {
        printf("\nNo asset data available.\n");
        return;
    }

    for (int i = 0; i < assetCount; i++) {
        totalValue += assets[i].purchaseValue;
    }

    printf("\n========== ASSET REPORT ==========\n");
    printf("Total Assets: %d\n", assetCount);
    printf("Total Purchase Value: N$%.2f\n",
           totalValue);

    for (int i = 0; i < assetCount; i++) {
        printf("\nAsset %d\n", i + 1);
        printf("ID: %d\n", assets[i].id);
        printf("Name: %s\n", assets[i].name);
        printf("Type: %s\n", assets[i].type);
        printf("Purchase Value: N$%.2f\n",
               assets[i].purchaseValue);
        printf("Department: %s\n", assets[i].department);
        printf("Condition: %s\n", assets[i].condition);
    }
}


/* =========================
   DUPLICATE ID VALIDATION
   ========================= */

int employeeIDExists(int id)
{
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            return 1;
        }
    }

    return 0;
}


int budgetIDExists(int id)
{
    for (int i = 0; i < budgetCount; i++) {
        if (budgets[i].id == id) {
            return 1;
        }
    }

    return 0;
}


int supplierIDExists(int id)
{
    for (int i = 0; i < supplierCount; i++) {
        if (suppliers[i].id == id) {
            return 1;
        }
    }

    return 0;
}


int assetIDExists(int id)
{
    for (int i = 0; i < assetCount; i++) {
        if (assets[i].id == id) {
            return 1;
        }
    }

    return 0;
}


/* =========================
   STRING FUNCTIONS
   ========================= */

/* Uses strlen() to make sure the text is not empty */
void readNonEmptyString(char text[], int size)
{
    do {
        scanf(" %[^\n]", text);

        if (strlen(text) == 0) {
            printf("Input cannot be empty. Try again: ");
        }

    } while (strlen(text) == 0);
}


/* Uses strcpy() to copy one string into another */
void copyText(char destination[], char source[])
{
    strcpy(destination, source);
}


/* Uses strcat() to combine supplier contact information */
void buildSupplierContact(Supplier supplier, char result[])
{
    strcpy(result, supplier.email);

    strcat(result, " | ");

    strcat(result, supplier.telephone);
}