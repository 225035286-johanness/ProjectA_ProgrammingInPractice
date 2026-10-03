#include <stdio.h>
#include "reports.h"
#include "assets.h"
#include "budget.h"
#include "employees.h"
#include "suppliers.h"

void employeeReport(void) {
    if (employeeCount == 0) {
        printf("\n=== EMPLOYEE REPORT ===\nNo employees to report.\n");
        return;
    }
    float total = 0;
    float highest = basicSalary[0];
    float lowest = basicSalary[0];

    for (int i = 0; i < employeeCount; i++) {
        float salary = basicSalary[i];
        total += salary;
        if (salary > highest) highest = salary;
        if (salary < lowest) lowest = salary;
    }

    float average = total / employeeCount;
    printf("\n=== EMPLOYEE REPORT ===\n");
    printf("Total Employees: %d\n", employeeCount);
    printf("Average Basic Salary: N$%.2f\n", average);
    printf("Highest Basic Salary: N$%.2f\n", highest);
    printf("Lowest Basic Salary: N$%.2f\n", lowest);
}

void budgetReport(void) {
    printf("\n=== BUDGET REPORT ===\n");
    if (deptCount == 0) {
        printf("No budget records found.\n");
        return;
    }
    double totalAllocated = 0.0;
    for (int i = 0; i < deptCount; i++) {
        totalAllocated += departments[i].allocated;
    }
    printf("Total Departments Registered: %d\n", deptCount);
    printf("Total Budget Allocated: N$%.2f\n", totalAllocated);
}

void supplierReport(void) {
    printf("\n=== SUPPLIER REPORT ===\n");
    if (supplierCount == 0) {
        printf("No supplier records found.\n");
        return;
    }
    printf("Total Suppliers: %d\n", supplierCount);
}

void displayAssetReport(void) {
    printf("\n=== ASSET REPORT ===\n");
    int count = getAssetCount();
    if (count == 0) {
        printf("No asset records found.\n");
        return;
    }
    printf("Total Assets: %d\n", count);
    printf("Total Asset Value: N$%.2f\n", getTotalAssetValue());
}