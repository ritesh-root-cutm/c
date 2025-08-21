#include <stdio.h>

int main() {
    int arr[100];   // Maximum capacity of array
    int n, pos;

    // Input size of array
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input position to delete
    printf("Enter position to delete (0-based index): ");
    scanf("%d", &pos);

    // Check for valid position
    if (pos < 0 || pos >= n) {
        printf("Invalid position! Position should be between 0 and %d\n", n - 1);
    } else {
        int deleted = arr[pos];  // store the deleted element

        // Shift elements to the left
        for (int i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--; // decrease size

        // Print updated array
        printf("Deleted element: %d\n", deleted);
        printf("Array after deletion:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    /*
    ==============================
    Time Complexity Analysis
    ==============================
    - Best Case: Delete last element → O(1)
    - Worst Case: Delete first element → O(n) (all elements shift)
    - Average Case: O(n/2) ≈ O(n)
    Final: O(n)
    ==============================
    */

    return 0;
}
