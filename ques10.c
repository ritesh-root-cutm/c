#include <stdio.h>

/*
 * Function to simulate an algorithm with time complexity:
 * T(N) = 5N^3 + 2N^2 + 100
 * 
 * Asymptotic Big O Notation focuses on the term that grows the fastest as N increases.
 * 
 * In this case:
 * - 5N^3 → dominates for large N
 * - 2N^2 and 100 become insignificant as N grows
 * 
 * Therefore, Big O = O(N^3)
 */

void simulatedAlgorithm(int N) {
    int count = 0;

    // Simulate 5N^3 operations
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                count++;  // Total: 5N^3 (simulated)
            }
        }
    }

    // Simulate 2N^2 operations
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            count++;  // Total: 2N^2 (simulated)
        }
    }

    // Simulate 100 constant operations
    for (int i = 0; i < 100; i++) {
        count++;
    }

    printf("Total operations (simulated): %d\n", count);
}

int main() {
    int N;
    printf("Enter input size N: ");
    scanf("%d", &N);

    simulatedAlgorithm(N);

    return 0;
}
