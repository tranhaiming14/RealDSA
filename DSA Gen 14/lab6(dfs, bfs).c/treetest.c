#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_ELEMENTS 100

// Define the structure for a tree node
typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new tree node
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to initialize an array with n random values
void initializeArray(int* arr, int n) {
    srand(time(NULL)); // Seed for random number generation
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Random values between 0 and 99
    }
}

// Function to build the complete binary tree
TreeNode* buildTree(int* arr, int n) {
    TreeNode** nodes = (TreeNode**)malloc(n * sizeof(TreeNode*));
    
    for (int i = 0; i < n; i++) {
        nodes[i] = createNode(arr[i]);
    }
    
    for (int i = 0; i < n / 2; i++) {
        nodes[i]->left = nodes[2 * i + 1];
        if (2 * i + 2 < n) {
            nodes[i]->right = nodes[2 * i + 2];
        }
    }
    
    TreeNode* root = nodes[0];
    free(nodes);
    return root;
}

// Function to display the tree information using inorder traversal
void displayTree(TreeNode* root) {
    if (root == NULL) return;
    
    displayTree(root->left);
    printf("%d ", root->value);
    displayTree(root->right);
}

// Function to search for a value recursively
TreeNode* search(TreeNode* root, int value) {
    if (root == NULL) return NULL;
    if (root->value == value) return root;
    
    TreeNode* leftSearch = search(root->left, value);
    if (leftSearch != NULL) return leftSearch;
    
    return search(root->right, value);
}

// Function to display the subtree rooted at a given node
void displaySubtree(TreeNode* root) {
    if (root == NULL) return;
    
    printf("%d ", root->value);
    displaySubtree(root->left);
    displaySubtree(root->right);
}

// Function to insert a new node into the tree
TreeNode* insert(TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    
    return root;
}

// Function to remove a node from the tree
TreeNode* removeNode(TreeNode* root, int value) {
    if (root == NULL) return NULL;
    
    if (value < root->value) {
        root->left = removeNode(root->left, value);
    } else if (value > root->value) {
        root->right = removeNode(root->right, value);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        
        // Node with two children: Get the inorder successor (smallest in the right subtree)
        TreeNode* temp = root->right;
        while (temp && temp->left != NULL) {
            temp = temp->left;
        }
        
        root->value = temp->value; // Copy the inorder successor's value to this node
        root->right = removeNode(root->right, temp->value); // Delete the inorder successor
    }
    return root;
}

// Main function to demonstrate the tree functionalities
int main() {
    int n = 5; // Number of elements
    int arr[MAX_ELEMENTS];
    
    // Initialize the array with random values
    initializeArray(arr, n);
    
    // Build the complete binary tree
    TreeNode* root = buildTree(arr, n);
    
    // Display the tree
    printf("Tree elements in inorder: ");
    displayTree(root );
    printf("\n");
    
    // Search for a value
    int searchValue = 20;
    TreeNode* foundNode = search(root, searchValue);
    if (foundNode != NULL) {
        printf("Found %d in the tree. Subtree rooted at %d: ", searchValue, searchValue);
        displaySubtree(foundNode);
        printf("\n");
    } else {
        printf("%d not found in the tree.\n", searchValue);
    }
    
    // Insert a new node
    int insertValue = 30;
    root = insert(root, insertValue);
    printf("Tree elements after insertion in inorder: ");
    displayTree(root);
    printf("\n");
    
    // Remove a node
    int removeValue = 20;
    root = removeNode(root, removeValue);
    printf("Tree elements after removal in inorder: ");
    displayTree(root);
    printf("\n");
    
    return 0;
}