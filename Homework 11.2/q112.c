#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* dyn_str_input();
char* name_Swap(char* name1,char* name2, int* opt);
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

	printMenu();
	printf("Enter a number: ");
	scanf_s("%d", &option_choice);
	printf("\nBefore The Visit:\n\n");
	puts(*people);
	puts(*(people + 1));
	printf("\nAfter the visit:\n%s", name_Swap(*people, *(people + 1), &option_choice));
	

	free(**people);
	free(**(people + 1));
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
	int count_name1 = 1;
	while (*(name1 + i) != ' ')
	{
		++count_name1;
		++i;
	}

	i = 0;
	int count_name2 = 1;
	while (*(name2 + i) != ' ')
	{
		++count_name2;
		++i;
	}

	switch (*opt)
	{
	case 1:
	{
			strcpy_s((name1 + count_name1), 51, (name2 + count_name2));
	return name1;
	}
	case 2:
		{
		strcpy_s((name1 +strlen(name1)), 51, (name2 + (--count_name2)));
			return name1;
		}
	case 3:
		{
		strcpy_s((name2 + count_name2), 51, (name1 + count_name1));
		return name2;
		}
	case 4:
		{
		strcpy_s((name2 + strlen(name2)), 51, (name1 + (--count_name1)));
		return name2;
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
