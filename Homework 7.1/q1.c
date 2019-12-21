#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define  SIZE 3

int isnum_reverse(int array1[], int size1, int array2[], int size2);
void num_arrayinput(int array[], int size);

void main()
{
	int arr1[SIZE] = { 0 };
	int arr2[SIZE] = { 0 };
	
	printf("Reversi Checker\n----------\n");
	num_arrayinput(arr1, SIZE);
	num_arrayinput(arr2, SIZE);
	isnum_reverse(arr1, SIZE, arr2, SIZE);

}

int isnum_reverse(int array1[], int size1, int array2[], int size2)
{
	int value = 0;
	for (int i = 0, j = size2-1; i < size1, j>-1;++i, --j)
	{
		if (array1[i] != array2[j])
		{
			value=1;
			break;
		}
		if (array1[i] == array2[j])
		{
			value = 0;
		}
		
	}
	if (value == 1)
	{
		printf("The entered numbers are not reversed.\n");
	}
	else{
		printf("The entered numbers are reversed.\n");
	}
	return value;
}

void num_arrayinput(int array[], int size)
{
	int temp_num, solo_num;
	printf("Enter a number (%d) \n", size);
	scanf("%d", &temp_num);
	for (int i = size-1; i > -1; --i)
	{
		solo_num = temp_num % 10;
		array[i] = solo_num;
		temp_num /= 10;
	}
	
}
 