#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Products
{
	char name[50];
	int quantity;
	struct Products *next;
};

struct Products *prod_head = NULL;
struct Products *prod_tail = NULL;

int validateProdName(char *name)
{
	struct Products *temp = prod_head;
	while (temp != NULL)
	{
		if (strcmp(temp->name, name) == 0)
		{
			return 1;  // Found
		}
		temp = temp->next;
	}
	return 0;  // Not found
}

int validateProdQuantity(char *name, int quantity)
{
	struct Products *temp = prod_head;
	while (temp != NULL)
	{
		if (strcmp(temp->name, name) == 0)
		{
			if (temp->quantity >= quantity)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		temp = temp->next;
	}
	return 0;
}

int getProdQuantity(char *name)
{
	struct Products *temp = prod_head;
	while (temp != NULL)
	{
		if (strcmp(temp->name, name) == 0)
		{
			return temp->quantity;
		}
		temp = temp->next;
	}
	return 0;
}

void reStock(char *name, int quantity)
{
	// If the item is already in the list, just add the quantity
	if (validateProdName(name))
	{
		struct Products *temp = prod_head;
		while (temp != NULL)
		{
			if (strcmp(temp->name, name) == 0)
			{
				temp->quantity += quantity;
				break;
			}
			temp = temp->next;
		}
		return;
	}

	struct Products *temp = (struct Products*) malloc(sizeof(struct Products));
	strcpy(temp->name, name);
	temp->quantity = quantity;
	temp->next = NULL;
	if (prod_head == NULL)
	{
		prod_head = temp;
		prod_tail = temp;
	}
	else
	{
		prod_tail->next = temp;
		prod_tail = temp;
	}
}

struct Customer
{
	char name[50];
	char product_name[50];
	int product_quantity;
	struct Customer *next;
};

struct CustomerLine
{
	struct Customer *front;
	struct Customer *rear;
	int size;
};

void init(struct CustomerLine *line)
{
	line->front = NULL;
	line->rear = NULL;
	line->size = 0;
}

void enqueue(struct CustomerLine *cust_queue, char *name, char *product_name, int product_quantity)
{
	struct Products *prod_chose = prod_head;
	while (prod_chose != NULL)
	{
		if (strcmp(prod_chose->name, product_name) == 0)
		{
			break;
		}
		prod_chose = prod_chose->next;
	}
	prod_chose->quantity -= product_quantity;

	struct Customer *temp = (struct Customer*) malloc(sizeof(struct Customer));
	strcpy(temp->name, name);
	strcpy(temp->product_name, product_name);
	temp->product_quantity = product_quantity;
	temp->next = NULL;
	if (cust_queue->front == NULL)
	{
		cust_queue->front = temp;
		cust_queue->rear = temp;
	}
	else
	{
		cust_queue->rear->next = temp;
		cust_queue->rear = temp;
	}
	cust_queue->size++;
}

void dequeue(struct CustomerLine *queue, int return_item)
{
	if (queue->size == 0)
	{
		printf("No customer in the queue\n");
		return;
	}

	// if return_item is true, add the product_quantity back to the stock list
	if (return_item)
	{
		struct Products *prod_chose = prod_head;
		while (prod_chose != NULL)
		{
			if (strcmp(prod_chose->name, queue->front->product_name) == 0)
			{
				prod_chose->quantity += queue->front->product_quantity;
				break;
			}
			prod_chose = prod_chose->next;
		}
	}

	// remove the customer from the front of the customer list
	struct Customer *temp = queue->front;
	queue->front = queue->front->next;
	free(temp);
	queue->size--;
}

void display(struct CustomerLine *cust_line)
{
	printf("==> Customer queue:\n");
	struct Customer *temp = cust_line->front;
	while (temp != NULL)
	{
		printf("%s: %d %s\n", temp->name, temp->product_quantity, temp->product_name);
		temp = temp->next;
	}
	printf("==> Product list:\n");
	struct Products *temp2 = prod_head;
	while (temp2 != NULL)
	{
		printf("%s: %d\n", temp2->name, temp2->quantity);
		temp2 = temp2->next;
	}
}

void cls()
{
	// For Unix-like systems
	printf("\033[H\033[J");
}

int main()
{
	struct CustomerLine *cust_line = (struct CustomerLine*) malloc(sizeof(struct CustomerLine));
	init(cust_line);
	cls();
	reStock("Orange", 200);
	reStock("Apple", 100);
	reStock("Banana", 150);
	char last_msg[100] = "";
	while (1)
	{
		cls();
		if (strcmp(last_msg, "") != 0)
		{
			printf("%s\n\n", last_msg);
			strcpy(last_msg, "");
		}
		display(cust_line);
		printf("\n");
		printf("1. A customer enters the line\n");
		printf("2. A customer leaves\n");
		printf("3. A customer buys a product\n");
		printf("4. Restock\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");

		int choice;
		scanf("%d", &choice);
		printf("\n");

		if (choice == 1)
		{
			cls();
			char name[50], product_name[50];
			int product_quantity;
			printf("Enter the customer name: ");
			scanf("%s", name);
			printf("Enter the product name: ");
			scanf("%s", product_name);
			while (1)
			{
				if (!validateProdName(product_name))
				{
					printf("Invalid product name, available products are: ");
					for (struct Products *temp = prod_head; temp != NULL; temp = temp->next)
					{
						printf("%s, ", temp->name);
					}
					printf("\nTry again: ");
					scanf("%s", product_name);
				}
				else if (getProdQuantity(product_name) == 0)
				{
					printf("Product is out of stock, try again: ");
					scanf("%s", product_name);
				}
				else
				{
					break;
				}
			}
			printf("Enter the product quantity: ");
			scanf("%d", &product_quantity);
			while (!validateProdQuantity(product_name, product_quantity))
			{
				printf("There's only %d %s left\n", getProdQuantity(product_name), product_name);
				printf("Try again: ");
				scanf("%d", &product_quantity);
			}
			enqueue(cust_line, name, product_name, product_quantity);
		}
		else if (choice == 2)
		{
			if (cust_line->size == 0)
			{
				strcpy(last_msg, "No customer in the queue");
				continue;
			}
			snprintf(last_msg, sizeof(last_msg), "%s left the line without buying anything", cust_line->front->name);
			dequeue(cust_line, 1);
		}
		else if (choice == 3)
		{
			if (cust_line->size == 0)
			{
				strcpy(last_msg, "No customer in the queue");
				continue;
			}
			snprintf(last_msg, sizeof(last_msg), "%s bought %d %s", cust_line->front->name, cust_line->front->product_quantity, cust_line->front->product_name);
			dequeue(cust_line, 0);
		}
		else if (choice == 4)
		{
			cls();
			char product_name[50];
			int product_quantity;
			printf("Enter the product name: ");
			scanf("%s", product_name);
			printf("Enter the product quantity: ");
			scanf("%d", &product_quantity);
			reStock(product_name, product_quantity);
		}
		else if (choice == 5)
		{
			break;
		}
	}
	return 0;
}
