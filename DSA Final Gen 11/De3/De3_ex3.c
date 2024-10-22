#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Comparison function for descending order
int compare(const void* a, const void* b) {
    return *(int*)b - *(int*)a; // Reverse the subtraction for descending order
}

// Function to check if a value exists in a hash set
bool existsInSet(int* set, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (set[i] == value) return true;
    }
    return false;
}

// Improved function to find triplets
void findTriplets(int arr[], int size) {
    // Sort the array in descending order
    qsort(arr, size, sizeof(int), compare);

    // Create a hash set to store the array elements
    int* hashSet = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        hashSet[i] = arr[i];
    }

    // Iterate over the array
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            // Calculate the product of the current pair
            int product = arr[i] * arr[j];

            // Check if the product exists in the hash set
            if (existsInSet(hashSet, size, product)) {
                // Ensure the product is not equal to the current pair
                if (product != arr[i] && product != arr[j]) {
                    printf("(%d, %d, %d)\n", arr[i], arr[j], product);
                }
            }
        }
    }

    // Free the allocated memory for the hash set
    free(hashSet);
}

// Main function
int main() {
    // Given array
    int arr[] = {4, 15, 45, 9, 40, 27, 3, 5, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Find and print triplets
    printf("Triplets (a, b, c) where a = b * c:\n");
    findTriplets(arr, size);

    return 0;
}