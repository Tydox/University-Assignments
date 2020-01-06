#include <stdio.h>
#include <string.h>

#define SIZE 18

int dupeFinder(int* str1, int size1, int* str2, int size2, int* adress);

void main()
{
	int num;
	int arr1[SIZE] = { 1,1,2,3,3,5,2,3,1,2,3,2,2,3,1,2,3,0 };
	int arr2[3] = { 1,2,3 };
	printf("Dupe amount:%d\n",dupeFinder(arr1, SIZE, arr2, 3, &num));
	printf("Address is: %p\n", (arr1+num));
	printf("Address is: %p\n", arr1);
}

int dupeFinder(int* str1, int size1, int* str2, int size2, int* adress)
{ 
	int* adrs=adress;
	int tempsize = size1;
	int counter = -1;
	int i = 0;
	int verifier = 0;
	while(tempsize>0)
	{
		if(*(str1+i)==*(str2))
		{
			for (int j = i, w = 0, temp = size2; temp > 0; ++j, ++w, --temp)
			{
				if (*(str1 + j) == (*(str2 + w)))
				{
					verifier = 0;
				}
				else
				{
					verifier = -1;
					break;
				}
			}
			if (verifier == 0)
			{
				++counter;
				if (counter == 0)
				{
					*adrs = i;
					++counter;
				}
			}
			
		}
		
		--tempsize;
		++i;
	}
	
	if(counter==-1)
	{
		return 0;
	}
	return counter;
}
