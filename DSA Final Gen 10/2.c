#include <stdio.h>

// Recursive function to calculate GCD using the Euclidean algorithm
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Recursive function to find co-prime pairs
void find_coprime_pairs_recursive(int arr[], int n, int i, int j) {
    // Base case: if we have checked all pairs
    if (i >= n) return;

    // Check if we need to move to the next element
    if (j >= n) {
        find_coprime_pairs_recursive(arr, n, i + 1, i + 2);
        return;
    }

    // Check if the pair is co-prime
    if (gcd(arr[i], arr[j]) == 1) {
        printf("(%d, %d)\n", arr[i], arr[j]);
    }

    // Move to the next pair
    find_coprime_pairs_recursive(arr, n, i, j + 1);
}

int main() {
    int array[] = {2, 10, 27, 13, 90, 45, 5, 26, 49, 50};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Co-prime pairs:\n");
    find_coprime_pairs_recursive(array, n, 0, 1);

    return 0;
}