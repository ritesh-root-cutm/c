#include <stdio.h>
#include <time.h>

int main() {
    
    int arr[] = {5, 2, 9, 1, 7, 3, 8};
    size_t n = sizeof(arr) / sizeof(arr[0]);
    int max = arr[0];
    for (size_t i = 1; i < n; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Maximum element in array: %d\n", max);
    
    printf("All pairs in the array:\n");
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            printf("(%d, %d) ", arr[i], arr[j]);
        }
        printf("\n");
    }
    
    int num = 1024;
    int steps = 0;
    printf("Dividing %d by 2 until it reaches 1:\n", num);
    while (num > 1) {
        num /= 2;
        steps++;
        printf("Step %d: %d\n", steps, num);
    }
   
    return 0;
}