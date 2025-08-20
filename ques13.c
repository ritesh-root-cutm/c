#include <stdio.h>

// Function to compute X^N using repeated multiplication
long long power(int x, int n) {
    long long result = 1;

    for (int i = 1; i <= n; i++) {
        result = result * x;  // multiply x repeatedly
    }

    return result;
}

int main() {
    int x, n;
    printf("Enter base (X): ");
    scanf("%d", &x);

    printf("Enter exponent (N): ");
    scanf("%d", &n);

    long long result = power(x, n);
    printf("%d^%d = %lld\n", x, n, result);

    /*
    ==============================
    Time Complexity Analysis
    ==============================

    Function power(x, n):
    - Uses a loop that runs exactly n times.
    - Each iteration performs 1 multiplication.

    Best Case:
    - If n = 0, loop does not run → O(1)

    Worst Case:
    - For n > 0, loop runs n times → O(n)

    Average Case:
    - On average, loop runs ~n/2 iterations → Still O(n)

    Final Answer:
    - Time Complexity = O(n)
    - Space Complexity = O(1) (only a few variables)
    ==============================
    */

    return 0;
}
