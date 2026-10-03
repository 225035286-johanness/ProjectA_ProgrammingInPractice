#ifndef BUDGET_H
#define BUDGET_H

#define MAX_DEPARTMENTS 10

typedef struct {
    char name[50];
    double allocated;
    double spent;
    double remaining;
    char status[20];
} Department;

extern Department departments[MAX_DEPARTMENTS];
extern int deptCount;

void calculateBudget(Department *d);
void addDepartment();
void displayDepartments();
void searchDepartment();

#endif







