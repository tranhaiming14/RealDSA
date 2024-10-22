#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function for modified bubble sort (Bidirectional Bubble Sort)
void cocktailShakerSort(int arr[], int n) {
    int start = 0, end = n - 1;
    int swapped;

    do {
        swapped = 0;

        // Traverse the array from left to right
        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);
                swapped = 1;
            }
        }

        // If no elements were swapped, the array is sorted
        if (!swapped)
            break;

        // Decrement the end point, since the largest element is now at the correct position
        end--;

        swapped = 0;

        // Traverse the array from right to left
        for (int i = end; i > start; i--) {
            if (arr[i] < arr[i - 1]) {
                swap(&arr[i], &arr[i - 1]);
                swapped = 1;
            }
        }

        // Increment the start point, since the smallest element is now at the correct position
        start++;

    } while (swapped);
}

int main() {
    int arr[] = {5, 1, 4, 2, 8, 0, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    cocktailShakerSort(arr, n);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
