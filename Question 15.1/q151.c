#define _CRT_SECURE_NO_WARNINGS
#define CHAR_GRADE '1'
#define NUM_GRADE '0'

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	long unsigned id;
	union Grade {
		unsigned gradeN; char gradec;
	} grade;
}studentGrade;

typedef struct Item
{
	studentGrade* data;
	struct Item* next;
}Item;

void printstudentDetails(char type, const studentGrade* st);
studentGrade* createStudentGrade(char type);

Item* addItemToEnd(Item* list, studentGrade* newValue);
Item* deleteValue(Item* list, unsigned long value);
void printList(Item* list, char type);
Item* addLastToStart(Item* list);

void main()
{
	char type;
	printf("set grade type: \n0-(0-100)\n1 -(A-D)\n");
	fseek(stdin, 0, SEEK_END);
	scanf("%c", &type);
	Item* list = NULL;
	int i;
	for (i = 0; i < 4; i++) {
		list = addItemToEnd(list, createStudentGrade(type));
	}
	printList(list, type);
	list = deleteValue(list, 1);

	system("pause");
}
void printstudentDetails(char type, const studentGrade* st) {
	printf("%ld ", st->id);
	switch (type)
	{
	case NUM_GRADE:
		printf("%d\n", st->grade.gradeN);
		break;
	case CHAR_GRADE:
		printf("%c\n", st->grade.gradec);
		break;
	default:
		printf("WRONG FORMAT!");
		break;
	}
}
studentGrade* createStudentGrade(char type) {
	studentGrade* s = (studentGrade*)malloc(sizeof(studentGrade));
	if (!s) {
		printf("Exiting the program....\n");
		exit(1);
	}
	printf("student id:");
	scanf("%d", &(s->id));
	printf("grade:");
	switch (type)
	{
	case (CHAR_GRADE):
		do {
			fseek(stdin, 0, SEEK_END);
			scanf("%c", &(s->grade.gradec));
			if ((s->grade.gradec > 'D' || s->grade.gradec < 'A')) puts("value should be A-D");
		} while (s->grade.gradec > 'D' || s->grade.gradec < 'A');
		break;
	case (NUM_GRADE):
		do {
			scanf("%d", &(s->grade.gradeN));
			if (s->grade.gradeN > 100 || s->grade.gradeN < 0) puts("value should be 0-100");
		} while (s->grade.gradeN > 100 || s->grade.gradeN < 0);
		break;
	}
	return s;
}

Item* addItemToEnd(Item* list, studentGrade* newValue)
{

	Item* newItem = (Item*)malloc(sizeof(Item));
	if (!newItem) {
		printf("Exiting the program....\n");
		exit(1);//not successful!
	}
	newItem->data = newValue;
	newItem->next = NULL;

	if (list == NULL) // empty list
	{
		list = newItem;
		return list;
	}
	Item* p;
	for (p = list; p->next != NULL; p = p->next);



	p->next = newItem;
	return list;
}


Item* deleteValue(Item* list, unsigned long value)
{
	//check if list pointer is empty
	if (list == NULL)
		return NULL;
	//make a temp list for skimming
	Item* temp_list = list;
	//temp previous location 1 prior
	Item* temp_previous = NULL;
	//loop until temp_list pointer is null
	while (temp_list != NULL)
	{
		//condition - ID is equal
		if (temp_list->data->id == value)
		{
			//condition - tmp prev is pointing to nothing meaning we are at the first location of the list
			if (temp_previous == NULL)
			{
				list = temp_list->next;
				free(temp_list->data);
				free(temp_list);
				temp_list = list;
			}
			//condition - we are not deleting on the first location
			else
			{
				temp_list->next = temp_list->next;
				free(temp_list->data);
				free(temp_list);
				temp_list = temp_previous;
			}
		}
		//if condition is not true, move to next node
		else {
			temp_previous = temp_list;
			temp_list = temp_list->next;
		}

	}
	return list;
}

Item* addLastToStart(Item* list)
{
	//check for empty list
	if (list == NULL)
		return NULL;

	//create a helping pointer
	Item* temp = list;
	Item* ptemp = NULL;

	while (temp->next!=NULL)
	{
		//first we trail on the list
		//if temp->next isnt null, we are not at the last node, thus we need to move to the next one
		ptemp = temp;
		temp = temp->next;
	}
	
		//move last node to first, and update pointer to second node
		temp->next = list;
		//update node header to first node
		list = temp;
		//NULL last new node
		ptemp->next = NULL;
	

	return list;
}





void printList(Item* list, char type) {
	Item* p = list;
	printf("\n items list:");
	for (int i = 1; p != NULL; p = p->next, i++)
	{
		printf("\n item %d:", i);
		printstudentDetails(type, p->data);
	}
}