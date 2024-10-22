#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct railroad
{
    int passenger;
    char *name;
    struct railroad *next;
};

struct railroad *head = NULL;
struct railroad *current = NULL;

void addCar(int passenger, char *name)
{
    struct railroad *newCar = (struct railroad *)malloc(sizeof(struct railroad));
    newCar->passenger = passenger;
    newCar->name = name;
    newCar->next = NULL;
    if (head == NULL)
    {
        head = newCar;
        current = newCar;
    }
    else
    {
        current->next = newCar;
        current = newCar;
    }
}

int railroadLength()
{
    int length = 0;
    struct railroad *temp = head;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

void printRailroad()
{
    struct railroad *temp = head;
    printf("==> The length of the railroad is %d\\n", railroadLength());
    while (temp != NULL)
    {
        printf("- Passenger: %d, Name: %s, Curr: %p, Next: %p\\n", temp->passenger, temp->name, temp, temp->next);
        temp = temp->next;
    }
}

void remEmptyCar()
{
    struct railroad *temp = head;
    struct railroad *prev = NULL;
    while (temp != NULL)
    {
        if (temp->passenger == 0)
        {
            if (prev == NULL)
            {
                head = temp->next;
                free(temp);
                temp = head;
            }
            else
            {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
}

void main()
{
    printf("==> How many cars do you want to add? ");
    int car_amount;
    scanf("%d", &car_amount);
    printf("Enter the # of passenger(s) and name of each car:\\n");
    for (int i = 0; i < car_amount; i++)
    {
        printf("Car %d: ", i + 1);
        int passenger;
        char *name = (char *)malloc(100);
        scanf("%d %s", &passenger, name);
        addCar(passenger, name);
    }
    printf("==> Remove empty cars? (y/n) ");
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y')
    {
        remEmptyCar();
    }
    printRailroad();

    printf("==> Add more car to the list? (y/n) ");
    scanf(" %c", &choice);
    if (choice == 'y')
    {
        printf("==> How many cars do you want to add? ");
        scanf("%d", &car_amount);
        printf("Enter the # of passenger(s) and name of each car:\\n");
        for (int i = 0; i < car_amount; i++)
        {
            printf("Car %d: ", i + 1);
            int passenger;
            char *name = (char *)malloc(100);
            scanf("%d %s", &passenger, name);
            addCar(passenger, name);
        }
        printf("==> Remove empty cars? (y/n) ");
        scanf(" %c", &choice);
        if (choice == 'y')
        {
            remEmptyCar();
        }
        printRailroad();
    }
}