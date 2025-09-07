#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Display a number in binary format with fixed width
void showBinary(int num, int width) {
    for (int i = width - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1); // Print each bit starting from MSB
    }
}

// Calculate minimum bits needed to represent a number
int countBits(int num) {
    if (num == 0) return 1;
    return (int)log2(abs(num)) + 1; // Use logarithm for bit count
}

// Non-Restoring Division algorithm implementation
void nonRestoringDivision(int dividend, int divisor) {
    int n = countBits(dividend);  // Number of steps = bits in dividend
    int A = 0;                    // Accumulator initialized to 0
    int Q = abs(dividend);        // Absolute value of dividend
    int M = abs(divisor);         // Absolute value of divisor

    // Print initial state for tracing
    printf("Initial State:\n");
    printf("A = "); showBinary(A, n);
    printf(" | Q = "); showBinary(Q, n);
    printf(" | M = "); showBinary(M, n);
    printf("\n\n");

    for (int step = 1; step <= n; step++) {
        // Left shift (A,Q) as one unit
        A = (A << 1) | ((Q >> (n - 1)) & 1);  // MSB of Q goes into A
        Q = (Q << 1) & ((1 << n) - 1);        // Shift Q left and mask to width

        // Non-restoring decision: subtract or add divisor
        if (A >= 0) {
            A -= M;  // Tentatively subtract
            if (A >= 0) Q |= 1; // Update Q0 if result still non-negative
            printf("Step %d: A>=0 -> Subtract M, Q0=1 if A>=0\n", step);
        } else {
            A += M;  // Tentatively add
            if (A >= 0) Q |= 1; // Update Q0 if result becomes non-negative
            printf("Step %d: A<0 -> Add M, Q0=1 if A>=0\n", step);
        }

        // Print state after this step
        printf("A = "); showBinary(A, n);
        printf(" | Q = "); showBinary(Q, n);
        printf("\n\n");
    }

    // Final correction if remainder is negative
    if (A < 0) A += M;

    // Adjust sign of quotient and remainder based on original input
    if ((dividend < 0) ^ (divisor < 0)) Q = -Q; // XOR: only one negative → quotient negative
    if (dividend < 0) A = -A;                  // Remainder has same sign as dividend

    // Display final results
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

    // Check for division by zero
    if (divisor == 0) {
        printf("Cannot divide by zero!\n");
        return 1;
    }

    nonRestoringDivision(dividend, divisor);
    return 0;
}

