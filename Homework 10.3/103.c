#include <stdio.h>
#include <string.h>

char* maxWord(char str[], char tav, int* num);

void main()
{
	int num = 0;
	char tav = 'a';
	char str1[] = { "er dfsa aaba" };
	maxWord(str1, tav, &num);
	printf(	"%d", num);
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
		max = 0;
		
		for (j = i; str[j] != ' '; ++j)
		{
			
			if (str[j] == tav)
			{
				++max;
			}
		}
		if(max>min)
		{
			min = max;
			*num = min;
			maxword = &str[i];
		}
		i = j;
	}
	return maxword;
}
