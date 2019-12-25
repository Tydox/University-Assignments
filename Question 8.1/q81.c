#define _CRT_SECURE_NO_WARNINGS
#define SIZE 11
#include <stdio.h>
#include <string.h>


int sizeStr(char str[]);

void main()
{
	char string[SIZE];
	printf("Enter a word (10 letters): \n");
	scanf("%10s", string);
	
	printf("You have %d capital letters\n", sizeStr(string));
	system("pause");
}

int sizeStr(char str[])
{
	int size=0;

	int i = 0;
	while (str[i])
	{
		
		if ((str[i] > 'A') && (str[i] < 'Z'))
		{
			++size;
		}
		++i;
	}

	return size;
}