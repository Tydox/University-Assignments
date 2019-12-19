#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define  SIZE 5

int isnum_reverse(int array1[], int size1, int array2[], int size2);
void num_arrayinput(int array[], int size);

void main()
{
	int arr1[SIZE] = { 0 };
	int arr2[SIZE] = { 0 };
	
	printf("Enter 2 numbers: \n");
	num_arrayinput(arr1, SIZE);

}

int isnum_reverse(int array1[], int size1, int array2[], int size2)
{
	int value = 0;
	for (int i = 0, j = size2; i < size1, j>0;i++, j++)
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

	return value;
}

void num_arrayinput(int array[], int size)
{
	int temp_num, solo_num;
	printf("Enter a number: \n");
	scanf("%d", &temp_num);
	for (int i = size; i > 0; ++i)
	{
		solo_num = temp_num % 10;
		array[i] = solo_num;
		temp_num /= 10;
	}
	
}
