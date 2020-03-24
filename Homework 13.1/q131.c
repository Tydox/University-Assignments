#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

int numorder(int* numarr, int size, int num);
int character(char* str1, char* str2);
int isBE(int num, int digit);
void my_strcpy(char  a[], char b[], int sizeA);

void main()
{
	
	printf("Welcome to Recursion Manifest\nFunction List:\n1. Lookup amount of Positive numbers\n2. Lexicographic compare\n3. Are there bigger numbers than yours?\n4. Text copy, lazy bum\n5. Close Terminal.\nOption: ");
	int userinput = 0;
	while (userinput != 5)
	{
		scanf("%d", &userinput);
		if ((userinput > 5 ) || (userinput < 1))
			printf("Invalid number, enter again!\nOption: ");
				
		switch (userinput)
		{
		case 1:
		{
			int locend = 0;
			printf("\nEnter amount of numbers you wish to enter\n");
			int arrsize = 0;
			scanf("%d", &arrsize);
			int* arr = (int*)malloc(arrsize * sizeof(int));
			printf("Enter your number:\n");
			for (int i = 0; i < arrsize; ++i)
			{
				printf("%d: ", i);
				scanf(" %d", &arr[i]);
			}
			//printf("Thanks for entering, computing....\n");
			printf("Enter how many numbers you wish to check if positive: \n");
			scanf(" %d", &locend);
			printf("Caluclating..\n");
			printf("%d\n\n", numorder(arr, arrsize, locend));
			free(arr);
			arr = NULL;
			printf("Function List:\n1. Lookup amount of Positive numbers\n2. Lexicographic compare\n3. Are there bigger numbers than yours?\n4. Text copy, lazy bum\n5. Close Terminal.\nOption: ");
			break;
		}
		case 2:
		{
			char str1[1000];
			char str2[1000];
			printf("\nEnter your First sentence: ");
			scanf(" %[^\n]s", str1);
			printf("Enter your Second sentence: ");
			scanf(" %[^\n]s", str2);
			char* mstr1 = (char*)malloc((1 + strlen(str1)) * sizeof(char));
			strcpy(mstr1, str1);
			char* mstr2 = (char*)malloc((1 + strlen(str2)) * sizeof(char));
			strcpy(mstr2, str2);
			printf("\n[Info Guide]\n1 First>Second\n0 Equal\n-1 Second>First\n");
			printf("Lexographic Order: %d\n\n", character(mstr1, mstr2));


			free(mstr1);
			free(mstr2);
			mstr1 = NULL;
			mstr2 = NULL;
			printf("Function List:\n1. Lookup amount of Positive numbers\n2. Lexigraphic compare\n3. Are there bigger numbers than yours?\n4. Text copy, lazy bum\n5. Close Terminal.\nOption: ");
			break;
		}
		case 3:
		{
			int num, digit;
			printf("\nEnter your desired number: ");
			scanf("%d", &num);
			printf("Enter your minimum number: ");
			scanf("%d", &digit);
			printf("Amount numbers equal/bigger: %d\n\n", isBE(num, digit));
			printf("Function List:\n1. Lookup amount of Positive numbers\n2. Lexigraphic compare\n3. Are there bigger numbers than yours?\n4. Text copy, lazy bum\n5. Close Terminal.\nOption: ");

			break;
		}
		case 4:
		{
			int size;
			char str1[1000];
			char str2[1000];
			printf("\nEnter your First sentence: ");
			scanf(" %[^\n]s", str1);
			printf("Enter your Second sentence: ");
			scanf(" %[^\n]s", str2);
			char* mstr1 = (char*)malloc((1 + strlen(str1)+strlen(str2)) * sizeof(char));
			strcpy(mstr1, str1);
			char* mstr2 = (char*)malloc((1 + strlen(str2)) * sizeof(char));
			strcpy(mstr2, str2);
			printf("Enter your desired length of dupilcation: ");
			scanf(" %d", &size);
			my_strcpy(mstr1, mstr2, size);
			printf("Duped wording: %s\n\n", mstr1);

			free(mstr1);
			free(mstr2);
			mstr1 = NULL;
			mstr2 = NULL;

			printf("Function List:\n1. Lookup amount of Positive numbers\n2. Lexigraphic compare\n3. Are there bigger numbers than yours?\n4. Text copy, lazy bum\n5. Close Terminal.\nOption: ");
			break;
		}
		}
		
	}
	char ending[] = { "\nThank you for using my program,\nDanno. 2020 meltdown\n" };
	int i = 0;
	while (ending[i])
	{
		Sleep(40);
		printf("%c", ending[i++]);
	}
}

int numorder(int* numarr, int size, int num)
{
	
	if (num == 1)
	{
		if (numarr[num - 1] > 0)

			return 1;
		else
			return 0;
	}

	if ((num == 0) || (num > size))
		return -1;

	int sum = numorder(numarr, size, num - 1);
	if (numarr[num - 1] > 0)

		return sum + 1;
	else
		return sum;
}

int character(char* str1, char* str2)
{
	if (*str1 == 0 || *str2 == 0)
		if (*str1 > * str2)
			return 1;
		else if (*str1 < *str2)
			return -1;
		else if (*str1 == *str2)
			return 0;


	if (*str1 != *str2)
	{
		if (*str1 > * str2)
			return 1;
		else if (*str1 < *str2)
			return -1;
	}

	return character((str1 + 1), (str2 + 1));

}

int isBE(int num, int digit)
{
	if (num < 10)
		if (num >= digit)
			return 1;
		else
			return 0;

	if ((num % 10) >= digit)
		return isBE((num / 10), digit) + 1;
	else
		return isBE((num / 10), digit);

}

void my_strcpy(char a[], char b[], int sizeA)
{
	if (sizeA == 0)
	{
		*a = '\0';
		return;
	}

	*a = *b;
	my_strcpy(a + 1, b + 1, sizeA - 1);

}
