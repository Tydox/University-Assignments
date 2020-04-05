#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



typedef struct { 
	int x; 
	int y; 
}point;


typedef struct item {
	point coord;
		struct item* next;
}Item;

Item* addPoint(Item* head, int x, int y);



void main()
{
	Item* test,test2;
	test = (Item*)malloc(sizeof(Item));
	test->coord.x = 0;
	test->coord.y = 0;
	test2 = (Item*)malloc(sizeof(Item));
	test->next = test2;
	test = addPoint(test,2,2);
	free(test);
}


Item* addPoint(Item* head, int x, int y)
{
	//check if linked list has 0
	// yes - add x,y
	if (head == NULL)
	{
		return NULL;
	}


	Item* indextemp = head; //[0]
	Item* nexttemp = head->next;//[1]
	Item* prevtemp = head; //[0]

	//avg first group
	double avg_min = (pow((double)(prevtemp->coord.x) - (double)x, 2) + pow((double)(prevtemp->coord.y) - (double)y, 2)) / 2;
	printf("Test: %f\n", avg_min);
	//loop till last node
	while (nexttemp->next != NULL)
	{
		if (avg_min > (pow((double)(nexttemp->coord.x) - (double)x, 2) + pow((double)(nexttemp->coord.y) - (double)y, 2)) / 2)
			avg_min = (pow((double)(nexttemp->coord.x) - (double)x, 2) + pow((double)(nexttemp->coord.y) - (double)y, 2)) / 2;
		else
		prevtemp = nexttemp;
		nexttemp = nexttemp->next;
	}
	printf("Test: %f\n", avg_min);
	return NULL;
}