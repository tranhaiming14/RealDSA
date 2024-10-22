#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int recursiveFindMin(int arr[], int start, int size) {
    if (start >= size) return start;
    int minIndex = recursiveFindMin(arr, start + 1, size);
    return (arr[start] < arr[minIndex]) ? start : minIndex;
}

int recursiveFindMax(int arr[], int start, int size) {
    if (start >= size) return start;
    int maxIndex = recursiveFindMax(arr, start + 1, size);
    return (arr[start] > arr[maxIndex]) ? start : maxIndex;
}

void binaryRecursiveSelectionSort(int arr[], int start, int end) {
    if (start >= end) return;
    
    int minIndex = recursiveFindMin(arr, start, end);
    int maxIndex = recursiveFindMax(arr, start, end);
    
    // Swap minimum to the front
    swap(&arr[start], &arr[minIndex]);
    
    // If the maximum is at the start, we need to swap it with the end
    // to avoid overwriting the position of the minimum element
    if (maxIndex == start) {
        maxIndex = minIndex; // Update maxIndex since it was swapped
    }
    swap(&arr[end], &arr[maxIndex]);
    
    binaryRecursiveSelectionSort(arr, start + 1, end - 1);
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    binaryRecursiveSelectionSort(arr, 0, size - 1);
    
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}