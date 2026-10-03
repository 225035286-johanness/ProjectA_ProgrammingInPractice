#include <stdio.h>
#include <string.h>
#include "employees.h"

char employeeID[MAX_EMPLOYEES][20];
char employeeName[MAX_EMPLOYEES][100];
char department[MAX_EMPLOYEES][50];

float basicSalary[MAX_EMPLOYEES];
float housingAllowance[MAX_EMPLOYEES];
float transportAllowance[MAX_EMPLOYEES];

int employeeCount = 0;

void removeNewline(char text[]) {
    int len = strlen(text);
    if (len > 0 && text[len - 1] == '\n') {
        text[len - 1] = '\0';
    }
}

void addEmployee(void) {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("System full!\n");
        return;
    }

    printf("\nEnter Employee ID: ");
    fgets(employeeID[employeeCount], 20, stdin);
    removeNewline(employeeID[employeeCount]);

    printf("Enter Employee Name: ");
    fgets(employeeName[employeeCount], 100, stdin);
    removeNewline(employeeName[employeeCount]);

    printf("Enter Department: ");
    fgets(department[employeeCount], 50, stdin);
    removeNewline(department[employeeCount]);

    printf("Enter Basic Salary: N$");
    scanf("%f", &basicSalary[employeeCount]);

    printf("Enter Housing Allowance: N$");
    scanf("%f", &housingAllowance[employeeCount]);

    printf("Enter Transport Allowance: N$");
    scanf("%f", &transportAllowance[employeeCount]);
    getchar();

    employeeCount++;
    printf("Employee added successfully!\n");
}

void displayEmployees(void) {
    if (employeeCount == 0) {
        printf("\nNo employees found.\n");
        return;
    }

    printf("\n%-10s %-20s %-15s %-12s %-12s %-12s %-12s\n",
           "ID", "Name", "Department", "Basic", "Housing", "Transport", "Gross");
    printf("-----------------------------------------------------------------------------------------\n");

    for (int i = 0; i < employeeCount; i++) {
        float gross = basicSalary[i] + housingAllowance[i] + transportAllowance[i];
        printf("%-10s %-20s %-15s N$%-10.2f N$%-10.2f N$%-10.2f N$%-10.2f\n",
               employeeID[i], employeeName[i], department[i],
               basicSalary[i], housingAllowance[i], transportAllowance[i], gross);
    }
}

void searchEmployee(void) {
    char searchID[20];
    printf("\nEnter Employee ID to search: ");
    fgets(searchID, 20, stdin);
    removeNewline(searchID);

    for (int i = 0; i < employeeCount; i++) {
        if (strcmp(employeeID[i], searchID) == 0) {
            float gross = basicSalary[i] + housingAllowance[i] + transportAllowance[i];
            printf("\nEmployee Found:\n");
            printf("ID: %s\nName: %s\nDept: %s\nGross Salary: N$%.2f\n",
                   employeeID[i], employeeName[i], department[i], gross);
            return;
        }
    }
    printf("Employee not found.\n");
}

void employeeMenu(void) {
    int choice;
    do {
        printf("\n--- EMPLOYEE MANAGEMENT ---\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee\n");
        printf("4. Return to Main Menu\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: return;
            default: printf("Invalid option.\n");
        }
    } while (choice != 4);
}