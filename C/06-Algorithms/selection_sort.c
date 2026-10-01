/**
 * Selection Sort Algorithm in C
 * Mechanism: Repeatedly finds minimum element and swaps to the sorted portion.
 * Time Complexity: Best: O(n^2), Average: O(n^2), Worst: O(n^2)
 * Space Complexity: O(1) [In-Place]
 * Stability: Unstable
 */

#include <stdio.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void selectionSort(int arr[], int n) {
    printf("Initial Array: ");
    printArray(arr, n);
    printf("----------------------------------------\n");

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;

        // Find the minimum element in the unsorted subarray
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap minimum element with the first element of unsorted part
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }

        printf("Pass %d (min: %d placed at idx %d): ", i + 1, arr[i], i);
        printArray(arr, n);
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("=== Selection Sort Simulation ===\n");
    selectionSort(arr, n);
    printf("----------------------------------------\n");
    printf("Final Sorted Array: ");
    printArray(arr, n);

    return 0;
}
