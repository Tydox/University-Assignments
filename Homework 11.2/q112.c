#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* dyn_str_input();
char* name_Swap(const char* name1, const char* name2, int* opt);
void printMenu();

void main()
{

	char* people[2];
	int option_choice = 5;

	
	printf("Welcome to Ministry of Interior\nPlease remember to abide to the rules.\nWhen entering a full name (given name and surname) make sure to have a space between the names!\nMake sure you press a valid option number.\n--------------------\n");
	printf("Enter the full name of person 1: ");
	*people=dyn_str_input();
	printf("Enter the full name of person 2: ");
	*(people + 1) = dyn_str_input();
	puts(*people);
	puts(*(people+1));
	printMenu();
	printf("Enter a number: ");
	scanf_s("%d", &option_choice);
	char* new_name = name_Swap(*people, *(people + 1), &option_choice);
	puts(new_name);

	free(*people);
	free(*(people + 1));
	*people = NULL;
	*(people+1) = NULL;
}


char* dyn_str_input() // user input data and return dynamic string address
{
	char temp_str[51];
	scanf_s(" %[^\n]s", &temp_str,50);
	int size = strlen(temp_str)+1;
	char* dyn_str = (char*)malloc((size) * sizeof(char));
	if (dyn_str == NULL)
	{
		printf("Error: out of memory.\n");
		return NULL;
	}
	strcpy_s(dyn_str, size * sizeof(char), temp_str);
	return dyn_str;
}

char* name_Swap(const char* name1, const char* name2, int* opt)
{
	char temp_name[51];
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
	switch (*opt)
	{
	case 1:
		{

		int name_length = strlen(name1)-1;
		while ((*(name1 + (name_length)) != ' '))
		{
			*(temp_name + (i++)) = *(name1 + (name_length--));
		}
		_strrev(temp_name);
		*(temp_name + i) = '\0';
		char* new_name = (char**)malloc((name_length + 1) * sizeof(char));
		strcpy_s(new_name, name_length + 1, temp_name);
		return new_name;
		}
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
