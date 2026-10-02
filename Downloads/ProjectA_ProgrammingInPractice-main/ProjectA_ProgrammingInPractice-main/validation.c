#include <stdio.h>
#include <string.h>
#include "validation.h"

int getValidInt(int min, int max) {
    int value;
    int status;
    while (1) {
        printf("Enter an integer (%d to %d): ", min, max);
        status = scanf("%d", &value);
        while (getchar() != '\n'); // clear input buffer
        if (status == 1 && value >= min && value <= max) {
            return value;
        }
        printf("Invalid input. Please try again.\n");
    }
}

float getValidFloat(float min, float max) {
    float value;
    int status;
    while (1) {
        printf("Enter a number (%.2f to %.2f): ", min, max);
        status = scanf("%f", &value);
        while (getchar() != '\n');
        if (status == 1 && value >= min && value <= max) {
            return value;
        }
        printf("Invalid input. Please try again.\n");
    }
}

void getValidString(char *buffer, int maxLength) {
    while (1) {
        printf("Enter text: ");
        if (fgets(buffer, maxLength, stdin) != NULL) {
            size_t len = strlen(buffer);
            if (len > 0 && buffer[len - 1] == '\n') {
                buffer[len - 1] = '\0';
            }
            if (strlen(buffer) > 0) {
                return;
            }
        }
        printf("Input cannot be empty. Try again.\n");
    }
}