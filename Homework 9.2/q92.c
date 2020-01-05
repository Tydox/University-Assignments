#include <stdio.h>

#define SIZE 50

void strComb(char* str1, char* str2, char* str3);

void main()
{
	char str1[SIZE] = { "abdmuz" };
	char str2[SIZE] = { "acdnz " };
	char str3[27] = { "9" };
	strComb(str1, str2, str3);
	printf("%s", str3);
	
}

//void strComb(char* str1, char* str2, char* str3)
//{
//	char str_temp[500] = { '\0' };
//	int i = 0;
//	while (((*(str1 + i)) != '\0') && (*(str2 + i)) != '\0')
//	{
//		if ((*(str1 + i)) == (*(str2 + i)))
//		{
//			*(str_temp + i) = *(str1 + i);
//			++i;
//	}
//		else
//			if ((*(str1 + i)) >= (*(str2 + i)))
//			{
//				*(str_temp + i) = *(str2 + i);
//				*(str_temp + i+1) = *(str1 + i);
//				++i;
//			}
//			else
//				if((*(str1 + i)) <= (*(str2 + i)))
//			{
//				*(str_temp + i) = *(str1 + i);
//				*(str_temp + i + 1) = *(str2 + i);
//				++i;
//			}
//	}
//	int j = 0;
//	while ((*(str_temp + j) != '\0'))
//	{
//		*(str3 + j) = *(str_temp + j);
//		++j;
//	}
//}

void strComb(char* str1, char* str2, char* str3)
{

	char str_temp[27] = { '0' };
	int i = 0;
	while (*(str1 + i) != '\0')
	{
		if ((*(str1 + i)) == (*(str2 + i)))
		{
			*(str_temp + i) = *(str1 + i);
			++i;

			int j = i;
			while (*(str2 + j) != '\0')
			{
				*(str2 + j) = *(str2 + j + 1);
				++j;
			}
			
		}
		else
		{
			*(str_temp + i) = (*(str1 + i));
			
			++i;
		}
		
	}
	int j = 0;
	while (*(str2 + j) != '\0')
	{
		*(str_temp + i) = (*(str2 + j));

		++i;
		++j;
	}
	
	
}

void removeDigits(char* str)
{
	int i = 0;

	while ((*(str + i) != '\0'))
	{

		if ((((*(str + i) >= '0') && (*(str + i) <= '9'))))
		{
			int j = i;
			while (*(str + j) != '\0')
			{
				*(str + j) = *(str + j + 1);
				++j;
			}
		}
		++i;

	}
}
