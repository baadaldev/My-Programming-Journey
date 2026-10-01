/**
 * Optimized Bubble Sort Algorithm in C
 * Mechanism: Swaps adjacent elements if they are in the wrong order.
 * Time Complexity: Best: O(n) [Optimized], Average: O(n^2), Worst: O(n^2)
 * Space Complexity: O(1) [In-Place]
 * Stability: Stable
 */

#include <stdio.h>
#include <stdbool.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void bubbleSortOptimized(int arr[], int n) {
    int passCount = 0;

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        passCount++;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        printf("Pass %d: ", passCount);
        printArray(arr, n);

        // If no two elements were swapped, array is already sorted
        if (!swapped) {
            printf("[Early Exit Triggered: Array sorted in %d passes]\n", passCount);
            break;
        }
    }
}

int main() {
    int arr[] = {5, 1, 4, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("=== Optimized Bubble Sort ===\n");
    printf("Initial: ");
    printArray(arr, n);

    bubbleSortOptimized(arr, n);

    printf("Final Sorted: ");
    printArray(arr, n);

    return 0;
}
