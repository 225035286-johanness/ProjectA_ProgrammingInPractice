#include <stdio.h>
#include <string.h>

#define MAX_DEPARTMENTS 10

typedef struct {
    char name[50];
    double allocated;
    double spent;
    double remaining;
    char status[20];
} Department;

Department departments[MAX_DEPARTMENTS];
int deptCount = 0;

void calculateBudget(Department *d) {
    d->remaining = d->allocated - d->spent;
    if (d->spent <= d->allocated) {
        strcpy(d->status, "WITHIN BUDGET");
    } else {
        strcpy(d->status, "EXCEEDED");
    }
}

void addDepartment() {
    if (deptCount >= MAX_DEPARTMENTS) {
        printf("Limit reached.\n");
        return;
    }

    Department d;
    printf("\nEnter Department Name: ");
    scanf(" %[^\n]", d.name);

    printf("Enter Allocated Budget: ");
    scanf("%lf", &d.allocated);
    if (d.allocated < 0) {
        printf("Budget must be positive.\n");
        return;
    }

    printf("Enter Expenditure: ");
    scanf("%lf", &d.spent);
    if (d.spent < 0) {
        printf("Expenditure must be positive.\n");
        return;
    }

    calculateBudget(&d);
    departments[deptCount++] = d;

    printf("Department added.\n");
}

void displayDepartments() {
    if (deptCount == 0) {
        printf("\nNo records.\n");
        return;
    }

    for (int i = 0; i < deptCount; i++) {
        printf("\nDepartment: %s\n", departments[i].name);
        printf("Allocated: N$%.2f\n", departments[i].allocated);
        printf("Expenditure: N$%.2f\n", departments[i].spent);
        printf("Remaining: N$%.2f\n", departments[i].remaining);
        printf("Status: %s\n", departments[i].status);
    }
}

void searchDepartment() {
    char search[50];
    int found = 0;

    printf("\nEnter Department Name: ");
    scanf(" %[^\n]", search);

    for (int i = 0; i < deptCount; i++) {
        if (strcmp(departments[i].name, search) == 0) {
            printf("\nDepartment: %s\n", departments[i].name);
            printf("Allocated: N$%.2f\n", departments[i].allocated);
            printf("Expenditure: N$%.2f\n", departments[i].spent);
            printf("Remaining: N$%.2f\n", departments[i].remaining);
            printf("Status: %s\n", departments[i].status);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Not found.\n");
    }
}



