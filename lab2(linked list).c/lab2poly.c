#include <stdio.h>
#include <stdlib.h>
#include <math.h> // For pow function

#define MAX_TERMS 100

typedef struct {
    double coefficient;
    int degree;
} PolynomialTerm;

typedef struct {
    PolynomialTerm terms[MAX_TERMS];
    int size;
} Polynomial;

// Function prototypes
void initPolynomial(Polynomial *p);
void addTerm(Polynomial *p, double coefficient, int degree);
void removeTerm(Polynomial *p, int degree);
double evaluatePolynomial(Polynomial *p, double x);
void displayPolynomial(Polynomial *p);

int main() {
    Polynomial p;
    initPolynomial(&p);

    // Adding terms to the polynomial
    addTerm(&p, 2.0, 2);  // 2x^2
    addTerm(&p, 3.0, 1);  // 3x^1
    addTerm(&p, 5.0, 0);  // 5x^0
    addTerm(&p, 4.0, 1);  // 4x^1 (should combine with the previous x^1 term)

    // Display polynomial
    printf("Polynomial: ");
    displayPolynomial(&p);
    
    // Evaluate the polynomial for a given x
    double x;
    printf("Enter a value for x: ");
    scanf("%lf", &x);
    double result = evaluatePolynomial(&p, x);
    printf("Polynomial evaluated at x = %.2f: %.2f\n", x, result);

    // Remove a term
    removeTerm(&p, 1); // Remove x^1 term
    printf("After removing x^1 term: ");
    displayPolynomial(&p);

    return 0;
}

// Initialize the polynomial
void initPolynomial(Polynomial *p) {
    p->size = 0;
}

// Add a term to the polynomial
void addTerm(Polynomial *p, double coefficient, int degree) {
    for (int i = 0; i < p->size; i++) {
        if (p->terms[i].degree == degree) {
            // Combine with existing term
            p->terms[i].coefficient += coefficient;
            return;
        }
    }
    // Add new term if it doesn't exist
    if (p->size < MAX_TERMS) {
        p->terms[p->size].coefficient = coefficient;
        p->terms[p->size].degree = degree;
        p->size++;
    } else {
        printf("Error: Maximum number of terms exceeded.\n");
    }
}

// Remove a term from the polynomial
void removeTerm(Polynomial *p, int degree) {
    for (int i = 0; i < p->size; i++) {
        if (p->terms[i].degree == degree) {
            // Shift terms down to remove the term
            for (int j = i; j < p->size - 1; j++) {
                p->terms[j] = p->terms[j + 1];
            }
            p->size--;
            return;
        }
    }
    printf("Term with degree %d not found.\n", degree);
}

// Evaluate the polynomial at a given value of x
double evaluatePolynomial(Polynomial *p, double x) {
    double result = 0.0;
    for (int i = 0; i < p->size; i++) {
        result += p->terms[i].coefficient * pow(x, p->terms[i].degree);
    }
    return result;
}

// Display the polynomial
void displayPolynomial(Polynomial *p) {
    for (int i = 0; i < p->size; i++) {
        if (i > 0 && p->terms[i].coefficient > 0) {
            printf(" + ");
        }
        printf("%.2fx^%d", p->terms[i].coefficient, p->terms[i].degree);
    }
    printf("\n");
}