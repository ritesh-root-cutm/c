#include <stdio.h>
#include <limits.h>

int main() {
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Array must have at least two elements.\n");
        return 0;
    }

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int first = INT_MIN, second = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > first) {
            second = first;   // update second largest
            first = arr[i];   // update largest
        } 
        else if (arr[i] > second && arr[i] < first) {
            second = arr[i];
        }
    }

    if (second == INT_MIN) {
        printf("No second largest element (all elements may be same).\n");
    } else {
        printf("The second largest element is: %d\n", second);
    }

    return 0;
}
