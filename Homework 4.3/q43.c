#include <stdio.h>

void main()
{

	int num1, num2, totnum;
	int numsum1 = 0, numsum2 = 0, rnum1, rnum2;

	printf("Enter 2 numbers: \n");
	printf("Number 1: \t");
	scanf_s("%d", &num1);
	printf("Number 2: \t");
	scanf_s("%d", &num2);


	while (num1)
	{
		rnum1 = num1 % 10;
		num1 = num1 / 10;
		numsum1 = numsum1 + rnum1;
	}

	while (num2)
	{
		rnum2 = num2 % 10;
		num2 = num2 / 10;
		numsum2 = numsum2 + rnum2;

	}

	numsum1 = numsum1 > numsum2 ? printf("The bigger sum is of number 1: %d", numsum1) : printf("The bigger sum is of number 2: %d", numsum2);

}