#include <stdio.h>

void myStrcpy(int* strA, int* strB);

void main()
{
	int *str1;
	int* str2;
}

void myStrcpy(int* strA, int* strB)
{
	int temp;
	temp = strA;
	*strA = strB;
	*strB = temp;
}
