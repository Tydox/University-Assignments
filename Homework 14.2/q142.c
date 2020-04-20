#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct { 
	int x; 
	int y; 
}point;

typedef struct Item {
	point p;
		struct Item* next;
}Item;

Item* addPoint(Item* head, int x, int y);
void printList(Item* head);
Item* deletePointIdx(Item* head, int idx);
Item* reverse(Item* head);
void freeItem (Item * head);

void main()
{
	int x1 = 8, y1 = 6;
	Item* head = (Item*)malloc(sizeof(Item));
	Item* sec = (Item*)malloc(sizeof(Item));
	Item* last = (Item*)malloc(sizeof(Item));
	Item* q1 = head;
	if (!last || !head || !sec)
	{
		printf("no memory\n");
		return;
	}
	head->p.x = 5;
	head->p.y = 6;
	head->next = sec;
	sec->p.x = 7;
	sec->p.y = 8;
	sec->next = last;
	last->p.x = 9;
	last->p.y = 10;
	last->next = NULL;
	addPoint(head, x1, y1);
	printList(head);
	printf("\nAfter\n");
	q1 = reverse(q1);
	printList(q1);
	freeItem(q1);
	printf("\nAfter\n");
	printList(q1);

}

Item* addPoint(Item* head, int x, int y)
{
	Item* temp = head;
	double min = 0, first_cord = 0, last_cord = 0;
	Item* newpoint = (Item*)malloc(sizeof(Item));
	if (newpoint == NULL)
	{
		printf("No memory\n");
		return NULL;
	}
	newpoint->p.x = x;
	newpoint->p.y = y;
	//empty list
	if (head == NULL)
	{
		head = newpoint;
		head->next = NULL;
		return head;

	}

	first_cord = (pow((double)(temp->p.x) - (double)(newpoint->p.x), 2)) + (pow((double)(temp->p.y) - (double)(newpoint->p.y), 2));
	min = first_cord;
	double distance;
	int location = 0;
	int i = 0;
	while (temp->next != NULL)
	{
		double x = 0, y = 0;

		x = (pow((double)temp->p.x - (double)newpoint->p.x, 2)) + (pow((double)temp->p.y - (double)newpoint->p.y, 2));
		temp = temp->next;

		if (temp->next == NULL)
			break;

		y = (pow((double)temp->p.x - (double)newpoint->p.x, 2)) + (pow((double)temp->p.y - (double)newpoint->p.y, 2));
		distance = (x + y) / 2;

		if (distance <= min)
		{
			min = distance;
			location = i;
		}

		temp = temp->next;
		++i;
	}

	last_cord = (pow((double)temp->p.x - (double)newpoint->p.x, 2)) + (pow((double)temp->p.y - (double)newpoint->p.y, 2));//add to the end
	
	if (last_cord <= min)
	{
		temp->next = newpoint;
		newpoint->next = NULL;

	}
	else if (location == i)//add to the head 
	{
		newpoint->next = head;
		head = newpoint;

	}
	else
	{
		temp = head;
		for (int i = 0; i < location; i++)
		{
			temp = temp->next;
		}
		Item* temp2 = temp->next;
		temp->next = newpoint;
		newpoint->next = temp2;
	}

	return head;
}

void printList(Item* head)
{
	if (head == NULL)
	{
		printf("empty list");
		return;
	}
	Item* temp = head;
	while (temp != NULL)
	{
		printf("\nX[%d]\tY[%d]\n", temp->p.x, temp->p.y);
		temp = temp->next;
	}
}

Item* deletePointIdx(Item* head, int idx)
{
	if (head == NULL)
		return NULL;

	Item* temp = head;
	Item* prev = NULL;
	
	//find idx
	for (int i = 0; i < idx; i++)
	{
		prev = temp;
		temp = temp->next;
	}
	//idx=0
	if (temp == head)
	{
		head = head->next;
		free(temp);
		return head;
	}
	//last idx
	if (!(temp->next))
	{
		free(temp);
		prev->next = NULL;
		return head;
	}
	//mid idx
	else
	{
		prev->next = temp->next;
		free(temp);
		return head;
	}
}

 
Item* reverse(Item* head)
{
	if (!head)
	{
		printf("Empty");
		return NULL;
	}

	Item* prev = NULL;
	Item* current = head;
	Item* next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	
	return prev;

}


void freeItem (Item * head)
{
  if (head->next == NULL)
    {
      free(head);
      return;
    }
  freeItem (head->next);
  head->next = NULL;
  free(head);
  head = NULL;
  return;
}