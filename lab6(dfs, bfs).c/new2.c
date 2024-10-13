#include <stdio.h>
#include  <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode{
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct QueueNode{
    struct TreeNode* TreeNode;
    struct QueueNode* next; 
}  QueueNode;

typedef struct Queue{
    QueueNode* front;
    QueueNode* rear;
} Queue;
void initQueue(Queue* queue){
    queue->front = queue->rear  = NULL;
}

    

void enqueue(Queue* queue, TreeNode* node){
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->TreeNode = node;
    newNode->next = NULL;
    if (queue->front == NULL){
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}
TreeNode* dequeue(Queue* queue){
    if (queue->front ==  NULL){
        return NULL;
    }
    QueueNode* temp = queue->front;
    TreeNode* poppedNode = temp->TreeNode;
    queue->front = queue->front->next;
    if (queue->front == NULL) queue->rear = NULL;
    free(temp);
    return poppedNode;
}
TreeNode* CreateTreeNode(int value){
    TreeNode* Treenode = (TreeNode*)malloc(sizeof(TreeNode));
    Treenode->value = value;
    Treenode->left = NULL;
    Treenode->right = NULL;
    return Treenode; // You were missing the return statement!

}
bool isEmpty(Queue* queue){
    return queue->front == NULL;
}
void BFS(TreeNode* root){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    initQueue(queue);
    enqueue(queue, root);
    while (!isEmpty(queue)){
        TreeNode* cur = dequeue(queue);
        printf("%d ", cur->value);

        if (cur->left  != NULL){
            enqueue(queue, cur->left);
        }
        if (cur->right  != NULL){
            enqueue(queue, cur->right);
        }

    }   
    free(queue);
}

int main(){
    TreeNode* root = CreateTreeNode(1);
    root->left = CreateTreeNode(2);
    root->right = CreateTreeNode(3);
    root->left->left = CreateTreeNode(4);
    root->left->right = CreateTreeNode(5);
    root->right->left = CreateTreeNode(6);
    root->right->right = CreateTreeNode(7);
    BFS(root);
    return 0;

}