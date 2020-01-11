#include  <stdio.h>
#include  <string.h>

void setArray3(const char* str1, const char* str2, char* str3);

void main()
{
	
	const char* str1= "hello world";
	const char* str2 = "lo";
	char str3[100];
	setArray3(str1,str2, str3);
	printf("The new string is: \n");
	puts(str3);

}

void setArray3(const char* str1,const char* str2, char* str3)
{
	int sizestr2 = strlen(str2);
	int i = 0;
	int w = 0;
	for (; *(str1 + i) != 0; ++i)
	{
		
		int j = 0;
		while(*(str2+j))
		{
			if(*(str1+i)==*(str2+j))
			{				
				*(str3 + w) = *(str1 + i);
				*(str3 + w + 1) = *(str1 + i);
				++j;
				++w;
				
			}
			else if(*(str1 + i) != *(str2 + j))
			{
				*(str3 + w) = *(str1 + i);
				++j;				
			}
			
		}
		++w;
	}
	*(str3 + w) = '\0';
	if(strcmp(str3,str1)==0)
	{
		*str3 = '\0';
	}

	
}
