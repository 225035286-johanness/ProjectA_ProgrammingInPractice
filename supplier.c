#include <stdio.h>
#include <string.h>

#define MAX_SUPPLIERS 100


struct Supplier {
    char supplierID[20];
    char supplierName[100];
    char supplierEmail[50];
    char telephoneNumber[15];
    char location[50];
};

// Function prototypes
int addSupplier(struct Supplier suppliers[], int count);
void displaySuppliers(struct Supplier suppliers[], int count);
void searchSupplier(struct Supplier suppliers[], int count);

int main() {

    struct Supplier suppliers[MAX_SUPPLIERS];

    int count = 0;
    int choice;

    do {
        printf("\n========================================\n");
        printf("       SUPPLIER MANAGEMENT SYSTEM\n");
        printf("========================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Exit\n");
        printf("========================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Remove leftover newline from scanf
        getchar();

        switch (choice) {

            case 1:
                count = addSupplier(suppliers, count);
                break;

            case 2:
                displaySuppliers(suppliers, count);
                break;

            case 3:
                searchSupplier(suppliers, count);
                break;

            case 4:
                printf("\nThank you for using the system!\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}



int addSupplier(struct Supplier suppliers[], int count) {

    printf("\n========== ADD A SUPPLIER ==========\n");

    if (count >= MAX_SUPPLIERS) {

        printf("Oops! The Supplier Database is full.\n");

        return count;
    }

    printf("Enter Supplier ID: ");
    fgets(suppliers[count].supplierID,
          sizeof(suppliers[count].supplierID),
          stdin);

    printf("Enter Supplier Name: ");
    fgets(suppliers[count].supplierName,
          sizeof(suppliers[count].supplierName),
          stdin);

    printf("Enter Supplier Email: ");
    fgets(suppliers[count].supplierEmail,
          sizeof(suppliers[count].supplierEmail),
          stdin);

    printf("Enter Supplier Telephone Number: ");
    fgets(suppliers[count].telephoneNumber,
          sizeof(suppliers[count].telephoneNumber),
          stdin);

    printf("Enter Supplier Location: ");
    fgets(suppliers[count].location,
          sizeof(suppliers[count].location),
          stdin);


    suppliers[count].supplierID[
        strcspn(suppliers[count].supplierID, "\n")
    ] = '\0';

    suppliers[count].supplierName[
        strcspn(suppliers[count].supplierName, "\n")
    ] = '\0';

    suppliers[count].supplierEmail[
        strcspn(suppliers[count].supplierEmail, "\n")
    ] = '\0';

    suppliers[count].telephoneNumber[
        strcspn(suppliers[count].telephoneNumber, "\n")
    ] = '\0';

    suppliers[count].location[
        strcspn(suppliers[count].location, "\n")
    ] = '\0';

    count++;

    printf("\nSupplier successfully added!\n");

    return count;
}



void displaySuppliers(struct Supplier suppliers[], int count) {

    printf("\n========== SUPPLIER LIST ==========\n");

    if (count == 0) {

        printf("There are no suppliers in the database.\n");

        return;
    }

    for (int i = 0; i < count; i++) {

        printf("\n========================================\n");

        printf("Supplier %d\n", i + 1);

        printf("Supplier ID: %s\n",
               suppliers[i].supplierID);

        printf("Supplier Name: %s\n",
               suppliers[i].supplierName);

        printf("Supplier Email: %s\n",
               suppliers[i].supplierEmail);

        printf("Telephone Number: %s\n",
               suppliers[i].telephoneNumber);

        printf("Location: %s\n",
               suppliers[i].location);

        printf("========================================\n");
    }
}




void searchSupplier(struct Supplier suppliers[], int count) {

    char searchName[100];
    int found = 0;

    if (count == 0) {

        printf("\nThere are no suppliers in the database.\n");

        return;
    }

    printf("\n========== SEARCH SUPPLIER ==========\n");

    printf("Enter Supplier Name: ");

    fgets(searchName, sizeof(searchName), stdin);


    searchName[strcspn(searchName, "\n")] = '\0';

    for (int i = 0; i < count; i++) {

        if (strcmp(searchName, suppliers[i].supplierName) == 0) {

            printf("\n========== SUPPLIER FOUND ==========\n");

            printf("Supplier ID: %s\n",
                   suppliers[i].supplierID);

            printf("Supplier Name: %s\n",
                   suppliers[i].supplierName);

            printf("Email: %s\n",
                   suppliers[i].supplierEmail);

            printf("Telephone: %s\n",
                   suppliers[i].telephoneNumber);

            printf("Location: %s\n",
                   suppliers[i].location);

            found = 1;

            break;
        }
    }

    if (!found) {

        printf("\nSupplier '%s' was not found in the database.\n",
               searchName);
    }
}