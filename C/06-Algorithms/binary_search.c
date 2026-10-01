/**
 * Binary Search Algorithm in C
 * Time Complexity: O(log n)
 * Space Complexity: O(1) Iterative, O(log n) Recursive
 * Prerequisite: Array must be sorted in ascending order.
 */

#include <stdio.h>

// Iterative Binary Search
int binarySearchIterative(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // Prevents overflow

        if (arr[mid] == target)
            return mid; // Target found
        else if (arr[mid] < target)
            low = mid + 1; // Search right half
        else
            high = mid - 1; // Search left half
    }
    return -1; // Target not found
}

// Recursive Binary Search
int binarySearchRecursive(int arr[], int low, int high, int target) {
    if (low > high)
        return -1; // Base case: not found

    int mid = low + (high - low) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return binarySearchRecursive(arr, mid + 1, high, target);
    else
        return binarySearchRecursive(arr, low, mid - 1, target);
}

int main() {
    int arr[] = {3, 8, 12, 17, 25, 34, 48, 59, 65};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 48;

    printf("Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\nTarget to search: %d\n\n", target);

    int idxIter = binarySearchIterative(arr, n, target);
    printf("[Iterative] Found at index: %d\n", idxIter);

    int idxRec = binarySearchRecursive(arr, 0, n - 1, target);
    printf("[Recursive] Found at index: %d\n", idxRec);

    return 0;
}
