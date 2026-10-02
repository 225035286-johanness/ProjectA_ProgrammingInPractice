#include <stdio.h>
#include <string.h>
#include "employees.h"

#define MAX_EMPLOYEES 100

/* Employee information arrays */
char employeeID[MAX_EMPLOYEES][20];
char employeeName[MAX_EMPLOYEES][100];
char department[MAX_EMPLOYEES][50];

float basicSalary[MAX_EMPLOYEES];
float housingAllowance[MAX_EMPLOYEES];
float transportAllowance[MAX_EMPLOYEES];

int employeeCount = 0;


/* =========================================
   ADD EMPLOYEE
   ========================================= */

void addEmployee(void)
{
    if (employeeCount >= MAX_EMPLOYEES)
    {
        printf("\nEmployee storage is full.\n");
        return;
    }

    printf("\n========================================\n");
    printf("           ADD NEW EMPLOYEE\n");
    printf("========================================\n");

    /* Employee ID */
    printf("Enter Employee ID: ");
    scanf(" %19[^\n]", employeeID[employeeCount]);

    /* Check for duplicate Employee ID */
    for (int i = 0; i < employeeCount; i++)
    {
        if (strcmp(employeeID[i], employeeID[employeeCount]) == 0)
        {
            printf("\nError: Employee ID already exists.\n");
            return;
        }
    }

    /* Employee Name */
    printf("Enter Employee Name: ");
    scanf(" %99[^\n]", employeeName[employeeCount]);

    /* Department */
    printf("Enter Department: ");
    scanf(" %49[^\n]", department[employeeCount]);

    /* Basic Salary */
    printf("Enter Basic Salary: ");
    scanf("%f", &basicSalary[employeeCount]);

    if (basicSalary[employeeCount] < 0)
    {
        printf("\nError: Basic salary cannot be negative.\n");
        return;
    }

    /* Housing Allowance */
    printf("Enter Housing Allowance: ");
    scanf("%f", &housingAllowance[employeeCount]);

    if (housingAllowance[employeeCount] < 0)
    {
        printf("\nError: Housing allowance cannot be negative.\n");
        return;
    }

    /* Transport Allowance */
    printf("Enter Transport Allowance: ");
    scanf("%f", &transportAllowance[employeeCount]);

    if (transportAllowance[employeeCount] < 0)
    {
        printf("\nError: Transport allowance cannot be negative.\n");
        return;
    }

    employeeCount++;

    printf("\nEmployee added successfully!\n");
}


/* =========================================
   DISPLAY ALL EMPLOYEES
   ========================================= */

void displayEmployees(void)
{
    if (employeeCount == 0)
    {
        printf("\nNo employees have been added yet.\n");
        return;
    }

    printf("\n========================================\n");
    printf("             ALL EMPLOYEES\n");
    printf("========================================\n");

    for (int i = 0; i < employeeCount; i++)
    {
        printf("\nEmployee %d\n", i + 1);
        printf("----------------------------------------\n");

        printf("Employee ID          : %s\n", employeeID[i]);
        printf("Employee Name        : %s\n", employeeName[i]);
        printf("Department           : %s\n", department[i]);
        printf("Basic Salary         : N$ %.2f\n", basicSalary[i]);
        printf("Housing Allowance    : N$ %.2f\n",
               housingAllowance[i]);
        printf("Transport Allowance  : N$ %.2f\n",
               transportAllowance[i]);

        printf("Gross Salary         : N$ %.2f\n",
               basicSalary[i]
               + housingAllowance[i]
               + transportAllowance[i]);
    }
}


/* =========================================
   SEARCH EMPLOYEE
   ========================================= */

void searchEmployee(void)
{
    char searchID[20];
    int found = 0;

    if (employeeCount == 0)
    {
        printf("\nNo employees have been added yet.\n");
        return;
    }

    printf("\n========================================\n");
    printf("            SEARCH EMPLOYEE\n");
    printf("========================================\n");

    printf("Enter Employee ID: ");
    scanf(" %19[^\n]", searchID);

    for (int i = 0; i < employeeCount; i++)
    {
        if (strcmp(employeeID[i], searchID) == 0)
        {
            printf("\nEmployee found!\n");
            printf("----------------------------------------\n");

            printf("Employee ID          : %s\n",
                   employeeID[i]);

            printf("Employee Name        : %s\n",
                   employeeName[i]);

            printf("Department           : %s\n",
                   department[i]);

            printf("Basic Salary         : N$ %.2f\n",
                   basicSalary[i]);

            printf("Housing Allowance    : N$ %.2f\n",
                   housingAllowance[i]);

            printf("Transport Allowance  : N$ %.2f\n",
                   transportAllowance[i]);

            printf("Gross Salary         : N$ %.2f\n",
                   basicSalary[i]
                   + housingAllowance[i]
                   + transportAllowance[i]);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nEmployee with ID %s was not found.\n",
               searchID);
    }
}


/* =========================================
   CALCULATE EMPLOYEE SALARY
   ========================================= */

void calculateSalary(void)
{
    char searchID[20];
    int found = 0;
    float grossSalary;

    if (employeeCount == 0)
    {
        printf("\nNo employees have been added yet.\n");
        return;
    }

    printf("\n========================================\n");
    printf("          CALCULATE SALARY\n");
    printf("========================================\n");

    printf("Enter Employee ID: ");
    scanf(" %19[^\n]", searchID);

    for (int i = 0; i < employeeCount; i++)
    {
        if (strcmp(employeeID[i], searchID) == 0)
        {
            grossSalary =
                basicSalary[i]
                + housingAllowance[i]
                + transportAllowance[i];

            printf("\nEmployee Name       : %s\n",
                   employeeName[i]);

            printf("Basic Salary        : N$ %.2f\n",
                   basicSalary[i]);

            printf("Housing Allowance   : N$ %.2f\n",
                   housingAllowance[i]);

            printf("Transport Allowance : N$ %.2f\n",
                   transportAllowance[i]);

            printf("----------------------------------------\n");

            printf("GROSS SALARY        : N$ %.2f\n",
                   grossSalary);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nEmployee with ID %s was not found.\n",
               searchID);
    }
}


/* =========================================
   EMPLOYEE MENU
   ========================================= */

void employeeMenu(void)
{
    int choice;

    do
    {
        printf("\n========================================\n");
        printf("         EMPLOYEE MANAGEMENT\n");
        printf("========================================\n");

        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Calculate Employee Salary\n");
        printf("5. Return to Main Menu\n");

        printf("----------------------------------------\n");
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

            case 5:
                printf("\nReturning to Main Menu...\n");
                break;

            default:
                printf("\nInvalid choice. Please choose 1-5.\n");
        }

    } while (choice != 5);
}
