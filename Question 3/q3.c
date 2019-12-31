#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10
void printstr(char* str1, char* str2);

void main()
{
	char str1[SIZE] = { '\0' };

	char str2[SIZE] = { '\0' };
	gets(str1, SIZE - 1);
	gets_s(str2, SIZE - 1);
	printstr(str1, str2);

	system("pause");
}

void printstr(char* str1, char* str2)
{
	for (char* i = str1, *j=str2; *i != '\0' && *j != '\0'; ++i, ++j)
	{
		if (*i == *j)
		{
			printf("%c\n", *i);
		}
		
	}
}
