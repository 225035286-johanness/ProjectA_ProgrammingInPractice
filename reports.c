#include <stdio.h>
#include "reports.h"
#include "assets.h"
#include "employees.h"

// ===== EXTERNAL DATA =====
extern Asset assets[MAX_ASSETS];
extern int assetCount;

extern char employeeID[100][20];
extern char employeeName[100][100];
extern char department[100][50];
extern float basicSalary[100];
extern float housingAllowance[100];
extern float transportAllowance[100];
extern int employeeCount;


// ===== EMPLOYEE REPORT =====
void employeeReport() {
    if (employeeCount == 0) {
        printf("No employees to report.\n");
        return;
    }

    float total = 0;
    float highest = basicSalary[0];
    float lowest = basicSalary[0];

    for (int i = 0; i < employeeCount; i++) {
        total += basicSalary[i];

        if (basicSalary[i] > highest)
            highest = basicSalary[i];

        if (basicSalary[i] < lowest)
            lowest = basicSalary[i];
    }

    float average = total / employeeCount;

    printf("\n=== EMPLOYEE REPORT ===\n");
    printf("Total Employees: %d\n", employeeCount);
    printf("Average Salary: N$%.2f\n", average);
    printf("Highest Salary: N$%.2f\n", highest);
    printf("Lowest Salary: N$%.2f\n", lowest);
}


// ===== BUDGET REPORT =====
typedef struct {
    char department[30];
    float allocated;
    float expenditure;
} Budget;

Budget sampleBudgets[] = {
    {"Finance", 500000, 420000},
    {"Health", 300000, 310000},
    {"Roads", 700000, 650000}
};

int sampleBudgetCount = 3;

void budgetReport() {
    if (sampleBudgetCount == 0) {
        printf("No budget data to report.\n");
        return;
    }

    float totalAllocated = 0, totalExpenditure = 0;

    printf("\n=== BUDGET REPORT ===\n");

    for (int i = 0; i < sampleBudgetCount; i++) {
        totalAllocated += sampleBudgets[i].allocated;
        totalExpenditure += sampleBudgets[i].expenditure;

        float remaining = sampleBudgets[i].allocated - sampleBudgets[i].expenditure;

        printf("%s: Allocated N$%.2f | Spent N$%.2f | Remaining N$%.2f",
               sampleBudgets[i].department,
               sampleBudgets[i].allocated,
               sampleBudgets[i].expenditure,
               remaining);

        if (remaining < 0)
            printf(" -- OVER BUDGET\n");
        else
            printf(" -- WITHIN BUDGET\n");
    }

    printf("\nTotal Allocated: N$%.2f\n", totalAllocated);
    printf("Total Expenditure: N$%.2f\n", totalExpenditure);
    printf("Total Remaining: N$%.2f\n", totalAllocated - totalExpenditure);
}


// ===== SUPPLIER REPORT =====
typedef struct {
    int supplierID;
    char name[50];
    char email[50];
    char phone[20];
    char town[30];
} Supplier;

Supplier sampleSuppliers[] = {
    {1, "BuildRight Ltd", "info@buildright.com", "0811234567", "Windhoek"},
    {2, "SteelWorks Namibia", "sales@steelworks.na", "0817654321", "Walvis Bay"}
};

int sampleSupplierCount = 2;

void supplierReport() {
    if (sampleSupplierCount == 0) {
        printf("No suppliers registered.\n");
        return;
    }

    printf("\n=== SUPPLIER REPORT ===\n");

    for (int i = 0; i < sampleSupplierCount; i++) {
        printf("ID: %d | %s | %s | %s | %s\n",
               sampleSuppliers[i].supplierID,
               sampleSuppliers[i].name,
               sampleSuppliers[i].email,
               sampleSuppliers[i].phone,
               sampleSuppliers[i].town);
    }
}


// ===== ASSET REPORT =====
void assetReport() {
    if (assetCount == 0) {
        printf("No assets registered.\n");
        return;
    }

    printf("\n=== ASSET REPORT ===\n");

    for (int i = 0; i < assetCount; i++) {
        printf("ID: %d | %s | %s | N$%.2f | %s | %s\n",
               assets[i].assetID,
               assets[i].assetName,
               assets[i].assetType,
               assets[i].purchaseValue,
               assets[i].department,
               assets[i].condition);
    }
}