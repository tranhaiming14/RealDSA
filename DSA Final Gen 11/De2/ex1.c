#include <stdio.h>

void recursive_selection_sort(int arr[], int n, int index) {
    // Base case: If index reaches the last element, return
    if (index >= n - 1) {
        return;
    }

    // Assume the minimum is the first element of the unsorted sublist
    int min_index = index;

    // Find the index of the smallest element in the unsorted sublist
    for (int j = index + 1; j < n; j++) {
        if (arr[j] < arr[min_index]) {
            min_index = j;
        }
    }

    // Swap only if a smaller element was found
    if (min_index != index) {
        int temp = arr[index];
        arr[index] = arr[min_index];
        arr[min_index] = temp;
    }

    // Recursively call the function for the next index
    recursive_selection_sort(arr, n, index + 1);
}

int main() {
    int numbers[] = {64, 25, 12, 22, 11};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    recursive_selection_sort(numbers, n, 0);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}