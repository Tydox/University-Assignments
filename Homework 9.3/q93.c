#include <stdio.h>
#include <string.h>

#define SIZE 500

void strSwitch(char* str1);

void main()
{
	char str[] = ("abcde");
	strSwitch(str);
	printf("%s", str);


}

void strSwitch(char* str1)
{
	int count = strlen((str1));
	if (count % 2 != 0)
	{
		(*(str1 + count - 1)) = '\0';
	}
	int i = 0;
	while ((*(str1 + i)) != '\0')
	{
		char temp;
		temp = *(str1 + i);
		*(str1 + i) = *(str1 + i + 1);
		*(str1 + i + 1) = temp;
		i = i + 2;
	}
	
}
