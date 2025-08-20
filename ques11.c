#include <stdio.h>

// Linear Search Function
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // element found
        }
    }
    return -1; // element not found
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("Enter element to search: ");
    scanf("%d", &key);

    int result = linearSearch(arr, n, key);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    /*
    ==============================
    Complexity Analysis of Linear Search
    ==============================

    Case 1: Best Case (Big Ω)
    - Key is at the first index.
    - Only 1 comparison.
    - Time Complexity: Ω(1)

    Case 2: Worst Case (Big O)
    - Key is at the last index OR not present at all.
    - n comparisons.
    - Time Complexity: O(n)

    Case 3: Average Case (Big Θ)
    - Key is somewhere in the middle on average.
    - About n/2 comparisons.
    - Time Complexity: Θ(n)

    ==============================
    Summary:
    - Big O   → O(n)  (upper bound)
    - Big Ω   → Ω(1)  (lower bound)
    - Big Θ   → Θ(n)  (tight bound)
    ==============================
    */

    return 0;
}
