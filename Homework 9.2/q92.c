#include <stdio.h>
#include <string.h>

#define SIZE 10
void lenflip(char* str1, char* str2, char* str3);
void main()
{
	char str1[SIZE] = { "abdfgz" };
	char str2[SIZE] = { "acehiz" };
	char str3[27] = { "\0" };
	printf("1: %s\n", str1);
	printf("2: %s\n", str2);
	printf("3: %s\n", str3);
	lenflip(str1, str2, str3);
	printf("------------\n");
	printf("After alpha  3: %s\n", str3);


}

void lenflip(char* str1, char* str2, char* str3)
{
	/*int len1 = strlen(str1);
	int len2 = strlen(str2);*/
	int locstr3 = 0;
	for (int i = strlen(str1) - 1, j = strlen(str2) - 1; i > 0 || j > 0;)
	{
		if ((*(str1 + i)) == (*(str2 + j)))
		{
			*(str3 + locstr3) = *(str1 + i);
			--i;
			--j;
			++locstr3;
		}

		if ((*(str1 + i)) >= (*(str2 + j)))
		{
			*(str3 + locstr3) = *(str1 + i);
			--i;
			++locstr3;
		}
		if ((*(str1 + i)) <= (*(str2 + j)))
		{
			*(str3 + locstr3) = *(str2 + j);
			--j;
			++locstr3;
		}
	}
}
