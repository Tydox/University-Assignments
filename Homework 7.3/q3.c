#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE1 3
#define SIZE2 4

void maxchar(int chararray[][SIZE1], int size);

void main()
{
	char tav_array[SIZE2][SIZE1] = { 0 };
	
}

void maxchar(int chararray[][SIZE1], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("Enter value %d:", i + 1);
		scanf_s("%d", &chararray[i]);
	}
}
