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
   REMOVE NEWLINE FROM TEXT
   ========================================= */

void removeNewline(char text[])
{
    text[strcspn(text, "\n")] = '\0';
}


/* =========================================
   ADD EMPLOYEE
   ========================================= */

void addEmployee(void)
{
    if (employeeCount >= MAX_EMPLOYEES)
    {
        printf("\nEmployee list is full.\n");
        return;
    }

    printf("\n========== ADD EMPLOYEE ==========\n");

    printf("Enter Employee ID: ");
    scanf("%19s", employeeID[employeeCount]);

    /* Check for duplicate Employee ID */
    for (int i = 0; i < employeeCount; i++)
    {
        if (strcmp(employeeID[i], employeeID[employeeCount]) == 0)
        {
            printf("\nError: Employee ID already exists.\n");
            return;
        }
    }

    /* Clear newline left by scanf */
    getchar();

    printf("Enter Employee Name: ");
    fgets(employeeName[employeeCount],
          sizeof(employeeName[employeeCount]),
          stdin);

    removeNewline(employeeName[employeeCount]);

    if (strlen(employeeName[employeeCount]) == 0)
    {
        printf("Employee name cannot be empty.\n");
        return;
    }

    printf("Enter Department: ");
    fgets(department[employeeCount],
          sizeof(department[employeeCount]),
          stdin);

    removeNewline(department[employeeCount]);

    if (strlen(department[employeeCount]) == 0)
    {
        printf("Department cannot be empty.\n");
        return;
    }

    printf("Enter Basic Salary: ");
    scanf("%f", &basicSalary[employeeCount]);

    if (basicSalary[employeeCount] < 0)
    {
        printf("Basic salary cannot be negative.\n");
        return;
    }

    printf("Enter Housing Allowance: ");
    scanf("%f", &housingAllowance[employeeCount]);

    if (housingAllowance[employeeCount] < 0)
    {
        printf("Housing allowance cannot be negative.\n");
        return;
    }

    printf("Enter Transport Allowance: ");
    scanf("%f", &transportAllowance[employeeCount]);

    if (transportAllowance[employeeCount] < 0)
    {
        printf("Transport allowance cannot be negative.\n");
        return;
    }

    employeeCount++;

    printf("\nEmployee added successfully!\n");
}


/* =========================================
   DISPLAY EMPLOYEES
   ========================================= */

void displayEmployees(void)
{
    if (employeeCount == 0)
    {
        printf("\nNo employees have been registered.\n");
        return;
    }

    printf("\n========== EMPLOYEE LIST ==========\n");

    for (int i = 0; i < employeeCount; i++)
    {
        printf("\nEmployee %d\n", i + 1);
        printf("-------------------------------\n");

        printf("ID: %s\n", employeeID[i]);
        printf("Name: %s\n", employeeName[i]);
        printf("Department: %s\n", department[i]);

        printf("Basic Salary: N$ %.2f\n",
               basicSalary[i]);

        printf("Housing Allowance: N$ %.2f\n",
               housingAllowance[i]);

        printf("Transport Allowance: N$ %.2f\n",
               transportAllowance[i]);

        printf("Gross Salary: N$ %.2f\n",
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

    if (employeeCount == 0)
    {
        printf("\nNo employees have been registered.\n");
        return;
    }

    printf("\n========== SEARCH EMPLOYEE ==========\n");

    printf("Enter Employee ID: ");
    scanf("%19s", searchID);

    for (int i = 0; i < employeeCount; i++)
    {
        if (strcmp(employeeID[i], searchID) == 0)
        {
            printf("\nEmployee Found!\n");
            printf("-------------------------------\n");

            printf("ID: %s\n",
                   employeeID[i]);

            printf("Name: %s\n",
                   employeeName[i]);

            printf("Department: %s\n",
                   department[i]);

            printf("Basic Salary: N$ %.2f\n",
                   basicSalary[i]);

            printf("Housing Allowance: N$ %.2f\n",
                   housingAllowance[i]);

            printf("Transport Allowance: N$ %.2f\n",
                   transportAllowance[i]);

            return;
        }
    }

    printf("\nEmployee ID not found.\n");
}


/* =========================================
   CALCULATE EMPLOYEE SALARY
   ========================================= */

void calculateSalary(void)
{
    char searchID[20];

    if (employeeCount == 0)
    {
        printf("\nNo employees have been registered.\n");
        return;
    }

    printf("\n========== CALCULATE SALARY ==========\n");

    printf("Enter Employee ID: ");
    scanf("%19s", searchID);

    for (int i = 0; i < employeeCount; i++)
    {
        if (strcmp(employeeID[i], searchID) == 0)
        {
            float grossSalary;

            grossSalary =
                basicSalary[i]
                + housingAllowance[i]
                + transportAllowance[i];

            printf("\nEmployee: %s\n",
                   employeeName[i]);

            printf("Basic Salary: N$ %.2f\n",
                   basicSalary[i]);

            printf("Housing Allowance: N$ %.2f\n",
                   housingAllowance[i]);

            printf("Transport Allowance: N$ %.2f\n",
                   transportAllowance[i]);

            printf("-------------------------------\n");

            printf("Gross Salary: N$ %.2f\n",
                   grossSalary);

            return;
        }
    }

    printf("\nEmployee ID not found.\n");
}


/* =========================================
   EMPLOYEE MENU
   ========================================= */

void employeeMenu(void)
{
    int choice;

    do
    {
        printf("\n================================\n");
        printf("       EMPLOYEE MANAGEMENT\n");
        printf("================================\n");

        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Calculate Salary\n");
        printf("5. Return to Main Menu\n");

        printf("\nEnter choice: ");
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
                printf("\nInvalid choice. Please enter 1-5.\n");
        }

    } while (choice != 5);
}
