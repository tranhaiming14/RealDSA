#include <stdio.h>
#include <math.h>

// Helper function to check if a number is prime
int is_prime(int n) {
    if (n <= 1)
        return 0;
    if (n == 2 || n == 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    }
    return 1;
}

// Function to find the largest divisor d1 and d2
void find_largest_divisors(int N, int *d1, int *d2) {
    for (int i = sqrt(N); i >= 1; i--) {
        if (N % i == 0) {
            *d1 = i;
            *d2 = N / i;
            return;
        }
    }
}

// Divide and conquer prime factorization
void divide_and_conquer_factorization(int N) {
    // Base case: if N is prime, print it and return
    if (is_prime(N)) {
        printf("%d ", N);
        return;
    }
    
    // Find largest divisors d1 and d2
    int d1, d2;
    find_largest_divisors(N, &d1, &d2);

    // If d1 or d2 is not prime, recursively factor them
    if (!is_prime(d1)) {
        divide_and_conquer_factorization(d1);
    } else {
        printf("%d ", d1);
    }

    if (!is_prime(d2)) {
        divide_and_conquer_factorization(d2);
    } else {
        printf("%d ", d2);
    }
}

int main() {
    int N;
    printf("Enter a number to factorize: ");
    scanf("%d", &N);

    printf("Prime factorization of %d: ", N);
    divide_and_conquer_factorization(N);
    printf("\n");

    return 0;
}
