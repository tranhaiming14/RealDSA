#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode{
    int value;
    struct TreeNode*  left;
    struct TreeNode*  right;

} TreeNode;

typedef struct StackNode{
    TreeNode* Treenode;
    struct StackNode* next;
} StackNode;

typedef struct  Stack{
    struct StackNode* top;
} Stack;

void initStack(Stack* stack){
    stack->top = NULL;
}

TreeNode* createTreeNode(int value){
    TreeNode* treenode = (TreeNode*)malloc(sizeof(TreeNode));
    treenode->value = value;
    treenode->left = NULL;
    treenode->right = NULL;  
    return treenode;
}

TreeNode* pop(Stack* stack){
    if (stack->top == NULL){
        return NULL;
    }
    StackNode* temp = stack->top;
    TreeNode* poppedNode = temp->Treenode;
    stack->top = stack->top->next;
    free(temp);
    return poppedNode;


}

void push(Stack* stack, TreeNode* treenode){
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->Treenode = treenode;
    newNode->next = stack->top;
    stack->top = newNode;
}
bool isEmpty(Stack* stack){
    if (stack->top == NULL){
        return true;
    }
    return false;
}
void DFS(TreeNode* root){
    if (root == NULL){
        return;
    }
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    initStack(stack);
    push(stack, root);
    while (!isEmpty(stack)){
        TreeNode* current = pop(stack);
        printf("%d ", current->value);
        if (current->right != NULL){
            push(stack, current->right);
        }
        if (current->left != NULL){
            push(stack,  current->left);
        }
    }
}
int main(){
    TreeNode* root = createTreeNode(1);
    root->left = createTreeNode(2);
    root->right = createTreeNode(3);
    root->left->left = createTreeNode(4);
    root->left->right = createTreeNode(5);
    root->right->left = createTreeNode(6);
    root->right->right = createTreeNode(7);
    printf("Address of root->right->right: %p\n", (void*)&root->right->right);   
    DFS(root);
}



