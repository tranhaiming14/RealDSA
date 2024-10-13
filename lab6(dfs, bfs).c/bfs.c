#include <stdio.h>
#include <stdlib.h>
struct Treenode{
    int value;
    struct Treenode* left;
    struct Treenode* right;
};
typedef struct Treenode TreeNode;

typedef struct QueueNode {
    TreeNode* treeNode;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// Function to create a new tree node
TreeNode* createTreeNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to create an empty queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to enqueue a tree node
void enqueue(Queue* q, TreeNode* node) {
    QueueNode* newQueueNode = (QueueNode*)malloc(sizeof(QueueNode));
    newQueueNode->treeNode = node;
    newQueueNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newQueueNode;
        return;
    }
    q->rear->next = newQueueNode;
    q->rear = newQueueNode;
}

// Function to dequeue a tree node
TreeNode* dequeue(Queue* q) {
    if (q->front == NULL) return NULL;
    QueueNode* temp = q->front;
    TreeNode* node = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return node;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// Level-order traversal
void levelOrderTraversal(TreeNode* root) {
    if (root == NULL) return;
    
    Queue* q = createQueue();
    enqueue(q, root);
    
    while (!isEmpty(q)) {
        TreeNode* current = dequeue(q);
        printf("%d ", current->value);
        
        if (current->left != NULL) enqueue(q, current->left);
        if (current->right != NULL) enqueue(q, current->right);
    }
    
    printf("\n");
}

int main() {
    // Creating the tree based on the provided structure
    TreeNode* root = createTreeNode(10);
    root->left = createTreeNode(4);
    root->right = createTreeNode(8);
    root->left->left = createTreeNode(9);
    root->left->right = createTreeNode(13);
    root->right->left = createTreeNode(70);
    root->right->right = createTreeNode(3);
    
    // Perform level-order traversal
    printf("Level-order traversal: ");
    levelOrderTraversal(root);

    return 0;
}
