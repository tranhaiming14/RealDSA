#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree.h"

// Function to initialize an array with n random values
void initArray(int* arr, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;  // Generate random values between 0 and 99
    }

}
// Function to build the binary tree
TreeNode* initTree(int* arr, int n) {
    TreeNode* root = NULL;
    for (int i = 0; i < n; i++) {
        insertNode(&root, arr[i]);
    }
    return root;
}

// Function to display the tree information
void displayTree(TreeNode* root, int level) {
    if (root == NULL) return;
    displayTree(root->right, level + 1);
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("%d\n", root->value);
    displayTree(root->left, level + 1);
}

// Function to search for a value in the tree using recursion
int searchTree(TreeNode* root, int value) {
    if (root == NULL) return -1;
    if (root->value == value) {
        displayTree(root, 0);
        return 0;
    }
    int left = searchTree(root->left, value);
    if (left != -1) return left;
    return searchTree(root->right, value);
}

// Function to insert a new node into the tree
void insertNode(TreeNode** root, int value) {
    if (*root == NULL) {
        *root = (TreeNode*)malloc(sizeof(TreeNode));
        (*root)->value = value;
        (*root)->left = NULL;
        (*root)->right = NULL;
    } else {
        if (value < (*root)->value) {
            insertNode(&((*root)->left), value);
        } else {
            insertNode(&((*root)->right), value);
        }
    }
}

// Function to remove a node from the tree
void removeNode(TreeNode** root, int value) {
    if (*root == NULL) return;
    if ((*root)->value == value) {
        // Replace the node with its smallest child (if any)
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root = NULL;
        } else if ((*root)->left == NULL) {
            TreeNode* temp = *root;
            *root = (*root)->right;
            free(temp);
        } else if ((*root)->right == NULL) {
            TreeNode* temp = *root;
            *root = (*root)->left;
            free(temp);
        } else {
            TreeNode* temp = (*root)->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            (*root)->value = temp->value;
            removeNode(&((*root)->right), temp->value);
        }
    } else {
        if (value < (*root)->value) {
            removeNode(&((*root)->left), value);
        } else {
            removeNode(&((*root)->right), value);
        }
    }
}

int main() {
    int arr[5];
    initArray(arr, 5);
    TreeNode* root = initTree(arr, 5);
    displayTree(root, 0);
    printf("Search for 20: %d\n", searchTree(root, 20));
    insertNode(&root, 15);
    displayTree(root, 0);
    removeNode(&root, 20);
    displayTree(root, 0);
    return 0;
}