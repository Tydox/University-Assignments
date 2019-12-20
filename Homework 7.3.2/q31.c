#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE1 6
#define SIZE2 6

void maxchar(char chararray[][SIZE1], int size1, int size2);

void main()
{
	int row=0, col=0;
	char base_tav_matrix[SIZE2][SIZE1] = {0};
	//initialize the array
	for (int row = 0; row < SIZE1; ++row)//rows
	{
		for (int column = 0; column < SIZE2; ++column)//column
		{

			base_tav_matrix[row][column] = '0';
		}
	}
	printf("Please enter your matrix size:\n");
	printf("How many rows?: \n");
	scanf(" %d", &row);
	printf("How many columns?: \n");
	scanf(" %d", &col);
	
	maxchar(base_tav_matrix, row, col);
}

void maxchar(char chararray[][SIZE1], int size1, int size2)
{
	if (size1 && size2 <= 6)
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

		//for (int row = 0; row < size1; ++row)//rows
		//{
		//	for (int column = 0; column < size2; ++column)//column
		//	{
		//		printf("Testing Memory Value:[%d][%d]: %c \n", row, column + 1, chararray[row][column]);

		//	}
		//}

		printf("\nTwo Dimensional array elements:\n");
		for (int i = 0; i < size1; i++) {
			for (int j = 0; j < size2; j++) {
				printf(" %c", chararray[i][j]);
				if (j == size2 - 1) {
					printf("\n");
				}
			}
		}

		printf("\nTwo Dimensional array elements(full map):\n");
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				printf(" %c", chararray[i][j]);
				if (j == 6 - 1) {
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
			if (maxtav < chararray[row][size2 - 1])
			{
				maxtav = chararray[row][size2 - 1];
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
	else
	{
		printf("Error the size is not in the pre-defined 6x6 layout, please try again!");
	}
}