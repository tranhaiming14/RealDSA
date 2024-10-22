#include <stdio.h>

void printBinary(int n) {
    if (n == 0) {
        printf("0");
        return;
    }
    
    int binary[32]; // Enough to hold binary representation
    int index = 0;

    // Convert integer part to binary
    while (n > 0) {
        binary[index] = n % 2;
        n /= 2;
        index++;
    }

    // Print binary representation in reverse
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
}

void printFractionBinary(float frac, int precision) {
    printf(".");
    while (precision-- > 0) {
        frac *= 2;
        int bit = (int) frac; // Get the integer part (0 or 1)
        printf("%d", bit);
        frac -= bit; // Remove the integer part
    }
}

int main() {
    float n;
    printf("Enter the number: ");
    scanf("%f", &n);
    
    printf("The num is: %.2f\n", n);
    
    printf("Enter the precision: ");
    int k;
    scanf("%d", &k);

    int deci = (int)n; // Get the integer part
    float frac = n - deci; // Get the fractional part

    // Print binary of integer part
    printf("Binary representation: ");
    printBinary(deci);

    // Print binary of fractional part
    printFractionBinary(frac, k);
    
    printf("\n");
    
    return 0;
}