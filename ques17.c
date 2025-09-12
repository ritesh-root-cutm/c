#include <stdio.h>

// Function to rotate array left by k positions
void leftRotate(int arr[], int n, int k) {
    int temp[k]; // store first k elements

    // Step 1: Copy first k elements
    for (int i = 0; i < k; i++) {
        temp[i] = arr[i];
    }

    // Step 2: Shift remaining elements to the left
    for (int i = k; i < n; i++) {
        arr[i - k] = arr[i];
    }

    // Step 3: Copy temp[] elements to the end
    for (int i = 0; i < k; i++) {
        arr[n - k + i] = temp[i];
    }
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, k;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter number of positions to rotate (k): ");
    scanf("%d", &k);

    // Handle case when k > n
    k = k % n;

    printf("Original array: ");
    printArray(arr, n);

    leftRotate(arr, n, k);

    printf("Array after left rotation by %d positions: ", k);
    printArray(arr, n);

    return 0;
}
