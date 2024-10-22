#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers for qsort
int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

// Function to find triplets
void findTriplets(int arr[], int size) {
    // Sort the array in ascending order
    qsort(arr, size, sizeof(int), compare);

    // Iterate over the array
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            // Calculate the product of the current pair
            int product = arr[i] * arr[j];

            // Check if the product exists in the array
            // A linear search is used to check if the product is in the array
            for (int k = 0; k < size; k++) {
                if (arr[k] == product) {
                    // Ensure the product is not equal to the current pair
                    if (product != arr[i] && product != arr[j]) {
                        printf("(%d, %d, %d)\n", arr[i], arr[j], product);
                    }
                    break; // Exit the loop once the product is found
                }
            }
        }
    }
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