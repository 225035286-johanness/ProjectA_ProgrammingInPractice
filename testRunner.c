#include <stdio.h>
#include <assert.h>

void test_salary_averages(void) {
    float salaries[] = {12000.0f, 18500.0f, 8500.0f};
    float sum = 0.0f;
    
    for (int i = 0; i < 3; i++) {
        sum += salaries[i];
    }
    
    float avg = sum / 3.0f;
    assert(avg > 0.0f);
    printf("[PASS] Salary calculation test completed.\n");
}

void test_budget_remaining(void) {
    float allocated = 500000.0f;
    float spent = 420000.0f;
    float remaining = allocated - spent;
    
    assert(remaining == 80000.0f);
    printf("[PASS] Budget logic test completed.\n");
}

int main(void) {
    printf("--- Running MFMS Module Tests ---\n\n");
    
    test_salary_averages();
    test_budget_remaining();
    
    printf("\nAll initial unit tests passed successfully.\n");
    return 0;
}
