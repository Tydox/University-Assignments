#include <stdio.h>

void main()
{

	int rownum, num2;
	char symbol, spacenum;

	printf("Enter how many rows you want the pyramid to be: \n");
	scanf_s("%d", &rownum);

	printf("Enter what symbol you want to use: \n");
	scanf_s(" %c", &symbol, 1);

	//symbol = getchar();

	for (int r = 1; r <= rownum; r++) //rows maker
	{
		for (int s = 1; s <= rownum; s++) //symbols scheme
		{
			if (s >= rownum + 1 - r)
			{
				printf("%c", symbol);
			}
			else
			{
				printf(" ");
			}

		}
		printf("\n");
	}

}