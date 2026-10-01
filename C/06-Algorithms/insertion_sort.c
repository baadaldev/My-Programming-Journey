/**
 * Insertion Sort Algorithm in C
 * Mechanism: Builds the sorted array one element at a time by shifting larger elements.
 * Time Complexity: Best: O(n) [Already sorted], Average: O(n^2), Worst: O(n^2)
 * Space Complexity: O(1) [In-Place]
 * Stability: Stable
 */

#include <stdio.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertionSort(int arr[], int n) {
    printf("Initial Array: ");
    printArray(arr, n);
    printf("----------------------------------------\n");

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

        printf("Pass %d (Inserted key %d): ", i, key);
        printArray(arr, n);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("=== Insertion Sort Simulation ===\n");
    insertionSort(arr, n);
    printf("----------------------------------------\n");
    printf("Final Sorted Array: ");
    printArray(arr, n);

    return 0;
}
