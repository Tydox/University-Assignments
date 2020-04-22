#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	unsigned int data;
	struct node* next;
} Node;


typedef struct Queue
{
	Node* head;
	Node* tail;
} Queue;


int isEmpty(Queue* q);
void enQueue(Queue* q, unsigned int data);
int deQueue(Queue* q);
void rotate(Queue* q);
void cutAndReplace(Queue* q);
void sort(Queue* q);


void main()
{
	Queue* lk = (Queue*)calloc(1, sizeof(Queue));
	if (lk == NULL)
	{
		printf("Heap Error, Exiting.\n");
		exit(69);
	}	
	

	printf(	"Functions List:\n1.Add numbers [Must Do First]\n2.Remove a number [Delete first in queue]\n3.Rotate [Bring last in queue to first]\n4.Cut & Replace [Weird Scramble]\n5.Sort [small->big]\n0.Exit\n\nEnter Option: ");
	int opt = -1;
	while (opt != 0)
	{
		scanf_s(" %d", &opt);
		switch (opt)
		{
		case 1:
			{
				printf("Numbers Input: [Enter X>0 || Stop X<0]\n");
				int user_input = 1;
				int i = 0;
				while (user_input > 0)
				{
					printf("%d:", i++);
					scanf_s(" %d", &user_input);
					if (user_input > 0)
						enQueue(lk, user_input);
				}
				
				printf("You have input:");
				Node* idx = lk->head;
				while (idx != NULL)
				{
					printf("%d,", idx->data);
					idx = idx->next;
				}
				printf("\n\nEnter new option: ");
				break;
			}
		case 2:
			{
				printf("Data that was removed: %d", deQueue(lk));
				printf("\n\nEnter new option: ");
				break;
			}
		case 3:
			{
				printf("Before Reverse: ");
				Node* idx = lk->head;
				while (idx != NULL)
				{
					printf("%d,", idx->data);
					idx = idx->next;
				}
				rotate(lk);
				printf("\nAfter Reverse: ");
				idx = lk->head;
				while (idx != NULL)
				{
					printf("%d,", idx->data);
					idx = idx->next;
				}
				printf("\n\nEnter new option: ");
				break;
			}
		case 4:
			{
				printf("Before Cut: ");
				Node* idx = lk->head;
				while (idx != NULL)
				{
					printf("%d,", idx->data);
					idx = idx->next;
				}
				cutAndReplace(lk);
				printf("\nAfter Cut: ");
				idx = lk->head;
				while (idx != NULL)
				{
					printf("%d,", idx->data);
					idx = idx->next;
				}
				printf("\n\nEnter new option: ");
				break;
			}
		case 5:
			{
				printf("Before Sort: ");
				Node* idx = lk->head;
				while (idx != NULL)
				{
					printf("%d,", idx->data);
					idx = idx->next;
				}
				sort(lk);
				printf("\nAfter sort: ");
				idx = lk->head;
				while (idx != NULL)
				{
					printf("%d,", idx->data);
					idx = idx->next;
				}
				printf("\n\nEnter new option: ");
				break;

			}
		case 0:
			{
				printf("This Program was made by Daniel, thank you for trying it =]\n");
				break;
			}
		default:
			{
				printf("Invalid option!\nEnter new option: ");
				break;
			}
		}
	}
}

int isEmpty(Queue* q)
{
	//check if both pointers at start are NULL
	return ((q->head == NULL) && (q->tail == NULL));
}

void enQueue(Queue* q, unsigned int data)
{
	//new node to add
	Node* new_data = (Node*)malloc(sizeof(Node));
	if (new_data == NULL)
	{
		printf("Heap Error, Exiting.\n");
		exit(69);
	}

	//node next points to null
	new_data->next = NULL;

	//add data
	new_data->data = data;

	//empty queue - head & tail will point to same node
	if (isEmpty(q))
	{
		q->tail = q->head = new_data;
		return;
	}
	//non-empty queue - head does not move, through tail we will pass the next node
	q->tail->next = new_data;
	q->tail = new_data;
}

int deQueue(Queue* q)
{
	//check if queue is empty
	if (isEmpty(q))
	{
		printf("Empty Queue, exit!");
		return 0;
	}
	//copy number
	int num = q->head->data;
	//treversing node
	Node* trev;
	//check if there is more than 1 in queue
	if (q->head == q->tail)
	{
		//free head
		free(q->head);
		//Nullify head & tail
		q->tail = q->head = NULL;
		//return removed queue
		return num;
	}
	else
	{
		//trev ptr = queue + 1
		trev = q->head->next;
		//free head
		free(q->head);
		//move head +1 in queue
		q->head = trev;
		//return removed queue
		return num;
	}
}

void rotate(Queue* q)
{
	//check if queue is empty
	if (isEmpty(q))
	{
		printf("Empty Queue, exit!");
		return;
	}

	//new temp LK queue
	Queue* temp_queue = (Queue*)calloc(1, sizeof(Queue));
	if (temp_queue == NULL)
	{
		printf("Heap Error, Exiting.\n");
		exit(69);
	}

	//temp int for data
	int temp_data = 0;

	//loop until queue = 1
	while ((q->head != q->tail))
	{
		//deQueue first & then save returned data
		temp_data = deQueue(q);
		//enQueue into Temp Queue
		enQueue(temp_queue, temp_data);
	}

	while (!isEmpty(temp_queue))
	{
		//deQueue first & then save returned data
		temp_data = deQueue(temp_queue);
		//enQueue into Temp Queue
		enQueue(q, temp_data);
	}

	free(temp_queue);
}

void cutAndReplace(Queue* q)
{
	//check if queue is empty
	if (isEmpty(q))
	{
		printf("Empty Queue, exit!");
		return;
	}

	//new temp LK queue
	Queue* temp_queue = (Queue*)calloc(1, sizeof(Queue));
	if (temp_queue == NULL)
	{
		printf("Heap Error, Exiting.\n");
		exit(69);
	}


	//temp int for data
	int temp_data = 0;

	//sum total amount of nodes
	int sum = 0;
	int count = 0;

	//loop until queue is empty
	while (!isEmpty(q))
	{
		//deQueue first & then save returned data
		temp_data = deQueue(q);
		//count total amount of nums together
		count += temp_data;
		//enQueue into Temp Queue
		enQueue(temp_queue, temp_data);
		//count sum
		++sum;
	}

	//odd
	if (sum % 2 == 1)
	{
		//avg
		int avg = count / sum;

		//add new avg to the queue
		enQueue(temp_queue, avg);
		++sum;
	}

	//new temp LK queue
	Queue* temp_queue2 = (Queue*)calloc(1, sizeof(Queue));
	if (temp_queue2 == NULL)
	{
		printf("Heap Error, Exiting.\n");
		exit(69);
	}


	count = sum / 2;
	while (count > 0)
	{
		//rotate first
		rotate(temp_queue);
		//deQueue + enQueue
		enQueue(q, deQueue(temp_queue));
		--count;
	}

	while (!isEmpty(temp_queue))
	{
		//deQueue + enQueue to secondary
		enQueue(q, deQueue(temp_queue));
	}

	free(temp_queue);
	free(temp_queue2);
}

void sort(Queue* q)
{
	//variables
	unsigned int x = deQueue(q);
	unsigned int y = deQueue(q);

	//nodes
	Queue* bigQ = (Queue*)calloc(1, sizeof(Queue));
	Queue* smallQ = (Queue*)calloc(1, sizeof(Queue));
	if (smallQ == NULL || bigQ == NULL)
	{
		printf("Heap Error, Exiting.\n");
		exit(69);
	}

	while (!isEmpty(q) || smallQ != bigQ)
	{
		while (y != 0)
		{
			if (x <= y)
			{
				enQueue(bigQ, y);
				if (isEmpty(q))
					y = 0;

				//	if (!isEmpty(q))
				//	y = deQueue(q);
			}
			else
			{
				enQueue(q, x);
				x = y;
				//y = deQueue(q);
			}
			if (!isEmpty(q))
			{
				y = deQueue(q);
			}
		}


		if (isEmpty(q))
		{
			enQueue(smallQ, x);
		}

		while (!isEmpty(bigQ))
		{
			enQueue(q, deQueue(bigQ));
		}


		if (isEmpty(q))
		{
			while (!isEmpty(smallQ))
			{
				enQueue(q, deQueue(smallQ));
				if (isEmpty(smallQ))
				{
					free(bigQ);
					free(smallQ);
					return;
				}
			}
		}

		x = deQueue(q);
		if (!isEmpty(q))
			y = deQueue(q);
	}
}
