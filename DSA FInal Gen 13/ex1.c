#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
bool isCube(int num, int n){
    int temp = pow(n, 3) + pow(n+1, 3);
    if (temp > num){
        return false;
    }
    if (temp == num){
        return true;
    }
    return isCube(num, n+1);
}

void checkarray(int* arr, int index, int size){
    if (index >= size){
        return;
    } 
    if (isCube(arr[index], 0)){
        printf("Yeah ! %d is a cube number\n", arr[index]);

    } 
    else{
        printf("Nah %d is not a cube number\n", arr[index]);
    }
    checkarray (arr, index+1, size);
}

int main(){
    int n;
    printf("Enter number of array: ");
    scanf("%d",  &n);
    int* nums = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++){
        scanf("%d",  &nums[i]);

    }
    checkarray(nums, 0, n);

}