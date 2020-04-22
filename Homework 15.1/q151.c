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
Node* addToHead(Node* head, Node* toAdd);
void printLK(Stack* s);
int isPlindrom(Stack* s);
void rotate(Stack* s, int n);


void main()
{
	Stack* s1 = (Stack*)malloc(sizeof(Stack));
	if (s1 == NULL)
	{
		printf("Heap Error, Exiting.\n");
		exit(69);
	}
	s1->head = NULL;


	printf(
		"Text Menu:\n1.Push Text\n2.Pop Text\n3.Palindrome Checker\n4.Rotate Text\n5.Reverse # in Text\n0.Exit\n\nEnter Option: ");
	int opt = -1;
	char str[1000] = {'\0'};
	while (opt != 0)
	{
		scanf_s(" %d", &opt);
		switch (opt)
		{
		case 1:
			{
				printf("Enter Text[Max 999]: ");
				scanf_s(" %[^\n]s", &str, 1000);
				int length = (int)strlen(str);

				for (int i = length; i > -1; --i)
					push(s1, str[i]);
				printf("You have input:");
				Node* node = s1->head;
				while (node->next != NULL)
				{
					printf("%c", node->data);
					node = node->next;
				}
				printf("\n\nEnter new option: ");
				break;
			}
		case 2:
			{
				printf("Data that was removed: %c", pop(s1));
				printf("\n\nEnter new option: ");
				break;
			}
		case 3:
			{
				printf("\nPolindrom [1=YES || 0=No]\nAnswer: %d ", isPlindrom(s1));
				printf("\n\nEnter new option: ");
				break;
			}
		case 4:
			{
				printf("Enter Index to rotate: ");
				int num;
				scanf_s(" %d", &num);
				rotate(s1, num);
				printf("After Rotate: ");
				Node* node = s1->head;
				while (node->next != NULL)
				{
					printf("%c", node->data);
					node = node->next;
				}
				printf("\n\nEnter new option: ");
				break;
			}
		case 5:
			{
				printLK(s1);
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
		while (s->head != NULL)
		{
			if ((s->head->data) != '#')
				printf("%c", pop(s));
			else
				break;
		}
		if (s->head == NULL)
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
	if (s->head == NULL)
		return;

	pop(s);
	printLK(s);
}


int isPlindrom(Stack* s)
{
	int count = 0, danno;
	Node* temp = s->head;
	while (temp != NULL)
	{
		++count;
		temp = temp->next;
	}
	danno = count;
	Stack* temp1 = (Stack*)malloc((count / 2) * sizeof(Stack));
	if (temp1 == NULL)
	{
		printf("NO MEMORY");
		return -1;
	}
	int x = danno / 2;

	if (danno % 2 == 0)
	{
		while (count > danno / 2)
		{
			push(temp1, pop(s));
			--count;
		}
	}
	else
	{
		count = 0;
		while (count < x)
		{
			push(temp1, pop(s));
			++count;
		}
		if (danno % 2 == 1)
			pop(s);
	}


	while ((s->head != NULL) && (temp1->head != NULL))
	{
		char x = pop(s);
		char y = pop(temp1);
		if (x != y)
		{
			free(temp1);
			return 0;
		}
	}
	free(temp1);
	return 1;
}

void rotate(Stack* s, int n)
{
	Stack* temp1 = (Stack*)malloc(sizeof(Stack));
	Stack* temp2 = (Stack*)malloc(sizeof(Stack));
	if (temp1 == NULL || temp2 == NULL)
	{
		printf("No Memory");
		return;
	}
	Node* index = s->head;
	int size = 0;
	while (index != NULL)
	{
		++size;
		index = index->next;
	}
	int new_size = size - n;
	for (int j = 0; j < new_size; ++j)
	{
		push(temp1, pop(s));
	}
	for (int w = 0; w < n; ++w)
	{
		push(temp2, pop(s));
	}
	for (int j = 0; j < new_size; ++j)
	{
		push(s, pop(temp1));
	}
	for (int w = 0; w < n; ++w)
	{
		push(s, pop(temp2));
	}
	free(temp1);
	free(temp2);
}
