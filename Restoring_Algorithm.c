#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void showBinary(int num, int width) {
    for (int i = width - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

int countBits(int num) {
    if (num == 0) return 1;
    return (int)log2(abs(num)) + 1;
}

void restoringDivision(int dividend, int divisor) {
    int n = countBits(dividend);  // steps = bits in dividend
    int A = 0;
    int Q = abs(dividend);
    int M = abs(divisor);

    printf("Initial State:\n");
    printf("A = "); showBinary(A, n);
    printf(" | Q = "); showBinary(Q, n);
    printf(" | M = "); showBinary(M, n);
    printf("\n\n");

    for (int step = 1; step <= n; step++) {
        // Left shift (A,Q)
        A = (A << 1) | ((Q >> (n - 1)) & 1);
        Q = (Q << 1) & ((1 << n) - 1);

        A -= M;
        if (A < 0) {
            A += M;
            Q &= ~1; // Q0 = 0
            printf("Step %d: Negative -> Restore, Q0=0\n", step);
        } else {
            Q |= 1; // Q0 = 1
            printf("Step %d: Positive -> Q0=1\n", step);
        }

        printf("A = "); showBinary(A, n);
        printf(" | Q = "); showBinary(Q, n);
        printf("\n\n");
    }

    if ((dividend < 0) ^ (divisor < 0)) Q = -Q;
    if (dividend < 0) A = -A;

    printf("Final Quotient = %d (Binary: ", Q);
    showBinary(Q, n);
    printf(")\n");
    printf("Final Remainder = %d (Binary: ", A);
    showBinary(A, n);
    printf(")\n");
}

int main() {
    int dividend, divisor;
    printf("Enter dividend: ");
    scanf("%d", &dividend);
    printf("Enter divisor: ");
    scanf("%d", &divisor);

    if (divisor == 0) {
        printf("Error: Divide by zero!\n");
        return 1;
    }

    restoringDivision(dividend, divisor);
    return 0;
}