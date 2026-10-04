#ifndef BUDGETS_H
#define BUDGETS_H

#define MAX_BUDGETS 100

// Budget structure
typedef struct
{
    int id;
    char department[100];
    float allocatedBudget;
    float expenditure;
} Budget;

// Budget data
extern Budget budgets[MAX_BUDGETS];
extern int budgetCount;

// Budget functions
void budgetMenu(void);
void addBudget(void);
void displayBudgets(void);
void searchBudget(void);
void calculateBudgetBalance(void);
int budgetIDExists(int id);

// Input functions from main.c
int readInt(void);
float readFloat(void);
void readNonEmptyString(char text[], int size);

#endif