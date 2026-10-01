/**
 * Euclidean Algorithm for Greatest Common Divisor (GCD) in C
 * Formula: gcd(a, b) = gcd(b, a % b) until b == 0
 * Time Complexity: O(log(min(a, b)))
 * Space Complexity: O(1) Iterative, O(log(min(a, b))) Recursive
 */

#include <stdio.h>

// Recursive Euclidean GCD with step logging
int gcdRecursive(int a, int b) {
    printf("  gcd(%d, %d)", a, b);
    if (b == 0) {
        printf(" -> Base case reached: GCD is %d\n", a);
        return a;
    }
    printf(" -> %d %% %d = %d\n", a, b, a % b);
    return gcdRecursive(b, a % b);
}

// Iterative Euclidean GCD
int gcdIterative(int a, int b) {
    while (b != 0) {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}

// Least Common Multiple (LCM) using GCD: LCM(a, b) = (a * b) / GCD(a, b)
long long lcm(int a, int b) {
    return ((long long)a * b) / gcdIterative(a, b);
}

int main() {
    int a = 48, b = 18;

    printf("=== Euclidean GCD Simulation ===\n");
    printf("Calculating GCD of %d and %d:\n", a, b);
    int result = gcdRecursive(a, b);

    printf("\nFinal Result: GCD(%d, %d) = %d\n", a, b, result);
    printf("LCM(%d, %d) = %lld\n", a, b, lcm(a, b));

    return 0;
}
