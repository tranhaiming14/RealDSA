#include <stdio.h>
int RecurSumofDigits(int n){
    if (n <= 0){
        return 0;
    }
    else{
    int reminder = n % 10;
    return reminder + RecurSumofDigits(n / 10);

    }
}

int IterSumofDigits(int n){
    int sum = 0;
    while (n>0){
        int reminder = n % 10;
        sum += reminder;
        n /= 10;
    }
    return sum;
}
int main(){
    printf("The sum  of digits of 123 is %d\n", IterSumofDigits(123));

    printf("The sum  of digits of 123 is %d\n", RecurSumofDigits(123));

}