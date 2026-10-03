#include <stdio.h>
#include "suppliers.h"

Supplier suppliers[MAX_SUPPLIERS];
int supplierCount = 0;

void supplierMenu(void) {
    printf("\n--- SUPPLIER MANAGEMENT ---\n");
    printf("Total registered suppliers: %d\n", supplierCount);
}