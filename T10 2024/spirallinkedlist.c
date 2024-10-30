#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int data;
    struct ListNode* next;
} ListNode;

void printInSpiralOrder(ListNode* head){
    ListNode* t = head;
    int count = 0;
    while (t != NULL){
        t = t->next;
        count++;
    }
    int* newarr = (int*)malloc(count*sizeof(int));
    int index = 0;
    t = head;
    while (t != NULL){
        newarr[index] = t->data;
        index++;
        t = t->next;
    }
    int mid = (count-1)/2;
    int left = mid;
    int right = mid + 1;
    while (left >= 0 || right < count){
        if  (left >= 0){
            printf("%d ", newarr[left]);
            left -= 1;
        }
        if (right < count){
            printf("%d ", newarr[right]);
            right += 1;
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
    
}
