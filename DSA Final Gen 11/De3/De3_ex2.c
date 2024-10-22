#include <stdio.h>
#include <stdlib.h>

// Comparison function for descending order
int compare(const void* a, const void* b) {
    return *(int*)b - *(int*)a; // Reverse the subtraction for descending order
}

// Recursive function to find triplets
void findTripletsRecursive(int arr[], int size, int i, int j) {
    // Base case: if we have iterated through all pairs
    if (i >= size - 1) return;
    if (j >= size) {
        // Move to the next element if we've exhausted pairs with the current i
        findTripletsRecursive(arr, size, i + 1, i + 2);
        return;
    }

    // Calculate the product of the current pair
    int product = arr[i] * arr[j];

    // Check if the product exists in the array
    for (int k = 0; k < size; k++) {
        if (arr[k] == product) {
            // Ensure the product is not equal to the current pair
            if (product != arr[i] && product != arr[j]) {
                printf("(%d, %d, %d)\n", arr[i], arr[j], product);
            }
            break; // Exit the loop once the product is found
        }
    }

    // Recursive call for the next pair
    findTripletsRecursive(arr, size, i, j + 1);
}

// Wrapper function to initiate the recursive search
void findTriplets(int arr[], int size) {
    // Sort the array in descending order
    qsort(arr, size, sizeof(int), compare);
    // Start recursion with the first two indices
    findTripletsRecursive(arr, size, 0, 1);
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