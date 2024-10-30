#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

void  push(Node** head, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL){
        *head = newNode;
    }
    else{
        Node* temp = *head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printlist(Node** head){
    Node* temp = *head;
    while (temp != NULL){
        printf("%d ->",  temp->data);
        temp = temp->next;
    }
    printf("NULL");
}
void freelist(Node** head) {
    while (*head != NULL) { // Check if the head node is not NULL
        Node* temp = *head; // Store the current head node
        *head = (*head)->next; // Move to the next node
        free(temp); // Free the current node
    }
}



int main(){
    Node* head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    push(&head, 6);
    printlist(&head);
    freelist(&head);

    return 0;
}
