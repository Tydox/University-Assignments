#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// if we need to change the queue we will pass a pointer to the fucntion
//if we do not need to change the queue valvues we will pass a copy of the content 
typedef struct node
{
	int data;
	struct node* next;
} NODE;


typedef struct Queue
{
	NODE* head;
	NODE* tail;
} QUEUE;


void initQueue(QUEUE* q);
int empty(QUEUE q);
void enqueue(QUEUE* q, int data);
int dequeue(QUEUE *q);

main() { }

void initQueue(QUEUE* q)
{
	if (q->head == NULL && q->tail == NULL)
	{
		printf("The Queue is already empty\n");
		return;
	}
	else
		q->tail = NULL;
	q->head = NULL;
}

int empty(QUEUE q)
{
	if (q.head == NULL && q.tail == NULL)
		return 1;

	else return 0;
}

void enqueue(QUEUE* q, int data)
{
	int x = empty(*q);
	switch (x)
	{
	case 1:
		{
			q->tail = (NODE*)malloc(sizeof(NODE));
			q->head = q->tail;
			if (q->tail == NULL)
			{
				printf("Added Malloc failed.\n");
				exit(1);
			}
			q->head->data = data;
			q->head->next=NULL;
			q->tail=q->head;
			q->tail->next = NULL;
			return;
		}
	case 0:
		{
			NODE* new_node = (NODE*)malloc(sizeof(NODE));
			if (q->tail == NULL)
			{
				printf("Added Malloc failed.\n");
				exit(1);
			}
			new_node->data=data;
			new_node->next =NULL;
			q->tail->next = new_node;
			q->tail = new_node;
			q->head->next=q->tail;
			return;
		}
	}
}

int dequeue(QUEUE* q)
{
	if(empty(*q)){
		printf("Empty queue");
		return -1;
		}
	
	int temp_num=q->head->data;
	NODE* temp_node=q->head;
	q->head=q->head->next;
	free(temp_node);
	return temp_num;
}
