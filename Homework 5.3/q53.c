#include <stdio.h>

int convertBase(int basenum, int num);
long getMiddleMult(long num);

void main()
{
	int basenum, num;
	printf("Base calculator\n-------------\nBase number (1-10): \n");
	scanf("%d", &basenum);
	printf("-------------\nNumber (0-2,147,483,647): \n");
	scanf("%d", &num);

	convertBase(basenum, num);

}

int convertBase(int basenum, int num)
{
	//check if the input base number and number are valid

	int checksum, newnum = num;
	while (newnum != 0)
	{
		int checknum = 0;
		checknum = newnum % 10;

		if (checknum >= basenum)
		{
			printf("Error, number is not related to the entered base number");
			break;
		}

		newnum = newnum / 10;

	}

	// calculate the base
	while (num != 0)
	{
		int multiplednum, exponum, newnum;


		int countExpo = 0;
		int num2 = num;
		while (num2 != 0)
		{
			num2 = num2 / 10;
			countExpo++;
		}

		int result = 0;
		int basenum2 = 0;
		int basenumer = 0;
		int i = 0;


		int exp1 = countExpo;
		int result2 = 1;
		while (exp1 != 0) {

			multiplednum = num % 10;
			num = num / 10;
			if (i == 0)
			{
				basenum2 = basenum * i + 1;
				result = result + (multiplednum * basenum2);
				i = i + 1;
				--exp1;
			}
			else
			{
				result2 = result2 * basenum;
				result = result + (multiplednum * result2);
				--exp1;
			}
		}printf("%d", result);

	}
}