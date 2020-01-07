#include <stdio.h>
#include <string.h>

int findLastWord(char* str);

void main()
{
	char str[50] = "macbb";
	findLastWord(str);

}

int findLastWord(char * str)
{
	int len = strlen(str);

	while (*(str + len) != ' ')
	{
		if (len == 0)
			break;

		--len;
	}
	printf("%s", (str + len));
}
