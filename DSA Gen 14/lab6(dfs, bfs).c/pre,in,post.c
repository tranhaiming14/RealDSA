#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node in the binary search tree
struct Node* insert(struct Node* node, int data) {
    // If the tree is empty, return a new node
    if (node == NULL) return createNode(data);

    // Otherwise, recur down the tree
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    // return the (unchanged) node pointer
    return node;
}

// Pre-order traversal
void preOrder(struct Node* node) {
    if (node == NULL) return;

    printf("%d ", node->data);  // Print data of node
    preOrder(node->left);       // Recur on left child
    preOrder(node->right);      // Recur on right child
}

// In-order traversal
void inOrder(struct Node* node) {
    if (node == NULL) return;

    inOrder(node->left);        // Recur on left child
    printf("%d ", node->data);  // Print data of node
    inOrder(node->right);       // Recur on right child
}

// Post-order traversal
void postOrder(struct Node* node) {
    if (node == NULL) return;

    postOrder(node->left);      // Recur on left child
    postOrder(node->right);     // Recur on right child
    printf("%d ", node->data);  // Print data of node
}

// Main function
int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Pre-order traversal: \n");
    preOrder(root);

    printf("\nIn-order traversal: \n");
    inOrder(root);

    printf("\nPost-order traversal: \n");
    postOrder(root);

    return 0;
}
