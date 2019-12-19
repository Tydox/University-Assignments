#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE1 2
#define SIZE2 2

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
	char maxtav = chararray[0][0];
	//row0+column all
	for (int row = 0; row < size1; ++row)//rows
	{
		for (int column = 0; column < size2-1; ++column)//column
		{
			if (chararray[row][column + 1] > maxtav)
			{
				maxtav = chararray[row][column+1];
			}

		}
	}
	
	printf(" %c", maxtav);
	
	
}
