#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Linear Search (O(N))
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// Binary Search (O(log N)) -> array must be sorted
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

void testPerformance(int n) {
    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    // Fill array with sorted values 1..n
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    int key = n; // search for last element (worst-case for linear search)

    clock_t start, end;
    double time_taken;

    // Linear Search Timing
    start = clock();
    int idx1 = linearSearch(arr, n, key);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Linear Search | Size = %d | Index = %d | Time = %f sec\n", n, idx1, time_taken);

    // Binary Search Timing
    start = clock();
    int idx2 = binarySearch(arr, n, key);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Binary Search | Size = %d | Index = %d | Time = %f sec\n\n", n, idx2, time_taken);

    free(arr);
}

int main() {
    int sizes[] = {1000, 10000, 100000, 1000000}; // you can add more
    int numTests = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < numTests; i++) {
        testPerformance(sizes[i]);
    }

    return 0;
}
