#include <stdio.h>

void main()
{

	int number, refreshnumber, newnumber, bouncer = -1;

	printf("Enter a number:\n ");
	scanf_s("%d", &number);

	while ((number != 0) && (bouncer != 0))	//only work when the final number is not equal to 0
	{
		newnumber = number % 10;		 //seperate the first digit from the right
		number = number / 10;		// update the number to be without the old digit
		refreshnumber = number % 10;		//seperate the next digit from the right


		if (refreshnumber > newnumber)		 // check if the new number is smaller than the old number, if so don't run
		{
			bouncer = bouncer + 1;
			printf("Your number is not on a positive incline");

		}


	}
	if (bouncer == -1)
	{
		printf("Your number is in a positive incline");
	}
}