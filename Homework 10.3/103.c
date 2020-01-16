#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

void delay(unsigned int value);
char* maxWord(char str[], char tav, int* num);



void main()
{
	int num = 0;
	char tav = 'a';
	char str1[501] = { "\0" };
	printf("Please enter a sentence: ");
	scanf_s("%[^\n]s", str1, 501);
	printf("\nEnter a letter: ");
	scanf_s(" %c", &tav, 1);

	char* ptr = maxWord(str1, tav, &num);
	if (num == 0)
	{
		puts("\nError, letter not found in sentence!");
	}
	if (num != 0)
	{
		printf("\nBiggest word size: |%d|\n", num);
		printf("\nWord:");
		int i = 0;
		while (num > 0)
		{
			Sleep(30);
			printf("%c", ptr[i]);
			++i;
			--num;
		}
	}

	char strend[] = { "\n\n----------\nDone...\n\nThank you for using this program!\n\nMade by Tydox\n\nShutting Down...\nBye! =]\n" };
	while (*(strend + num))
	{
		
		Sleep(30);
		printf("%c", strend[++num]);
		
	}
}

char* maxWord(char str[], char tav, int* num)
{
	
	int min = 0;
	int max = 0;
	int j = 0;
	int length = strlen(str);
	char* maxword = str;

	for (int i = 0; i<length; ++i)
	{
		int count = 0;
		max = 0;
		
		for (j = i; str[j] != ' ' && str[j] != '\0'; ++j)
		{
			++count;
			if (str[j] == tav)
			{
				
				++max;
			}
		}
		if(max>min)
		{
			min = max;
			*num = count;
			maxword = &str[i];
		}
		i = j;
	}
	return maxword;
}