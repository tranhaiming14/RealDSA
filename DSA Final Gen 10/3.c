#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;
// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
void insertEnd(int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode; // Modify the head pointer
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Recursive function to calculate GCD using the Euclidean algorithm
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to find and print co-prime pairs in the linked list using a single pointer
void findCoprimePairs(Node* head) {
    Node* current1 = head;
    
    while (current1 != NULL) {
        Node* current2 = head->next; // Reset current2 to the head for each new current1
        while (current2 != NULL) {
            // Avoid checking the same node
            if (current1 != current2 && gcd(current1->data, current2->data) == 1) {
                printf("(%d, %d)\n", current1->data, current2->data);
            }
            current2 = current2->next; // Move to the next node
        }
        current1 = current1->next; // Move to the next node
    }
}

// Main function
int main() {

    // Given array
    int array[] = {2, 10, 27, 13, 90, 45, 5, 26, 49, 50};
    int n = sizeof(array) / sizeof(array[0]);

    // Insert elements into the linked list
    for (int i = 0; i < n; i++) {
        insertEnd(&head, array[i]); // Pass the address of head
    }

    printf("Co-prime pairs:\n");
    findCoprimePairs(head);

    // Free the linked list memory
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}