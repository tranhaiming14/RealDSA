#include <stdio.h>

void improvedBubbleSort(int arr[], int n) {
    int max_idx, min_idx;
    for (int i = 0; i < n / 2; i++) {
        // Find the maximum and minimum elements
        max_idx = i;
        min_idx = i;
        for (int j = i; j < n - i; j++) {
            if (arr[j] > arr[max_idx]) {
                max_idx = j;
            }
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the maximum element to the end
        int temp = arr[max_idx];
        arr[max_idx] = arr[n - i - 1];
        arr[n - i - 1] = temp;

        // Adjust the minimum index if the maximum was swapped from the beginning
        if (min_idx == n - i - 1) {
            min_idx = max_idx;
        }

        // Swap the minimum element to the beginning
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr[] = {5, 1, 4, 2, 8, 3, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    improvedBubbleSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}