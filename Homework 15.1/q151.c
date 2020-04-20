#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//linked list
typedef struct Node
{
	char data;
	struct Node* next;
} Node;

//stack
typedef struct Stack
{
	Node* head;
} Stack;

void push(Stack* s, char data);
char pop(Stack* s);
int isEmpty(Stack s);
void print(char* s);
Node* addToHead(Node* head, Node* toAdd);
char pop(Stack* s);
void printLK(Stack* s);
Stack* tempstack(Stack* s);


void main()
{
	Stack* s1 = (Stack*)malloc(sizeof(Stack));
	//s1->head =(Node*)malloc(sizeof(Node));
	if (s1 == NULL)
	{
		printf("No Memory");
		return;
	}

	char str[] = "Remem#reb# thi#carp s#tice";

	int length = (int)strlen(str);

	for (int i = length - 1; i > -1; --i)
		push(s1, str[i]);

	//pop
	//printf("%c\n",pop(s1));
	printLK(s1);
	//print
	/*Node* node = s1->head;
	while (node != NULL)
	{
		printf("%c", node->data);
		node = node->next;
	}*/
}

void push(Stack* s, char data)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL)
	{
		printf("push: memory allocation problem\n");
		return;
	}
	new_node->data = data;
	s->head = addToHead(s->head, new_node);
}

Node* addToHead(Node* head, Node* toAdd)
{
	toAdd->next = head;
	head = toAdd;
	return head;
}


char pop(Stack* s)
{
	Node* temp = s->head;
	if (temp == NULL)
	{
		printf("the stack is empty\n");
		return 0;
	}
	s->head = temp->next;
	return temp->data;
}

void printLK(Stack* s)
{
	if (s->head != NULL)
	{
		while ((s->head->data) != '#')
		{
			printf("%c", pop(s));
		}
		//skip #
		if (s->head->data == '#')
			s->head = s->head->next;
		//temp LK
		Stack* s2 = (Stack*)malloc(sizeof(Stack));
		if (s2 == NULL)
		{
			printf("No Memory");
			return;
		}

		int count = 0;
		while ((s->head->data) != '#')
		{
			push(s2, pop(s));
			++count;
		}
		while (count > 0)
		{
			printf("%c", pop(s2));
			--count;
		}
	}
	pop(s);
	printLK(s);

	return;
}


Stack* tempstack(Stack* s)
{
	int count = 1;


	return NULL;
}


/*start
Node* temp=(Node*)malloc(sizeof(Node));
if (temp == NULL)
{
	printf("No Memory"); return;
}
	s->head=temp;


Node* head=temp;
int length=strlen(data);
for(int i =0;i<length;++i)
	{
	if (i==0)
	{
		
	memcpy(&(temp->data), data+i, 1);
		
		Node* head=(Node*)malloc(sizeof(Node));
			if (head == NULL)
			{
				printf("No Memory"); return;
			}
			
	}
}*/
