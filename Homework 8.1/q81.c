#include <stdio.h>
#define SIZE 11
void myStrcpy(char strA[], char strB[]);

void main()
{
	char str1[SIZE] = { '\0' };
	char str2[SIZE] = { '\0' };
	printf("Enter a tav: \n");
	scanf_s(" %s", str1, SIZE-1);
	printf("Enter a tav: \n");
	scanf_s(" %s", str2, SIZE-1);
	printf("Copying: \n");
	myStrcpy(str1, str2);
	printf("A: %s\nB: %s", str1, str2);

}

void myStrcpy(char strA[], char strB[])
{
	int i;
	for(i=0 ; strA[i] != '\0';++i)
	{
		strB[i] = strA[i];
		
	}
	strB[i] = '\0';
}
