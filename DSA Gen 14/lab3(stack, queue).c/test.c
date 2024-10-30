#include <stdio.h>
#include <string.h>


int main(void) {
    char input[10]; // Allocate a fixed-size buffer
    printf("Enter a string: ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Remove the newline character from the input
        input[strcspn(input, "\n")] = '\0';
        printf("You entered: %s\n", input);
    } else {
        printf("Error reading input.\n");
    }
    printf("New line here!");
    return 0;
}