#include  <stdio.h>
#include  <string.h>

int localMax(int* arr, int* arrPtr[], int size);

#define SIZE 9
void main()
{
	int arr[] = { 1,2,1,2,1,2,1 };
	int* arrPtr[SIZE];
	int size = localMax(arr, arrPtr, SIZE);
	for (int i = 0; i < size; i++)
	{
		printf("arr[%d] = %d \n", i, *(*(arrPtr + i)));
	}
	
}

int localMax(int* arr, int* arrPtr[], int size)
{
	int i = 0;
	int ptrnum = 0;
	while (i < size-2)
	{
		if (i == 0 || i == size - 2)
		{
			if ((*(arr + i)) > (* (arr + i + 1)))
			{
				arrPtr[ptrnum] = arr + i;
				++ptrnum;
			}
		}
		else if (((*(arr + i)) > (*(arr + i + 1))) && ((*(arr + i)) > (*(arr + i - 1))))
		{
			arrPtr[ptrnum] = arr+i;
			++ptrnum;
			
		}
		++i;
	}
	return ptrnum;
}
