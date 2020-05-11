#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ADD_NAME 1
#define DELETE_NAME 2
#define PRINT_NAME 3
#define REPLACE_TEACHER 4
#define EXIT 5

typedef struct class {
	const char* teacher;
	int registered;
	int max_class;
	char** students;
} Class;

Class *const buildClass(char * teacher, int size);

void addStudent(Class *);
void deleteName(Class * c);
void printClass(Class * c);
void freeClass(Class *c);
void replaceTeacher(Class *c, char ** t);

void main()
{
	char * teachers[] = { "Neta","Hila" };
	Class * c = buildClass(teachers[0], 3);
	int option;

	do {
		printf("\n1. Add Name \n2. Delete  \n3. Print \n4. Replace Teacher \n5. Exit");

		printf("\nEnter your choice: ");
		scanf_s("%d", &option);
		switch (option) {
		case ADD_NAME:
			addStudent(c);
			break;
		case DELETE_NAME:
			deleteName(c);
			break;
		case PRINT_NAME:
			printClass(c);
			break;
		case REPLACE_TEACHER:
			replaceTeacher(c, teachers);
			break;
		case EXIT:
			freeClass(c);
			break;
		default:
			printf("\nInvalid choice. Please try again...");
			break;
		}
	} while (option != EXIT);}

/* Add new name to the array.
The new name will be added to the first empty place = first NULL*/
void addStudent(Class * c)
{
	if(c->registered==c->max_class)
	{
		printf("ERROR CLASS IS FULL,RETURN\n");
		return;
	}
	
	char name[30]={'\0'};
	printf("Enter students name: ");
	scanf(" %[^\n]s", name);
	char* name1=(char*)calloc(strlen(name)+1,sizeof(char));
	if(!name1)
		exit(-69);
	strcpy_s(name1,strlen(name)+1,name);
	c->students[c->registered]=name1;
	c->registered++;
}

/* Delete name from the array */
void deleteName(Class * c)
{
	//add your code here
}
/* Print all the names of the array */
void printClass(Class * c)
{
	int i;
	printf("Teacher: %s ",c->teacher);
	if (c->registered > 0)
	{
		printf("\n ** Printing names: **\n");

		for (i = 0; i < c->registered; i++)
		{
			printf("%s\n", c->students[i]);
		}
	}
}
/* Build class allocate memory for class and student array*/

Class* const buildClass(char * teacher, int size) {
	if(!teacher)
	exit(-69);
	
	
	Class* nclass=(Class*)malloc(sizeof(Class));
	char** students=(char**)calloc(size,sizeof(char*));
	if(!nclass || !students)
		exit(-69);
	
	nclass->teacher=teacher;
	nclass->students=students;
	nclass->max_class=size;
	nclass->registered=0;
	return nclass;
}
/* Free all memory allocations of the class*/
void freeClass(Class *c)
{

	//add your code here
}

void replaceTeacher(Class *c, char ** t) {
	//add your code here
}

