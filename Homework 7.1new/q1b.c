#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define  SIZE 3
#define  SIZE1 3

void num_arrayinput(int array[][SIZE], int size1,int size2); // user enters a number and it will put it automatically into an array
void is_mirrored_array(const int array1[][SIZE], int size1, int size12, const int array2[][SIZE],int size2, int size22); // check if 2 arrays are mirrored
int isnum_reverse(int array1[], int size1, int array2[], int size2);



void main()
{
	int arr1[SIZE1][SIZE] = { 0 };
	int arr2[SIZE1][SIZE] = { 0 };
	
	printf("Enter %d numbers: \n", SIZE1 * SIZE);
	num_arrayinput(arr1, SIZE1, SIZE);

	printf("Enter %d numbers: \n", SIZE1*SIZE);
	num_arrayinput(arr2, SIZE1, SIZE);
	
	printf("----------\nCalculating\n----------\n");
	is_mirrored_array(arr1, SIZE1,SIZE, arr2, SIZE1,SIZE);

}




void num_arrayinput(int array[][SIZE], int size1, int size2)
{
	printf("Enter your character one by one:\n");
	for (int row = 0; row < size1; ++row)//rows
	{
		for (int column = 0; column < size2; ++column)//column
		{
			printf("Enter value:[%d][%d]: \n", row+1, column + 1);
			scanf("%d", &array[row][column]);
		}
	}

	printf("\nTwo Dimensional array elements(full map):\n");
	for (int i = 0; i < SIZE1; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf(" %d", array[i][j]);
			if (j == SIZE - 1) {
				printf("\n");
			}
		}
	}
}


void is_mirrored_array(const int array1[][SIZE], int size1, int size12, const int array2[][SIZE], int size2, int size22)
{
	//call function to enter numbers into arrays
	int value = 0; //init 0, 1 true, 2 false

	for (int u = 0, j = size1 - 1; j > u; ++u, --j) // U:A0->An && J:An->U
	{
		if ((array1[u] < 0) || (array1[j] < 0) || (size12 != size22) || (size1 != size2)) // stop program because of invalid input
		{
			printf("Error, invalid input!\n");
			break;
		}
		for (int row1 = 0, row2=size1-1; row1 < size1; ++row1,--row2)
		{
			for (int col1 = 0, col2=size22-1; col1 < size12; ++col1,--col2)
			{
				if (array1[row1][col1]!=array2[row2][col2])
				{
					value = 2;
					break;
				}
			}
		}
	}
	if (value==2)
	{
		printf("The arrays are not mirrored");
	}
	if (value == 0)
	{
		printf("The arrays are mirrored");
	}
}