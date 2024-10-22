#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
// Function to check if three numbers form a Pythagorean triple
int checkPythagoreanTriple(int a, int b, int c) {
    return (a * a + b * b == c * c) || 
           (a * a + c * c == b * b) || 
           (b * b + c * c == a * a);
}

// Recursive function to find and print all Pythagorean triples in an array
void recursivePythagoreanTriples(int arr[], int i, int j, int k, int size) {
    // Base case: If i reaches the end, we are done
    if (i >= size - 2) return;

    // Base case: Move to the next j if j exceeds limit
    if (j >= size - 1) {
        recursivePythagoreanTriples(arr, i + 1, i + 2, i + 3, size);
        return;
    }

    // Base case: Move to the next k if k exceeds limit
    if (k >= size) {
        recursivePythagoreanTriples(arr, i, j + 1, j + 2, size);
        return;
    }

    // Check if the current combination forms a Pythagorean triple
    if (checkPythagoreanTriple(arr[i], arr[j], arr[k])) {
        printf("Pythagorean triple: %d, %d, %d\n", arr[i], arr[j], arr[k]);
    }

    // Recursive case: move to the next k
    recursivePythagoreanTriples(arr, i, j, k + 1, size);
}

bool isPentagon(int a, int b, int c){
    if (a*a + b*b == c*c || c*c+a*a==b*b || c*c + b*b == a){
        return true;
    }
    return false;
}
void FindPentagon(int arr[], int size){
    for (int i = 0; i < size - 2; i++){
        for (int j = i+1; j < size + 1; j++){
            for (int k = 0; k < size ; k++){
                if (isPentagon(arr[i], arr[j], arr[k])){
                    printf("Pentagon triple: %d, %d, %d");
                }

            }
        }
    }

}
int main() {
    srand(time(0));
    const int size = 10; // Initialize an array with 10 random values
    int arr[size];

    // Fill the array with random numbers between 1 and 20
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 20 + 1;
    }

    // Print the array
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Find and print all Pythagorean triples using recursion
    FindPentagon(arr, size);

    return 0;
}
