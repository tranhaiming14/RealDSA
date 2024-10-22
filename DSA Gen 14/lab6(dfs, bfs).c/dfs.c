#include <stdio.h>
#include <stdlib.h>

// Define TreeNode structure
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Define StackNode structure for the stack nodes
typedef struct StackNode {
    TreeNode* treeNode;
    struct StackNode* next;
} StackNode;

// Define Stack structure that holds the top of the stack
typedef struct Stack {
    StackNode* top;
} Stack;

// Function to create a new tree node
TreeNode* createTreeNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to create a new stack node
StackNode* createStackNode(TreeNode* treeNode) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->treeNode = treeNode;
    newNode->next = NULL;
    return newNode;
}

// Initialize the stack
void initStack(Stack* stack) {
    stack->top = NULL;
}

// Function to push a tree node onto the stack
void push(Stack* stack, TreeNode* treeNode) {
    StackNode* newStackNode = createStackNode(treeNode);
    newStackNode->next = stack->top; // Link the new node to the previous top
    stack->top = newStackNode;       // Update the top pointer to the new node
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Function to pop a tree node from the stack
TreeNode* pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return NULL;
    }
    StackNode* temp = stack->top;
    TreeNode* poppedNode = temp->treeNode;
    stack->top = stack->top->next; // Move the top pointer to the next node
    free(temp);                    // Free the old top
    return poppedNode;
}

// DFS using stack
void DFS(TreeNode* root) {
    if (root == NULL) return;

    Stack stack;
    initStack(&stack);  // Initialize the stack

    // Push the root node
    push(&stack, root);

    while (!isEmpty(&stack)) {
        // Pop the top node
        TreeNode* currentNode = pop(&stack);
        printf("%d ", currentNode->data);

        // Push right and left children (right first so that left is processed first)
        if (currentNode->right != NULL) push(&stack, currentNode->right);
        if (currentNode->left != NULL) push(&stack, currentNode->left);
    }
}

// Driver function
int main() {
    // Create the tree manually
    TreeNode* root = createTreeNode(1);
    root->left = createTreeNode(2);
    root->right = createTreeNode(3);
    root->left->left = createTreeNode(4);
    root->left->right = createTreeNode(5);
    root->right->left = createTreeNode(6);
    root->right->right = createTreeNode(7);

    printf("DFS new traversal of the tree: ");
    DFS(root);

    return 0;
}
