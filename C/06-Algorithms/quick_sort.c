/**
 * Quick Sort Algorithm in C
 * Mechanism: Divide and Conquer with pivot-based partition (Lomuto Partition Scheme).
 * Time Complexity: Best: O(n log n), Average: O(n log n), Worst: O(n^2)
 * Space Complexity: O(log n) stack space [In-Place]
 * Stability: Unstable
 */

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivot chosen as the last element
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("=== Quick Sort Demo ===\n");
    printf("Initial: ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted:  ");
    printArray(arr, n);

    return 0;
}
