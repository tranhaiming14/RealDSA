#ifndef TREE_H
#define TREE_H

typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* initTree(int* arr, int n);
void displayTree(TreeNode* root, int level);
int searchTree(TreeNode* root, int value);
void insertNode(TreeNode** root, int value);
void removeNode(TreeNode** root, int value);

#endif  // TREE_H