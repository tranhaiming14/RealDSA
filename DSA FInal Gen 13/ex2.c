#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Queue structure
typedef struct Queue {
    Node* data[100];
    int front, rear;
} Queue;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to initialize the queue
void initQueue(Queue* q) {
    q->front = q->rear = -1;
}

// Function to check if the queue is empty
int isQueueEmpty(Queue* q) {
    return (q->front == -1 && q->rear == -1);
}

// Function to enqueue a node
void enqueue(Queue* q, Node* node) {
    if (q->rear == 99) {
        printf("Queue is full.\n");
        return;
    }
    if (isQueueEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }
    q->data[q->rear] = node;
}

// Function to dequeue a node
Node* dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        return NULL;
    }
    Node* node = q->data[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return node;
}

// Function to traverse and display the tree
void traverseTree(Node* root) {
    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isQueueEmpty(&q)) {
        Node* node = dequeue(&q);
        printf("%d ", node->data);

        if (node->left) {
            enqueue(&q, node->left);
        }
        if (node->right) {
            enqueue(&q, node->right);
        }
    }
}

int main() {
    // Create the tree
    Node* root = createNode(10);
    root->left = createNode(4);
    root->right = createNode(8);
    root->left->left = createNode(9);
    root->left->right = createNode(13);
    root->right->left = createNode(70);
    root->right->right = createNode(3);

    // Traverse and display the tree
    traverseTree(root);
    printf("\n");

    return 0;
}