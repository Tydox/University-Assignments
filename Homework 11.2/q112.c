#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 51
char* dyn_str_input();
char* name_Swap(char* name1, char* name2, int* opt);
void printMenu();

void main()
{

	char* people[2];
	int option_choice = 5;


	printf("Welcome to Ministry of Interior\nPlease remember to abide to the rules.\nWhen entering a full name (given name and surname) make sure to have a space between the names!\nMake sure you press a valid option number.\n--------------------\n");
	printf("Enter the full name of person 1: ");
	*people = dyn_str_input();
	printf("Enter the full name of person 2: ");
	*(people + 1) = dyn_str_input();

	printMenu();
	printf("Enter a number: ");
	scanf_s("%d", &option_choice,1);
	printf("\nBefore The Visit:\n\n");
	printf("1: %s\n", *people);
	printf("2: %s\n", *(people + 1));
	char* newname = name_Swap(*people, *(people + 1), &option_choice);
	printf("\nAfter the visit:\n");
	if (option_choice == 1 || option_choice == 2)
	{
		printf("%s\n", newname);
		printf("%s\n\n Bye Bye!", *(people + 1));
	}
	else
		if (option_choice == 3 || option_choice == 4)
		{
			printf("%s\n", newname);
			printf("%s\n\nBye Bye!", *people);
		}
		else
			if(option_choice==5)
			printf("\nYou've chosen to decide later, no changes were made\nBye Bye!\n");


	
	free(*people);
	free(*(people + 1));
	free(newname);
	newname = NULL;
	*people = NULL;
	*(people + 1) = NULL;
}


char* dyn_str_input() // user input data and return dynamic string address
{
	char temp_str[SIZE];
	scanf_s(" %[^\n]s", &temp_str, SIZE - 1);
	int size = strlen(temp_str) + 1;
	char* dyn_str = (char*)malloc((size) * sizeof(char));
	if (dyn_str == NULL)
	{
		printf("Error: out of memory.\n");
		return NULL;
	}
	strcpy_s(dyn_str, size * sizeof(char), temp_str);
	return dyn_str;
}

char* name_Swap(char* name1, char* name2, int* opt)
{


	if (!((*opt >= 1) && (*opt <= 5))) // check if entered number is between 1-5 options
	{
		puts("Error, invalid number. \nEnd.\n");
		return NULL;
	}
	if (*name1 == 0) // check that the string is not empty
	{
		printf("String is empty.\nEnd.\n");
		return NULL;
	}
	if (*name2 == 0) // check that the string is not empty
	{
		printf("String is empty.\nEnd.\n");
		return NULL;
	}

	int i = 0;
	int count_fname1 = 1;
	
	while (*(name1 + i) != ' ')
	{
		++count_fname1;
		++i;
	}
	int count_lname1 = strlen(name1) - count_fname1;
	
	i = 0;
	int count_fname2 = 1;
	while (*(name2 + i) != ' ')
	{
		++count_fname2;
		++i;
	}
	
	int count_lname2 = strlen(name2) - count_fname2;
	
	switch (*opt)
	{
	case 1:
	{
		char* new_name = (char*)malloc(((count_fname1 + count_lname2)+1) * sizeof(char));
		memcpy(new_name, name1, count_fname1);
		memcpy(new_name + count_fname1, name2+count_fname2, count_lname2+1);
		return new_name;
	}
	case 2:
	{

		char* new_name = (char*)malloc(((strlen(name1)) + count_lname2+2) * sizeof(char));
		memcpy(new_name, name1, strlen(name1)+1);
		memcpy(new_name+strlen(name1), name2 + count_fname2-1, count_lname2+2);
			return new_name;
	}
	case 3:
	{
		char* new_name = (char*)malloc(((count_fname2 + count_lname1) + 1) * sizeof(char));
		memcpy(new_name, name2, count_fname2);
		memcpy(new_name + count_fname2, name1 + count_fname1, count_lname1 + 1);
		return new_name;
	}
	case 4:
	{
		char* new_name = (char*)malloc(((strlen(name2)) + count_lname1+2) * sizeof(char));
		memcpy(new_name, name2, strlen(name2)+1);
		memcpy(new_name+strlen(name2), name1 + count_fname1-1, count_lname1+2);
			return new_name;
			
	}
	case 5:
		return NULL;

	}

	return NULL;
}

void printMenu()
{
	printf("--------------------\nPlease select one of the folowing options  [1-5]: \n");
	printf("1 -Change first partner's last name to second  partner's last name.\n");
	printf("2 -Add second  partner's last name to first partner's full name.\n");
	printf("3 -Change second partner's last name to  first partner's last name.\n");
	printf("4 -Add first partner's last name to second  partner's full name.\n");
	printf("5 -Decide Later.\n");
}
