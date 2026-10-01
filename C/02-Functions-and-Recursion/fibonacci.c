/**
 * Fibonacci Sequence Implementations in C
 * 1. Naive Recursive: O(2^n) time, O(n) space
 * 2. Iterative: O(n) time, O(1) space
 * 3. Memoized (Dynamic Programming): O(n) time, O(n) space
 */

#include <stdio.h>
#define MAX 100

long long memo[MAX];

// 1. Naive Recursive (Exponential)
long long fibRecursive(int n) {
    if (n <= 1)
        return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

// 2. Iterative (Linear time, Constant space)
long long fibIterative(int n) {
    if (n <= 1)
        return n;
    long long prev2 = 0, prev1 = 1, current;
    for (int i = 2; i <= n; i++) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return current;
}

// 3. Memoized Recursion
long long fibMemoized(int n) {
    if (n <= 1)
        return n;
    if (memo[n] != -1)
        return memo[n];
    return memo[n] = fibMemoized(n - 1) + fibMemoized(n - 2);
}

int main() {
    int n = 10;

    for (int i = 0; i < MAX; i++) memo[i] = -1;

    printf("=== Fibonacci Series Demonstration (n = %d) ===\n", n);
    printf("Series: ");
    for (int i = 0; i <= n; i++) {
        printf("%lld ", fibIterative(i));
    }
    printf("\n\n");

    printf("Fibonacci(%d) [Recursive]: %lld\n", n, fibRecursive(n));
    printf("Fibonacci(%d) [Iterative]: %lld\n", n, fibIterative(n));
    printf("Fibonacci(%d) [Memoized] : %lld\n", n, fibMemoized(n));

    return 0;
}
