#include <stdio.h>

#define SIZE 31

int str_super_cmp(char firstIdx[], char secondIdx[], int firstidxnum, int secondIdxnum, int cmpnum);

void main()
{
	char str1[SIZE] = { '\0' };
	char str2[SIZE] = { '\0' };
	int str1index = 0;
	int str2index = 0;
	int indexnum = 0;
	printf("MEGA TEXT ANALYZER\n----------\n");
	printf("Enter a sentence %d: \n", SIZE-1);
	scanf_s(" %[^\n]s", str1, SIZE - 1);
	printf("What is the index for string 1?\n");
	scanf_s(" %d", &str1index);
	printf("Enter a sentence %d: \n", SIZE-1);
	scanf_s(" %[^\n]s", str2, SIZE - 1);
	printf("What is the index for string 2?\n");
	scanf_s(" %d", &str2index);
	printf("Enter how many letters to check (number only): \n");
	scanf_s("%d", &indexnum);
	printf("%d", str_super_cmp(str1, str2, str1index, str2index, indexnum));
}

int str_super_cmp(char firstIdx[], char secondIdx[], int firstidxnum, int secondIdxnum, int cmpnum)
{
	int verifier = 0;
	int i = firstidxnum + 1;
	int j = secondIdxnum + 1;
	int w = cmpnum;
	while ((firstIdx[i] != '\0') && (secondIdx[j] != '\0') && (w>0))
	{
		
		if (firstIdx[i] > 'A' && firstIdx[i] < 'Z') //ignore lowercase difference
		{
			firstIdx[i] -= 32;
		}
		if (secondIdx[j] > 'A' && secondIdx[j] < 'Z') //ignore lowercase difference
		{
			secondIdx[j] -= 32;
		}

			if ((firstIdx[i] - secondIdx[j]) != 0)
			{

				if ((firstIdx[i] - secondIdx[j]) > 0)
				{
					verifier = verifier + (firstIdx[i] - secondIdx[j]);
				}
				if ((secondIdx[j] - firstIdx[i]) > 0)
				{
					verifier = verifier + (secondIdx[j] - firstIdx[i]);
				}

			/*verifier = ((firstIdx[i] - secondIdx[j]) > 0) ? firstIdx[i] - secondIdx[j] : verifier;
			verifier = ((secondIdx[j] - firstIdx[i]) > 0) ? secondIdx[j] - firstIdx[i] : verifier;
			verifier = ((secondIdx[j] - firstIdx[i]) == 0) ? 0 : verifier;*/

		}
			++i;
			++j;
			--w;

		
		
	}
	return verifier;
}

////if ((firstIdx[i] == '\0') || (secondIdx[j] == '\0') || (w==0)) // break the loop when reaching the end
//{
//	break;
//}
//while ((firstIdx[i] == secondIdx[j]) && (cmpnum>-1)&& (firstIdx[i] != '\0') && (secondIdx[j] != '\0'))
//for (int i = firstidxnum, j = secondIdxnum, w = 0; w < cmpnum; ++i, ++j, ++w) //i first index, j second index, w is char number to go over