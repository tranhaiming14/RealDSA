#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isPerfectSquare(int num) {
    int sqrt_num = sqrt(num);
    return (sqrt_num * sqrt_num == num);
}

void findPythagoreanTriplets(int arr[], int n, int start, int end) {
    if (start >= end) {
        return;
    }

    int a = arr[start];
    for (int i = start + 1; i <= end; i++) {
        int b = arr[i];
        int c_squared = a * a + b * b;
        if (isPerfectSquare(c_squared)) {
            int c = sqrt(c_squared);
            printf("(%d, %d, %d)\n", a, b, c);
        }
    }

    findPythagoreanTriplets(arr, n, start + 1, end);
}

int main() {
    int arr[] = {4, 15, 28, 45, 40, 9, 53, 41, 8, 17, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    findPythagoreanTriplets(arr, n, 0, n - 1);

    return 0;
}