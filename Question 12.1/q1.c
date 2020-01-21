#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_SIZE 50

typedef struct {
	char name[NAME_SIZE];
	int id;
	float avg;
}Student;

typedef struct {
	Student* class_name;
	int class_size;
} Class;

void init_student(Student* stdname);
void print_Student(Student* stdname);
void init_Class(Class* class_name);
void print_Class(Class* class_name);



void main()
{
	//Student ben;
	//init_student(&ben);
	//print_Student(&ben);
	Class cname;
	init_Class(&cname);
	print_Class(&cname.class_name);
	system("pause");
	free(cname.class_name);
}



void init_student(Student* stdname)
{
	puts("Enter name:");
	scanf(" %[^\n]s", stdname->name);
	puts("Enter ID:");
	scanf(" %d", &(stdname->id));
	puts("Enter Student Average Number:");
	scanf(" %f", &(stdname->avg));
}

void print_Student(Student* stdname)
{
	puts("The students info is:\n----------\n");
	printf("Full Name: %s\n", stdname->name);
	printf("ID: %d\n", stdname->id);
	printf("Grade Average: %.2f \n", stdname->avg);

}

void init_Class(Class* class_name)
{
	printf("How many students are in the class?\n");
	scanf(" %d", &(class_name->class_size));
	Student* class = (Student*)malloc((class_name->class_size) * sizeof(Class));
	class_name->class_name = class;

	for (int i = 0; i < (class_name->class_size); ++i)
	{
		init_student(&(class[i]));
	}
}

void print_Class(Class* class_name)
{
	printf("Class Summery:\n----------\n");
	for (int i = 0; i < (class_name->class_size); ++i)
	{
		print_Student(&(class_name->class_name[i]));
	}
}

