#include <stdio.h>
#include "reports.h"
#include "assets.h"

extern Asset assets[MAX_ASSETS];
extern int assetCount;

typedef struct {
    int id;
    char name[50];
    float basicSalary;
} Employee;
 
Employee sampleEmployees[] = {
    {1, "John Doe", 12000},
    {2, "Jane Smith", 18500},
    {3, "Peter Shikongo", 8500},
    {4, "Maria Amutenya", 42000},
    {5, "Ndapewa Iileka", 15000}
};
int sampleEmployeeCount = 5;

void employeeReport() {
    if (sampleEmployeeCount == 0) {
        printf("No employees to report.\n");
        return;
    }

    float total = 0;
    float highest = sampleEmployees[0].basicSalary;
    float lowest = sampleEmployees[0].basicSalary;

    for (int i = 0; i < sampleEmployeeCount; i++) {
        float salary = sampleEmployees[i].basicSalary;
        total += salary;
        if (salary > highest) highest = salary;
        if (salary < lowest) lowest = salary;
    }

    float average = total / sampleEmployeeCount;

    printf("\n=== EMPLOYEE REPORT ===\n");
    printf("Total Employees: %d\n", sampleEmployeeCount);
    printf("Average Salary: N$%.2f\n", average);
    printf("Highest Salary: N$%.2f\n", highest);
    printf("Lowest Salary: N$%.2f\n", lowest);
}
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
               sampleBudgets[i].department, sampleBudgets[i].allocated,
               sampleBudgets[i].expenditure, remaining);

        if (remaining < 0)
            printf(" -- OVER BUDGET\n");
        else
            printf(" -- WITHIN BUDGET\n");
    }

    printf("\nTotal Allocated: N$%.2f\n", totalAllocated);
    printf("Total Expenditure: N$%.2f\n", totalExpenditure);
    printf("Total Remaining: N$%.2f\n", totalAllocated - totalExpenditure);
}
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
               sampleSuppliers[i].supplierID, sampleSuppliers[i].name,
               sampleSuppliers[i].email, sampleSuppliers[i].phone,
               sampleSuppliers[i].town);
    }
}

void assetReport() {
    if (assetCount == 0) {
        printf("No assets registered.\n");
        return;
    }

    printf("\n=== ASSET REPORT ===\n");
    for (int i = 0; i < assetCount; i++) {
        printf("ID: %d | %s | %s | N$%.2f | %s | %s\n",
               assets[i].assetId, assets[i].assetName,
               assets[i].category, assets[i].value,
               assets[i].location, assets[i].status);
    }
}