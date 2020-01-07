#include <stdio.h>

long getMiddleMult(long num);
int isKaprekar(int num);

int main()
{
	int num;
	printf("Enter a number and I will tell you if it is a Kaprekar number: \n");
	scanf("%d", &num);
	isKaprekar(num);

}


int isKaprekar(int num)
{
	int leftnum = 0, rightnum = 0, newnum;
	long bignum = 0;
	newnum = num * num;
	bignum = getMiddleMult(newnum);
	leftnum = newnum / bignum;
	rightnum = newnum % bignum;
	if (num == leftnum + rightnum)
	{
		printf("The number is a Kaprekar number");
		return 1;

	}
	else
	{
		printf("The number is not a Kaprekar number");
		return 0;
	}


}


long getMiddleMult(long num) {
	int countDigits = 0;
	while (num != 0) {
		num = num / 10;
		countDigits++;
	}
	// printf("Testing first stage %d\n \n ", countDigits);

	if (countDigits % 2 == 0) {
		int expo = countDigits / 2, result = 1;

		while (expo != 0) {

			result = result * 10;
			expo = expo - 1;

		}
		// printf("%d\n \n ", result);
		return result;

	}
	else

	{
		int expo = (countDigits / 2) + 1, result = 1;
		while (expo != 0)
		{

			result = result * 10;
			expo = expo - 1;

		}
		// printf("%d\n \n ", result);
		return result;
	}
}