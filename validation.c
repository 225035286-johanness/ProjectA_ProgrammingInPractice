#include <stdio.h>
#include "validation.h"

int getValidInt(int min, int max) {
    int choice;
    while (1) {
        printf("Enter choice (%d-%d): ", min, max);
        if (scanf("%d", &choice) == 1 && choice >= min && choice <= max) {
            return choice;
        }
        while (getchar() != '\n');
        printf("Invalid input. Try again.\n");
    }
}