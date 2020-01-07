#include <stdio.h>

void main()
{
	int number1, number2;
	char symbol;
	float fnum;

	printf("Enter 2 numbers and a mathematical sign, using the following template: \nnumber+/-/*/:/number\n");
	//scanf_s("%d%c%d ", &number1, &symbol, &number2); <--- why does this not work?

	scanf_s("%d", &number1);
	scanf_s(" %c", &symbol);
	scanf_s("%d", &number2);

	switch (symbol)
	{
	case '+': fnum = (float)number1 + number2; printf("%d%c%d=%.f\n", number1, symbol, number2, fnum); break;
	case '-': fnum = (float)number1 - number2; printf("%d%c%d=%.f\n", number1, symbol, number2, fnum); break;
	case '*': fnum = (float)number1 * number2; printf("%d%c%d=%.f\n", number1, symbol, number2, fnum); break;
	case '/': fnum = (float)number1 / number2; printf("%d%c%d=%.2f\n", number1, symbol, number2, fnum); break;
	default: printf("Invalid characters");
	}


}