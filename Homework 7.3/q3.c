#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE1 3
#define SIZE2 3

void maxchar(char chararray[][SIZE1], int size1, int size2);

void main()
{
	char tav_matrix[SIZE2][SIZE1] = { 0 };
	maxchar(tav_matrix, SIZE2, SIZE1);
}

void maxchar(char chararray[][SIZE1], int size1, int size2)
{

	printf("Enter your character one by one:\n");
	for (int row = 0; row < size1; ++row)//rows
	{
		for (int column = 0; column < size2; ++column)//column
		{
			printf("Enter value:[%d][%d]: \n", row, column + 1);
			scanf(" %c", &chararray[row][column]);
		}
	}

	for (int row = 0; row < size1; ++row)//rows
	{
		for (int column = 0; column < size2; ++column)//column
		{
			printf("Testing Memory Value:[%d][%d]: %c \n", row, column + 1, chararray[row][column]);

		}
	}

	printf("\nTwo Dimensional array elements:\n");
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			printf(" %c", chararray[i][j]);
			if (j == size2 - 1) {
				printf("\n");
			}
		}
	}
	char maxtav = chararray[0][0];

	for (int row = 0; row < size1; ++row)//rows
	{
		if (maxtav < chararray[row][0]) 
		{
			maxtav = chararray[row][0];
		}
		if (maxtav < chararray[row][size2-1])
		{
			maxtav = chararray[row][size2-1];
		}
	}
	
	for (int col = 0; col < size2; ++col)//rows
	{
		if (maxtav < chararray[0][col])
		{
			maxtav = chararray[0][col];
		}
		if (maxtav < chararray[size1 - 1][col])
		{
			maxtav = chararray[size1 - 1][col];
	}
	}
	printf("\nMAX TAV %c", maxtav);
}