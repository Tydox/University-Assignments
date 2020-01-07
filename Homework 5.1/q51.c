#include <stdio.h>

unsigned long getMiddleMult(long num);

void main()
{
	int num;
	printf("Enter a number and I will calculate it's base 10: \n");
	scanf("%d", &num);
	getMiddleMult(num);
}

unsigned long getMiddleMult(long num) {
	int countDigits = 0;
	while (num != 0) {
		num = num / 10;
		countDigits++;
	}
	printf("Testing first stage %d\n \n ", countDigits);

	if (countDigits % 2 == 0) {
		int expo = countDigits / 2, result = 1;

		while (expo != 0) {

			result = result * 10;
			expo = expo - 1;

		}
		printf("%d\n \n ", result);

	}
	else

	{
		int expo = (countDigits / 2) + 1, result = 1;
		while (expo != 0)
		{

			result = result * 10;
			expo = expo - 1;

		}
		printf("%d\n \n ", result);
	}
}