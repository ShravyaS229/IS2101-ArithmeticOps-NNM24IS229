#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Print binary with given bit width
void showBinary(int num, int width) {
    for (int i = width - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

// Count bits required for a number
int countBits(int num) {
    if (num == 0) return 1;
    return (int)log2(abs(num)) + 1;
}

void sequentialMultiply(int m, int q) {
    int n = countBits(q);  // number of steps = bits in multiplier
    int A = 0;
    int M = abs(m);
    int Q = abs(q);

    printf("Initial State:\n");
    printf("A = "); showBinary(A, n);
    printf(" | Q = "); showBinary(Q, n);
    printf(" | M = "); showBinary(M, n);
    printf("\n\n");

    for (int step = 1; step <= n; step++) {
        if (Q & 1) {
            A += M;
            printf("Step %d: Q0=1 -> A = A+M\n", step);
        } else {
            printf("Step %d: Q0=0 -> No addition\n", step);
        }

        // Right shift (A,Q)
        int combined = (A << n) | Q;
        combined >>= 1;
        A = (combined >> n) & ((1 << n) - 1);
        Q = combined & ((1 << n) - 1);

        printf("After shift: A = "); showBinary(A, n);
        printf(" | Q = "); showBinary(Q, n);
        printf("\n\n");
    }

    int product = (A << n) | Q;
    if ((m < 0) ^ (q < 0)) product = -product;

    printf("Final Product = %d (Binary: ", product);
    showBinary(product, n * 2);
    printf(")\n");
}

int main() {
    int m, q;
    printf("Enter multiplicand: ");
    scanf("%d", &m);
    printf("Enter multiplier: ");
    scanf("%d", &q);

    sequentialMultiply(m, q);
    return 0;
}