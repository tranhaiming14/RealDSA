#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int data;
    struct ListNode* next;
} ListNode;

ListNode* getMidNode(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void reversetillMidNode(ListNode* head){
    ListNode* mid = getMidNode(head);
    ListNode* nexttoMid =  mid->next;
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next = NULL;
    while (curr != nexttoMid){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

}

void printInSpiralOrder(ListNode* head){
    ListNode* mid = getMidNode(head);
    ListNode* nexttomid = mid->next;
    reversetillMidNode(head);

    ListNode* iter1 = mid;
    ListNode* iter2 = nexttomid;
    while (iter1 != NULL || iter2 != NULL){
        if (iter1  != NULL){
            printf("%d ", iter1->data);
            iter1 = iter1->next;}
        if (iter2 != NULL){
            printf("%d ", iter2->data);
            iter2 = iter2->next;
        }
    }
}
int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    ListNode* head = NULL;
    for (int i = 0;  i < n; i++){   
        ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
        newNode->data = arr[i];
        newNode->next = NULL;
        if (head == NULL){
            head = newNode;
        }
        else{
            ListNode* temp = head;
            while (temp->next  != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    printInSpiralOrder(head);
    while (head != NULL){
        ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}
