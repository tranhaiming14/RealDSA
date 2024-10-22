#include <stdio.h>

// Function to calculate GCD using the Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to find co-prime pairs in the array
void find_coprime_pairs(int arr[], int n) {
    printf("Co-prime pairs:\n");
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (gcd(arr[i], arr[j]) == 1) {
                printf("(%d, %d)\n", arr[i], arr[j]);
            }
        }
    }
}

int main() {
    int array[] = {2, 10, 27, 13, 90, 45, 5, 26, 49, 50};
    int n = sizeof(array) / sizeof(array[0]);
    
    find_coprime_pairs(array, n);
    
    return 0;
}