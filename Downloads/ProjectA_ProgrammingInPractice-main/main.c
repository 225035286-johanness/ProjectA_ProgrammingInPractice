#include <stdio.h>
#include "validation.h"

int main(void) {
    int choice;

    do {
        printf("\n=========================================\n");
        printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM \n");
        printf("=========================================\n");
        printf("1. Employee Management\n");
        printf("2. Budget Management\n");
        printf("3. Supplier Management\n");
        printf("4. Asset Management\n");
        printf("5. Reports\n");
        printf("6. Exit\n");

        choice = getValidInt(1, 6);

        switch (choice) {
            case 1:
                printf("\n--- Employee Management ---\n");
                break;
            case 2:
                printf("\n--- Budget Management ---\n");
                break;
            case 3:
                printf("\n--- Supplier Management ---\n");
                break;
            case 4:
                printf("\n--- Asset Management ---\n");
                break;
            case 5:
                printf("\n--- Reports ---\n");
                break;
            case 6:
                printf("\nExiting system. Goodbye!\n");
                break;
        }
    } while (choice != 6);

    return 0;
}