#include <stdio.h>
#define SIZE 40
void removeDigits(char* str);

void main()
{
	char str[SIZE] = { "Today I had 3 apples and 2 bananas1!" };
	removeDigits(str);
	printf("%s", str);
}

void removeDigits(char* str)
{
	int i = 0;
	
	while ((*(str+i) != '\0'))
	{
	
		if ((((*(str + i) >= '0') && (*(str + i) <= '9'))))
		{
			int j = i;
			while(*(str + j) != '\0')
			{
				*(str + j) = *(str + j + 1);
				++j;
			}
		}
		++i;
		
	}
}
