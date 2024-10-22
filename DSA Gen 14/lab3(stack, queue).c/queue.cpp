#include <iostream>
using namespace std;

struct Products
{
	string name;
	int quantity;
	Products *next;
};

Products *prod_head = NULL;
Products *prod_tail = NULL;

bool validateProdName(string name)
{
	Products *temp = prod_head;
	while (temp != NULL)
	{
		if (temp->name == name)
		{
			return true;
		}
		temp = temp->next;
	}
	return false;
}

bool validateProdQuantity(string name, int quantity)
{
	Products *temp = prod_head;
	while (temp != NULL)
	{
		if (temp->name == name)
		{
			if (temp->quantity >= quantity)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		temp = temp->next;
	}
	return false;
}

int getProdQuantity(string name)
{
	Products *temp = prod_head;
	while (temp != NULL)
	{
		if (temp->name == name)
		{
			return temp->quantity;
		}
		temp = temp->next;
	}
	return 0;
}

void reStock(string name, int quantity)
{
	// If the item is already in the list, just add the quantity
	if (validateProdName(name))
	{
		Products *temp = prod_head;
		while (temp != NULL)
		{
			if (temp->name == name)
			{
				temp->quantity += quantity;
				break;
			}
			temp = temp->next;
		}
		return;
	}
	Products *temp = new Products;
	temp->name = name;
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
	string name;
	string product_name;
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

void enqueue(CustomerLine *cust_queue, Products *stock, string name, string product_name, int product_quantity)
{
	Products *prod_chose = prod_head;
	while (prod_chose != NULL)
	{
		if (prod_chose->name == product_name)
		{
			break;
		}
		prod_chose = prod_chose->next;
	}
	prod_chose->quantity -= product_quantity;
	Customer *temp = new Customer;
	temp->name = name;
	temp->product_name = product_name;
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

void dequeue(CustomerLine *queue, Products *stock, bool return_item)
{
	if (queue->size == 0)
	{
		cout << "No customer in the queue" << endl;
		return;
	}
	// if return_item is true, add the product_quantity back to the stock list
	if (return_item)
	{
		Products *prod_chose = prod_head;
		while (prod_chose != NULL)
		{
			if (prod_chose->name == queue->front->product_name)
			{
				prod_chose->quantity += queue->front->product_quantity;
				break;
			}
			prod_chose = prod_chose->next;
		}
	}
	// remove the customer from the front of the customer list
	Customer *temp = queue->front;
	queue->front = queue->front->next;
	delete temp;
	queue->size--;
}

void display(CustomerLine *cust_line, Products *prod)
{
	cout << "==> Customer queue:" << endl;
	Customer *temp = cust_line->front;
	while (temp != NULL)
	{
		cout << temp->name << ": " << temp->product_quantity << " " << temp->product_name << endl;
		temp = temp->next;
	}
	cout << "==> Product list:" << endl;
	Products *temp2 = prod_head;
	while (temp2 != NULL)
	{
		cout << temp2->name << ": " << temp2->quantity << endl;
		temp2 = temp2->next;
	}
}

void cls()
{
	// CSI[2J clears screen, CSI[H moves the cursor to top-left corner
	std::cout << "\\x1B[2J\\x1B[H";
}

string intToString(int num)
{
	string result = "";
	while (num > 0)
	{
		result = (char)(num % 10 + 48) + result;
		num /= 10;
	}
	return result;
}

int main()
{
	CustomerLine *cust_line = new CustomerLine;
	init(cust_line);
	cls();
	reStock("Orange", 200);
	reStock("Apple", 100);
	reStock("Banana", 150);
	string last_msg = "";
	while (true)
	{
		cls();
		if (last_msg != "")
		{
			cout << last_msg << endl
					 << endl;
			last_msg = "";
		}
		display(cust_line, prod_head);
		cout << endl;
		cout << "1. A customer enters the line" << endl;
		cout << "2. A customer leaves" << endl;
		cout << "3. A customer buys a product" << endl;
		cout << "4. Restock" << endl;
		cout << "5. Exit" << endl;
		cout << "Enter your choice: ";

		int choice;
		cin >> choice;
		cout << endl;
		if (cin.fail() || choice < 1 || choice > 6)
		{
			cin.clear();
			cin.ignore(1);
			last_msg = "Invalid choice";
			continue;
		}

		if (choice == 1)
		{
			cls();
			string name, product_name;
			int product_quantity;
			cout << "Enter the customer name: ";
			cin >> name;
			cout << "Enter the product name: ";
			cin >> product_name;
			while (true)
			{
				if (!validateProdName(product_name))
				{
					cout << "Invalid product name, available products are: ";
					for (Products *temp = prod_head; temp != NULL; temp = temp->next)
					{
						cout << temp->name << ", ";
					}
					cout << endl;
					cout << "Try again or Ctrl+C to exit: ";
					cin >> product_name;
				}
				else if (getProdQuantity(product_name) == 0)
				{
					cout << "Product is out of stock, try again or Ctrl+C to exit: ";
					cin >> product_name;
				}
				else
				{
					break;
				}
			}
			cout << "Enter the product quantity: ";
			cin >> product_quantity;
			while (!validateProdQuantity(product_name, product_quantity))
			{
				cout << "There's only " << getProdQuantity(product_name) << " " << product_name << " left" << endl;
				cout << "Try again or Ctrl+C to exit: ";
				cin >> product_quantity;
			}
			enqueue(cust_line, prod_head, name, product_name, product_quantity);
		}
		else if (choice == 2)
		{
			if (cust_line->size == 0)
			{
				last_msg = "No customer in the queue";
				continue;
			}
			last_msg = cust_line->front->name + " left the line without buying anything";
			dequeue(cust_line, prod_head, true);
		}
		else if (choice == 3)
		{
			if (cust_line->size == 0)
			{
				last_msg = "No customer in the queue";
				continue;
			}
			last_msg = cust_line->front->name + " bought " + intToString(cust_line->front->product_quantity) + " " + cust_line->front->product_name;
			dequeue(cust_line, prod_head, false);
		}
		else if (choice == 4)
		{
			cls();
			string product_name;
			int product_quantity;
			cout << "Enter the product name: ";
			cin >> product_name;
			cout << "Enter the product quantity: ";
			cin >> product_quantity;
			reStock(product_name, product_quantity);
		}
		else if (choice == 5)
		{
			break;
		}
	}
	return 0;
}