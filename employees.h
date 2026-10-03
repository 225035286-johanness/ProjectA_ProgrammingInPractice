#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 100

extern char employeeID[MAX_EMPLOYEES][20];
extern char employeeName[MAX_EMPLOYEES][100];
extern char department[MAX_EMPLOYEES][50];

extern float basicSalary[MAX_EMPLOYEES];
extern float housingAllowance[MAX_EMPLOYEES];
extern float transportAllowance[MAX_EMPLOYEES];

extern int employeeCount;

void removeNewline(char text[]);
void addEmployee(void);
void displayEmployees(void);
void searchEmployee(void);
void calculateSalary(void);
void employeeMenu(void);

#endif