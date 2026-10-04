#include <stdio.h>
#include "budgets.h"

// Budget data
Budget budgets[MAX_BUDGETS];
int budgetCount = 0;

// Check if Budget ID already exists
int budgetIDExists(int id)
{
    int i;

    for (i = 0; i < budgetCount; i++)
    {
        if (budgets[i].id == id)
        {
            return 1;
        }
    }

    return 0;
}

// Budget Menu
void budgetMenu(void)
{
    int choice;

    do
    {
        printf("\n========== BUDGET MANAGEMENT ==========\n");
        printf("1. Add Budget\n");
        printf("2. Display Budgets\n");
        printf("3. Search Budget\n");
        printf("4. Calculate Budget Balance\n");
        printf("0. Back\n");
        printf("Enter your choice: ");

        choice = readInt();

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
                calculateBudgetBalance();
                break;

            case 0:
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);
}

// Add Budget
void addBudget(void)
{
    if (budgetCount >= MAX_BUDGETS)
    {
        printf("Budget limit reached.\n");
        return;
    }

    do
    {
        printf("Enter Budget ID: ");
        budgets[budgetCount].id = readInt();

        if (budgets[budgetCount].id <= 0)
        {
            printf("Budget ID must be greater than 0.\n");
        }
        else if (budgetIDExists(budgets[budgetCount].id))
        {
            printf("Budget ID already exists. Enter a different ID.\n");
        }

    } while (budgets[budgetCount].id <= 0 ||
             budgetIDExists(budgets[budgetCount].id));

    printf("Enter Department: ");
    readNonEmptyString(budgets[budgetCount].department,
                       sizeof(budgets[budgetCount].department));

    do
    {
        printf("Enter Allocated Budget: ");
        budgets[budgetCount].allocatedBudget = readFloat();

        if (budgets[budgetCount].allocatedBudget < 0)
        {
            printf("Budget cannot be negative.\n");
        }

    } while (budgets[budgetCount].allocatedBudget < 0);

    do
    {
        printf("Enter Expenditure: ");
        budgets[budgetCount].expenditure = readFloat();

        if (budgets[budgetCount].expenditure < 0)
        {
            printf("Expenditure cannot be negative.\n");
        }

    } while (budgets[budgetCount].expenditure < 0);

    budgetCount++;

    printf("Budget added successfully.\n");
}

// Display Budgets
void displayBudgets(void)
{
    int i;
    float remaining;

    if (budgetCount == 0)
    {
        printf("No budgets available.\n");
        return;
    }

    printf("\n========== BUDGETS ==========\n");

    for (i = 0; i < budgetCount; i++)
    {
        remaining = budgets[i].allocatedBudget -
                    budgets[i].expenditure;

        printf("\nBudget ID: %d\n", budgets[i].id);
        printf("Department: %s\n", budgets[i].department);
        printf("Allocated Budget: %.2f\n",
               budgets[i].allocatedBudget);
        printf("Expenditure: %.2f\n",
               budgets[i].expenditure);
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

// Search Budget
void searchBudget(void)
{
    int id;
    int i;

    printf("Enter Budget ID to search: ");
    id = readInt();

    for (i = 0; i < budgetCount; i++)
    {
        if (budgets[i].id == id)
        {
            printf("\nBudget Found\n");
            printf("ID: %d\n", budgets[i].id);
            printf("Department: %s\n", budgets[i].department);
            printf("Allocated Budget: %.2f\n",
                   budgets[i].allocatedBudget);
            printf("Expenditure: %.2f\n",
                   budgets[i].expenditure);
            printf("Remaining Budget: %.2f\n",
                   budgets[i].allocatedBudget -
                   budgets[i].expenditure);
            return;
        }
    }

    printf("Budget not found.\n");
}

// Calculate Budget Balance
void calculateBudgetBalance(void)
{
    int id;
    int i;
    float remaining;

    printf("Enter Budget ID: ");
    id = readInt();

    for (i = 0; i < budgetCount; i++)
    {
        if (budgets[i].id == id)
        {
            remaining = budgets[i].allocatedBudget -
                        budgets[i].expenditure;

            printf("Remaining Budget: %.2f\n", remaining);

            if (remaining >= 0)
            {
                printf("Status: Within Budget\n");
            }
            else
            {
                printf("Status: Over Budget\n");
            }

            return;
        }
    }

    printf("Budget not found.\n");
}
