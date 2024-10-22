#include <stdio.h>

// Recursive function for prime factorization
void prime_factorization(int N, int factor) {
    // Base case: If N is reduced to 1, return
    if (N == 1) 
        return;

    // Check if N is divisible by the current factor
    while (N % factor == 0) {
        printf("%d ", factor);
        N /= factor;
    }

    // Recursively check the next factor
    prime_factorization(N, factor + 1);
}

int main() {
    int N;
    printf("Enter a number to factorize: ");
    scanf("%d", &N);
    
    printf("Prime factorization of %d: ", N);
    prime_factorization(N, 2);
    
    return 0;
}
