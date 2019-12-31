#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void calcNums(int num1, int num2, int* sum, int* div, int* dup);

void main()
{
	int num1, num2, sum, div, dup;
	printf("Enter 2 numbers\n");
	scanf("%d%d", &num1, &num2);
	calcNums(num1, num2, &sum, &div, &dup);
	printf("Sum:%d\nMinus:%d\nDup:%d\n", sum, div, dup);
	system("pause");
}

void calcNums(int num1, int num2, int* sum, int* div, int* dup)
{
	*sum = num1 + num2;
	*div = num1 - num2;
	*dup = num1 * num2;
}
