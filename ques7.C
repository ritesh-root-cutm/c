#include <stdio.h>

long long largestPrimeFactor(long long n) {
    long long largest = -1;

    // Divide out the factor 2
    while (n % 2 == 0) {
        largest = 2;
        n /= 2;
    }

    // Check for odd factors from 3 onward
    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            largest = i;
            n /= i;
        }
    }

    // If n is still greater than 2, then n itself is a prime factor
    if (n > 2)
        largest = n;

    return largest;
}

int main() {
    long long n;
    printf("Enter a number: ");
    scanf("%lld", &n);

    long long result = largestPrimeFactor(n);
    printf("The largest prime factor of %lld is: %lld\n", n, result);

    return 0;
}
