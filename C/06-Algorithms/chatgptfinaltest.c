#include <stdio.h>

int main() {

    int n, key, count = 0, i;
    int firstposition = -1, lastposition = -1;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements: ");

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the search key: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++) {

        if (arr[i] == key) {

            count++;

            if (firstposition == -1) {
                firstposition = i;
            }

            lastposition = i;
        }
    }

    if (firstposition == -1) {
        printf("Element not found\n");
    }
    else {
        printf("Element found\n");
        printf("First occurrence at index %d\n", firstposition);
        printf("Last occurrence at index %d\n", lastposition);
        printf("Element occurs %d times\n", count);
    }

    return 0;
}