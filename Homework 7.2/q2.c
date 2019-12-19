#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define  SIZE2 2

void num_arrayinput(int array[], int size); // user enters a number and it will put it automatically into an array
void is_mirrored_array(const int array1[], int size1); // check if 2 arrays are mirrored

void main()
{
	int arr1[SIZE2] = { 0 };
	printf("Enter 6 numbers: \n");
	
	num_arrayinput(arr1, SIZE2);
	
	printf("Calculating... \n");
	is_mirrored_array(arr1, SIZE2);
	printf("Done... \n");
}

void num_arrayinput(int array[], int size)
{
	int temp_num;
	for (int i = 0 ; i < size; ++i)
	{
		printf("Number %d:", i+1);
		scanf("%d", &temp_num);
		array[i] = temp_num;
		
	}

}

void is_mirrored_array(const int array1[], int size1)
{
	//call function to enter numbers into arrays
	//num_arrayinput(array1, size1);
	int refresher1, oldnum1, newnum1 = 0, value = 0;//init 0, 1 true, 2 false
	
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
			value = (array1[j] == newnum1) ? value == 1 : value == 2;
		if (value==2)
		{
			printf("The array is not a mirrored array!\n");
			break;
		}
	}
	if (value == 1)
	{
		printf("The array is a mirrored array!\n");
	}
}
