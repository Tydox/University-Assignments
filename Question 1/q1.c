#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 6
void printBigger(int* ptr1, int size);

void main()
{
	int arr[SIZE] = { 0 };
	printf("Enter a number\n");
	for (int i = 0; i < SIZE; i++)
	{
		scanf(" %d", &arr[i]);
	}

	printBigger(arr, SIZE);
	system("pause");
}

void printBigger(int* ptr1,int size)
{
	for (int* p = ptr1; p < ptr1+size-1; p++)
	{
		if ((*(p + 1)-*p)==1)
		{
			printf("%d\n", *(p + 1));
		}
	}
}