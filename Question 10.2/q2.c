#include <stdio.h>
#include <string.h>

char* maxlenstr(char* str, int size);



char * maxlenstr(char* str, int size)
{
	int max = strlen(str[size]);
	char* maxstr;
	for (int i = 0; i < size; ++i)
	{
		if (strlen(str[i]) > max)
		{
		max = strlen(str[i]);
		maxstr = str[i];
		}
	}
	return maxstr;
}
