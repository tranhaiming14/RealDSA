#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// Node structure for linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insert(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to free the linked list
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to check if a number is a perfect square
bool isPerfectSquare(int num) {
    int sqrt_num = (int)sqrt(num);
    return (sqrt_num * sqrt_num == num);
}

// Function to find Pythagorean triplets
void findPythagoreanTriplets(Node* head) {
    Node* current = head;
    Node* nextNode;
    
    while (current != NULL) {
        nextNode = current->next;
        while (nextNode != NULL) {
            int c_squared = current->data * current->data + nextNode->data * nextNode->data;
            if (isPerfectSquare(c_squared)) {
                int c = (int)sqrt(c_squared);
                printf("(%d, %d, %d)\n", current->data, nextNode->data, c);
            }
            nextNode = nextNode->next;
        }
        current = current->next;
    }
}

// Main function
int main() {
    Node* head = NULL;
    int elements[] = {4, 15, 28, 45, 40, 9, 53, 41, 8, 17, 3, 5};
    int size = sizeof(elements) / sizeof(elements[0]);

    // Insert elements into the linked list
    for (int i = 0; i < size; i++) {
        insert(&head, elements[i]);
    }

    // Find and print Pythagorean triplets
    findPythagoreanTriplets(head);

    // Free the linked list
    freeList(head);
    
    return 0;
}