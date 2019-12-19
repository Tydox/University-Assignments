#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define  SIZE 6

void num_arrayinput(int array[], int size); // user enters a number and it will put it automatically into an array
void is_mirrored_array(int array1[], int size1); // check if 2 arrays are mirrored

void main()
{
	int arr1[SIZE] = { 0 };
	is_mirrored_array(arr1, SIZE);

}

void num_arrayinput(int array[], int size)
{
	int temp_num, solo_num;
	printf("Enter 6 numbers: \n");
	for (int i = 0 ; i < size; ++i)
	{
		printf("Number %d:", i+1);
		scanf("%d", &temp_num);
		array[i] = temp_num;
		
	}

}

void is_mirrored_array(int array1[], int size1)
{
	//call function to enter numbers into arrays
	num_arrayinput(array1, size1);
	int refresher1, oldnum1, newnum1=0, value=0;
	
	for (int u = 0, j = size1; j < u; ++u, --j) // U:A0->An && J:An->U
	{
		if ((array1[u] < 0) || (array1[j] < 0)) // stop program because of invalid input
		{
			printf("Error, invalid input!\n");
			break;
		}

		oldnum1 = array1[u];
		
			while(oldnum1>0) // reverse numbers
			{
				refresher1 = oldnum1 % 10;
				newnum1 = (newnum1+refresher1) * 10;
				oldnum1 = oldnum1 / 10;
		
			}
		value = array1[j] != newnum1?

		}
	}
