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
int isPlindrom(Stack* s);



void main()
{
	Stack* s1 = (Stack*)malloc(sizeof(Stack));
	if (s1 == NULL)
	{
		printf("No Memory");
		return;
	}
	s1->head=NULL;
	char str[] = "123321";

	int length = (int)strlen(str);

	for (int i = length - 1; i > -1; --i)
		push(s1, str[i]);

	//print
	//Node* node = s1->head;
	//while (node->next != NULL)
	//{
	//	printf("%c", node->data);
	//	node = node->next;
	//}
	//after
	//
	//printf("Before: %s\nAfter: ",str);
	//printLK(s1);
	
	int x=isPlindrom(s1);
	printf("%d",x);
	
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
		while (s->head!=NULL)
		{
			if((s->head->data) != '#')
			printf("%c", pop(s));
			else
			break;
		}
		if(s->head==NULL)
			return;
		
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
	if(s->head==NULL)
	return;
	
	pop(s);
	printLK(s);

	return;
}


int isPlindrom(Stack* s)
{
	int count = 0,danno;
	Node* temp=s->head;
	while (temp != NULL)
	{
		++count;
		temp = temp->next;		
	}
	danno = count;
	Stack* temp1 = (Stack*)malloc((count/2)*sizeof(Stack));
	if (temp1 == NULL) { printf("NO MEMORY"); return -1; }
	int x= danno/2;
	
	if(danno%2==0)
	{
		while (count >danno/2)
	{
		push(temp1, pop(s));
		--count;
		}
	}
	else
	{
		count=0;
		while (count<x)
	{
		push(temp1, pop(s));
		++count;
	}
	if(danno%2==1)
		pop(s);
	}

	
	while ((s->head != NULL) && (temp1->head != NULL))
	{
		char x = pop(s);
		char y = pop(temp1);
		if (x != y)
		{
			return 0;
		}
	}
	return 1;

}

