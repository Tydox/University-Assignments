#include <stdio.h>

#define SIZE 501

void password_encrypt(char passwordstr[], int idx);

void main()
{
	char pstr[SIZE] = { '0' };
	int indexnum=0;
	printf("Enter your text [%d]: \n", SIZE - 1);
	scanf_s(" %[^\n]s", pstr, SIZE - 1);
	printf("Enter your index to encrypt: \n");
	scanf_s("%d", &indexnum);
	password_encrypt(pstr, indexnum);
	printf("%s", pstr);
}

void password_encrypt(char passwordstr[], int idx)
{
	char tempstr[501] = { '\0' };
	int i = idx+1;
	int j = 0;
	for (j; passwordstr[i] != '\0'; ++i, ++j) // copy text after cut
	{
		tempstr[j] = passwordstr[i];
	}
	for (int i = 0; i < idx+1; ++i,++j) // copy text before the cut
	{
		tempstr[j] = passwordstr[i];
	}

	
	for (int i = 0; tempstr[i] != '\0'; ++i)
	{
		passwordstr[i] = tempstr[i];
		
	}
	passwordstr[j + 1] = '\0';
}
