#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "assets.h"

Asset assets[MAX_ASSETS];
int assetCount = 0;

void clearInputA(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int isEmptyString(const char *s) {
    if (strlen(s) == 0) return 1;
    for (int i = 0; s[i] != '\0'; i++) {
        if (!isspace((unsigned char)s[i])) return 0;
    }
    return 1;
}

void addAsset(void) {
    if (assetCount >= MAX_ASSETS) {
        printf("Error: Asset storage limit reached!\n");
        return;
    }

    Asset n;

    printf("Asset ID: ");
    if (scanf("%d", &n.assetID) != 1) {
        printf("Invalid input for Asset ID.\n");
        clearInputA();
        return;
    }
    clearInputA();

    for (int i = 0; i < assetCount; i++) {
        if (assets[i].assetID == n.assetID) {
            printf("Error: Duplicate Asset ID!\n");
            return;
        }
    }

    printf("Name: ");
    if (fgets(n.assetName, sizeof(n.assetName), stdin)) {
        n.assetName[strcspn(n.assetName, "\n")] = '\0';
    }
    if (isEmptyString(n.assetName)) {
        printf("Error: Name cannot be empty!\n");
        return;
    }

    printf("Type: ");
    if (fgets(n.assetType, sizeof(n.assetType), stdin)) {
        n.assetType[strcspn(n.assetType, "\n")] = '\0';
    }

    printf("Value: ");
    if (scanf("%f", &n.purchaseValue) != 1) {
        printf("Invalid value format.\n");
        clearInputA();
        return;
    }
    clearInputA();

    if (n.purchaseValue < 0) {
        printf("Error: Value cannot be negative!\n");
        return;
    }

    printf("Dept: ");
    if (fgets(n.department, sizeof(n.department), stdin)) {
        n.department[strcspn(n.department, "\n")] = '\0';
    }

    printf("Condition: ");
    if (fgets(n.condition, sizeof(n.condition), stdin)) {
        n.condition[strcspn(n.condition, "\n")] = '\0';
    }

    assets[assetCount++] = n;
    printf("Asset successfully added! Total assets: %d\n", assetCount);
}

void displayAssets(void) {
    if (assetCount == 0) {
        printf("No assets registered.\n");
        return;
    }

    printf("\n%-6s %-20s %-12s %-10s %-12s %-10s\n", "ID", "Name", "Type", "Value", "Dept", "Cond");
    printf("-----------------------------------------------------------------------\n");
    for (int i = 0; i < assetCount; i++) {
        printf("%-6d %-20s %-12s N$%-9.2f %-12s %-10s\n",
               assets[i].assetID, assets[i].assetName, assets[i].assetType,
               assets[i].purchaseValue, assets[i].department, assets[i].condition);
    }
}

void searchAsset(void) {
    int option;
    printf("\nSearch by: 1. ID  2. Department  3. Type\nChoice: ");
    if (scanf("%d", &option) != 1) {
        clearInputA();
        printf("Invalid option.\n");
        return;
    }
    clearInputA();

    if (option == 1) {
        int id;
        printf("Enter Asset ID: ");
        if (scanf("%d", &id) != 1) {
            clearInputA();
            printf("Invalid ID.\n");
            return;
        }
        clearInputA();

        for (int i = 0; i < assetCount; i++) {
            if (assets[i].assetID == id) {
                printf("Found: %s | Value: N$%.2f | Dept: %s\n",
                       assets[i].assetName, assets[i].purchaseValue, assets[i].department);
                return;
            }
        }
        printf("Asset ID not found.\n");
    } else if (option == 2) {
        char dept[30];
        printf("Enter Department: ");
        if (fgets(dept, sizeof(dept), stdin)) {
            dept[strcspn(dept, "\n")] = '\0';
        }

        int found = 0;
        for (int i = 0; i < assetCount; i++) {
            if (strcmp(assets[i].department, dept) == 0) {
                printf("ID: %d | Name: %s | Value: N$%.2f\n",
                       assets[i].assetID, assets[i].assetName, assets[i].purchaseValue);
                found = 1;
            }
        }
        if (!found) printf("No assets found for department: %s\n", dept);
    } else if (option == 3) {
        char type[30];
        printf("Enter Type: ");
        if (fgets(type, sizeof(type), stdin)) {
            type[strcspn(type, "\n")] = '\0';
        }

        int found = 0;
        for (int i = 0; i < assetCount; i++) {
            if (strcmp(assets[i].assetType, type) == 0) {
                printf("ID: %d | Name: %s | Value: N$%.2f\n",
                       assets[i].assetID, assets[i].assetName, assets[i].purchaseValue);
                found = 1;
            }
        }
        if (!found) printf("No assets found for type: %s\n", type);
    } else {
        printf("Invalid search option.\n");
    }
}

void assetReport(void) {
    float total = getTotalAssetValue();
    printf("\n=== ASSET SUMMARY REPORT ===\n");
    printf("Total Asset Count: %d\n", assetCount);
    printf("Total Monetary Value: N$%.2f\n", total);
}

int getAssetCount(void) {
    return assetCount;
}

float getTotalAssetValue(void) {
    float total = 0;
    for (int i = 0; i < assetCount; i++) {
        total += assets[i].purchaseValue;
    }
    return total;
}

Asset* getAssetsArray(void) {
    return assets;
}

void assetMenu(void) {
    int choice;
    do {
        printf("\n--- ASSET MANAGEMENT ---\n");
        printf("1. Add Asset\n");
        printf("2. Display All Assets\n");
        printf("3. Search Asset\n");
        printf("4. Asset Summary Report\n");
        printf("5. Return to Main Menu\n");
        printf("Choice: ");

        if (scanf("%d", &choice) != 1) {
            clearInputA();
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        clearInputA();

        switch (choice) {
            case 1: addAsset(); break;
            case 2: displayAssets(); break;
            case 3: searchAsset(); break;
            case 4: assetReport(); break;
            case 5: return;
            default: printf("Invalid option! Please select 1-5.\n");
        }
    } while (choice != 5);
}