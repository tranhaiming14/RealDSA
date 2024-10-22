#include <iostream>
#include <vector>
using namespace std;

// Function to check if a number is pentagonal using recursion
bool isPentagonal(int num, int n = 1) {
    int pentagonalValue = (3 * n * n - n) / 2;
    
    if (pentagonalValue == num)
        return true;
    else if (pentagonalValue > num)
        return false;
    else
        return isPentagonal(num, n + 1);
}

// Function to check if all elements in the array are pentagonal
void checkArrayPentagonal(const vector<int>& arr, int index = 0) {
    if (index >= arr.size())
        return;

    if (isPentagonal(arr[index]))
        cout << arr[index] << " is a pentagonal number." << endl;
    else
        cout << arr[index] << " is not a pentagonal number." << endl;
    
    // Recursively check the next element in the array
    checkArrayPentagonal(arr, index + 1);
}

int main() {
    // Initialize a random array
    vector<int> arr = {1, 5, 12, 15, 22, 35};
    
    // Check if each number in the array is pentagonal
    checkArrayPentagonal(arr);
    
    return 0;
}
