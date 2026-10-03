# Municipal Financial Management System (MFMS)

The Municipal Financial Management System (MFMS) is a foundational console application built in standard ANSI C (C99) for public sector accounting tracking. It provides simple menu-driven modules for tracking employee payroll packages, departmental budgets, supplier contacts, and municipal equipment assets.

## Course Information
* **Course Code:** PAP521S - Programming in Practice
* **Institution:** Namibia University of Science and Technology (NUST)
* **Faculty:** Faculty of Computing and Informatics
* **Department:** Department of Software Engineering
* **Project Stage:** Project A (Foundation System)

## System Features
* **Employee Management:** Register staff, list entries, search records by ID, and compute total gross pay (Basic + Housing + Transport).
* **Budget Management:** Set departmental allocations, log actual spending, calculate remaining funds, and flag budget overruns.
* **Supplier Management:** Maintain a vendor registry with contact details and location search capabilities.
* **Asset Register:** Record municipal property, asset types, allocation departments, purchase valuations, and physical conditions.
* **Summary Reports:** Generate statistical overviews covering payroll totals, high/low salaries, budget deficits, and overall asset valuations.

## Group Members & Module Allocation
| Student Name | Student ID | Primary Responsibility / Module |
| :--- | :--- | :--- |
| Joyce Nghilifavali | 225041049 | Employee Management (`employees.c`, `employees.h`) |
| Rosina Lita | 226042316 | Budget Management (`budget.c`, `budget.h`) |
| Ipinge Krobinian | 223030015 | Supplier Management (`suppliers.c`, `suppliers.h`) |
| Josef Andreas | 221083685 | Asset Management (`assets.c`, `assets.h`) |
| Jona Johannes | 225047888 | System Reports (`reports.c`, `reports.h`) |
| Sirkka Mudjanima | 225031086 | System Integration & Validation (`main.c`) |
| Johannes Jason | 2250352836 | Testing, Documentation, Build Scripts, & Git |

## Compilation & Run Instructions

### Compiling with Makefile
```bash
make
./mfms
