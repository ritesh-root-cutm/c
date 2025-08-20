#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime (Naive Method)
bool isPrime(int n) {
    if (n <= 1) 
        return false;

    // Check divisibility from 2 to n-1
    for (int i = 2; i < n; i++) {
        if (n % i == 0) 
            return false; // not prime
    }
    return true; // prime
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPrime(num))
        printf("%d is a Prime Number.\n", num);
    else
        printf("%d is NOT a Prime Number.\n", num);

    /*
    ==============================
    Time Complexity Analysis
    ==============================

    Function isPrime(n):
    - We check divisibility from 2 up to (n-1).
    - Total comparisons = (n - 2) ≈ O(n)

    Best Case:
    - If n = 1 or 2, we return immediately.
    - Time Complexity: O(1)

    Worst Case:
    - If n is prime, loop runs fully (n-2 iterations).
    - Time Complexity: O(n)

    Average Case:
    - On average, about n/2 checks before finding a divisor.
    - Still considered O(n).

    ==============================
    Final Answer:
    - Naive Primality Test runs in O(n) time.
    - Not efficient for large numbers.
    ==============================
    */

    return 0;
}
