#include <iostream>
using namespace std;

struct Action_queue
{
	string action;
	Action_queue *next;
};
Action_queue *head = NULL;
Action_queue *tail = NULL;

int queueLength(Action_queue *queue)
{
	int length = 0;
	while (queue != NULL)
	{
		length++;
		queue = queue->next;
	}
	return length;
}

void push(Action_queue *queue, string action)
{
	Action_queue *new_node = new Action_queue;
	new_node->action = action;
	new_node->next = NULL;
	if (queue == NULL)
	{
		queue = new_node;
		return;
	}
	while (queue->next != NULL)
	{
		queue = queue->next;
	}
	queue->next = new_node;
}

string pop(Action_queue *queue)
{
	if (queue == NULL)
	{
		return "";
	}
	while (queue->next->next != NULL)
	{
		queue = queue->next;
	}
	string action = queue->next->action;
	delete queue->next;
	queue->next = NULL;
	return action;
}

void printQueue(Action_queue *queue)
{
	int qLength = queueLength(queue);
	if (qLength == 1)
	{
		cout << "Queue is empty";
	}
	for (int i = 0; i < qLength; i++)
	{
		if (queue->action != "")
		{
			cout << queue->action << ", ";
		}
		queue = queue->next;
	}
	cout << endl;
}

void cls()
{
	// CSI[2J clears screen, CSI[H moves the cursor to top-left corner
	std::cout << "\\x1B[2J\\x1B[H";
}

int main()
{
	Action_queue *undo_queue = new Action_queue;
	Action_queue *redo_queue = new Action_queue;
	for (int i = 0; i < 10; i++)
	{
		push(undo_queue, "action" + to_string(i));
	}
	string action;
	string errMsg = "";
	while (true)
	{
		if (errMsg != "")
		{
			cout << errMsg << endl;
			errMsg = "";
			cls();
		}
		else
		{
			cls();
		}
		cout << errMsg << endl;
		cout << "Undo queue: ";
		printQueue(undo_queue);
		cout << "Redo queue: ";
		printQueue(redo_queue);
		cout << "" << endl;
		cout << "1. Add an action to the undo queue" << endl;
		cout << "2. Undo an action" << endl;
		cout << "3. Redo an action" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter an action: ";
		cin >> action;
		if (action == "1")
		{
			string action_name;
			cout << "Enter an action name: ";
			cin >> action_name;
			push(undo_queue, action_name);
		}
		else if (action == "2")
		{
			if (queueLength(undo_queue) == 1)
			{
				errMsg = "Undo queue is empty, cannot undo";
				continue;
			}
			push(redo_queue, pop(undo_queue));
		}
		else if (action == "3")
		{
			if (queueLength(redo_queue) == 1)
			{
				errMsg = "Redo queue is empty, cannot redo";
				continue;
			}
			push(undo_queue, pop(redo_queue));
		}
		else if (action == "4")
		{
			break;
		}
		else
		{
			cout << "Invalid input" << endl;
		}
	}
	return 0;
}