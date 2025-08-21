#include <stdio.h>

int main() {
    int arr[100];   // Maximum capacity of array
    int n, pos, elem;

    // Input size of array
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input element to insert and its position
    printf("Enter element to insert: ");
    scanf("%d", &elem);

    printf("Enter position (0-based index): ");
    scanf("%d", &pos);

    // Check if array is full
    if (n == 100) {
        printf("Insertion not possible. Array is full.\n");
    }
    // Check valid position
    else if (pos < 0 || pos > n) {
        printf("Invalid position! Position should be between 0 and %d\n", n);
    }
    else {
        // Shift elements to the right
        for (int i = n; i > pos; i--) {
            arr[i] = arr[i - 1];
        }

        // Insert the new element
        arr[pos] = elem;
        n++;  // Increase size

        // Print updated array
        printf("Array after insertion:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    /*
    ==============================
    Time Complexity Analysis
    ==============================
    - Best Case: Insert at the end → O(1)
    - Worst Case: Insert at the beginning → O(n) (all elements shift)
    - Average Case: O(n/2) ≈ O(n)
    Final: O(n)
    ==============================
    */

    return 0;
}
