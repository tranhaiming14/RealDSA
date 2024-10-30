#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACTION_LENGTH 50

struct Action_queue
{
    char action[MAX_ACTION_LENGTH];
    struct Action_queue *next;
};

struct Action_queue *head = NULL;
struct Action_queue *tail = NULL;

int queueLength(struct Action_queue *queue)
{
    int length = 0;
    while (queue != NULL)
    {
        length++;
        queue = queue->next;
    }
    return length;
}

void push(struct Action_queue **queue, const char *action)
{
    struct Action_queue *new_node = (struct Action_queue *)malloc(sizeof(struct Action_queue));
    strcpy(new_node->action, action);
    new_node->next = NULL;
    
    if (*queue == NULL)
    {
        *queue = new_node;
        return;
    }
    
    struct Action_queue *temp = *queue;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

char* pop(struct Action_queue **queue)
{
    if (*queue == NULL || (*queue)->next == NULL)
    {
        return "";
    }
    
    struct Action_queue *temp = *queue;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    
    char *action = (char*)malloc(MAX_ACTION_LENGTH * sizeof(char));
    strcpy(action, temp->next->action);
    free(temp->next);
    temp->next = NULL;
    
    return action;
}

void printQueue(struct Action_queue *queue)
{
    int qLength = queueLength(queue);
    if (qLength == 0)
    {
        printf("Queue is empty\n");
        return;
    }
    
    while (queue != NULL)
    {
        if (strlen(queue->action) > 0)
        {
            printf("%s, ", queue->action);
        }
        queue = queue->next;
    }
    printf("\n");
}

void cls()
{
    printf("\033[2J\033[H");
}

int main()
{
    struct Action_queue *undo_queue = NULL;
    struct Action_queue *redo_queue = NULL;

    // Initializing undo queue with actions
    for (int i = 0; i < 10; i++)
    {
        char action[MAX_ACTION_LENGTH];
        sprintf(action, "action%d", i);
        push(&undo_queue, action);
    }

    char action[10];
    char errMsg[MAX_ACTION_LENGTH] = "";

    while (1)
    {
        if (strlen(errMsg) > 0)
        {
            printf("%s\n", errMsg);
            strcpy(errMsg, "");
            cls();
        }
        else
        {
            cls();
        }

        printf("Undo queue: ");
        printQueue(undo_queue);
        printf("Redo queue: ");
        printQueue(redo_queue);

        printf("\n1. Add an action to the undo queue\n");
        printf("2. Undo an action\n");
        printf("3. Redo an action\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%s", action);

        if (strcmp(action, "1") == 0)
        {
            char action_name[MAX_ACTION_LENGTH];
            printf("Enter an action name: ");
            scanf("%s", action_name);
            push(&undo_queue, action_name);
        }
        else if (strcmp(action, "2") == 0)
        {
            if (queueLength(undo_queue) == 0)
            {
                strcpy(errMsg, "Undo queue is empty, cannot undo");
                continue;
            }
            char *popped_action = pop(&undo_queue);
            push(&redo_queue, popped_action);
            free(popped_action);
        }
        else if (strcmp(action, "3") == 0)
        {
            if (queueLength(redo_queue) == 0)
            {
                strcpy(errMsg, "Redo queue is empty, cannot redo");
                continue;
            }
            char *popped_action = pop(&redo_queue);
            push(&undo_queue, popped_action);
            free(popped_action);
        }
        else if (strcmp(action, "4") == 0)
        {
            break;
        }
        else
        {
            printf("Invalid input\n");
        }
    }

    return 0;
}
